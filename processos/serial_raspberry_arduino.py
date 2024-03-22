#Programa : Comunicacao Raspberry e Arduino

#Execute os codigos abaixo no terminal do Raspbian para configurar a porta serial ttyACM0 corretamente
#sudo systemctl mask serial-getty@ttyAMAO.service
#sudo reboot
 
import RPi.GPIO as GPIO
import time
import serial
 
#Configura a serial e a velocidade de transmissao
ser = serial.Serial("/dev/ttyACM0", 115200)
 
GPIO.setmode(GPIO.BOARD)

#Mensagem inicial
print ("Pressione a tecla L...")
 
while(1):
       #Envia o caracter L pela serial
       data = 'L'.encode() #funcao para transformar string L em byte
       ser.write(data) 
       print('Enviado - L')
       #Aguarda reposta
       resposta = ser.readline()
       #Mostra na tela a resposta enviada
       #pelo Arduino
       print (resposta)
       #Aguarda 0,5 segundos e reinicia o processo
       time.sleep(0.5)
