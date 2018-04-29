#include<Wire.h>

const int MPU=0x68;  

float AcX,AcY,AcZ,Tmp,GyX,GyY,GyZ;

void setup(){
  Serial.begin(9600);
  
  Wire.begin();
  Wire.beginTransmission(MPU);
  Wire.write(0x6B); 
  
  Wire.write(0); 
  Wire.endTransmission(true);
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
  Serial.print(" | AcZ = "); Serial.print(round(AcZ/12000));
  Serial.print(" | Tmp = "); Serial.print(Tmp/340.00+36.53);
  Serial.print(" | GyX = "); Serial.print(round(GyX/-280));
  Serial.print(" | GyY = "); Serial.print(round(GyY/-100));
  Serial.print(" | GyZ = "); Serial.println(round(GyZ/100));
  
  delay(1000);
}
