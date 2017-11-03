// include the library code:
#include <LiquidCrystal.h>

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//salida raya
int led6 = 6;
//salida punto
int led7 = 7;
//variable para almacenar la entrada
String read;
//variable auxiliar para entrada decodificada
String inputDecod;


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
  while (Serial.available() == 0) {
    lcd.clear();
  }
  read = Serial.readString();
  lcd.print(read);

  inputDecod = decoder(read);
  for (int i = 0; i < inputDecod.length(); i++) {
    if (i >= 16) {
      //empty();
      lcd.setCursor(i, 1);
      lcd.scrollDisplayLeft();
      
    } else {
      lcd.setCursor(i, 1);
    }
    lcd.print(inputDecod.charAt(i));
    player(inputDecod.charAt(i));
  }
}


//param: the string read from the keyboard.
//pre: true
//pos: a string containing the decoded message in Morse code.
String decoder(String s) {
  String res = "";
  for (int i = 0; i < s.length(); i++) {
    res = res + matchLetters(s.charAt(i));
  }
  return res;
}

//param: the character current in the string to decode.
//pre: true
//pos: a string with the code corresponding to the letter.
String matchLetters(char current) {
  switch (current) {
    case 'a':
      return ".-";
    case 'b':
      return "-...";
    case 'c':
      return "-.-.";
    case 'd':
      return "-..";
    case 'e':
      return ".";
    case 'f':
      return "..-.";
    case 'g':
      return "--.";
    case 'h':
      return "....";
    case 'i':
      return "..";
    case 'j':
      return ".---";
    case 'k':
      return "-.-";
    case 'l':
      return ".-..";
    case 'm':
      return "--";
    case 'n':
      return "-.";
    /*case 'ñ':
      return "--.--";*/
    case 'o':
      return "---";
    case 'p':
      return ".--.";
    case 'q':
      return "--.-";
    case 'r':
      return ".-.";
    case 's':
      return "...";
    case 't':
      return "-";
    case 'u':
      return "..-";
    case 'v':
      return "...-";
    case 'w':
      return ".--";
    case 'x':
      return "-..-";
    case 'y':
      return "-.--";
    case 'z':
      return "--..";
    case '0':
      return "-----";
    case '1':
      return ".----";
    case '2':
      return "..---";
    case '3':
      return "...--";
    case '4':
      return "....-";
    case '5':
      return ".....";
    case '6':
      return "-....";
    case '7':
      return "--...";
    case '8':
      return "---..";
    case '9':
      return "----.";
    case ' ':
      return " ";
  }
  return "ERROR!";
}

//param: an already decoded string.
//pre: true.
//pos: reproduces all the encoded message.
void interpreter(String s) {
  for (int i = 0; i < s.length(); i++) {
    player(s.charAt(i));
  }
}

//param: evaluates the current character in morse code.
//pre: true.
//pos: performs an action for a particular character.
void player(char current) {
  switch (current) {
    case '-':
      digitalWrite(led6, HIGH);
      delay(1000);
      digitalWrite(led6, LOW);
      break;
    case '.':
      digitalWrite(led7, HIGH);
      delay(350);
      digitalWrite(led7, LOW);
      break;
    default:
      delay(3000);
      break;
  }
  delay(1000);
}

void empty() {
  lcd.setCursor(0, 2);
  lcd.print("                ");
  lcd.setCursor(0, 2);
}
