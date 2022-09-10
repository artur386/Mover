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
	this->lastSpeed = lastSpeed;
}

void MotorDC::setSpeed(uint8_t lastSpeed)
{
	this->lastSpeed = lastSpeed;
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

void MotorDC::soft_start(uint8_t dir, uint8_t lastSpeed, int timeIn)
{
	this->dir = dir;
	this->lastSpeed = lastSpeed;
	this->timeIn = timeIn
	// TODO
}

void MotorDC::smooth_stop(int timeOut)
{
	this->timeOut = timeOut;
	// TODO
}
