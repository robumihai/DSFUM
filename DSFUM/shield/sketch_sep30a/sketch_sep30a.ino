void setup ()
{
  pinMode(4, OUTPUT); // latch
  pinMode(7, OUTPUT); // clock
  pinMode(8, OUTPUT); // data
}

void loop()
{
  // cifrele in format lbsfirst
  byte cifre[] = {
    0b11111100, // 0
    0b01100000, // 1
    0b11011010, // 2
    0b11110010, // 3
    0b01100110, // 4
    0b10110110, // 5
    0b10111110, // 6
    0b11100000, // 7
    0b11111110, // 8
    0b11110110  // 9
  };

  // pozitia activa
  byte pozitie = 242;

  for (int i = 0; i <= 9; i++) {
    afiseazaValoare(cifre[i], pozitie);
    delay(1000);
  }
}

void afiseazaValoare(byte valoare, byte segment)
{
  digitalWrite(4, LOW);
  shiftOut(8, 7, LSBFIRST, ~valoare); // trimitem segmentele
  shiftOut(8, 7, LSBFIRST, segment); // trimitem pozitia
  digitalWrite(4, HIGH);
}
