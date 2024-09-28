#include <Servo.h>

const int tPrPin = A0;
const int bPrPin = A1;
const int lPrPin = A2;
const int rPrPin = A3;
const int vPin = A4;
Servo pitchServo;
Servo yawServo;

short int pitchPos = 0;
short int yawPos = 0;

//initialize run flag
short int flag = 0;

void setup() {
  //initialize the baude rate
  Serial.begin(9600);

  //updown
  pitchServo.attach(9);
  //leftright
  yawServo.attach(10);

  //check if pitch servo is properly attached
  if(pitchServo.attached())
  {
    Serial.print("Pitch Servo successfully attached at position: ");
    pitchPos = pitchServo.read();
    Serial.println(pitchPos);
    flag = 1;
  }
  else
  {
    Serial.println("Pitch Servo not properly attached, program will not run");
  }

  //check if yaw servo is properly attached
  if(yawServo.attached())
  {
    Serial.print("Yaw Servo successfully attached at position: ");
    yawPos = yawServo.read();
    Serial.println(yawPos);
    flag = 1;
  }
  else
  {
    Serial.println("Yaw Servo not properly attached, program will not run");
  }
}

void loop() {
  if(flag == 1)
  {
    //initialize values for photoresistors
    int tVal = 0;
    int bVal = 0;
    int lVal = 0;
    int rVal = 0;

    //read values from photoresistors
    tVal = analogRead(tPrPin);
    bVal = analogRead(bPrPin);
    lVal = analogRead(lPrPin);
    rVal = analogRead(rPrPin);

    //prodvides a slight leniency for the sides
    int leniency = 50;

    //checks if bottom is brighter than the top
    if(tVal < (bVal - leniency))
    {
      Serial.println("down");
      rotateServo(pitchServo, &pitchPos, -1);
    }
    else if(bVal < (tVal - leniency))
    {
      Serial.println("up");
      rotateServo(pitchServo, &pitchPos, 1);
    }
    else
    {
      Serial.println("pitch good");
    }

    if(lVal < (rVal - leniency))
    {
      Serial.println("turn right");
      rotateServo(yawServo, &yawPos, 1);
    }
    else if(rVal < (lVal - leniency))
    {
      Serial.println("turn left");
      rotateServo(yawServo, &yawPos, -1);
    }
    else
    {
      Serial.println("yaw good");
    }

    delay(15);

    int val = analogRead(vPin);
    Serial.print("Voltage:");
    Serial.print(val);
    }
}

void rotateServo(Servo serv, short int* pos, short int rot)
{
  short int tPos = *pos;
  if(rot > 0 && (rot + tPos) > 140)
  {
    return;
  }
  if(rot < 0 && (rot + tPos) < 40)
  {
    return;
  }
  *pos += rot;
  serv.write(*pos);
}
