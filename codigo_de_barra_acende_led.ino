const int pino_led = 13; // Define o pino 13 do LED como constante
String comando; // Variável para armazenar a string recebida, pois queremos mandar um conjunto de caracteres ou numeros para o arduino
int estado = 1; // Atribui 1 à variável estado

// Função setup - Configurações iniciais
void setup() {
  pinMode(pino_led, OUTPUT); // Define o pino do LED (13) como saída - Porta Digital
  Serial.begin(115200); // Estabelece a comunicação serial com uma taxa de 115200
}

// Função loop - Código principal - Roda em loop
void loop() {
  while (Serial.available() > 0) { // Enquanto houver comunicação serial
    comando = Serial.readString(); // Lê a string até o caractere de nova linha

    if (strcmp(comando.c_str(), "7908639900537") == 0) { // Compara a string com "LIGAR"
      digitalWrite(pino_led, HIGH); // Acende o LED
      delay(1000); // Aguarda intervalo de tempo em milissegundos
      digitalWrite(pino_led, LOW); // Apaga o LED
      delay(1000); // Aguarda intervalo de tempo em milissegundos
      Serial.println("Recebido! - LED aceso!"); // Envia a resposta para o Raspberry
    }
    else{
      Serial.println("Digite 'LIGAR' para acender o LED!"); // Envia a resposta para o Raspberry
    }

    estado = !estado; // Inverte o estado do LED
  }
}
