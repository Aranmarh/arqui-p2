int cm = 0;
int cm2 = 0;
int salida=27;
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
  // put your setup code here, to run once:

}

void loop() {

  cm = 0.01723 * distancia(6, 6);
  // put your main code here, to run repeatedly:

}
