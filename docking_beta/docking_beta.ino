#include <SharpIR.h>
#include <IRremote.h>

#define sensor_1 7; //define os pinos do sensor frente
#define sensor_2 8; //define o pino do sensor frente_esquerda
#define sensor_3 9; //define o pino do sensor frente_direita
#define sensor_4 10; //define o pino do sensor direita
#define sensor_5 11; //define o pino do sensor esquerda
#define sensor_6 12; //define o pino do sensor tras

IRrecv frente(sensor_1);
IRrecv frente_esquerda(sensor_2);
IRrecv frente_direita(sensor_3);
IRrecv direita(sensor_4);
IRrecv esquerda(sensor_5);
IRrecv tras(sensor_6);

decode_results results;

void setup() {
 
  Serial.begin(9600); 
  frente.enableIRIn();
  frente_esquerda.enableIRIn();
  frente_direita.enableIRIn();
  esquerda.enableIRIn();
  direita.enableIRIn();
  tras.enableIRIn();
}

void loop() {
  if(frente.decode(&results)){ //se o sensor da frente receber o sinal
      Serial1.write('1');//direciona o carrinho para frente
      frente.resume();//reinicia o sensor
  }
  else if(frente_esquerda.decode(&results)){ //se o senor da frente_esquerda receber o sinal
      Serial1.write('2');//direciona o carrinho para manobra esquerda
      frente_esquerda.resume();//reinicia o sensor
  }
  else if(frente_direita.decode(&results)){
      Serial1.write('3');//direciona o carrinho para manobra direita 
      frente_direita.resume();//reinicia o sensor 
  }
  else if(esquerda.decode(&results)){ //se o sensor lado esquerdo receber o sinal
      Serial1.write('4');//manobra brusca para esquerda
      esquerda.resume();//reinicia o sensor  
  }
  else if(direita.decode(&results)){ //se o sensor lado direito recebr o sinal
      Serial1.write('5');//manobra brusca para direita
      direita.resume();//reinicia o sensor
  }
  else if(tras.decode(&results)){ //se o senor traseiro receber o sinal 
      Serial1.write('6');//manobra 180º
      tras.resume();//reinicia o sensor 
 }
} 
