#include <Servo.h>

Servo servo1;

void setup()
{
  Serial.begin(9600);
  servo1.attach(9);

  int flag = 0;
  //check if servo is properly attached
  if(servo1.attached())
  {
    Serial.println("Servo successfully attached");
    Serial.println("There will be a delay of 500 ms between steps in case the servo breaks for you to stop the program");
    flag = 1;
  }
  else
  {
    Serial.println("Servo not properly attached");
  }
  
  if(flag == 1)
  {
    int angle = 0;
    delay(500);
    //read initial servo angle
    readServo();
    angle = servo1.read();

    delay(500);
    functionTest(servo1, &angle);

    // delay(500);
    // //set servo in a single write to 90 degrees
    // Serial.println("Single write rotation to 90 degrees");
    // servo1.write(90);
    // readServo();

    // delay(500);
    // //set servo in a single write to 0 degrees
    // Serial.println("Single write rotation to 0 degrees");
    // servo1.write(0);
    // readServo();

    // delay(500);
    // //continuously move servo to 180 degrees at an increment of 2 degrees and a midstep of 15ms
    // for(int angle = 0; angle <= 180; angle += 2)
    // {
    //   servo1.write(angle);
    //   delay(15);
    // }
    // readServo();

    // Serial.println("Test finished");
  }
}

void loop()
{

}

void readServo()
{
  Serial.print("Current angle: ");
  Serial.println(servo1.read());
}

void functionTest(Servo serv, short int* motorPos)
{
  *motorPos += 10;
  readServo()
  serv.write(motorPos)
}