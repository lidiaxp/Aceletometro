#include <Wire.h>
const int MPU2 = 0x69, MPU1=0x68;
const int be1 = 3;
const int be2 = 4;
const int be3 = 5;
const int bd1 = 6;
const int bd2 = 7;
const int bd3 = 8;
const int ce1 = 9;
const int ce2 = 10;
const int ce3 = 11;

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

  for(int x = 3; x < 12; x++){
    pinMode(x, OUTPUT);
  }
}

void loop(){
  GetMpuValue(MPU1, 1);
  Serial.print("\t ||| \t");

  GetMpuValue(MPU2, 2);
  Serial.println("");
  //braço 1 devagar
  if(accelX > 20 && accelX < 120 && accelX2 < 20){
    digitalWrite(be1, LOW);
    digitalWrite(be2, LOW);
    digitalWrite(be3, HIGH);
    delay(1000);
    digitalWrite(be1, HIGH);
    digitalWrite(be2, LOW);
    digitalWrite(be3, LOW);
    delay(1000);
    digitalWrite(be1, LOW);
    digitalWrite(be2, HIGH);
    digitalWrite(be3, LOW);
    delay(1000);
    digitalWrite(be1, HIGH);
    digitalWrite(be2, HIGH);
    digitalWrite(be3, HIGH);
    delay(1000);
  }
  //braço 1 rapido
  if(accelX > 120 && accelX2 < 20){
    digitalWrite(be1, HIGH);
    digitalWrite(be2, LOW);
    digitalWrite(be3, HIGH);
    delay(500);
    digitalWrite(be1, HIGH);
    digitalWrite(be2, HIGH);
    digitalWrite(be3, LOW);
    delay(500);
    digitalWrite(be1, LOW);
    digitalWrite(be2, HIGH);
    digitalWrite(be3, HIGH);
    delay(500);
    digitalWrite(be1, HIGH);
    digitalWrite(be2, HIGH);
    digitalWrite(be3, HIGH);
    delay(50);
  }
  //braço 2 devagar
  iF(accelX2 > 20 && accelX2 < 120 && accelX < 20){
    digitalWrite(bd1, LOW);
    digitalWrite(bd2, LOW);
    digitalWrite(bd3, HIGH);
    delay(1000);
    digitalWrite(bd1, HIGH);
    digitalWrite(bd2, LOW);
    digitalWrite(bd3, LOW);
    delay(1000);
    digitalWrite(bd1, LOW);
    digitalWrite(bd2, HIGH);
    digitalWrite(bd3, LOW);
    delay(1000);
    digitalWrite(bd1, HIGH);
    digitalWrite(bd2, HIGH);
    digitalWrite(bd3, HIGH);
    delay(1000);
  }
  //braço 2 rapido
  if(accelX2 > 120 && accelX < 20){
    digitalWrite(bd1, LOW);
    digitalWrite(bd2, LOW);
    digitalWrite(bd3, HIGH);
    delay(500);
    digitalWrite(bd1, HIGH);
    digitalWrite(bd2, LOW);
    digitalWrite(bd3, LOW);
    delay(500);
    digitalWrite(bd1, LOW);
    digitalWrite(bd2, HIGH);
    digitalWrite(bd3, LOW);
    delay(500);
    digitalWrite(bd1, HIGH);
    digitalWrite(bd2, HIGH);
    digitalWrite(bd3, HIGH);
    delay(500);
  }
  //dois braços devagar
  if(accelX > 20 && accelX < 120 && accelX2 > 20 && accelX2 < 120){
    digitalWrite(be1, LOW);
    digitalWrite(be2, LOW);
    digitalWrite(be3, HIGH);
    digitalWrite(bd1, LOW);
    digitalWrite(bd2, LOW);
    digitalWrite(bd3, HIGH);
    digitalWrite(ce1, LOW);
    digitalWrite(ce2, LOW);
    digitalWrite(ce3, HIGH);
    delay(1000);
    digitalWrite(be1, HIGH);
    digitalWrite(be2, LOW);
    digitalWrite(be3, LOW);
    digitalWrite(bd1, HIGH);
    digitalWrite(bd2, LOW);
    digitalWrite(bd3, LOW);
    digitalWrite(ce1, HIGH);
    digitalWrite(ce2, LOW);
    digitalWrite(ce3, LOW);
    delay(1000);
    digitalWrite(be1, LOW);
    digitalWrite(be2, HIGH);
    digitalWrite(be3, LOW);
    digitalWrite(bd1, LOW);
    digitalWrite(bd2, HIGH);
    digitalWrite(bd3, LOW);
    digitalWrite(ce1, LOW);
    digitalWrite(ce2, HIGH);
    digitalWrite(ce3, LOW);
    delay(1000);
    digitalWrite(be1, HIGH);
    digitalWrite(be2, HIGH);
    digitalWrite(be3, HIGH);
    digitalWrite(bd1, HIGH);
    digitalWrite(bd2, HIGH);
    digitalWrite(bd3, HIGH);
    digitalWrite(ce1, HIGH);
    digitalWrite(ce2, HIGH);
    digitalWrite(ce3, HIGH);
    delay(1000);
  }
  //dois braços rapidos
  if(accelX > 120 && accelX2 > 120){
    digitalWrite(be1, HIGH);
    digitalWrite(be2, LOW);
    digitalWrite(be3, HIGH);
    digitalWrite(bd1, HIGH);
    digitalWrite(bd2, LOW);
    digitalWrite(bd3, HIGH);
    digitalWrite(ce1, HIGH);
    digitalWrite(ce2, LOW);
    digitalWrite(ce3, HIGH);
    delay(500);
    digitalWrite(be1, HIGH);
    digitalWrite(be2, HIGH);
    digitalWrite(be3, LOW);
    digitalWrite(bd1, HIGH);
    digitalWrite(bd2, HIGH);
    digitalWrite(bd3, LOW);
    digitalWrite(ce1, HIGH);
    digitalWrite(ce2, HIGH);
    digitalWrite(ce3, LOW);
    delay(500);
    digitalWrite(be1, LOW);
    digitalWrite(be2, HIGH);
    digitalWrite(be3, HIGH);
    digitalWrite(bd1, LOW);
    digitalWrite(bd2, HIGH);
    digitalWrite(bd3, HIGH);
    digitalWrite(ce1, LOW);
    digitalWrite(ce2, HIGH);
    digitalWrite(ce3, HIGH);
    delay(500);
    digitalWrite(be1, HIGH);
    digitalWrite(be2, HIGH);
    digitalWrite(be3, HIGH);
    digitalWrite(bd1, HIGH);
    digitalWrite(bd2, HIGH);
    digitalWrite(bd3, HIGH);
    digitalWrite(ce1, HIGH);
    digitalWrite(ce2, HIGH);
    digitalWrite(ce3, HIGH);
    delay(500);
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
