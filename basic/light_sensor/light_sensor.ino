const int SENSOR = 5;
const int LED = 10;

int brightness = 0;

int mapped(int val, int from_low, int from_high, int to_low, int to_high) {
    float ratio = float (to_high - to_low) / float (from_high - from_low);
    int ret = int (val * ratio);
    if (ret < to_low) { ret = to_low; }
    if (ret > to_high) { ret = to_high; }
    return ret;
}

int mappedRead() {
    int sensor_read = analogRead(SENSOR);
    int light = mapped(sensor_read, 0, 135, 0, 255);
    Serial.print(sensor_read);
    Serial.print(" ");
    Serial.println(light);
    return light;
}

void setup() {
    pinMode(SENSOR, INPUT);
    Serial.begin(9600);
}

void loop() {
    brightness = (0.9 * brightness) + (0.1 * (255 - mappedRead()));

    analogWrite(LED, brightness);
    delay(30);
}

