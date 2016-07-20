#define echoPin 6 //mesafe sensorunun bagli oldugu pinler tanimlaniyor
#define trigPin 7
#define buzzerPin 8 //buzzerin bagli oldugu pin tanimlaniyor

int maximumRange = 50; //maksimum ve minimum olcum araligi tanimlaniyor
int minimumRange = 0;

void setup()
{
  pinMode(trigPin, OUTPUT); //sensorun trig pini ve buzzer cikis, echo pini giris olarak tanimlaniyor
  pinMode(echoPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop()
{
  int olcum = mesafe(maximumRange, minimumRange);
  melodi(olcum * 10);
}

int mesafe(int maxrange, int minrange) //mesafe olcumu icin gerekli komutlar ayri bir fonksiyonda bulunuyor
{
  long duration, distance;
  digitalWrite(trigPin, LOW); //trig pini lojik 0 seviyesine cekiliyor
  delayMicroseconds(2); //2 mikrosaniye bekleniyor
  digitalWrite(trigPin, HIGH); // trig pini lojik 1 seviyesine cekiliyor
  delayMicroseconds(10); //10 mikrosaniye bekleniyor
  digitalWrite(trigPin, LOW); //trig pini tekrar lojik 0 seviyesine cekiliyor
  duration = pulseIn(echoPin, HIGH); //sensorun yolladigi ultrasonik ses dalgasının geri gelme suresi olculuyor
  distance = duration / 58.2; //olculen sure, ses hizinin iki katina bolunuyor ve mesafeye cevriliyor (ses hizi ~= 29 mikrosn/cm)
  if (distance >= maxrange || distance <= minrange) //olculen deger maksimum mesafeden yuksek ise mesafe olarak 0 yollaniyor
    return 0;
  return distance;
  delay(50); //islem bittikten sonra 50 ms bekleniyor
}

int melodi(int dly) //buzzerdan ses cikisi icin gerekli komutlar ayri bir fonksiyonda yer aliyor
{
  tone(buzzerPin, 440); //buzzer pininden 440Hz frekansinda (la notasi) ses cikisi saglaniyor
  delay(dly); //parametre olarak verilen sure kadar bekleniyor
  noTone(buzzerPin); //ses kesiliyor
  delay(dly); //parametre olarak verilen sure kadar bekleniyor
}

