const int BUTTON = 7;
const int LED = 10;

int state = 0;
int val = 0;
int old_val = LOW;
int brightness = 128;
long push_start = millis();

void setup() {
  Serial.begin(9600);
  pinMode(7, INPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  val = digitalRead(BUTTON);
  if (val == HIGH)  {
    if (old_val == LOW) {
      Serial.println(8);
      push_start = millis();
    } else {
      Serial.println(10);
      brightness = (brightness + 1) % 256;
      if (brightness < 80) {
        delay(30);
      } else if (brightness < 100) {
        delay(15);
      } else {
        delay(2);
      }
    }
  }
  if ((val == LOW) &&
      (old_val == HIGH) &&
      ((millis() - push_start) < 250)) {
        Serial.println(11);
        Serial.println(millis() - push_start);
        state =  1 - state;
        delay(50);
      }
  if (old_val != val) {
    Serial.println(val);
  }
  old_val = val;
  
  if (state == 1) {
    analogWrite(LED, brightness);
  } else {
    analogWrite(LED, 0);
  }
  
}
