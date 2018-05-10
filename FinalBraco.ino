String oi;
String last;

void setup() {
  Serial.begin(9600);
  for(int x = 2; x < 14; x++){
    pinMode(x, OUTPUT);  
  }
}
//2 a 7 esquerdo
//8 a 13 direito
void loop() {
  if(Serial.available()){
    oi = Serial.read();  
    if(oi == "a"){ //esquerdo de cima pra baixo
      for(int x = 2; x < 8; x++){
        digitalWrite(x, HIGH);
        delay(1500);
      }
      last = "";
    }
    if(oi == "b"){//direito de cima pra baixo
      for(int x = 8; x < 14; x++){
        digitalWrite(x, HIGH);
        delay(1500);
      }
      last = "";
    }
    if(oi == "c"){//esquerdo de baixo pra cima
      for(int x = 7; x > 1; x--){
        digitalWrite(x, HIGH);
        delay(1500);
      }
      last = "";
    }
    if(oi == "d"){//direito de baixo pra cima
      for(int x = 13; x > 7; x--){
        digitalWrite(x, HIGH);
        delay(1500);
      }
      last = "";
    }
    if(oi == "e"){//esquerdo piscando
      last = "e";
    }
    if(oi == "f"){//direito piscando
      last = "f";
    }
    if(oi == "g"){//pisca tudo devagar
      last = "g";
    }
    if(oi == "h"){//apaga direito
      last = "h";
    }
    if(oi == "i"){//apaga esquerdo
      last = "i";
    }
    if(oi == "j"){//apaga tudo
      for(int x = 2; x < 14; x++){
        digitalWrite(x, LOW);
      }
      last = "";
    }
    if(oi == "k"){//pisca tudo rapido
      last = "k";
    }
    if(oi == "l"){//esquerdo liga
      for(int x = 2; x < 8; x++){
        digitalWrite(x, HIGH);
        delay(1500);
      }
      last = "";
    }
    if(oi == "m"){//direito liga
      for(int x = 8; x < 14; x++){
        digitalWrite(x, HIGH);
      }
      last = "";
    }
    if(oi == "n"){//liga tudo
      for(int x = 2; x < 14; x++){
        digitalWrite(x, HIGH);
      }
      last = "";
    }
  }

  if(last == "e"){
    for(int x = 2; x < 8; x++){
        digitalWrite(x, HIGH);
      }
      delay(1500);
      for(int x = 2; x < 8; x++){
        digitalWrite(x, LOW);
      }
      delay(1500);
  } else if(last == "f"){
     for(int x = 8; x < 14; x++){
        digitalWrite(x, HIGH);
      }
      delay(1500);
      for(int x = 8; x < 14; x++){
        digitalWrite(x, LOW);
      }
      delay(1500);
  }else if(last == "g"){
    for(int x = 2; x < 14; x++){
        digitalWrite(x, HIGH);
      }
      delay(3000);
      for(int x = 2; x < 14; x++){
        digitalWrite(x, LOW);
      }
      delay(3000);
  }else if(last == "h"){
    for(int x = 8; x < 14; x++){
        digitalWrite(x, LOW);
        delay(1500);
      }
  }else if(last == "i"){
    for(int x = 2; x < 8; x++){
        digitalWrite(x, LOW);
        delay(1500);
      }
  }else if(last == "k"){
    for(int x = 2; x < 14; x++){
        digitalWrite(x, HIGH);
      }
      delay(750);
      for(int x = 2; x < 14; x++){
        digitalWrite(x, LOW);
      }
      delay(750);
  }
}
