#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x20, 16, 2);

void setup()
{
   lcd.begin(16,2);
   lcd.init();
   lcd.backlight();
   Serial.begin(9600);

}

void loop()
{
  float nb1;
  float nb2;
  float resultat;
  char operateur;
  
  lcd.setCursor(0,0);
  lcd.print("Entre une valeur:");
  lcd.scrollDisplayLeft();
  while (Serial.available() == 0);
  nb1 = Serial.parseFloat();
  lcd.setCursor(1,1);
  lcd.print(nb1);
  delay(4000);
  lcd.clear();

  
  lcd.setCursor(0,0);
  lcd.print("Entre une deuxieme valeur:");
  lcd.scrollDisplayLeft();
  while (Serial.available() == 0);
  nb2 = Serial.parseFloat();
  lcd.setCursor(1,1);
  lcd.print(nb2);
  delay(4000);

  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("Choisir un operateur '+' '-' '*' '/'");
  lcd.scrollDisplayLeft();
  while (Serial.available() == 0);
  operateur = Serial.read();
  lcd.setCursor(1,1);
  lcd.print(operateur);
  delay(4000);
  lcd.clear();
 
  if (operateur = '*' )
  {
    resultat = nb1 * nb2;
  }
  if (operateur = '+' ) 
  {
    resultat = nb1 + nb2;
  }
  if ( operateur = '-')
  {
    resultat = nb1 - nb2;
  }
  if (operateur = '/' && nb1 == 0 | nb2 == 0  )
  { 
    lcd.print("choisir de nouvelle valleur");
  }
    else(resultat = nb1 / nb2);
  lcd.clear();
  lcd.print(resultat);
  delay(5000);
}
