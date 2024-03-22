import serial
import time

# Conectar-se à porta serial do Arduino
ser = serial.Serial('/dev/ttyACM0', 9600)

while True:
    codigo = input("Digite um código de barras válido: ")

    # Enviar código de barras para o Arduino
    ser.write(codigo.encode())

    # Esperar a resposta do Arduino
    resposta = ser.readline().decode().strip()

    if resposta == "Código válido":
        altura = ser.readline().decode().strip()
        largura = ser.readline().decode().strip()
        print(f"Altura: {altura}, Largura: {largura}")
    else:
        print("Código de barras não encontrado.")

    continuar = input("Deseja digitar mais um código? (S/N): ")
    if continuar.lower() != 's':
        break

# Fechar a conexão com a porta serial
ser.close()

print("Programa encerrado.")
