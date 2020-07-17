#include <AFMotor.h> //biblioteca shield motores


AF_DCMotor motor1(1); //define motor 1 no shield
AF_DCMotor motor2(2); //motor 2 no shield
AF_DCMotor motor3(3); //motor 3 no shield
AF_DCMotor motor1(4); //motor 4 no shield ativar quando estiver usando as peças do turtlebot  
 
int velocidade = 255; //maxima velocidade
int velocidadeVirar = 255; //velocidade para manobra

int distancia_min = 30; //distancia minima para o desvio, sera comparada com a distancia recebida do arduino mestre 


void setup() {
  Serial.begin(9600); //INICIALIZA O MONITOR SERIAL
  delay(500);
}
 
void loop() {
  
  parado();

  if(Serial.available()>0){
    char valor=Serial.read();//recebe valora enviado pelo arduino primary
    if(valor == '1'){
      frente();  
    } 
    if(valor == '2'){
      direita();  
    }
    if(valor == '3'){
      esquerda();  
    } 
  }
 
  delay(500); //INTERVALO DE 500 MILISSEGUNDOS*/
}

/*void manobra(){
  esquerda();
  delay(500);
  tras();
  delay(500);
}*/

void frente(){
  motor1.setSpeed(velocidade);
  motor1.run(FORWARRD);
  motor2.setSpeed(velocidade);
  motor2.run(FORWARD);
  motor3.setSpeed(velocidade);
  motor3.run(FORWARRD);
  motor4.setSpeed(velocidade);
  motor4.run(FORWARD);
  
}

void tras(){
  motor1.setSpeed(velocidade);
  motor1.run(BACKWARD);
  motor2.setSpeed(velocidade);
  motor2.run(BACKWARD);
  motor3.setSpeed(velocidade);
  motor3.run(BACKWARD);
  motor4.setSpeed(velocidade);
  motor4.run(BACKWARD);
}

void esquerda(){
  motor1.setSpeed(velocidade);
  motor1.run(FORWARD);
  motor2.setSpeed(velocidade);
  motor2.run(FORWARD);
  motor3.setSpeed(velocidade);
  motor3.run(BACKWARD);
  motor4.setSpeed(velocidade);
  motor4.run(BACKWARD);

}

void direita(){
  motor1.setSpeed(velocidade);
  motor1.run(BACKWARD);
  motor2.setSpeed(velocidade);
  motor2.run(BACKWARD);
  motor3.setSpeed(velocidade);
  motor3.run(FORWARD);
  motor4.setSpeed(velocidade);
  motor4.run(FORWARD);
}

void parado(){
  motor1.setSpeed(velocidade);
  motor1.run(RELEASE);
  motor2.setSpeed(velocidade);
  motor2.run(RELEASE);
  motor3.setSpeed(velocidade);
  motor3.run(RELEASE);
  motor4.setSpeed(velocidade);
  motor4.run(RELEASE);
}
