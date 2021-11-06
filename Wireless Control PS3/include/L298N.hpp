#ifndef L298N_HPP
#define L298N_HPP
#include <Arduino.h>

class L298N{

private:
    int _ENA;
    int _ENB;
    int _IN1;
    int _IN2;
    int _IN3;
    int _IN4;

public:

    L298N(int ENA, int ENB, int IN1, int IN2, int IN3, int IN4){
        _ENA = ENA;
        _ENB = ENB;
        _IN1 = IN1;
        _IN2 = IN2;
        _IN3 = IN3;
        _IN4 = IN4;
    }

    void init(){
        pinMode(_ENA, OUTPUT);
        pinMode(_ENB, OUTPUT);
        pinMode(_IN1, OUTPUT);
        pinMode(_IN2, OUTPUT);
        pinMode(_IN3, OUTPUT);
        pinMode(_IN4, OUTPUT);
    }

    void safeStart(){
        digitalWrite(_IN1, LOW); 
        digitalWrite(_IN2, LOW);
        digitalWrite(_IN3, LOW);
        digitalWrite(_IN4, LOW);
        digitalWrite(_ENA, LOW);
        digitalWrite(_ENB, LOW);
    }

    void clockwise(){
        digitalWrite(_IN1, LOW); 
        digitalWrite(_IN2, HIGH);
        digitalWrite(_IN3, LOW);
        digitalWrite(_IN4, HIGH);
    }

        void antiClockwise(){
        digitalWrite(_IN1, HIGH); 
        digitalWrite(_IN2, LOW);
        digitalWrite(_IN3, HIGH);
        digitalWrite(_IN4, LOW);
    }

    void motorPower1(int ENA, int pwm){
        analogWrite(ENA, pwm);
    }

    void motorPower2(int ENB, int pwm){
        analogWrite(ENB, pwm);
    }

};


#endif