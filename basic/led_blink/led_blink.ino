const int LED = 13;
const int BUTTON = 7;
int state = 0;
int val = 0;
int old_val = 0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  digitalWrite(LED, HIGH);
  delay(1000);
  digitalWrite(LED, LOW);
  delay(1000);
}
