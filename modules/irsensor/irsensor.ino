#define IRPIN D7
#define BUZZERPIN D3

void setup(){
    Serial.begin(9600);
    pinMode(IRPIN, INPUT);
    pinMode(BUZZERPIN, OUTPUT) ;
    digitalWrite(BUZZERPIN, LOW) ;
    pinMode(D4, OUTPUT) ; 
    digitalWrite(D4, HIGH);
}

void loop() {
    int obstacle = digitalRead(IRPIN);
    if (obstacle == LOW){
        Serial.println("Obstacle detected."); 
        digitalWrite(BUZZERPIN, HIGH) ; 
        digitalWrite(D4,0);
    }
    else {      
        digitalWrite(BUZZERPIN, LOW) ; 
        digitalWrite(D4,1);
    }
    delay(200);
}
