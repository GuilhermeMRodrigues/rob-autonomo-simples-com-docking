#include <SharpIR.h>

#define senor1 A1 //pino analogioco em que o sensor sharp1 esta conectado
#define senor2 A2 //pino analogioco em que o sensor sharp1 esta conectado
#define senor3 A3 //pino analogioco em que o sensor sharp1 esta conectado
#define senor4 A4 //pino analogioco em que o sensor sharp1 esta conectado
#define senor5 A5 //pino analogioco em que o sensor sharp1 esta conectado

#define model 1080 //determina o modelo do sensor

Frente SharpIR(sensor1, model); //Passa os parametros para a função (Pino analogico, Modelo do SENSOR)
Esquerda SharpIR(sensor2, model); //Passa os parametros para a função (Pino analogico, Modelo do SENSOR)
Direita SharpIR(sensor3, model); //Passa os parametros para a função (Pino analogico, Modelo do SENSOR)
Tras SharpIR(sensor4, model); //Passa os parametros para a função (Pino analogico, Modelo do SENSOR)
/*EsquerdaLado SharpIR(sensor5, model); //Passa os parametros para a função (Pino analogico, Modelo do SENSOR)
DireitaLado SharpIR(sensor6, model); //Passa os parametros para a função (Pino analogico, Modelo do SENSOR)*/

int distancia_min = 30;

void setup() {
  Serial.begin(9600);
  delay(500);

}

void loop() {
  int distancia_frente = Frente.distance(); //variavel recebe a distancia medida
  int distancia_esquerda = Esquerda.distance(); //variavel recebe a distancia medida
  int distancia_frente = Direita.distance(); //variavel recebe a distancia medida
  int distancia_tras = Tras.distance(); //variavel recebe a distancia medida

 //condições para manobra

 if(distancia_frente < distancia_min){
    vira();
 }
 else{
    Serial1.write('1'); //envia o valor 1 para o arduino secondary, 1 = frente
 }
 dela(500); 
}//fim loop

void vira(){
  if(distancia_esqueda > distancia_direita){
    Serial1.write('2')//envia o valor 2 para o arduino secondary, 2 = vira direita   
  }
  else{
    Serial1.write('3')////envia o valor 3 para o arduino secondary, 3 = vira esqueda  
  }
}
