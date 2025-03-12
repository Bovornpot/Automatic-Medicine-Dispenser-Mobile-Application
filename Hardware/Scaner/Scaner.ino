#include <SoftwareSerial.h>
SoftwareSerial mySerial(2, 3); // RX, TX
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27, 16, 2);
char i = '0';
char a[15] = {'0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0', '0'};
int k = 0;
int relay_pin = 5;
void setup()
{
  lcd.backlight();
  //lcd.init();
  pinMode(relay_pin, OUTPUT);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" The door has a ");
  while (!Serial) ;
  mySerial.begin(9600);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print(" The door has a ");
  lcd.setCursor(4, 1);
  lcd.print("Password ");
  delay(5000);
  lcd.clear();
  lcd.print("Please Scan Your ");
  lcd.setCursor(0, 1);
  lcd.setCursor(6, 1);
  lcd.print("Cad ");


}
void loop()
{
  digitalWrite(relay_pin, HIGH);
  if (mySerial.available()) {

    //Serial.write(mySerial.read());
    i = mySerial.read();
    //Serial.println(i);
    a[k] = i;


    k = k + 1;
    // Serial.println(k);

    if (k == 15)
    {
      Serial.print("ID : ");
      Serial.print(a[0]);
      Serial.print(a[1]);
      Serial.print(a[2]);
      Serial.print(a[3]);
      Serial.print(a[4]);
      Serial.print(a[5]);
      Serial.print(a[6]);
      Serial.print(a[7]);
      Serial.println(a[8]);


      if (a[0] == 'E' && a[1] == 'L' && a[2] == '1' && a[3] == '1' && a[4] == '-' && a[5] == '0' && a[6] == '2' && a[7] == '7' && a[8] == 'Q')  {
        Serial.print("Name : ");
        Serial.println("Makham XIONG");
        Serial.println();
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Makham XIONG");
        lcd.setCursor(3, 1);
        lcd.print("ID: EL11-027Q");
        digitalWrite(relay_pin, HIGH);
      }
      if (a[0] == 'E' && a[1] == 'L' && a[2] == '1' && a[3] == '1' && a[4] == '-' && a[5] == '0' && a[6] == '2' && a[7] == '4' && a[8] == 'Q')  {
        Serial.print("Name : ");
        Serial.println("Kantana XAIYASID ");
        Serial.println();
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Kantana XAIYASID");
        lcd.setCursor(3, 1);
        lcd.print("ID: EL11-024Q");
        digitalWrite(relay_pin, HIGH);
      }
      if (a[0] == 'E' && a[1] == 'L' && a[2] == '1' && a[3] == '1' && a[4] == '-' && a[5] == '0' && a[6] == '2' && a[7] == '8' && a[8] == 'Q')  {
        Serial.print("Name : ");
        Serial.println("Phong XIONG");
        Serial.println();
        lcd.clear();
        lcd.setCursor(1, 0);
        lcd.print("Phong XIONG");
        lcd.setCursor(3, 1);
        lcd.print("ID: EL11-028Q");
        digitalWrite(relay_pin, HIGH);
      }
      else {
        digitalWrite(relay_pin, LOW);
        lcd.clear();
        lcd.print("Wrong Your cad");
        lcd.setCursor(0, 0);
        lcd.print("To Open");
        lcd.setCursor(0, 1);
        lcd.print("change the Cad");
        delay(2000);
        lcd.clear();
        lcd.print("Wrong Try Again");
        lcd.setCursor(0, 1);
        delay(500);
        i = 0;
        lcd.clear();
        lcd.print("Please Scan Your ");
        lcd.setCursor(0, 1);
        lcd.setCursor(6, 1);
        lcd.print("Cad ");
      }
      k = 0;
    }
  }
}
