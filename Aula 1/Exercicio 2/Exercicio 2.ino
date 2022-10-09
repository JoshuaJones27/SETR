#define LED 12
#define BUTTON 2

int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, OUTPUT);
}

void loop() {
  val = digitalRead(BUTTON);

  if (val == HIGH) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }

}