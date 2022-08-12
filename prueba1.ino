#include <Ultrasonic.h>
Ultrasonic ultrasonic(5,6);
#include <SPI.h>
#include <SD.h>
File datafile;



void setup()
{  

  Serial.begin(9600);    
while (!Serial) {
    ; // 
  }

  if (!SD.begin(4)) {
    Serial.println("iniciacion fallida!");
    while (1);
  }
  Serial.println("iniciacion exitosa.");


   datafile = SD.open("datalog.txt", FILE_WRITE);
   
  if (datafile) {
    Serial.println("done.");
  } 
  else {
    Serial.println("error abriendo datalog.txt");
  }
 }

void loop()
{
 
String dataString = "";

int t = ultrasonic.distanceRead();
File dataFile = SD.open("datalog.txt", FILE_WRITE); 
if (dataFile) {

dataFile.print("DISTANCIA: ");
dataFile.print(String(t));
 dataFile.println(" CM"); 
  
 dataFile.close(); 
 Serial.print("DISTANCIA: ");
Serial.print(String(t)); 
 Serial.println("CM");



delay(2000); // Cada 2 segundos
} 
else { Serial.println("Error apertura datalog.txt"); 
}  

   
}
