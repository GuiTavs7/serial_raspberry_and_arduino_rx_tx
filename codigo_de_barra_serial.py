#Programa : Comunicacao Raspberry e Arduino
#Autor : MakerHero

#Execute os codigos abaixo no terminal do Raspbian para configurar a porta serial ttyACM0 corretamente
#sudo systemctl mask serial-getty@ttyAMAO.service
#sudo reboot
 
import RPi.GPIO as GPIO
import time
import serial
 
#Configura a serial e a velocidade de transmissao
ser = serial.Serial("/dev/ttyACM0", 115200)
 
GPIO.setmode(GPIO.BOARD)
 
#Define o pino do botao como entrada
GPIO.setup(18, GPIO.IN)
 
#Mensagem inicial
print ("Pressione o botao...")
 
while True:
    # Lê a variável digitada pelo usuário
    comando = input("Digite a variável: ")

    # Converte a variável para bytes
    data = comando.encode()

    # Envia a variável para o Arduino
    ser.write(data)

    # Exibe mensagem de confirmação
    print(f"Enviado - {comando}")

    # Aguarda resposta do Arduino
    resposta = ser.readline()

    # Exibe a resposta do Arduino
    print(resposta.decode())

    # Aguarda 0,5 segundos
    time.sleep(0.5)
