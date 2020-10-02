#define BUZZERPIN D3

void setup(){
    pinMode(BUZZERPIN, OUTPUT); 
    digitalWrite(BUZZERPIN, LOW); 
    Serial.begin(9600); 
}

void loop() {
    int aVal = analogRead(A0); 
    int mLevel = map(aVal, 0, 1023, 1, 5); 
    Serial.print("Moisture Level = ");
    Serial.println(mLevel); 
    if (mLevel < 3){
        digitalWrite(BUZZERPIN, HIGH); 
    }else {
        digitalWrite(BUZZERPIN, LOW); 
    }
    delay(1000); 

}
