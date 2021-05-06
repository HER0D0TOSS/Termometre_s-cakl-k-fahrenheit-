int ledk1 = 2;
int ledk2 = 3;
int leds1 = 4;
int leds2 = 5;
int ledy1 = 6;
int ledy2 = 7;

float sensor = A0;

int sicaklik;
float durum;
float gerilim;
int hesap;
float Celcius;

void setup()
{
  pinMode(ledk1, OUTPUT);
  pinMode(ledk2, OUTPUT);
  pinMode(leds1, OUTPUT);
  pinMode(leds2, OUTPUT);
  pinMode(ledy1, OUTPUT);
  pinMode(ledy2, OUTPUT);
  
  pinMode(sensor,INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  int sicaklik = analogRead(sensor);
  //Serial.println(sicaklik);
  gerilim = (sicaklik *5.0);
  gerilim = (gerilim /1024);
  //Serial.println(gerilim);
  //Serial.println(hesap);
  celcius_cevir();
  
  if (hesap<=30){
   	digitalWrite(ledk1,LOW);
    digitalWrite(ledk2,LOW);
    digitalWrite(leds1,LOW);
    digitalWrite(leds2,LOW);
    digitalWrite(ledy1,LOW);
    digitalWrite(ledy2,LOW);
  }
  else if ((hesap>=30)&&(hesap<41)){
    digitalWrite(ledk1,HIGH);
    digitalWrite(ledk2,LOW);
    digitalWrite(leds1,LOW);
    digitalWrite(leds2,LOW);
    digitalWrite(ledy1,LOW);
    digitalWrite(ledy2,LOW);
  }

  else if((hesap>=41)&&(hesap<46)){
    digitalWrite(ledk1,HIGH);
    digitalWrite(ledk2,HIGH);
    digitalWrite(leds1,LOW);
    digitalWrite(leds2,LOW);
    digitalWrite(ledy1,LOW);
    digitalWrite(ledy2,LOW);
  }

  else if((hesap>=46)&&(hesap<51)){
    digitalWrite(ledk1,HIGH);
    digitalWrite(ledk2,HIGH);
    digitalWrite(leds1,HIGH);
    digitalWrite(leds2,LOW);
    digitalWrite(ledy1,LOW);
    digitalWrite(ledy2,LOW);}

  else if((hesap>=51)&&(hesap<56)){
    digitalWrite(ledk1,HIGH);
    digitalWrite(ledk2,HIGH);
    digitalWrite(leds1,HIGH);
    digitalWrite(leds2,HIGH);
    digitalWrite(ledy1,LOW);
    digitalWrite(ledy2,LOW);}
  
   else if((hesap>=56)&&(hesap<61)){
    digitalWrite(ledk1,HIGH);
    digitalWrite(ledk2,HIGH);
    digitalWrite(leds1,HIGH);
    digitalWrite(leds2,HIGH);
    digitalWrite(ledy1,HIGH);
    digitalWrite(ledy2,LOW);}
  
  else if(hesap>=61){
    digitalWrite(ledk1,HIGH);
    digitalWrite(ledk2,HIGH);
    digitalWrite(leds1,HIGH);
    digitalWrite(leds2,HIGH);
    digitalWrite(ledy1,HIGH);
    digitalWrite(ledy2,HIGH);}
	
}

void celcius_cevir(){
  Celcius = (gerilim - 0.5) * -100 ;
  //Serial.print("CELCIUS:");
  //Serial.println(Celcius);
  delay(2000);
  Fahrenheit();}

void Fahrenheit(){
  hesap = (Celcius*1.8)+32;
  Serial.println("------------------------");
  Serial.print("Fahrenheit degeri:");
  Serial.println(hesap);
  //Serial.print("F");
  Serial.println("------------------------");
}