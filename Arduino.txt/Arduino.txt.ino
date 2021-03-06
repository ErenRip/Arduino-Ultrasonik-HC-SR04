#include <LiquidCrystal_I2C.h>

#include <Wire.h>

LiquidCrystal_I2C lcdekranim(0x27,16,2);

void setup() 
{
  lcdekranim.init();
  lcdekranim.backlight();
  lcdekranim.setCursor(0,0);
  lcdekranim.print("|-LOGIN-|");
  delay(1000);
  lcdekranim.clear();
  pinMode(6,OUTPUT);//Trig
  pinMode(7,INPUT); //Echo
  pinMode(4,OUTPUT);  
  Serial.begin(9600);
}

void loop()
{
digitalWrite(6,1); delay(1);
digitalWrite(6,0);
int sure=pulseIn(7,1);
int mesafe=(sure/2)/28.97;
Serial.print("Olculen Mesafe=");
Serial.println(mesafe);
delay(1);

lcdekranim.setCursor(0,0);
lcdekranim.print("|-olcum-|");
lcdekranim.setCursor(3,1);
lcdekranim.print(mesafe);
  delay(0120);
  lcdekranim.clear();
if(mesafe<=25)
{
  digitalWrite(4,1);
  }
else if(mesafe<=50)
{
  digitalWrite(4,1);
  delay(0050);
  digitalWrite(4,0);
  delay(0050);
  digitalWrite(4,1);
  delay(0050);
  digitalWrite(4,0);
  
 }

else if(mesafe >51)
{
  digitalWrite(4,0);
  } 
else
{
  digitalWrite(4,0);
  } 


}
