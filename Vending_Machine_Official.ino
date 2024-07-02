#include <Servo.h>
#include <LiquidCrystal_I2C.h>


int redButton = 22;
int yellowButton = 24;
int greenButton = 26;
int blueButton = 28;

LiquidCrystal_I2C lcd(0x27, 16, 2);

// Create a servo instance.
// It will send signals to different pins according to the button pressed.
Servo myServo;

int redServoPin = 8;
int yellowServoPin = 9;
int greenServoPin = 2;
int blueServoPin = 3;

void ServoAction();

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  pinMode(redServoPin, OUTPUT);
  pinMode(yellowServoPin, OUTPUT);
  pinMode(greenServoPin, OUTPUT);
  pinMode(blueServoPin, OUTPUT);
}

void loop() {
  lcd.clear();
  lcd.setCursor(7, 0);
  lcd.print("X");
  lcd.setCursor(8, 0);
  lcd.print("X");
  lcd.setCursor(7, 1);
  lcd.print("~");
  lcd.setCursor(8, 1);
  lcd.print("~");
  if (digitalRead(redButton) == 1) {
    myServo.attach(redServoPin);
    ServoAction("Red");
  }
  if (digitalRead(yellowButton) == 1) {
    myServo.attach(yellowServoPin);
    ServoAction("Yellow");
  }
  if (digitalRead(greenButton) == 1) {
    myServo.attach(greenServoPin);
    ServoAction("Green");
  }
  if (digitalRead(blueButton) == 1) {
    myServo.attach(blueServoPin);
    ServoAction("Blue");
  }
}

void ServoAction(String color) {
  Serial.print(color);
  Serial.println(" pressed");
  lcd.clear();
  lcd.print(color);
  lcd.print(" pressed");
  myServo.write(60);
  delay(1830);
  myServo.detach();
  delay(500);
}

