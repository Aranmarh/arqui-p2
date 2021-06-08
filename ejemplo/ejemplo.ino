
#include <LiquidCrystal.h>
LiquidCrystal lcd(7,6,5,4,3,2);
void setup() {
  Serial.begin(9600);
  // put your setup code here, to run once:
  lcd.begin(20, 2);
  lcd.print("Lab Arqui");
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.print("Lab Arqui111111");

}
