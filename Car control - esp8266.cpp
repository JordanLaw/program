#include <Arduino.h>
#include <SoftwareSerial.h>

int BRIN1 = 16; 
int BRIN2 = 5;
int BLIN3 = 4; 
int BLIN4 = 0; 
int FRIN1 = 14;
int FRIN2 = 12; 
int FLIN3 = 13; 
int FLIN4 = 15; 

const byte rxpin = 3;
const byte txpin = 1;
SoftwareSerial BT(rxpin, txpin);
char Data;

void setup() {
  // put your setup code here, to run once:
  pinMode(BRIN1,OUTPUT);
  pinMode(BRIN2,OUTPUT);
  pinMode(BLIN3,OUTPUT);
  pinMode(BLIN4,OUTPUT);
  pinMode(FRIN1,OUTPUT);
  pinMode(FRIN2,OUTPUT);
  pinMode(FLIN3,OUTPUT);
  pinMode(FLIN4,OUTPUT);

  pinMode(rxpin, INPUT);
  pinMode(txpin, OUTPUT);
  BT.begin(115200);

}

void M_Forward(){
  digitalWrite(FRIN1, HIGH);
  digitalWrite(FRIN2, LOW);
  digitalWrite(FLIN3, HIGH);
  digitalWrite(FLIN4, LOW);
  digitalWrite(BRIN1, HIGH);
  digitalWrite(BRIN2, LOW);
  digitalWrite(BLIN3, HIGH);
  digitalWrite(BLIN4, LOW);

}

void M_Backward(){
  digitalWrite(FRIN1, LOW);
  digitalWrite(FRIN2, HIGH);
  digitalWrite(FLIN3, LOW);
  digitalWrite(FLIN4, HIGH);
  digitalWrite(BRIN1, LOW);
  digitalWrite(BRIN2, HIGH);
  digitalWrite(BLIN3, LOW);
  digitalWrite(BLIN4, HIGH);

}

void M_Left(){
  digitalWrite(FRIN1, HIGH);
  digitalWrite(FRIN2, LOW);
  digitalWrite(FLIN3, LOW);
  digitalWrite(FLIN4, HIGH);
  digitalWrite(BRIN1, LOW);
  digitalWrite(BRIN2, HIGH);
  digitalWrite(BLIN3, HIGH);
  digitalWrite(BLIN4, LOW);
}

void M_Right(){
  digitalWrite(FRIN1, LOW);
  digitalWrite(FRIN2, HIGH);
  digitalWrite(FLIN3, HIGH);
  digitalWrite(FLIN4, LOW);
  digitalWrite(BRIN1, HIGH);
  digitalWrite(BRIN2, LOW);
  digitalWrite(BLIN3, LOW);
  digitalWrite(BLIN4, HIGH);
}

void M_F_Left(){
  digitalWrite(FRIN1, HIGH);
  digitalWrite(FRIN2, LOW);
  digitalWrite(FLIN3, LOW);
  digitalWrite(FLIN4, LOW);
  digitalWrite(BRIN1, LOW);
  digitalWrite(BRIN2, LOW);
  digitalWrite(BLIN3, HIGH);
  digitalWrite(BLIN4, LOW);
}

void M_F_Right(){
  digitalWrite(FRIN1, LOW);
  digitalWrite(FRIN2, LOW);
  digitalWrite(FLIN3, HIGH);
  digitalWrite(FLIN4, LOW);
  digitalWrite(BRIN1, HIGH);
  digitalWrite(BRIN2, LOW);
  digitalWrite(BLIN3, LOW);
  digitalWrite(BLIN4, LOW);
}

void M_B_Right(){
  digitalWrite(FRIN1, LOW);
  digitalWrite(FRIN2, LOW);
  digitalWrite(FLIN3, LOW);
  digitalWrite(FLIN4, HIGH);
  digitalWrite(BRIN1, LOW);
  digitalWrite(BRIN2, HIGH);
  digitalWrite(BLIN3, LOW);
  digitalWrite(BLIN4, LOW);
}

void M_B_Left(){
  digitalWrite(FRIN1, LOW);
  digitalWrite(FRIN2, HIGH);
  digitalWrite(FLIN3, LOW);
  digitalWrite(FLIN4, LOW);
  digitalWrite(BRIN1, LOW);
  digitalWrite(BRIN2, LOW);
  digitalWrite(BLIN3, LOW);
  digitalWrite(BLIN4, HIGH);
}

void T_Right(){
  digitalWrite(FRIN1, LOW);
  digitalWrite(FRIN2, HIGH);
  digitalWrite(FLIN3, HIGH);
  digitalWrite(FLIN4, LOW);
  digitalWrite(BRIN1, LOW);
  digitalWrite(BRIN2, HIGH);
  digitalWrite(BLIN3, HIGH);
  digitalWrite(BLIN4, LOW);
}

void T_Left(){
  digitalWrite(FRIN1, HIGH);
  digitalWrite(FRIN2, LOW);
  digitalWrite(FLIN3, LOW);
  digitalWrite(FLIN4, HIGH);
  digitalWrite(BRIN1, HIGH);
  digitalWrite(BRIN2, LOW);
  digitalWrite(BLIN3, LOW);
  digitalWrite(BLIN4, HIGH);
}

void M_Stop(){
  digitalWrite(FRIN1, LOW);
  digitalWrite(FRIN2, LOW);
  digitalWrite(FLIN3, LOW);
  digitalWrite(FLIN4, LOW);
  digitalWrite(BRIN1, LOW);
  digitalWrite(BRIN2, LOW);
  digitalWrite(BLIN3, LOW);
  digitalWrite(BLIN4, LOW);
}

void loop() {
  while (BT.available()){
    Data = BT.read();

    switch (Data)
    {
    case 'w':
      M_Forward();
      break;

    case 'x':
      M_Backward();
      break;     
    
    case 'd':
      M_Right();
      break;

    case 'a':
      M_Left();
      break;

    case 'e':
      M_F_Right();
      break;

    case 'q':
      M_F_Left();
      break;

    case 'z':
      M_B_Right();
      break;

    case 'c':
      M_B_Left();
      break;

    case 'n':
      T_Left();
      break;

    case 'm':
      T_Right();
      break;

    case 's':
      M_Stop();
      break;  

    default:
      break;
    }
  }
}