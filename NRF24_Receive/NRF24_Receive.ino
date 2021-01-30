#include <RF24_config.h>
#include <RF24.h>
#include <printf.h>
#include <nRF24L01.h>

unsigned long appTime;
unsigned long timer = 0;
RF24 radio(7,8);
const byte address[6] = "00101";

void setup() {
	Serial.begin(9600);
	radio.begin();
	printf_begin();
	radio.openReadingPipe(0, address);
	
	radio.setPALevel(RF24_PA_MAX);
	radio.startListening();
	radio.printDetails();
	Serial.println("NRF2401 receiver");
	Serial.println("waiting...");
	appTime = millis();
}

void loop() {
	unsigned long dt = millis() - appTime;
	appTime = millis();

	timer += dt;

	//if (timer > 1000.0) {
	//	timer = 0;
	//	Serial.println("1 sec. is passed!");
	//}
	if (radio.available()) {
		char text[32] = "";
		radio.read(&text, sizeof(text));
		Serial.println(text);
	}
}
