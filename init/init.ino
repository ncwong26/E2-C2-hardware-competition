#include <Servo.h>

Servo pitchServo;
Servo yawServo;

void setup() {
  Serial.begin(9600);
  pitchServo.attach(9);
  yawServo.attach(10);
  
  pitchServo.write(90);
  yawServo.write(90);
  Serial.println("init finished");
}

void loop() {
  // put your main code here, to run repeatedly:

}
