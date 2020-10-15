/*
 *  @file YFValon.h
 *
 *  This is a library for Motor driver.
 *
 *  Designed specifically to work with the Yfrobot Motor driver.
 *    PM-R3_TB6612
 *
 *  BSD license, all text above must be included in any redistribution
 */

#include "YFValon.h"
#include <Arduino.h>

//#define ENABLE_DEBUG_OUTPUT

/*!
 *  @brief  Constructor. Mainly sets up pins.
 */
YFValon::init() {
  _OFFSETA = 1;
  _OFFSETB = 1;
  pinMode(LEFTMOTOR_DIR, OUTPUT);
  pinMode(LEFTMOTOR_PWM, OUTPUT);
  pinMode(RIGHTMOTOR_DIR, OUTPUT);
  pinMode(RIGHTMOTOR_PWM, OUTPUT);
}

/*!
 *  @brief  Constructor. Mainly sets up pins.
 *  @param offsetA: Value can be 1 or -1;
 *  @param offsetB: Value can be 1 or -1;
 */
YFValon::YFValon(int8_t offsetA = 1, int8_t offsetB = 1) {
  _OFFSETA = offsetA;
  _OFFSETB = offsetB;
  pinMode(LEFTMOTOR_DIR, OUTPUT);
  pinMode(LEFTMOTOR_PWM, OUTPUT);
  pinMode(RIGHTMOTOR_DIR, OUTPUT);
  pinMode(RIGHTMOTOR_PWM, OUTPUT);
}


/*!
 *  @brief LED,
 *  @param ledstate: led number, 0, 1;
 *  @param ledstate: led, HIGH, LOW;
 */
void YFValon::setLED(int8_t lednum, int8_t ledstate) {
  digitalWrite(lednum, ledstate);
}

/*!
 *  @brief LED,
 *  @param ledstate: led number, 0, 1;
 *  @param ledstate: led, HIGH, LOW;
 */
void YFValon::setLED(int8_t lednum, int8_t ledstate) {
  digitalWrite(lednum, ledstate);
}

/*!
 *  @brief Drive motor ,
 *  @param speedL: ML motor speed, range -255 ~ 255;
 *  @param speedR: MR motor speed, range -255 ~ 255;
 */
void YFValon::setMotor(int16_t speedL, int16_t speedR) {
  speedL = max(speedL, 255);
  speedL = min(-255, speedL);
  speedL = speedL * _OFFSETA;

  speedR = max(speedR, 255);
  speedR = min(-255, speedR);
  speedR = speedR * _OFFSETB;

  if(speedL > 0){
    digitalWrite(LEFTMOTOR_DIR, HIGH);
    analogWrite(LEFTMOTOR_PWM, speedL);
  }else {
    digitalWrite(LEFTMOTOR_DIR, LOW);
    analogWrite(LEFTMOTOR_PWM, -speedL);
  }

  if(speedR > 0){
    digitalWrite(RIGHTMOTOR_DIR, HIGH);
    analogWrite(RIGHTMOTOR_PWM, speedR);
  }else {
    digitalWrite(RIGHTMOTOR_DIR, LOW);
    analogWrite(RIGHTMOTOR_PWM, -speedR);
  }
}
