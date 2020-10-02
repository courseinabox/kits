#include <FirebaseCloudMessaging.h>
#include <FirebaseArduino.h>
#include <Firebase.h>
#include <FirebaseHttpClient.h>
#include <FirebaseObject.h>
#include <FirebaseError.h>
#include <DHT.h>

#include "myconstants.h"


#define PUMPPIN D0
#define DHTPIN D6

DHT dhtSensor(DHTPIN, DHT11);

void setup(){
  pinMode(PUMPPIN, OUTPUT); 
  digitalWrite(PUMPPIN, HIGH); 
  Serial.begin(9600);
  /*
  const char* WIFI_SSID = "yourssid";
  const char* WIFI_PASSWORD = "ssid_password";
  const char* FIREBASE_HOST = "your firebase project name";
  const char* FIREBASE_AUTH  = "your firebase auth code" ; 
  */
  Firebase.wiconnect(WIFI_SSID, WIFI_PASSWORD);
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
}

void loop() {
  int aVal = analogRead(A0); 
  int mLevel = map(aVal, 0, 1023, 1, 5); 
  Serial.print("Moisture Level = ");
  Serial.println(mLevel); 
  double humidity = dhtSensor.readHumidity() ; 
  Serial.print("Outside Humidity = ") ; 
  Serial.println(humidity); 
  if (mLevel < 3) {
    // If soil is very dry, then irrespective of the 
    //humidity, switch on the pump
    digitalWrite(PUMPPIN, LOW) ; 
  }else if (mLevel == 3  && humidity < 50) {
    digitalWrite(PUMPPIN, LOW) ; 
  }else if (mLevel >=3 && humidity >= 50) {
    digitalWrite(PUMPPIN, HIGH) ;
  }else {
    // When the level is 5 which means that there is 
    // a lot of water. Switch off the pump at this stage. 
    digitalWrite(PUMPPIN, HIGH) ; 
  }
  Firebase.setInt("Moisture Level", mLevel) ; 
  Firebase.setFloat("Humidity", humidity) ; 
  delay(1000);
}
