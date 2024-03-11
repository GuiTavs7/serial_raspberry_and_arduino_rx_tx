#Script / código em Python para integrar dados entre um Raspberry Pi 4 e um Arduino Uno via comunicação serial

# IMPORTAÇÃO DE BIBLIOTECAS

import RPi.GPIO as GPIO # importa a biblioteca que permite controle dos pinos GPIO do Raspberry Pi
import time # importa biblioteca com várias funções de tempo
import serial # importa a biblioteca de comunicação serial com dispositivos externos, como o Arduino

# ----------------------------------------------------------------------------------------------------------------------------------

# CONFIGURAÇÕES INICIAIS

# Configura a comunicação serial com o Arduino 
# Estamos criando um objeto Serial chamado ser que representa a comunicação serial com o dispositivo conectado à porta /dev/ttyACM0 do Raspberry Pi
# Com uma velocidade de transmissão de 115200 bps.

ser = serial.Serial("/dev/ttyACM0", 115200)

GPIO.setmode(GPIO.BOARD) # Configuração do modo de numeração dos pinos do GPIO, caso seja conectado algum LED ou algo do tipo no Rasperry.

# Mensagem inicial
print("Verificador de código de barras...")

# ----------------------------------------------------------------------------------------------------------------------------------

# LOOP PRINCIPAL DO PROGRAMA

while True:
  
    # Lê a variável digitada pelo usuário
    comando = input("Digite o valor do codigo de barras: ")

    # Converte a variável para bytes
    data = comando.encode()

    # Envia a variável para o Arduino
    ser.write(data)

    # Exibe mensagem de confirmação de envio para o Arduino
    print(f"Enviado - {comando}")

    # Neste trecho, aguardamos a resposta do Arduino. Estamos lendo cada linha de resposta do Arduino; 

    resposta = ""
    while True:
        resposta_atual = ser.readline().decode() #ser.readline() lê uma linha de dados da porta serial, e decode() converte os bytes lidos em uma string Unicode.
        resposta += resposta_atual # Concatenando a resposta atual à variável resposta. Isso nos permite acumular todas as respostas recebidas do Arduino em uma única string.
        print(resposta_atual.strip())  # Imprime a resposta atual sem espaços em branco. O método strip() remove os espaços em branco (incluindo espaços, tabulações e novas linhas) do início e do fim da string.
        
        # Verifica se a resposta atual começa com informação de "altura" e, caso seja isso mesmo, continua a execução do programa
        if resposta_atual.startswith("Altura:"):
            break

    # Lê se o usuário deseja continuar
    continuar = input("Digite se deseja continuar... 1 para Sim, 0 para Não: ")
    
    # Se o valor de continuar for diferente de 1 encerra o programa
    if continuar != '1': 
        break
        
# ----------------------------------------------------------------------------------------------------------------------------------

# Fechar a conexão com a porta serial
ser.close()

print("Programa encerrado.")


