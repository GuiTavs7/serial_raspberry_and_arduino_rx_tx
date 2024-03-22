String comando; // Variável para armazenar a string recebida
const int pino_led = 13; // Define o pino 13 do LED como constante

// Vetores para códigos de barras, larguras e alturas
String codigos[] = {"15756719", "15756540", "15755617", "15755656", "15755512"}; //Vetor de strings para os códigos de barras
float larguras[] = {2.36, 1.27, 2.02, 1.57, 1.58}; //Vetor de larguras correspondentes às peças conforme os códigos de barras
float alturas[] = {1.51, 1.68, 2.02, 1.51, 1.52}; //Vetor de alturas correspondentes às peças conforme os códigos de barras
int num_pedidos = sizeof(codigos) / sizeof(codigos[0]); // Variável para ser utilizada no limite do loop "for", para fazer o programa iterar até a quantidade necessária de códigos de barras

// Função setup - Configurações iniciais

void setup() {
  Serial.begin(115200); // Estabelece a comunicação serial com uma taxa de 115200
  pinMode(pino_led, OUTPUT); // Define o pino do LED (13) como saída - Porta Digital
}

// Fim da função setup

// -----------------------------------------------------------------------------------------

// Função loop - Código principal - Roda em loop

void loop() {

  while (Serial.available() > 0) { // Enquanto houver comunicação serial

    
    comando = Serial.readString(); // Lê a string recebida por comunicação serial através do python Raspberry

    boolean encontrado = false;

    // Loop "for" percorre o vetor de códigos de barras
    
    for (int i = 0; i < num_pedidos; i++) {
      if (codigos[i] == comando) {
        // Código encontrado - exibir informações
        Serial.println("Código de barras encontrado: ");
        Serial.println(codigos[i]);
        Serial.print("Largura: ");
        Serial.println(larguras[i]);
        Serial.print("Altura: ");
        Serial.println(alturas[i]);
        encontrado = true;
        digitalWrite(pino_led, HIGH); // Acende o LED
        delay(1000); // Aguarda intervalo de tempo em milissegundos
        digitalWrite(pino_led, LOW); // Apaga o LED
        delay(1000); // Aguarda intervalo de tempo em milissegundos
        Serial.println("Recebido! - LED aceso!"); // Envia a resposta para o Raspberry
      }
    } // Fim do loop "for"

    if (!encontrado) {
      // Código não encontrado - exibir mensagem
      Serial.println("Código de barras não encontrado! Reinicie o programa!");
    }

  } // Fim do loop "while", ou seja, encerrou a transferência de dados via serial entre o Arduino e o Raspberry
  
}  // Fim da função loop
