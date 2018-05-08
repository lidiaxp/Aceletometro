#include <AcceleroMMA7361.h>
#include<Wire.h>

const int MPU=0x68;  
  
AcceleroMMA7361 accelero;

int x;
int y;
int z;

int menor = 10;
int maior = 50;

int p = 500;
int g = 1000;

int res, res1;
int anterior, anterior1;

float x1,y1,z1,Tmp,GyX,GyY,GyZ;

void setup(){
  Serial.begin(9600);
  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3);  //sets the AREF voltage to 3.3V
  accelero.setSensitivity(LOW);  //sets the sensitivity to 6G
  accelero.calibrate();

  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  
  Wire.write(0); 
  Wire.endTransmission(true);
  
  for(int i = 1; i < 10; i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); 
  Wire.endTransmission(false);

  Wire.requestFrom(MPU,14,true);  
  
  x1=Wire.read()<<8|Wire.read();       
  y1=Wire.read()<<8|Wire.read();  
  z1=Wire.read()<<8|Wire.read();  
  Tmp=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  

  res = x + y + z;
  res1 = (x1/-300) + (y1/400) + z1;

   if(modulo(anterior - res) < menor*2 || modulo(anterior1 - res1) < menor*2){
    if(modulo(anterior - res) < menor*2){
      for(int i = 1; i < 4; i++){
        digitalWrite(i, LOW);
      }
      for(int i = 7; i < 10; i++){
        digitalWrite(i, LOW);
      }
    }

    if(modulo(anterior1 - res1) < menor*2){
      for(int i = 4; i < 10; i++){
        digitalWrite(i, LOW);
      }
    }

    if(modulo(anterior1 - res1) < menor*2 && modulo(anterior - res) < menor*2){
      for(int i = 1; i < 10; i++){
        digitalWrite(i, LOW);
      }
    }
  }else{
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(7, 9), HIGH);
    digitalWrite(random(7, 9), HIGH);
    delay(p + p/2);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }

  for(int x = 0; x < 2; x++){
    repetir();  
  }

  anterior = x + y + z;
  anterior1 = x1 + y1 + z1;
}

float modulo(int valor){
    if(valor < 0){
      return valor * -1;  
    }else{
      return valor;  
    }
}

void repetir(){
  checagem();
  delay(g);  
}

void checagem(){
  //braco 1 devagar
  if(modulo(res-(x+y+z)) >= menor && modulo(res-(x+y+z)) <= maior && modulo(res1-(x1+y1+z1)) <= menor){
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(1, 3), HIGH);
    delay(g);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //braco 1 rapido
  if(modulo(res-(x+y+z)) >= maior && modulo(res1-(x1+y1+z1)) <= menor){
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(1, 3), HIGH);
    delay(p);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //braco 2 devagar
  if(modulo(res1-(x1+y1+z1)) >= menor && modulo(res1-(x1+y1+z1)) <= maior && modulo(res-(x+y+z)) <= menor){
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(4, 6), HIGH);
    delay(g);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //braco 2 rapido
  if(modulo(res1-(x1+y1+z1)) >= maior && modulo(res-(x+y+z)) <= menor){
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(4, 6), HIGH);
    delay(p);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //dois braços devagar
  if(modulo(res-(x+y+z)) >= menor && modulo(res-(x+y+z)) <= maior && modulo(res1-(x1+y1+z1)) >= menor && modulo(res1-(x1+y1+z1)) <= maior){
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(7, 9), HIGH);
    digitalWrite(random(7, 9), HIGH);
    delay(g);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //dois braços rapidos
  if(modulo(res-(x+y+z)) >= maior && modulo(res1-(x1+y1+z1)) >= maior){
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(7, 9), HIGH);
    digitalWrite(random(7, 9), HIGH);
    delay(p);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //braco 1 devagar e 2 rapido
  if(modulo(res-(x+y+z)) >= menor && modulo(res-(x+y+z)) <= maior && modulo(res1-(x1+y1+z1)) >= maior){
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(7, 9), HIGH);
    digitalWrite(random(7, 9), HIGH);
    delay(p);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(random(7, 9), HIGH);
    digitalWrite(random(7, 9), HIGH);
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(1, 3), HIGH);
    delay(p);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //braco 1 rapido e 2 devagar
  if(modulo(res-(x+y+z)) >= maior && modulo(res1-(x1+y1+z1)) >= menor && modulo(res1-(x1+y1+z1)) <= maior){
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(1, 3), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(7, 9), HIGH);
    digitalWrite(random(7, 9), HIGH);
    delay(p);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
    digitalWrite(random(7, 9), HIGH);
    digitalWrite(random(7, 9), HIGH);
    digitalWrite(random(4, 6), HIGH);
    digitalWrite(random(4, 6), HIGH);
    delay(p);
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else{
    for(int i = 1; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }
}
