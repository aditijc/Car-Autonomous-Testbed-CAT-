#include <Servo.h>
#include <cstdlib>

Servo myservo;
int LOWER_BOUND = -180;
int UPPER_BOUND = 180;
int AXIS = 0;

void setup() {
  myservo.attach(15);
  Serial.begin(9600);
}

void loop() {
  int angle = rand() % (UPPER_BOUND - LOWER_BOUND + 1) + LOWER_BOUND;
  myservo.write(angle);
  delay(2000);
  Serial.println(angle);
  Serial.println(AXIS);
}
