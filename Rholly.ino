//Bibliotecas do sensor e do motor
#include <HCSR04.h>
#include <AFMotor.h> 

//Instâncias dos motores e do sensor
AF_DCMotor motorE(1);
AF_DCMotor motorD(2);  
UltraSonicDistanceSensor distanceSensor(9, 10);

int distancia;

void setup(){
//Definição da velocidade dos motores, caso um gire mais rapido que o outro ajustar por aqui.  
motorE.setSpeed(255);
motorD.setSpeed(255);
}  
   
void loop(){
  //Veririfca a distância
    distancia = distanceSensor.measureDistanceCm();
    if(distancia > 0){ //Caso o sensor tenha algum problema ele retorna "-1", verifica isto.
    if(distancia < 15){ //Verifica se está à 15 centímetros.
      //Inicia a ré
     motorD.run(BACKWARD);
     motorE.run(BACKWARD);
     delay(1000);
      //Realiza o giro
     motorD.run(FORWARD);
     motorE.run(BACKWARD);
     delay(400);
    }else{
      //Anda para frente caso não tenha algo próximo.
    motorE.run(FORWARD);
    motorD.run(FORWARD);
    }
   }
  }    
