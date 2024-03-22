String comando; // Variável para armazenar a string recebida

// Vetores para códigos de barras, larguras e alturas
String codigos[] = {"131974", "131975", "131394", "131976", "131978", "132799", "132611", "132612", "132751"}; //Vetor de strings para os códigos de barras
float larguras[] = {0.81, 0.86, 0.87, 0.93, 0.96, 0.96, 1, 1, 1.01}; //Vetor de larguras correspondentes às peças conforme os códigos de barras
float alturas[] = {1.35, 1.25, 1.2, 1.35, 1.25, 2.4, 2.49, 2.49, 2.6}; //Vetor de alturas correspondentes às peças conforme os códigos de barras
int num_pedidos = sizeof(codigos) / sizeof(codigos[0]); // Variável para ser utilizada no limite do loop "for", para fazer o programa iterar até a quantidade necessária de códigos de barras

// Função setup - Configurações iniciais

void setup() {
  Serial.begin(115200); // Estabelece a comunicação serial com uma taxa de 115200
}

// Fim da função setup

// -----------------------------------------------------------------------------------------

// Função loop - Código principal - Roda em loop

void loop() {

  while (Serial.available() > 0) { // Enquanto houver comunicação serial

    
    comando = Serial.readString(); // Lê a string até o caractere de nova linha

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
      }
    } // Fim do loop "for"

    if (!encontrado) {
      // Código não encontrado - exibir mensagem
      Serial.println("Código de barras não encontrado! Reinicie o programa!");
    }

  } // Fim do loop "while", ou seja, encerrou a transferência de dados via serial entre o Arduino e o Raspberry
  
}  // Fim da função loop
