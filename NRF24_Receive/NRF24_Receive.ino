#include <RF24_config.h>
#include <RF24.h>
#include <printf.h>
#include <nRF24L01.h>

RF24 radio(7,8);
const byte address[6] = "00001";

void setup() {
	Serial.begin(9600);
	printf_begin();
	radio.openReadingPipe(0, address);
	radio.setPALevel(RF24_PA_MIN);
	radio.startListening();
	radio.printDetails();
	Serial.println("NRF2401 receiver");
	Serial.println("waiting...");
}

void loop() {
	if (radio.available()) {
		char text[32] = "";
		radio.read(&text, sizeof(text));
		Serial.println(text);
	}
}
