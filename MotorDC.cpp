#include "MotorDC.h"

MotorDC::MotorDC(uint8_t forwardPin, uint8_t reversePin, uint8_t pwmPin)
{
	pinMode(forwardPin, OUTPUT);
	pinMode(reversePin, OUTPUT);
	pinMode(pwmPin, OUTPUT);

	digitalWrite(forwardPin, LOW);
	digitalWrite(reversePin, LOW);
	digitalWrite(pwmPin, LOW);

	this->forwardPin = forwardPin;
	this->reversePin = reversePin;
	this->pwmPin = pwmPin;
	// TODO
}

MotorDC::MotorDC(uint8_t forwardPin, uint8_t reversePin, uint8_t pwmPin, uint8_t tempPin)
{
	pinMode(forwardPin, OUTPUT);
	pinMode(reversePin, OUTPUT);
	pinMode(pwmPin, OUTPUT);
	pinMode(tempPin, OUTPUT);

	digitalWrite(forwardPin, LOW);
	digitalWrite(reversePin, LOW);
	digitalWrite(pwmPin, LOW);
	digitalWrite(tempPin, LOW);

	this->forwardPin = forwardPin;
	this->reversePin = reversePin;
	this->pwmPin = pwmPin;
	this->tempPin = tempPin;
	// TODO
}

void MotorDC::runMotor(uint8_t dir, uint8_t lastSpeed)
{
	this->dir = dir;
	if (this->dir == 0)
	{
		/**Forward */
		digitalWrite(forwardPin, HIGH);
	}
	else
	{
		/**Reverse */
		digitalWrite(reversePin, HIGH);
	}
	this->setSpeed(lastSpeed);
}

void MotorDC::setSpeed(uint8_t lastSpeed)
{
	this->lastSpeed = lastSpeed;
	this->setPWM(this->speedToPWM(this->lastSpeed));
	// TODO
}

void MotorDC::stopMotor(void)
{
	// TODO
}

void MotorDC::dc_break(void)
{
	// TODO
}

void MotorDC::soft_start(uint8_t dir, uint8_t speed, int time)
{
	this->dir = dir;
	// this->lastSpeed = newSpeed;
	this->newSpeed = speed;
	this->timeIn = time;
	// TODO

	if (STATUS != SOFT_START)
	{
		STATUS = SOFT_START;
		this->fadeTime = millis();
	}
}

void MotorDC::speedChangeOverTime(uint8_t lastSpeed, uint8_t newSpeed, uint16_t changeTime)
{
	uint16_t time = millis() - this->fadeTime;
	uint8_t pwmMin;
	uint8_t pwmMax;
	uint8_t speed;

	pwmMin = this->speedToPWM(lastSpeed);
	pwmMax = this->speedToPWM(newSpeed);
	if (time <= changeTime)
	{
		speed = map(time, 0, changeTime, PWM_MIN, PWM_MAX);
	}
	else
	{
		PWM_LEFT = PWM_MAX;
		LeftMotorIsOn = true;
	}
	analogWrite(PWM_L, PWM_LEFT);
}

void MotorDC::smooth_stop(int timeOut)
{
	this->timeOut = timeOut;

	// TODO
}

uint8_t MotorDC::speedToPWM(uint8_t speed)
{
	return map(speed, 0, 100, this->pwmDutyMin, this->pwmDutyMax);
}

void MotorDC::setPWM(uint8_t pwm)
{
	this->pwmDuty = pwm;
	analogWrite(this->pwmPin, this->pwmDuty);
}