#include <RF24_config.h>
#include <RF24.h>
#include <printf.h>
#include <nRF24L01.h>

unsigned long appTime;
unsigned long timer = 0;
RF24 radio(7, 8);
const byte address[][6] = {"QWE","ASD"};
const byte address0[6] = "00005";
void setup() {
//	Serial.begin(115200);
//	radio.begin();
//	printf_begin();
//	radio.setPALevel(RF24_PA_MAX);
//	
//	radio.openWritingPipe(address[1]);
//	radio.openReadingPipe(0, address[0]);
//	
//	
//	radio.startListening();
//	radio.printDetails();
//	Serial.println("NRF2401 receiver");
//	Serial.println("waiting...");
//	appTime = millis();
//
//	pinMode(LED_BUILTIN, OUTPUT);

	Serial.begin(115200);
    radio.begin();
    printf_begin();
    // Set the PA Level low to prevent power supply related issues since this is a
    // getting_started sketch, and the likelihood of close proximity of the devices. RF24_PA_MAX is default.
    radio.setPALevel(RF24_PA_LOW);
    
    // Open a writing and reading pipe on each radio, with opposite addresses
//    radio.openWritingPipe(address0);
    radio.openReadingPipe(1,address[0]);
    radio.printDetails();
    radio.startListening();
}

void loop() {
//	unsigned long dt = millis() - appTime;
//	appTime = millis();
//	if (timer > 0){
//		timer -= dt;
//	}
//  
//	if (timer <= 0) {
//		timer = 0;
//	}
//
//	uint8_t pipe;
//	if (radio.available(&pipe)) {
//		char text[32] = "";
//		radio.read(&text, sizeof(text));
//		timer = 1.0;
//		Serial.println(text);
//		//Serial.print(F(" bytes on pipe "));
//		//Serial.print(pipe);
//	}
}
