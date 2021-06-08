#include <Servo.h>
#include <Key.h>
#include <Keypad.h>

#include <LiquidCrystal.h>

LiquidCrystal lcd(53, 51, 49, 47, 45, 43);

Servo servo;
Servo servo2;

int cm = 0;
int cm2 =0;

long distancia(int trigger, int echo){
  pinMode(trigger, OUTPUT);
  digitalWrite(trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);    

  pinMode(echo, INPUT);
  return pulseIn(echo, HIGH);
}


void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  servo.attach(A0);
  servo2.attach(A1);
 
  
}

void loop() {
  
  
  cm = 0.01723 * distancia(6, 6);
  cm2 = 0.01723 * distancia(5, 5);
  lcd.clear();
  lcd.print("Distancia:"+cm);
  Serial.print("Sensor 1: ");
  Serial.print(cm);
  Serial.println("");
  Serial.print("Sensor 2: ");
  Serial.print(cm2);
  
  if(cm<=150){
    int d = 150-cm;
    Serial.println("");
    //Serial.print("esto es: ");
   // Serial.print(10);
    delay(500);
    servo.write(180);
    //motorDerecho(d);
   // delay(10000);
  } 
}

void motorDerecho(int dist){
  servo.write(dist);
}


void motorIzquierdo(int dist){
  servo2.write(dist);
}
