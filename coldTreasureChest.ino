
// COLD TREASURE CHEST

#include <ServoTimer1.h>

int TempsensorPin = 0; //the analog pin the TMP36's Vout (sense) pin is connected to
                       //the resolution is 10 mV / degree centigrade with a
                       //500 mV offset to allow for negative temperatures

int ledpin = 13;
int ledpin2 = 10;


ServoTimer1 servo1;

void setup()
{
 Serial.begin(9600);  
 pinMode(ledpin, OUTPUT);
 pinMode(ledpin2, OUTPUT);

 
servo1.attach(10);                
}

void loop()                     // run over and over again
{

 
// digitalWrite(ledpin, HIGH);
 
 //getting the voltage reading from the temperature sensor
int reading = analogRead(TempsensorPin);  

// converting that reading to voltage, for 3.3v arduino use 3.3
float voltage = reading * 5.0 / 1024;

// print out the voltage
//Serial.print(voltage); Serial.println(" volts");

// now print out the temperature
float temperatureC = (voltage - 0.5) * 100 ;  //converting from 10 mv per degree wit 500 mV offset
                                              //to degrees ((volatge - 500mV) times 100)
// Serial.print(temperatureC); Serial.println(" degress C");

// now convert to Fahrenheight
float temperatureF = (temperatureC * 9 / 5) + 32;
Serial.print(temperatureF); Serial.println(" degress F");

if (temperatureF <= 65){
  digitalWrite(ledpin2, HIGH);
    //pin 10
} else {
  digitalWrite(ledpin2, LOW);
}

if (temperatureF <= 60){
 //servo1.write(180);
 digitalWrite(ledpin, HIGH);
} else {
  digitalWrite(ledpin, LOW);
}

delay(1000);                                     //waiting a second
}
