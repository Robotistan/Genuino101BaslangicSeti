#include <math.h> //kullanacagimiz log() fonksiyonunu iceren kutuphane dahil ediliyor

int ntc_pin = A0; //ntc sensorunun bagli oldugu pin tanimlaniyor
int deger = 0; //degiskenlere baslangic olarak 0 degerleri ataniyor
double sicaklik = 0.0;

void setup()
{
  Serial.begin(9600); //seri port iletisimi baslatiliyor
}

void loop()
{
  deger = analogRead(ntc_pin); //analog giristen okunan degeri tanimladigimiz degiskene atiyor
  sicaklik = log(((10240000 / deger) - 10000)); //ntc hesaplamasi icin gerekli matematik islemleri yapiliyor
  sicaklik = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * sicaklik * sicaklik )) * sicaklik );
  sicaklik = sicaklik - 273.15;
  Serial.println(sicaklik); //seri port ekranina sicaklik degeri yaziliyor
  delay(500); //kod her yarim saniyede bir tekrar ediyor. (500ms = 0,5sn)
}
