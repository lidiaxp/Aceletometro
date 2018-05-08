#include <AcceleroMMA7361.h>
#include<Wire.h>

const int MPU=0x68;  
  
AcceleroMMA7361 accelero;

int x;
int y;
int z;

float AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

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
  
  for(int i = 2; i < 10; i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  Wire.beginTransmission(MPU);
  Wire.write(0x3B); 
  Wire.endTransmission(false);

  Wire.requestFrom(MPU,14,true);  
  
  AcX=Wire.read()<<8|Wire.read();       
  AcY=Wire.read()<<8|Wire.read();  
  AcZ=Wire.read()<<8|Wire.read();  
  Tmp=Wire.read()<<8|Wire.read();  
  GyX=Wire.read()<<8|Wire.read();  
  GyY=Wire.read()<<8|Wire.read();  
  GyZ=Wire.read()<<8|Wire.read();  
  
  Serial.print("AcX = "); Serial.print(round(AcX/-4700)); //giroscopio frente tras
  Serial.print(" | AcY = "); Serial.print(round(AcY/6000)); //girocopio esquerda direita
}

float modulo(int valor){
    if(valor < 0){
      return valor * -1;  
    }else{
      return valor;  
    }
}
