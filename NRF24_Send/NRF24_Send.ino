#include <RF24.h>
#include <RF24_config.h>
#include <printf.h>
#include <nRF24L01.h>

RF24 radio(7, 8);
const byte address[][6] = {"1Node","2Node"};

int count = 0;

void setup() {
	Serial.begin(115200);
	radio.begin();                     //初始化 nRF24L01摸組
	printf_begin();
	
	radio.openWritingPipe(address[1]); //開始寫入管線
	radio.openReadingPipe(1, address[0]);
	radio.setPALevel(RF24_PA_MAX);     //設為低功率
	radio.printDetails();
	
	radio.stopListening();             //傳送端不需接收
	
}

void loop() {
	char text[32];
	sprintf(text, "Hello World %d", count);
	// Serial.println(text);

	radio.write(&text, sizeof(text));
	count++;
	delay(2000);
}
