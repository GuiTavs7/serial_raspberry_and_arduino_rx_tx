//CODIGO PARA TESTAR COMUNICACAO SERIAL ENTRE RASPBERRY E ARDUINO

const int pino_led = 13; //Define o pino 13 do LED como constante
char buf; // Variavel char buf
int estado = 1; // Atribui 1 a variavel estado

// Inicio da funcao setup - CONFIGURACOES INICIAIS

void setup() {

  pinMode(pino_led, OUTPUT); //Define o pino do LED (13) como saida - Porta Digital
  Serial.begin(115200); //Estabelece a comunicao serial com uma taxa de 115200
  

} // FIM DA FUNCAO SETUP 


// Inicio da funcao LOOP - CODIGO PRINCIPAL - RODA EM LOOP

void loop() {

  while (Serial.available() > 0) //Enquanto houver comunicacao serial
  {
    buf = Serial.read();

    if (buf == 'L') // Caso seja recebido o caractere L, acenda o LED
    {
      // Liga ou desliga o led da porta 13

      //Acende o led
      digitalWrite(pino_led, HIGH);
    
      //Aguarda intervalo de tempo em milissegundos
      delay(1000);
    
      //Apaga o led
      digitalWrite(pino_led, LOW);
    
      //Aguarda intervalo de tempo em milissegundos
      delay(1000);
      
      digitalWrite(pino_led, estado);
      
      // Envia a resposta para o Raspberry
      Serial.print("Recebido! - Estado Led: ");
      
      //if (estado == 1)
      //{
        //Serial.println("Ligado");
      //} 
      //else
        //Serial.println("Desligado");
        
    } // FIM DO PRIMEIRO IF 
    
    // Inverte o estado do led
    estado = !estado;
    
  }
  
} // FIM FA FUNCAO LOOP
