

#ifndef MotorDC_h
#define MotorDC_h

#define STOP 0
#define SOFT_START 1
#define SMOOTH_STOP 2
#define START 3

#include <Arduino.h>

class MotorDC
{
private:
    /* data */
    uint8_t STATUS;
    uint8_t forwardPin;
    uint8_t reversePin;
    uint8_t pwmPin;
    uint8_t tempPin;
    uint8_t pwmDutyMax;
    uint8_t pwmDutyMin;
    uint8_t pwmDuty;
    uint8_t dir;
    uint8_t lastSpeed;
    uint8_t newSpeed;
    int timeIn;
    int timeOut;
    int timeSmooth = 2000;
    unsigned long fadeTime;

public:
    MotorDC(uint8_t forwardPin, uint8_t reversePin, uint8_t pwmPin);
    MotorDC(uint8_t forwardPin, uint8_t reversePin, uint8_t pwmPin, uint8_t tempPin);
    void runMotor(uint8_t dir, uint8_t lastSpeed);
    void setSpeed(uint8_t lastSpeed);
    void stopMotor(void);
    void dc_break(void);
    void soft_start(uint8_t dir, uint8_t speed, int time);
    void smooth_stop(int timeOut);
    uint8_t speedToPWM(uint8_t speed);
    void setPWM(uint8_t pwm);
    void speedChangeOverTime(uint8_t lastSpeed, uint8_t newSpeed, uint16_t changeTime);
};

#endif