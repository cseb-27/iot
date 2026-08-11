// Experiment No. 3
// Interfacing HC-SR04, PIR Sensor and MQ-2 Gas Sensor with ESP32
// Pin Definitions
#define TRIG_PIN 5
#define ECHO_PIN 18
#define PIR_PIN 19
#define GAS_PIN 34
long duration;
float distance;
int gasValue;
int pirState;
void setup() {
Serial.begin(115200);
pinMode(TRIG_PIN, OUTPUT);
pinMode(ECHO_PIN, INPUT);
pinMode(PIR_PIN, INPUT);
pinMode(GAS_PIN, INPUT);
Serial.println("ESP32 Sensor Interfacing");
}
void loop() {
// ---------- Ultrasonic Sensor ----------
digitalWrite(TRIG_PIN, LOW);
delayMicroseconds(2);
digitalWrite(TRIG_PIN, HIGH);
delayMicroseconds(10);
digitalWrite(TRIG_PIN, LOW);
duration = pulseIn(ECHO_PIN, HIGH);
distance = duration * 0.0343 / 2;
// ---------- PIR Sensor ----------

pirState = digitalRead(PIR_PIN);
// ---------- MQ-2 Gas Sensor ----------
gasValue = analogRead(GAS_PIN);
// ---------- Display Output ----------
Serial.println("------------------------------");
Serial.print("Distance : ");
Serial.print(distance);
Serial.println(" cm");
if (pirState == HIGH)
{
Serial.println("Motion Detected");
}
else
{
Serial.println("No Motion");
}
Serial.print("Gas Sensor Value : ");
Serial.println(gasValue);
delay(1000);
}