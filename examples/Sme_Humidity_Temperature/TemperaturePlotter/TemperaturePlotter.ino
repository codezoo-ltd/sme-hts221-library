/*
   This example is designed to be used with the Arduino 1.6.6+ IDE Serial Plotter.
   Place the sensor near a heat source or a fan and you will see the temperature change in real time.

   From http://www.st.com/web/en/resource/technical/document/datasheet/DM00116291.pdf
   The HTS221 is an ultra compact sensor for relative humidity and temperature. It includes a
   sensing element and a mixed signal ASIC to provide the measurement information through
   digital serial interfaces.
   The sensing element consists of a polymer dielectric planar capacitor structure capable of
   detecting relative humidity variations.
 */
#include <Wire.h>
#include <HTS221.h>
#include <Arduino.h>

#define SerialUSB Serial
#define NB_IOT_LED  4

double temperature;
unsigned int pollingInterval = 1000; // in milliseconds

// The setup function runs once when you press reset or power the board
void setup() {
	Wire.begin();
	pinMode(NB_IOT_LED, OUTPUT);

	if (!smeHumidity.begin()) { // led ON if there is an error initializing the sensor
		digitalWrite(NB_IOT_LED, HIGH);
	}
	else {
		digitalWrite(NB_IOT_LED, LOW);
	}
	SerialUSB.begin(9600);
}

// The loop function runs over and over again forever
void loop() {
	// The value is returned in Celsius
	temperature = smeHumidity.readTemperature();
	SerialUSB.println(temperature);
	delay(pollingInterval);
}

