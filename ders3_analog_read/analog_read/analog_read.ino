int potPin = 0;
int latchPin = 5;
int clockPin = 6;
int dataPin = 4;

int leds = 0;

void setup() 
{
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);  
  pinMode(clockPin, OUTPUT);
}

void loop() 
{
  int deger  = analogRead(potPin);
  int yanan_ledsayisi = deger / 114;  //1023 / 9
  leds = 0;
  for (int i = 0; i < yanan_ledsayisi; i++)
  {
    bitSet(leds, i); 
  }
  registeraYaz();
}

void registeraYaz()
{
   digitalWrite(latchPin, LOW);
   shiftOut(dataPin, clockPin, LSBFIRST, leds);
   digitalWrite(latchPin, HIGH);
}
