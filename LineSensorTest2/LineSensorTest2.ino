int qreLeft = A0;
int qreRight = A2;

void setup() {
  Serial.begin(9600);

}

void loop() {
  int QRE_Left=analogRead(qreLeft);
  int QRE_Right=analogRead(qreRight);
  Serial.print("Left: ");
  Serial.print(QRE_Left);
  Serial.print(" Right: ");
  Serial.println(QRE_Right);
  delay(2000);

}
