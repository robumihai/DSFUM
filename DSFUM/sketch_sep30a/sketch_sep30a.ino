void setup() {

pinMode (8, OUTPUT);

pinMode (10, OUTPUT);

pinMode (12, OUTPUT);

}

void loop() {

digitalWrite(8, millis() / 2000 & 1);

digitalWrite(12, millis() / 4000 & 1);

digitalWrite(10, millis() / 3000 & 1);

}