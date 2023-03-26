#include <LiquidCrystal_I2C.h>

//pines led
int led1=13;
int led2=12;
int led3=11;
int led4=10;
int led5=9;
//potenciometro
//int potenciometro=A1;
// ultrasonico
const int trigger=2;
const int echo = 3;

//CREANOS UNA INSTANCIA 
LiquidCrystal_I2C lcd(0x27, 16, 2);


//simbolos 

// Degree symbol:grados
byte grados[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

// hackaton :D

//definimos el sensor del LM35
#define sensorPin A0 // aqui conectas el sensor de temperatura

void setup (){

  //leds
  digitalWrite(led1,OUTPUT); 
  digitalWrite(led2,OUTPUT);
  digitalWrite(led3,OUTPUT);
  digitalWrite(led4,OUTPUT);
  digitalWrite(led5,OUTPUT);

  //ultrasonico
  pinMode(echo,INPUT);
  pinMode(trigger,OUTPUT);
  digitalWrite(trigger,LOW);

  //potenciometro

  //inciamos la pantalla LCD 

  lcd.init();
  lcd.backlight();


  //creamos el simbolo de los caracteres'
  lcd.createChar(0,grados);
  
  
}



void loop(){
  //obtenemos la lectura con el sensor de temperatura :D
  int lectura = analogRead(sensorPin);

 //convertimos la lectura 

  float datos = lectura * (5000/1024.0);

  //convertimos ese voltaje para pasarlo a grados celcius
   
  float temperatura = datos /10 ;

//ultrasonico
long t;
long d;
 digitalWrite(trigger,HIGH);
 delayMicroseconds(10);
 digitalWrite(trigger,LOW);
  t = pulseIn(echo,HIGH);
  d= t/59;
  if(d<=3)
  {
    // imprimimos

  lcd.setCursor(0,0);
  lcd.print("🌡temperatura🌡");
  lcd.setCursor(0,1);
  lcd.print(temperatura);
  lcd.write(0);
  lcd.print("C");

  //aqui hacemos el hack para escuchar el serial y este serial lo pasara a visual (la temperatura) se pueden hacer estaticos los datos4
  //daniel
  //chirrion
  //30 ans
  

  delay(100);
  }
//potenciometro
int valorpote = analogRead(A1);
if (valorpote==0)
{
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
} else if (valorpote > 1 && valorpote <= 204.6) 
{ 
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
  } else if (valorpote >= 204.6 && valorpote <= 409.2) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
} else if (valorpote >= 409.2 && valorpote <= 613.8) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, LOW);
    digitalWrite(led5, LOW);
} else if (valorpote >= 613.8 && valorpote <= 818.4) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, LOW);
} else if (valorpote >= 818.4 && valorpote <= 1023) {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
    digitalWrite(led4, HIGH);
    digitalWrite(led5, HIGH);
  }
}
