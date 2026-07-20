#include <Wire.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>

// Pin Configuration
const int BUZZER_PIN = 2;
const int GREEN_LED = 4;
const int RED_LED = 10;

Adafruit_MPU6050 mpu;

// System States
bool isRadioConnected = false; 
unsigned long lastHeartbeat = 0;

void setup() {
  Serial.begin(115200);

  pinMode(GREEN_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);
  pinMode(BUZZER_PIN, OUTPUT);

  // Initialize MPU6050 Onboard Sensor
  if (!mpu.begin()) {
    Serial.println(F("[ERROR] Onboard MPU6050 Balance Sensor Not Found!"));
    while (1) {
      digitalWrite(RED_LED, HIGH);
      delay(100);
      digitalWrite(RED_LED, LOW);
      delay(100);
    }
  }

  Serial.println(F("=========================================="));
  Serial.println(F(" VeloX-Rescue V1 - Drone Receiver Active  "));
  Serial.println(F(" Press 'c' in Serial Monitor to CONNECT   "));
  Serial.println(F(" Press 'd' in Serial Monitor to DISCONNECT"));
  Serial.println(F("=========================================="));
}

void loop() {
  // Serial Input Simulation for Glove RF Link
  if (Serial.available() > 0) {
    char command = Serial.read();
    if (command == 'c' || command == 'C') {
      isRadioConnected = true;
      lastHeartbeat = millis();
      Serial.println(F("[RF LINK] Glove Signal Established!"));
    } else if (command == 'd' || command == 'D') {
      isRadioConnected = false;
      Serial.println(F("[RF LINK] Signal Lost!"));
    }
  }

  // Read Onboard MPU6050 Stability Data
  sensors_event_t a, g, temp;
  mpu.getEvent(&a, &g, &temp);

  // Check Failsafe Condition (5 sec timeout or disconnected)
  if (!isRadioConnected || (millis() - lastHeartbeat > 5000)) {
    triggerFailsafeAlert(a.acceleration.x, a.acceleration.y);
  } else {
    executeFlightMode(a.acceleration.x, a.acceleration.y);
  }

  delay(200);
}

void triggerFailsafeAlert(float ax, float ay) {
  digitalWrite(GREEN_LED, LOW);
  digitalWrite(RED_LED, HIGH);
  tone(BUZZER_PIN, 1000); // 1kHz Emergency Alarm

  Serial.print(F("[FAILSAFE ACTIVE] Emergency Hover | Tilt X: "));
  Serial.print(ax);
  Serial.print(F(" | Tilt Y: "));
  Serial.println(ay);
}

void executeFlightMode(float ax, float ay) {
  noTone(BUZZER_PIN);
  digitalWrite(GREEN_LED, HIGH);
  digitalWrite(RED_LED, LOW);

  Serial.print(F("[FLIGHT ACTIVE] Stable Telemetry | Angle X: "));
  Serial.print(ax);
  Serial.print(F(" | Angle Y: "));
  Serial.println(ay);
}
