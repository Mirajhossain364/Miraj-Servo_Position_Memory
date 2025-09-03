#include <SPI.h>
#include <SD.h>
#include <Servo.h>

const int  cs = 4;

int pos = 0;

Servo myservo;
//File datafile;

void setup ()
{
  Serial.begin (9600);
  while(!Serial )
  {
    
  }

  Serial.println ("Initialing SD card For Aust Rocketry!!");
  delay (5000);

  if (!SD.begin (cs))
  {
    Serial.println ("Failed to connect");

    while (1);
  }
  Serial.println ("Card is connected");

  

  myservo.attach (10);
  
}

void loop ()
{
  String dataString = "";

  pos = map (analogRead (A0) , 0 , 1023 , 0 , 180);

  dataString += String (pos);

  myservo . write (pos);
  delay (15);


  File dataFile = SD.open ("servopop.txt" , FILE_WRITE);

  if (dataFile)
  {
    dataFile .println (dataString);
    dataFile.close ();
    Serial.println (dataString);
    
  }

  else 
  {
    Serial.println ("error opening File");
  }
  
}
