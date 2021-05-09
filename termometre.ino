int ledk1 = 2;
int ledk2 = 3;
int leds1 = 4;
int leds2 = 5;
int ledy1 = 6;
int ledy2 = 7;

int dht_pin =A0;

int sensor;
double sicaklik;

float durum;
float hesap;


void setup()
{
  pinMode(ledk1, OUTPUT);
  pinMode(ledk2, OUTPUT);
  pinMode(leds1, OUTPUT);
  pinMode(leds2, OUTPUT);
  pinMode(ledy1, OUTPUT);
  pinMode(ledy2, OUTPUT);
  
  pinMode(dht_pin,INPUT);
  
  Serial.begin(9600);
}

void loop()
{
  sensor =analogRead(dht_pin);
  
  sicaklik = (double)sensor/ 1024;       
  sicaklik = sicaklik * 5;     
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
  sicaklik = sicaklik - 0.5;               
  sicaklik = sicaklik * 100;
  //Serial.print("CELCIUS:");
  //Serial.println(sicaklik);
  delay(2000);
  Fahrenheit();}

void Fahrenheit(){
  hesap = (sicaklik*1.8)+32;
  //Serial.println("------------------------");
  Serial.print("Fahrenheit degeri:");
  Serial.print(hesap);
  Serial.println("F");
  //Serial.println("------------------------");
}
