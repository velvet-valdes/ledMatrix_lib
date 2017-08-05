/*
  LedMatrix.h - A Library I made to learn how to make libraries.
  This drives a 2x4 LED matrix with animation functions
*/

// ensure this library description is only included once

#ifndef LedMatrix_h
#define LedMatrix_h

#include "Arduino.h"

// library interface description

class Matrix {
    // public interface
  public:

    Matrix(int bank01, int bank02, int bank03, int bank04, int bank05, int bank06, int bank07, int bank08);
    void turnOn();
    void turnOff();
    void turnOnAll();
    void turnOffAll();
    void downHorizontal(int maxCount, int onTime, int offTime);
    void upHorizontal(int maxCount, int onTime, int offTime);
    void downLeft(int maxCount, int onTime, int offTime);
    void upRight(int maxCount, int onTime, int offTime);
    void upLeft(int maxCount, int onTime, int offTime);
    void downRight(int maxCount, int onTime, int offTime);
    void snakeDown(int maxCount, int onTime, int offTime);
    void snakeUp(int maxCount, int onTime, int offTime);
    void randomOne(int maxCount, int onTime, int offTime);
    void randomTwo(int maxCount, int onTime, int offTime);
    void randomThree(int maxCount, int onTime, int offTime);
    void blinkRed(int maxCount, int onTime, int offTime);
    void blinkWhite(int maxCount, int onTime, int offTime);
    void rowDown(int maxCount, int onTime, int offTime);
    void rowUp(int maxCount, int onTime, int offTime);
    void blinkSingleWhiteDown(int maxCount, int onTime, int offTime);
    void blinkSingleRedDown(int maxCount, int onTime, int offTime);
    void blinkSingleWhiteUp(int maxCount, int onTime, int offTime);
    void blinkSingleRedUp(int maxCount, int onTime, int offTime);
    void cycleBackwardAlpha(int maxCount, int onTime, int offTime);
    void cycleBackwardBravo(int maxCount, int onTime, int offTime);
    void cycleForwardAlpha(int maxCount, int onTime, int offTime);
    void cycleForwardBravo(int maxCount, int onTime, int offTime);
    void sweepUpRight(int maxCount, int onTime, int offTime);
    void sweepDownRight(int maxCount, int onTime, int offTime);
    void sweepUpLeft(int maxCount, int onTime, int offTime);
    void sweepDownLeft(int maxCount, int onTime, int offTime);
    void sweepRowUp(int maxCount, int onTime, int offTime);
    void sweepRowDown(int maxCount, int onTime, int offTime);

    // private interface
  private:

    int _bankFloat;
    int _bankCount;
    int _ledState;
    int _cycleState;  // variable to determine if the ON OFF cycle is complete
    int _subState;    // counter for the components of state completion
    int _animationCount;  // counter for the animation function completion
    int _bank01;
    int _bank02;
    int _bank03;
    int _bank04;
    int _bank05;
    int _bank06;
    int _bank07;
    int _bank08;
    unsigned long _previousMillis;
    unsigned long _currentMillis;
    long _onTime;
    long _offTime;
};

#endif

