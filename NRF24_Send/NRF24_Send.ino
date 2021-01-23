#include <RF24.h>
#include <RF24_config.h>
#include <printf.h>
#include <nRF24L01.h>

RF24 radio(7,8);
const byte address[6] = "00101";

int count = 0;

void setup() {
	Serial.begin(9600);
	radio.begin();					//��l�� nRF24L01�N��
	radio.openWritingPipe(address);	//�}�l�g�J�޽u
	radio.setPALevel(RF24_PA_MIN);	//�]���C�\�v
	radio.stopListening();			//�ǰe�ݤ��ݱ���
}

void loop() {
	char text[32];
	sprintf(text, "Hello World %d", count);
	Serial.println(text);

	radio.write(&text, sizeof(text));
	count++;
	delay(1000);
}
