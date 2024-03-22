#include <Arduino.h>
#include <SoftwareSerial.h>

SoftwareSerial mySerial(2, 3); // RX, TX

long pedido[] = {131974, 131974, 131394, 131974, 131974, 132799, 132611, 132611, 132751};
float largura[] = {0.81, 0.86, 0.87, 0.93, 0.96, 0.96, 1, 1, 1.01};
float altura[] = {1.35, 1.25, 1.2, 1.35, 1.25, 2.4, 2.49, 2.49, 2.6};
int num_pedidos = sizeof(pedido) / sizeof(pedido[0]);

void setup() {
  // Inicializar a comunicação serial
  Serial.begin(9600);
  mySerial.begin(9600);
}

void loop() {
  if (mySerial.available() > 0) {
    // Receber código de barras do Raspberry Pi
    long codigo = mySerial.parseInt();

    // Verificar se o código existe no vetor
    boolean encontrado = false;
    for (int i = 0; i < num_pedidos; i++) {
      if (pedido[i] == codigo) {
        // Enviar resposta "Código válido" ao Raspberry Pi
        mySerial.println("Código válido");

        // Enviar altura e largura correspondentes ao Raspberry Pi
        mySerial.println(altura[i]);
        mySerial.println(largura[i]);
        encontrado = true;
        break;
      }
    }

    if (!encontrado) {
      // Enviar resposta "Código inválido" ao Raspberry Pi
      mySerial.println("Código inválido");
    }
  }
}
