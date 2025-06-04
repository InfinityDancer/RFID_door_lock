#include <Servo.h>
#include <SPI.h>
#include <RFID.h>


RFID rfid(10, 9); //SDA connected to pin 10, RST to 9
byte password[5] = {
  208,
  74,
  76,
  37,
  243
}; //array with 5 bytes, unique to RFID key

Servo myservo; //represents servo motor
boolean card = false; // initialises card to false, boolean data type

void setup() {
  Serial.begin(9600); //serial port is capable of transferring max 9600 bits/s
  SPI.begin(); // allows you to communicate with SPI devices, with the Arduino as the controller device, send information one by one
  rfid.init(); // initializing the RFID sensor module
  myservo.attach(3); // servo connected to digital pin 3 on UNO
  myservo.write(100); // changes servo angle to 100 degrees
}

void loop()
{
  if (rfid.isCard()) //goes to block statements if value is true
  {
    if (rfid.readCardSerial())
    //checking if the RFID matches the Serial Number of the card 
    {
      Serial.print("Found ID: ");
      for (int i = 0; i < 5; i++)
      {
        Serial.print(rfid.serNum[i]);
        if (i < 4)
            Serial.print(",");
      }
    }

    card = true;
    for (int i = 0; i < 5; i++)
    {
      card = card && (rfid.serNum[i] == password[i]);
      // card is false if any digit does not match.
    }

    if (card)
    {
      Serial.println("Correct Card");
      myservo.write(20);
      delay(15000);
      myservo.write(100);
    }
    
    else
    {
      Serial.println("Wrong Card");
    }

    rfid.halt(); // prevents the RFID module from reading the same card
  }
  else
  {
    Serial.println("No Card");
  }
}
