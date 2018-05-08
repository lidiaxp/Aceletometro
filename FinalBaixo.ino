#include <Wire.h> 
#define address 0x1E 
#include <AcceleroMMA7361.h>
  
AcceleroMMA7361 accelero;

int anterior = 0;
int anterior1 = 0;
int x1;
int y1;
int z1;
int x;
int y;
int z;

int res;
int res1;

int menor = 10;
int maior = 50;

void setup(){
  Serial.begin(9600);
  Wire.begin();
  
  Wire.beginTransmission(address); 
  Wire.write(0x02); 
  Wire.write(0x00); 
  Wire.endTransmission();

  accelero.begin(13, 12, 11, 10, A0, A1, A2);
  accelero.setARefVoltage(3.3);  
  accelero.setSensitivity(LOW);  
  accelero.calibrate();

  for(int i = 2; i < 10; i++){
    pinMode(i, OUTPUT);
  }
}

void loop(){
  Wire.beginTransmission(address);
  Wire.write(0x03); 
  Wire.endTransmission();
 
  Wire.requestFrom(address, 6);
  if(6<=Wire.available()){
    x = Wire.read()<<8; 
    x |= Wire.read(); 
    z = Wire.read()<<8; 
    z |= Wire.read(); 
    y = Wire.read()<<8; 
    y |= Wire.read(); 
  }
  
  Serial.print("x: ");
  Serial.print(x);
  Serial.print("  y: ");
  Serial.print(y);
  Serial.print("  z: ");
  Serial.println(z);

  x1 = accelero.getXRaw();
  y1 = accelero.getYRaw();
  z1 = accelero.getZRaw();
  
  res = x + y + z;
  res1 = x1 + y1 + z1;

  if(modulo(anterior - res) < menor*2 || modulo(anterior1 - res1) < menor*2){
    if(modulo(anterior - res) < menor*2){
      for(int i = 2; i < 6; i++){
        digitalWrite(i, LOW);
      }
    }

    if(modulo(anterior1 - res1) < menor*2){
      for(int i = 6; i < 10; i++){
        digitalWrite(i, LOW);
      }
    }
  }else{
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(750);
    for(int i = 2; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }

  for(int x = 0; x < 5; x++){
    repetir();  
  }

  anterior = x + y + z;
  anterior1 = x1 + y1 + z1;
}


float modulo(int valor){
  if(valor < 1){
    valor *= -1;
    return valor;
  }else{
    return valor;
  }
}

void checagem(){
  //esquerda devagar
  if(modulo(res-(x+y+z)) >= menor && modulo(res-(x+y+z)) <= maior && modulo(res1-(x1+y1+z1)) <= menor){
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    delay(1000);
    for(int i = 2; i < 6; i++){
      digitalWrite(i, LOW);
    }
  }else 

  //esquerda rapido
  if(modulo(res-(x+y+z)) >= maior && modulo(res1-(x1+y1+z1)) <= menor){
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    delay(500);
    for(int i = 2; i < 6; i++){
      digitalWrite(i, LOW);
    }
  }else

  //direito devagar
  if(modulo(res1-(x1+y1+z1)) >= menor && modulo(res1-(x1+y1+z1)) <= maior && modulo(res-(x+y+z)) <= menor){
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(1000);
    for(int i = 6; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //direito rapido
  if(modulo(res1-(x1+y1+z1)) >= maior && modulo(res-(x+y+z)) <= menor){
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(500);
    for(int i = 6; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //duas pernas devagar
  if(modulo(res-(x+y+z)) >= menor && modulo(res-(x+y+z)) <= maior && modulo(res1-(x1+y1+z1)) >= menor && modulo(res1-(x1+y1+z1)) <= maior){
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(1000);
    for(int i = 2; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //duas pernas rapido
  if(modulo(res-(x+y+z)) >= maior && modulo(res1-(x1+y1+z1)) >= maior){
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(2, 5), HIGH);
    digitalWrite(random(6, 9), HIGH);
    digitalWrite(random(6, 9), HIGH);
    delay(500);
    for(int i = 2; i < 10; i++){
      digitalWrite(i, LOW);
    }
  }else

  //esquerda devagar e direita rapida
  if(modulo(res-(x+y+z)) >= menor && modulo(res-(x+y+z)) <= maior && modulo(res1-(x1+y1+z1)) >= maior){
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
  }else

  //esquerda rapido e direita devagar
  if(modulo(res-(x+y+z)) >= maior && modulo(res1-(x1+y1+z1)) >= menor && modulo(res1-(x1+y1+z1)) <= maior){
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
  }else{
    for(int i = 2; i < 10; i++){
      pinMode(i, OUTPUT);
    }
  }
}

void repetir(){
  checagem();
  delay(1000);
}
