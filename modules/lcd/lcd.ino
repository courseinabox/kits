#include <qlcddisplay.h>

#ifdef __AVR__
    #define BUZZERPIN 4
    #define SDAPIN A4
    #define SCLPIN A5 
#els  e
    #define BUZZERPIN D3
    int SDAPIN = D2;
    int SCLPIN = D1;
#endif

#define PBPIN 3

int ctr =0; 
QLcdDisplay qdisp;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  qdisp.init(SDAPIN, SCLPIN);
  pinMode(BUZZERPIN, OUTPUT) ; 
  pinMode(PBPIN, INPUT_PULLUP) ; 
  digitalWrite(BUZZERPIN, LOW) ; 
  qdisp.backlight_off(); 
  qdisp.displayText("Press the", "Push Button") ;
  Serial.print("I2C addr = 0x");
  Serial.println(qdisp.getAddress(), HEX); 
}

void loop() {
    // put your main code here, to run repeatedly:
    int pbstate = digitalRead(PBPIN) ; 
    if (pbstate == LOW) {
      ctr = ctr + 1; 
      qdisp.displayText("Count:", String(ctr)) ;
      Serial.println("Setting display to " + String(ctr)); 
      if (ctr %2 == 0) {
        qdisp.backlight_off(); 
      }else {
        qdisp.backlight_on(); 

      }
      
      delay(1000); 
    }
    
}
