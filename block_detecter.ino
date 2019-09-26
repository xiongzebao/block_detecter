 // Visual Micro is in vMicro>General>Tutorial Mode
// 
/*
    Name:       block_detecter.ino
    Created:	2019/9/26 11:49:22
    Author:     lenovo-PC\lenovo
*/

 
#include <MsTimer2.h>

int tick = 0;
int oldTick = 0;
int pinInterrupt = 2; //���ж��źŵĽ�
int blockTimes = 0;
int beepTimes = 0;

bool isStopPrint = false;


int pinBeep = 4;
int pinSwitch = 5;


void stopPrint() {
	isStopPrint = true;
	
}

void stopBeep() {

}

void startBeep() {

}



void onTimer() {
	if (!isStopPrint) {
		if (oldTick == tick) {
			blockTimes++;
			if (blockTimes == 2) {
				stopPrint();
				startBeep();
			}
			return;
		}
		oldTick = tick;
		return;
	} 

	if (beepTimes == 2) {
		stopBeep();
		MsTimer2::stop();
	}
	else {
		beepTimes++;
	}
}

void onTick() {
	tick++;
	if (tick == 10) {
		MsTimer2::start(); //��ʼ��ʱ

	}
}


void setup()
{
	Serial.begin(9600); //��ʼ������
	pinMode(pinInterrupt, INPUT); 
	pinMode(pinBeep, OUTPUT);
	pinMode(pinSwitch, OUTPUT);

   //Enable�жϹܽ�, �жϷ������ΪonChange(), �������ű仯
	attachInterrupt(digitalPinToInterrupt(pinInterrupt), onTick, FALLING);
	MsTimer2::set(10000, onTimer); //�����жϣ�ÿ1000ms����һ���жϷ������ onTimer()
}

// Add the main program code into the continuous loop() function
void loop()
{


}
