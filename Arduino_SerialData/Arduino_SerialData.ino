int counter = 0;

void setup() {
  Serial.begin(115200);
}

void loop() {
  Serial.print("#");
  Serial.println(counter++);
  
  delay(1000);
}

