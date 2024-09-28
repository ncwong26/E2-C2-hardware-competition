const int prPin = A0

void setup() {
  // initialize the baude rate
  Serial.begin(9600);
}

void loop() {
  int val = 0;
  val = analogRead(prPin);
  Serial.println(val);
}
