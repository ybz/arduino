const int BUTTON = 7;
const int LED = 10;

int state = 0;
int brightness = 0;
int dir = 1;
int button_val = LOW;
int button_old_val = LOW;
int pulse_delay = 5;

void setup() {
    pinMode(BUTTON, INPUT);
    pinMode(LED, OUTPUT);
}

void loop() {
    button_val = digitalRead(BUTTON);

    if ((button_val == HIGH) && (button_old_val == LOW)) {
        state = 1 - state;
        delay(50);
        if (state == 0) {
            brightness = 0;
        }
    }

    analogWrite(LED, brightness);

    if (state == 1) {
        brightness = brightness + dir;
        if (brightness < 3) {
            brightness = 3;
            dir = 1;
        }
        if (brightness > 255) {
            brightness = 255;
            dir = -1;
        }
        delay(pulse_delay);
    }

    button_old_val = button_val;
}
