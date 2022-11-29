/*
 * CRobot.h
 *
 *  Created on: Nov 29, 2022
 *      Author: sophiasouvi
 */
#include "Arduino.h"


class CRobot
{
	String name1, name2;
	int fwd0, fwd1;
public:
	CRobot(String a, String b, int c, int d)
	{
		name1 = a;
		name2 = b;
		fwd0 = c;
		fwd1 = d;

	}
	void fwdUntil()
	{

		EmoroServo.write(SERVO_0, fwd0);
		EmoroServo.write(SERVO_1, fwd1);

	}
	void turnRight()
	{
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1400);
		EmoroServo.write(SERVO_1, 1400);
				while (Gyr.readDegreesZ() < 90 )
					{

						delay(100);
					}
		EmoroServo.write(SERVO_0, fwd0);
		EmoroServo.write(SERVO_1, fwd1);
	}
	void turnLeft()
	{
		Gyr.resetDegrees();
		EmoroServo.write(SERVO_0,1600);
		EmoroServo.write(SERVO_1, 1600);
		delay(100);
				while (Gyr.readDegreesZ() > 270 )
					{

							delay(100);
					}
		EmoroServo.write(SERVO_0, fwd0);
		EmoroServo.write(SERVO_1, fwd1);
	}
};



