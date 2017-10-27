
// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
String read;
//salida raya
int led6 = 6;
//salida punto
int led7 = 7;
void setup() {
  // set up the LCD's number of columns and rows
  pinMode(led6, OUTPUT);
  pinMode(led7, OUTPUT);
  lcd.begin(16, 2);
  // Print a message to the LCD.
  Serial.begin(9600);
  
  
}

void loop() {
  // set the cursor to column 0, line 1
  // (note: line 1 is the second row, since counting begins with 0):
  while(Serial.available()==0){
    }
  read = Serial.readString();
  lcd.print(read);
  lcd.setCursor(0, 0);
  digitalWrite(led6, HIGH);
  digitalWrite(led7, HIGH);   
  delay(1000);                      
  digitalWrite(led6, LOW);
  digitalWrite(led7, LOW);    
  delay(1000);          
  
}

