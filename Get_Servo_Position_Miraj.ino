#include <SPI.h>
#include <SD.h>
#include <Servo.h>

const int  cs = 4;

int pos = 0;

Servo myservo;
//File datafile;
String buffer;

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
  File dataFile = SD.open ("servopon.txt");

  if (dataFile)
  {
    while (dataFile.available ())
    {
      buffer = dataFile.readStringUntil ('\n');

      Serial.println (buffer);

      myservo.write (buffer.toInt ());
      delay (15);
    }

    dataFile.close();

  }

  else 
  {
    Serial.println ("error connection");
  }
}
