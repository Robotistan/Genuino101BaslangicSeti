int kirmiziPin = 3;
int yesilPin = 5;
int maviPin = 6;


void setup()
{
  pinMode(kirmiziPin, OUTPUT);
  pinMode(yesilPin, OUTPUT);
  pinMode(maviPin, OUTPUT);  
}

void loop()
{
  renkAyarla(255, 0, 0);  // kirmizi
  delay(1500);
  renkAyarla(0, 255, 0);  // yesil
  delay(1500);
  renkAyarla(0, 0, 255);  // mavi
  delay(1500);
  renkAyarla(255, 255, 0);  // sari
  delay(1500);  
  renkAyarla(80, 0, 80);  // mor
  delay(1500);
  renkAyarla(0, 255, 255);  // acik mavi
  delay(1500);
  renkAyarla(255, 255, 255); // beyaz
  delay(1500);
}

void renkAyarla(int kirmizi, int yesil, int mavi)
{
  kirmizi = 255 - kirmizi;
  yesil = 255 - yesil;
  mavi = 255 - mavi;
  analogWrite(kirmiziPin, kirmizi);
  analogWrite(yesilPin, yesil);
  analogWrite(maviPin, mavi);  
}

