char oi;
char last;

void setup() {
  Serial.begin(9600);
  for(int x = 3; x < 11; x++){
    pinMode(x, OUTPUT);  
  }
  //3 4 5 vagina  3 fica perto da barriga
  //6 7 8 9 10 barriga  6 fica perto do pescoco
}

void loop() {
  if(Serial.available()){
    oi = Serial.read();  
    if(oi == "o"){
      for(int x = 8; x < 11; x++){
        digitalWrite(x, HIGH);
        delay(1500);
      }
      last = "";
    }

    if(oi == "p"){
      last = "p";
    }

    if(oi == "q"){
      for(int x = 8; x < 11; x++){
        digitalWrite(x, HIGH);
      }
      last = "";
    }

    if(oi == "r"){
      for(int x = 8; x < 11; x++){
        digitalWrite(x, LOW);
      }
      last = "";
    }

    if(oi == "s"){
      for(int x = 3; x < 6; x++){
        digitalWrite(x, HIGH);
        delay(1500);
      }
      last = "";
    }

    if(oi == "t"){
      last = "t";
    }

    if(oi == "u"){
      for(int x = 3; x < 6; x++){
        digitalWrite(x, HIGH);
      }
      last = "";
    }

    if(oi == "v"){
      for(int x = 3; x < 6; x++){
        digitalWrite(x, LOW);
      }
      last = "";
    }

    if(oi == "n"){
      for(int x = 3; x < 11; x++){
        digitalWrite(x, HIGH);
      }
      last = "";
    }

    if(oi == "k"){
      last = "k";
    }

    if(oi == "g"){
      last = "g";
    }

    if(oi == "j"){
      for(int x = 3; x < 11; x++){
        digitalWrite(x, LOW);  
      }
      last = "";
    }
  }

  if(last == "k"){
    for(int x = 3; x < 11; x++){
        digitalWrite(x, HIGH);
        delay(750);  
      }
      for(int x = 3; x < 11; x++){
        digitalWrite(x, LOW);
        delay(750);  
      }
  }else if(last == "g"){
    for(int x = 3; x < 11; x++){
        digitalWrite(x, HIGH);
        delay(3000);  
      }
      for(int x = 3; x < 11; x++){
        digitalWrite(x, LOW);
        delay(3000);  
      }
  }else if(last == "t"){
    for(int x = 3; x < 6; x++){
       digitalWrite(x, HIGH);
     }
     delay(1500);
     for(int x = 3; x < 6; x++){
       digitalWrite(x, LOW);
     }
     delay(1500);
  }else if(last == "p"){
    for(int x = 8; x < 11; x++){
       digitalWrite(x, HIGH);
     }
     delay(1500);
     for(int x = 8; x < 11; x++){
       digitalWrite(x, LOW);
     }
     delay(1500);
  }
}
