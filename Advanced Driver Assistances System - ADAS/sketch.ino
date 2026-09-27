#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_MPU6050.h>
#include <TinyGPS++.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
Adafruit_MPU6050 mpu;

#define TRIG_PIN 5
#define ECHO_PIN 18
#define BUZZER_PIN 25
#define LED_PIN 26
#define RELAY_PIN 27

void setup()
{
  Serial.begin(115200);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED_PIN, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  Wire.begin();
  lcd.init();
  lcd.backlight();
  mpu.begin();

  lcd.setCursor(0, 0);
  lcd.print("ADAS SYSTEM");
}

void loop()
{
  float distance = readDistance();

  sensors_event_t acceleration;
  sensors_event_t gyro;
  sensors_event_t temperature;
  mpu.getEvent(&acceleration, &gyro, &temperature);

  bool obstacle = distance < 50.0;

  bool abnormalMovement =
      abs(acceleration.acceleration.x) > 10 ||
      abs(acceleration.acceleration.y) > 10 ||
      abs(acceleration.acceleration.z) > 15;

  if (obstacle || abnormalMovement)
  {
    digitalWrite(BUZZER_PIN, HIGH);
    digitalWrite(LED_PIN, HIGH);
    digitalWrite(RELAY_PIN, HIGH);

    lcd.clear();
    lcd.print("WARNING");
  }
  else
  {
    digitalWrite(BUZZER_PIN, LOW);
    digitalWrite(LED_PIN, LOW);
    digitalWrite(RELAY_PIN, LOW);

    lcd.clear();
    lcd.print("SYSTEM SAFE");
  }

  delay(200);
}

float readDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);
  return duration * 0.034 / 2;
}