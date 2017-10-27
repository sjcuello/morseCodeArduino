String prueba = "hola";
String result;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  result = decoder(prueba);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(result);
}
//param: the string read from the keyboard.
//pre: true
//pos: a string containing the decoded message in Morse code.
String decoder(String s){
    String res = "";
    for(int i=0;i<s.length();i++){
      res = res + matchLetters(s.charAt(i));
    }
    return res;
}

//param: the character current in the string to decode.
//pre: true
//pos: a string with the code corresponding to the letter.
String matchLetters(char current){
  switch(current){
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
    case 'ñ':
      return "--.--";
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
  }
  return "ERROR!";
}

//
//
//
void interpreter(String s){
  for(int i=0;i<s.length();i++){
    
  }
}

//
//
//
void player(char current){
  switch(current){
    case '-':
    break;
    case '.':
    break;
    default:
    break;
  }
}
