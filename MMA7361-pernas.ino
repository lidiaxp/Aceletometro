#include <AcceleroMMA7361.h>
  
AcceleroMMA7361 accelero;
AcceleroMMA7361 accelero2;
int x;
int y;
int z;
int x2;
int y2;
int z2;
int x0;
int y0;
int z0;
int x20;
int y20;
int z20;
 
void setup(){
  Serial.begin(9600);
  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero2.begin(13, 12, 11, 10, A3, A4, A5);
  accelero.setARefVoltage(3.3);  //sets the AREF voltage to 3.3V
  accelero.setSensitivity(LOW);  //sets the sensitivity to 6G
  accelero.calibrate();
  accelero2.setARefVoltage(3.3);  //sets the AREF voltage to 3.3V
  accelero2.setSensitivity(LOW);  //sets the sensitivity to 6G
  accelero2.calibrate();
  for(int i = 2; i < 10; i++){
    pinMode(i, OUTPUT);
  }
  x0 = accelero.getXRaw();
  y0 = accelero.getYRaw();
  z0 = accelero.getZRaw();
  x20 = accelero2.getXRaw();
  y20 = accelero2.getYRaw();
  z20 = accelero2.getZRaw();
}
 
void loop(){
  x = accelero.getXRaw();
  y = accelero.getYRaw();
  z = accelero.getZRaw();
  x2 = accelero2.getXRaw();
  y2 = accelero2.getYRaw();
  z2 = accelero2.getZRaw();
  int a = x - x0;
  int b = x2 - x20;
  
  //perna esquerda devagar
  if(modulo(a) > 10 && modulo(a) < 50 && modulo(b) < 10){
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    delay(1000);
    for(int i = 2; i < 6; i++){
      digitalWrite(i, LOW);
    }
  }

  //perna esquerda rapido
  if(modulo(a) >= 50 && modulo(b) < 10){
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    delay(500);
    for(int i = 2; i < 6; i++){
      digitalWrite(i, LOW);
    }
  }

  //perda direita devagar
  if(modulo(b) > 10 && modulo(b) < 50 && modulo(a) < 10){
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(1000);
    for(int i = 6; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }

  //perna direita rapido
  if(modulo(b) >= 50 && modulo(a) < 10){
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(500);
    for(int i = 6; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }
  
  //duas pernas devagar
  if(modulo(a) > 10 && modulo(a) < 50 && modulo(b) > 10 && modulo(b) < 50){
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(1000);
    for(int i = 2; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }

  //duas pernas rapidas
  if(modulo(a) >= 50 && modulo(b) >= 50){
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(500);
    for(int i = 2; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }

  //perna esquerda devagar e direita rapida
  if(modulo(a) > 10 && modulo(a) < 50 && modulo(b) >= 50){
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(500);
    for(int i = 6; i < 10; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(500);
    for(int i = 2; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }

  //perna esquerda rapida e direita devagar
  if(modulo(a) >= 50 && modulo(b) > 10 && modulo(b) < 50){
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    delay(500);
    for(int i = 2; i < 6; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    delay(500);
    for(int i = 2; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }

  for(int i = 2; i < 10; i++){
    digitalWrite(i, LOW);
  }
}

float modulo(int valor){
    if(valor < 0){
      return valor * -1;  
    }else{
      return valor;  
    }
}
