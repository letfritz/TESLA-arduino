#include <LiquidCrystal.h>

LiquidCrystal lcd(3,5,10,11,12,13);

void setup() {
  // put your setup code here, to run once:
  
  lcd.begin(16,2);

}

void loop() {
  // put your main code here, to run repeatedly:

  lcd.clear();
  lcd.setCursor(2,0);
  lcd.print("Eu sou mais,");
  lcd.setCursor(2,1);
  lcd.print("sou Tesla Jr");
  delay(2000);

  for(int posicao = 0; posicao < 2; posicao++){
    lcd.scrollDisplayLeft();
    delay(300);
  }

  for(int posicao = 0; posicao < 4; posicao++){
    lcd.scrollDisplayRight();
    delay(300);
  }

}


