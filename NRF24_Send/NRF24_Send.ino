#include <RF24.h>
#include <RF24_config.h>
#include <printf.h>
#include <nRF24L01.h>

RF24 radio(7,8);
const byte address[6] = "00101";

int count = 0;

void setup() {
	Serial.begin(9600);
	radio.begin();					//初始化 nRF24L01摸組
	radio.openWritingPipe(address);	//開始寫入管線
	radio.setPALevel(RF24_PA_MAX);	//設為低功率
	radio.stopListening();			//傳送端不需接收
//  radio.printDetails();
}

void loop() {
	char text[32];
	sprintf(text, "Hello World %d", count);
//	Serial.println(text);

	radio.write(&text, sizeof(text));
	count++;
	delay(2000);
}
