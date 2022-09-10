

class Mover
{
private:
    /* data */

    byte pwmDutyMin;
    byte pwmDutyMax;
    unsigned int softStartTime;
    unsigned int softStopTime;

public:
    Mover(byte rr, byte rf, byte lr, byte lf, byte pwm_l, byte pwm_r);
    ~Mover();

    SetMinPwmDuty(byte minDutyCycle);
    SetMaxPwmDuty(byte maxDutyCycle);

    StartLeftMotor(int dir, int strength, int startTime)
};

Mover::Mover(byte rr, byte rf, byte lr, byte lf, byte pwm_l, byte pwm_r)
{
}

Mover::~Mover()
{
}
