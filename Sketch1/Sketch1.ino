#include <Servo.h>

Servo theServo; 				

int pos = 10;    
int pushButton = 2;
int clicks = 0;

void setup()
{
	Serial.begin(9600);
	theServo.attach(9);  
	pinMode(pushButton, INPUT_PULLUP);	
}

void loop() {
	int buttonState = digitalRead(pushButton);
	if (buttonState == 0 && pos <= 160) {
		clicks = clicks + 1;
		Serial.print("Clicks: ");
		Serial.println(clicks);
		pos = map(clicks, 0, 29, 15, 160);
		theServo.write(pos);              
		delay(100);
	}
	else if (buttonState == 0) {
		theServo.write(0);   
		clicks = 0;
		pos = 10;
		delay(100);
	}
}