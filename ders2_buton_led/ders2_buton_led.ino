int ledler[] = {4, 5, 6, 7}; //ledlerin bagli oldugu pinler tanimlaniyor
int led_sayisi = 4; //led adedi tanimlaniyor
int buton_pin = 2; //butonun bagli oldugu pin tanimlaniyor
int buton_deger = 0; //butonun baslangic degeri olarak 0 ataniyor
int buton_basilma = 0; //butona kac defa basildigi tanimlaniyor ve baslangic icin 0 ataniyor

void setup()
{
  pinMode(4, OUTPUT); //giris ve cikis pinleri tanimlaniyor
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(buton_pin, INPUT);
}

void loop()
{
  buton_deger = digitalRead(buton_pin); //butonun bagli oldugu pin degeri okunuyor
  if (buton_deger == HIGH) //deger 1 ise
  {
    for (int i = 0 ; i < led_sayisi ; i++) //tanimlanan led sayisi kadar islem yapilmasi icin for dongusu kullaniliyor
    {
      if (buton_basilma % led_sayisi == i) //butona basilma sayisinin led sayisina bolumunden kalan (modulus) numarali led yaniyor
        digitalWrite(ledler[i], HIGH);
      else
        digitalWrite(ledler[i], LOW); //diger ledler sonuyor
    }
    buton_basilma++; //buton basilma sayisi bir arttiriliyor
    delay(200); //stabilite 200ms bekleme suresi ekleniyor
  }
}

