
#include <LiquidCrystal.h>

const int rs = 8, en = 9, d4 = 10, d5 = 11, d6 = 12, d7 = 13;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#define Re 7

//#define Resetpin 6

#define LDR A0

void setup() {
  // put your setup code here, to run once:
 // digitalWrite(Resetpin,HIGH);
Serial.begin(9600);
pinMode(Re,OUTPUT);
pinMode(LDR,INPUT);
//pinMode(Resetpin,OUTPUT);
  
  lcd.begin(16, 2);
  
  lcd.print("Elasped time:");
  lcd.setCursor(5,1);
  lcd.print("Secs");
  Serial.print("Secs");
}
void(* resetFunc) (void) = 0; //declare reset function @ address 0

void loop() {

 int ldr = analogRead(LDR);
   Serial.println(ldr); 

    if (ldr < 50){
      
  lcd.setCursor(0, 1);
  lcd.print(millis() / 1000);
Serial.println(millis() / 1000);

if ((millis()/1000) == 0){   
    lcd.setCursor(13,0);
  lcd.print("OFF");
  digitalWrite (Re,LOW);
}

if ((millis()/1000) == 10){
  lcd.setCursor(13,0);
  lcd.print("-ON");
  digitalWrite (Re,HIGH);
  }

if ((millis()/1000) == 40){
  
   // lcd.setCursor(13,0);
 // lcd.print("OFF");
  //digitalWrite (Relaypin,LOW);
//  digitalWrite (Resetpin,LOW);
   Serial.println("resetting");
  resetFunc();  //call reset
 
  delay(100);
  }
    }
           if (ldr >50){
            digitalWrite(Re,LOW);
            delay(1000);
  resetFunc();  //call reset
 
  delay(5000);
}
}
