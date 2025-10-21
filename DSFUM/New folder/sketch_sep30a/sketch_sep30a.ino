int latchPin = 4;   // pin pentru latch
int clockPin = 7;   // pin pentru clock
int dataPin  = 8;   // pin pentru date

// Codificări pentru cifre (logica inversă, LSBFIRST, shield inversat)
byte cifre[10] = {
  0b11000000, // 0
  0b11111001, // 1
  0b10100100, // 2
  0b10110000, // 3
  0b10011001, // 4
  0b10010010, // 5
  0b10000010, // 6
  0b11111000, // 7
  0b10000000, // 8
  0b10010000  // 9
};

// Poziția activă (un singur digit)
byte pozitie = 0b00000001;  // doar prima cifră (dreapta)

// Funcție generală pentru afișare
void afiseazaValoare(byte valoare, byte segment) {
  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, valoare);
  shiftOut(dataPin, clockPin, LSBFIRST, segment);
  digitalWrite(latchPin, HIGH);
}

void setup() {
  pinMode(latchPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
}

void loop() {
  for (int i = 0; i < 10; i++) {
    afiseazaValoare(cifre[i], pozitie);
    delay(1000); // 1 secundă între cifre
  }
}
