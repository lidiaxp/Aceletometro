#include <Wire.h>
const int MPU2 = 0x69, MPU1=0x68;
const int be1 = 3;
const int be2 = 4;
const int be3 = 5;
const int be4 = 6;
const int be5 = 7;
const int bd1 = 8;
const int bd2 = 9;
const int bd3 = 10;
const int bd4 = 11;
const int bd5 = 12;


long accelX, accelY, accelZ;
float gForceX, gForceY, gForceZ, gyroX, gyroY, gyroZ,rotX, rotY, rotZ;
long accelX2, accelY2, accelZ2;
float gForceX2, gForceY2, gForceZ2, gyroX2, gyroY2, gyroZ2,rotX2, rotY2, rotZ2;

void setup(){
  Wire.begin();
  Wire.beginTransmission(MPU1);
  Wire.write(0x6B);
  Wire.write(0b00000000);
  Wire.endTransmission();  
  Wire.beginTransmission(MPU1);
  Wire.write(0x1B);
  Wire.write(0x00000000);
  Wire.endTransmission(); 
  Wire.beginTransmission(MPU1);
  Wire.write(0x1C);
  Wire.write(0b00000000);
  Wire.endTransmission(); 
  
  Wire.begin();
  Wire.beginTransmission(MPU2);
  Wire.write(0x6B);
  Wire.write(0b00000000); 
  Wire.endTransmission();  
  Wire.beginTransmission(MPU2); 
  Wire.write(0x1B);
  Wire.write(0x00000000);
  Wire.endTransmission(); 
  Wire.beginTransmission(MPU2);
  Wire.write(0x1C);
  Wire.write(0b00000000);
  Wire.endTransmission(); 
  Serial.begin(38400);

  for(int x = 2; x < 13; x++){
    pinMode(x, OUTPUT);
  }
}

void loop(){
  GetMpuValue(MPU1, 1);
  Serial.print("\t ||| \t");

  GetMpuValue(MPU2, 2);
  Serial.println("");
  //perna 1 devagar
  if(accelX > 20 && accelX < 120 && accelX2 < 20){
    for(int x = 3; x < 8; x++){
      digitalWrite(x, HIGH);
      digitalWrite(random(3, 7), HIGH);
      delay(1000);
      for(int y = 3; x < 8; x++){
        digitalWrite(x, LOW);
      }
    }
  }
  
  //perna 1 rapido
  if(accelX > 120 && accelX2 < 20){
    for(int x = 3; x < 8; x++){
      digitalWrite(x, HIGH);
      digitalWrite(random(3, 7), HIGH);
      delay(500);
      for(int y = 3; y < 8; y++){
        digitalWrite(y, LOW);
      }
    }
  }
  //perna 2 devagar
  if(accelX2 > 20 && accelX2 < 120 && accelX < 20){
    for(int x = 8; x < 13; x++){
      digitalWrite(x, HIGH);
      digitalWrite(random(8, 12), HIGH);
      delay(1000);
      for(int y = 3; x < 8; x++){
        digitalWrite(x, LOW);
      }
    }
  }
  //perna 2 rapido
  if(accelX2 > 120 && accelX < 20){
    for(int x = 8; x < 13; x++){
      digitalWrite(x, HIGH);
      digitalWrite(random(8, 12), HIGH);
      delay(500);
      for(int y = 3; x < 8; x++){
        digitalWrite(x, LOW);
      }
    }
  }
  //duas pernas devagar
  if(accelX > 20 && accelX < 120 && accelX2 > 20 && accelX2 < 120){
    for(int x = 3; x < 8; x++){
      digitalWrite(x, HIGH);
      digitalWrite(x + 5, HIGH);
      digitalWrite(random(3, 7), HIGH);
      digitalWrite(random(8, 13), HIGH);
      delay(1000);
      for(int y = 3; x < 13; x++){
        digitalWrite(x, LOW);
      }
    }
  }
  
  //duas pernas rapidos
  if(accelX > 120 && accelX2 > 120){
    for(int x = 3; x < 8; x++){
      digitalWrite(x, HIGH);
      digitalWrite(x + 5, HIGH);
      digitalWrite(random(3, 7), HIGH);
      digitalWrite(random(8, 13), HIGH);
      delay(500);
      for(int y = 3; x < 13; x++){
        digitalWrite(x, LOW);
      }
    }
  }
}

void GetMpuValue(const int MPU, int valor){
  if(valor == 1){
    Wire.beginTransmission(MPU); 
    Wire.write(0x3B);
    Wire.endTransmission();
    Wire.requestFrom(MPU,6);
    while(Wire.available() < 6);
    accelX = Wire.read()<<8|Wire.read(); 
    accelY = Wire.read()<<8|Wire.read(); 
    accelZ = Wire.read()<<8|Wire.read();
  
    Wire.beginTransmission(MPU);
    Wire.write(0x43);
    Wire.endTransmission();
    Wire.requestFrom(MPU,6);
    while(Wire.available() < 6);
    gyroX = Wire.read()<<8|Wire.read();
    gyroY = Wire.read()<<8|Wire.read();
    gyroZ = Wire.read()<<8|Wire.read(); 

    gForceX = accelX / 16384.0;
    gForceY = accelY / 16384.0; 
    gForceZ = accelZ / 16384.0;
    rotX = gyroX / 131.0;
    rotY = gyroY / 131.0; 
    rotZ = gyroZ / 131.0;
    Serial.print("gyro\t");
    Serial.print(rotX);
    Serial.print("\t");
    Serial.print(rotY);
    Serial.print("\t");
    Serial.print(rotZ);
    Serial.print("\tAcc\t");
    Serial.print(gForceX);
    Serial.print("\t");
    Serial.print(gForceY);
    Serial.print("\t");
    Serial.print(gForceZ);
    delay(100);
  }else{
    Wire.beginTransmission(MPU); 
    Wire.write(0x3B);
    Wire.endTransmission();
    Wire.requestFrom(MPU,6);
    while(Wire.available() < 6);
    accelX2 = Wire.read()<<8|Wire.read(); 
    accelY2 = Wire.read()<<8|Wire.read(); 
    accelZ2 = Wire.read()<<8|Wire.read();
  
    Wire.beginTransmission(MPU);
    Wire.write(0x43);
    Wire.endTransmission();
    Wire.requestFrom(MPU,6);
    while(Wire.available() < 6);
    gyroX2 = Wire.read()<<8|Wire.read();
    gyroY2 = Wire.read()<<8|Wire.read();
    gyroZ2 = Wire.read()<<8|Wire.read(); 

    gForceX2 = accelX2 / 16384.0;
    gForceY2 = accelY2 / 16384.0; 
    gForceZ2 = accelZ2 / 16384.0;
    rotX2 = gyroX2 / 131.0;
    rotY2 = gyroY2 / 131.0; 
    rotZ2 = gyroZ2 / 131.0;
    Serial.print("gyro2\t");
    Serial.print(rotX2);
    Serial.print("\t");
    Serial.print(rotY2);
    Serial.print("\t");
    Serial.print(rotZ2);
    Serial.print("\tAcc2\t");
    Serial.print(gForceX2);
    Serial.print("\t");
    Serial.print(gForceY2);
    Serial.print("\t");
    Serial.print(gForceZ2);
    delay(100);
  }
  
}
