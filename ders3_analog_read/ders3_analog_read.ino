int potPin = A0; //potansiyometreyi bagladigimiz analog pini tanimliyor
int deger = 0; //potansiyometreden okuyacagimiz deger icin bir degisken tanimliyor

void setup() 
{
  Serial.begin(9600); //seri port iletisimini baslatiyor
  Serial.println("Analog input okuma ornegi.");
}
void loop() 
{
  deger  = analogRead(potPin); //analog giristen okudugumuz degeri tanimladigimiz degiskene atiyor
  Serial.println(deger); //degeri seri port ekranina yazdiriyor
  delay(100); //her bir okuma arasinda 100ms bekleme suresi ekliyor
}

