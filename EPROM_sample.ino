
#include <EEPROM.h>


void setup() {
 Serial.begin(115200);
 Serial.println("Writing Config");
 EEPROM.begin(512);
  delay(500);

//Clear EEPROM  
// for (int i = 0 ; i < 512 ; i++) {
//    EEPROM.write(i, 0);
//    Serial.println("done");
// }

//write Char
 EEPROM.write(0,'C');
 EEPROM.write(1,'F');
 EEPROM.write(2,'G'); 


if (EEPROM.read(0) == 'C' && EEPROM.read(1) == 'F'  && EEPROM.read(2) == 'G' )
{
    Serial.println("Configurarion Found!");
    Serial.println("Its Ok!");
}

else
Serial.println("Configurarion Not Found!");

//Write String
String name1 = "Ehsan";
WriteStringToEEPROM(64,name1); 
//Read String
 String ss = ReadStringFromEEPROM(64);
Serial.println("eprom write : " + ss);
}

void WriteStringToEEPROM(int beginaddress, String string)
{
  char  charBuf[string.length()+1];
  string.toCharArray(charBuf, string.length()+1);
  for (int t=  0; t<sizeof(charBuf);t++)
  {
      EEPROM.write(beginaddress + t,charBuf[t]);
  }
}
String  ReadStringFromEEPROM(int beginaddress)
{
  byte counter=0;
  char rChar;
  String retString = "";
  while (1)
  {
    rChar = EEPROM.read(beginaddress + counter);
    if (rChar == 0) break;
    if (counter > 31) break;
    counter++;
    retString.concat(rChar);

  }
  return retString;
}
void loop() {
}
