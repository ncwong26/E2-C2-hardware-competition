const int tPrPin = A0
const int bPrPin = A1
const int lPrPin = A2
const int rPrPin = A3

void setup() {
  //initialize the baude rate
  Serial.begin(9600);
}

void loop() {
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

  if(tVal < bVal)
  {
    Serial.println("down");
  }
  else if(bVal < tVal)
  {
    Serial.println("up");
  }
  else
  {
    Serial.println("pitch good");
  }

  if(lVal < rVal)
  {
    Serial.println("turn left");
  }
  else if(rVal < lVal)
  {
    Serial.println("turn right");
  }
  else
  {
    Serial.println("yaw good");
  }
}
