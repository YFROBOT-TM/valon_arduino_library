/*
 *  @file YFValon.h
 *
 *  This is a library for Valon-I.
 *
 *  Designed specifically to work with the Yfrobot Valon-I.
 *
 *  BSD license, all text above must be included in any redistribution
 */

#ifndef _YFValon_H
#define _YFValon_H

#include <Arduino.h>

#define LEFTMOTOR_DIR 4
#define LEFTMOTOR_PWM 5
#define RIGHTMOTOR_DIR 9
#define RIGHTMOTOR_PWM 6
#define LEFTEncoderRXOR 2
#define LEFTEncoderRB 7
#define RIGHTEncoderRXOR 3
#define RIGHTEncoderRB 8

#define BUZZERPIN 11
#define ULTRASONIC_TRIG 12
#define ULTRASONIC_ECHO 13

#define RGBLEDPIN 13

#define LED_D1 0
#define LED_D2 1

#define VBATPIN A7

#define LINESENSOR_1 A0
#define LINESENSOR_2 A1
#define LINESENSOR_3 A2
#define LINESENSOR_4 A3
#define LINESENSOR_5 A6
#define EMITTER_PIN 10


/*!
 *  @brief  Class that stores state and functions for interacting with TB6612
 * PWM chip
 */
class YFValon {
 public:
  init();
  void led();

  void setMotor(int16_t speedA, int16_t speedB);   // 驱动电机

 private:
  int8_t _OFFSETL;
  int8_t _OFFSETR;
};

#endif