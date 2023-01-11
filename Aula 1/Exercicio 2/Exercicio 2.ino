#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2)

float tempC;

int tempPin = A1;

void setup(){
  lcd.begin(16, 2);
  lcd.print("Temp: ");
  lcd.setCursor(0, 1);
  Serial.begin(9600);
}

void loop(){
  tempC = analogRead(tempPin);
  tempC = (tempC * 5 * 100.0)/1024.0;

  //print result to lcd display
  lcd.setCursor(6, 0);
  lcd.print(tempC, 1);
  Serial.print("Temperautra: ");
  
}