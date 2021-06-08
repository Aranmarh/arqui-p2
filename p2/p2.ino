#include <Servo.h>
int cm = 0;
int cm2 = 0;
int salida=27;

Servo servo,servo2;
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
    servo.attach(27);
   servo2.attach(A0);

}

void loop() {

  cm = 0.01723 * distancia(6, 6);
  cm2 = 0.01723 * distancia(29, 29);
  int x = 150 - cm;
  motorDerecho(x);
  int y = 150-cm2;
  motorIzquierdo(y);
  delay(100);

}

void motorDerecho(int dist){
  servo.write(dist);
}


void motorIzquierdo(int dist){
  servo2.write(dist);
}
