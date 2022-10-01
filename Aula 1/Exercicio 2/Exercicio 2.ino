int ledDelay = 10000;
int redPin = 11;
int yellowPin = 10;
int greenPin= 9;


void setup() {
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  digitalWrite(redPin, HIGH);
  delay(ledDelay);

  digitalWrite(yellowPin, HIGH);
  delay(2000);
  
  digitalWrite(greenPin, HIGH);
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOw);
  delay(ledDelay);
}
