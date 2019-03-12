/*
   humidity.cpp

   Example on SmartEverything humidity / temperature sensor reading

Created: 4/27/2015 10:32:11 PM
Author: speirano
 */

#include <Wire.h>
#include <Arduino.h>
#include <HTS221.h>

#define SerialUSB Serial
#define NB_IOT_LED  4

// the setup function runs once when you press reset or power the board
void setup() {
	//Initiate the Wire library and join the I2C bus
	Wire.begin();
	pinMode(NB_IOT_LED, OUTPUT);

	smeHumidity.begin();
	SerialUSB.begin(9600);
}

// the loop function runs over and over again forever
void loop() {

	double data = 0;

	data = smeHumidity.readHumidity();
	SerialUSB.print("Humidity   : ");
	SerialUSB.print(data);
	SerialUSB.println(" %");

	data = smeHumidity.readTemperature();
	SerialUSB.print("Temperature: ");
	SerialUSB.print(data);
	SerialUSB.println(" celsius");

	digitalWrite(NB_IOT_LED, LOW);
	delay(300);

	digitalWrite(NB_IOT_LED, HIGH);       // turn the LED on
	delay(700);              // wait for a second

}
