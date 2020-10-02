#define BUZZER_PIN D3
#define  PIR_PIN D4 

void setup() {
  // put your setup code here, to run once:
  pinMode(PIR_PIN, INPUT) ; 
  pinMode(BUZZER_PIN, OUTPUT) ; 
  digitalWrite(BUZZER_PIN, LOW) ;  
}

void loop() {
  int pbState = digitalRead(PIR_PIN) ; 
  if (pbState == 1) {
    digitalWrite(BUZZER_PIN, HIGH) ; 
  } else {
    digitalWrite(BUZZER_PIN, LOW) ;  
  }
}
