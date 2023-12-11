//libraries we are using 
#include <SD.h>
#include <SPI.h>
#include "RTClib.h"

//clock stuff
RTC_DS3231 rtc;

//this shows where the res is being read, each corresponds with a position on the
//circuit that reads each electric potential so we can find resistance of the thermistor
int InPinMid = A2;
int InPinIn = A0;
int InPinGround= A1;

//create char variable for file name
char fname[] = "mmddhhnn.csv";

//most file stuff is from adafruit SD code examples <3
 File myFile;

void setup() {
  // starts the serial monitor
  Serial.begin(9600);

//starts the clock.. kinda irrelavant in my code but im scared to delete anything in case it stops working entirely 
  rtc.begin();
  //calls make file name function from Dr. Gerbi
  makefname();
  //way to check the makefname code is working. prints the file name to serial monitor 
  Serial.print("fname: ");
  Serial.println(fname);
 
  //put in year,month,day,hour,minute,second, later if clock or count added
  Serial.println("thermistorresistance,thermistortemperature");

//checks that the SD card is in by printing to serial if it failed or not. only helpful on the computer
    pinMode(10, OUTPUT);
  if (!SD.begin(10)) {
    Serial.println("initialization failed!");
    return;
  }
  Serial.println("initialization done.");

  

  //print the file header to the file
  myFile = SD.open(fname, FILE_WRITE);
  //year,month,day,hour,minute,second, later if clock or count added
  myFile.println("thermistorresistance,thermistortemperature");
  myFile.close(); //closes file


}

void loop() {
  float restemp=resfunc(InPinIn,InPinMid,InPinGround); //finds the resistance of 
  //an unknown resistor
  float temp= gettemp(restemp); //uses the calculated resistance and finds temperature
  print2serial(restemp,temp); //prints resistance and temperature to serial monitor
  writeSD(restemp,temp); //prints resistance and temperature to a file on the SD card
  delay(1000); //1 second delay

}
