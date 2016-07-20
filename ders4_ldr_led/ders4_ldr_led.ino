int ledler[] = {4, 5, 6, 7}; //ledlerin bagli oldugu pinler tanimlaniyor
int led_sayisi = 4; //led adedi tanimlaniyor
int ldr_pin = A0; //ldr sensorumuzun bagli oldugu pini tanimliyor
int deger = 0; //sensor baslangic degeri olarak 0 ataniyor

void setup()
{
  pinMode(4, OUTPUT); //cikis pinleri tanimlaniyor
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
}

void loop()
{
  deger = analogRead(ldr_pin); // analog giristen okudugumuz degeri tanimladigimiz degiskene atiyor
  if (deger > 0 && deger <= 255) //4 adet led icin 4 farkli deger araligina gore ledler yanacak
  {
    digitalWrite(ledler[0], HIGH);
    digitalWrite(ledler[1], LOW);
    digitalWrite(ledler[2], LOW);
    digitalWrite(ledler[3], LOW);
  }
  if (deger > 256 && deger <= 511)
  {
    digitalWrite(ledler[0], HIGH);
    digitalWrite(ledler[1], HIGH);
    digitalWrite(ledler[2], LOW);
    digitalWrite(ledler[3], LOW);
  }
  if (deger > 512 && deger <= 767)
  {
    digitalWrite(ledler[0], HIGH);
    digitalWrite(ledler[1], HIGH);
    digitalWrite(ledler[2], HIGH);
    digitalWrite(ledler[3], LOW);
  }
  if (deger > 768 && deger <= 1023)
  {
    digitalWrite(ledler[0], HIGH);
    digitalWrite(ledler[1], HIGH);
    digitalWrite(ledler[2], HIGH);
    digitalWrite(ledler[3], HIGH);
  }
  delay(100); //stabilite icin 100ms bekleme suresi ekleniyor
}

