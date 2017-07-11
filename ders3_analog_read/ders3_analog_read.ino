int potPin = A0; //potansiyometreyi bagladigimiz analog pini tanimliyor
int deger = 0; //potansiyometreden okuyacagimiz deger icin bir degisken tanimliyor

void setup() 
{
  Serial.begin(9600); //seri port iletisimini baslatiyor
  delay(3000); //iletisimin baslayabilmesi icin 3sn bekleniyor
}
void loop() 
{
  Serial.print("Analog pin degeri: "); //on aciklama metnini yaziyor
  deger  = analogRead(potPin); //analog giristen okudugumuz degeri tanimladigimiz degiskene atiyor
  Serial.println(deger); //degeri seri port ekranina yazdiriyor
  delay(100); //her bir okuma arasinda 100ms bekleme suresi ekliyor
}
