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
    void downHorizontal(int maxCount, int time); // testing
    void upHorizontal(int maxCount, int time); // testing
    void downLeft(int maxCount, int time); // testing
    void upRight(int maxCount, int time); // testing
    void upLeft(int maxCount, int time); // testing
    void downRight(int maxCount, int time); // testing
    void snakeDown(int maxCount, int time); // testing
    void snakeUp(int maxCount, int time); // testing
    void randomOne(int maxCount, int time); // testing
    void randomTwo(int maxCount, int time); // testing
    void randomThree(int maxCount, int time); // testing
    void blinkRed(int maxCount, int time); // testing
    void blinkWhite(int maxCount, int time); // testing
    void rowDown(int maxCount, int time); // testing
    void rowUp(int maxCount, int time); // testing
    void blinkSingleWhiteDown(int maxCount, int time); // testing
    void blinkSingleRedDown(int maxCount, int time); // testing
    void blinkSingleWhiteUp(int maxCount, int time); // testing
    void blinkSingleRedUp(int maxCount, int time); // testing
    void turnOnAllButOne(int maxCount, int time);
    void turnOnAllButTwo(int maxCount, int time);
    void test(int maxCount, int time);
    void test_downHorizontal(int maxCount, int onTime, int offTime);
    void test_upHorizontal(int maxCount, int onTime, int offTime);
    void test_rowUp(int maxCount, int onTime, int offTime);
    void test_rowDown(int maxCount, int onTime, int offTime);
    void test_downLeft(int maxCount, int onTime, int offTime);
    void test_downRight(int maxCount, int onTime, int offTime);
    void test_upRight(int maxCount, int onTime, int offTime);
    void test_upLeft(int maxCount, int onTime, int offTime);
    void test_snakeDown (int maxCount, int onTime, int offTime);
    void test_snakeUp (int maxCount, int onTime, int offTime);
    void test_randomOne(int maxCount, int onTime, int offTime);
    void test_randomTwo(int maxCount, int onTime, int offTime);
    void test_randomThree(int maxCount, int onTime, int offTime);
    void test_blinkSingleWhiteDown(int maxCount, int onTime, int offTime);
    void test_blinkSingleWhiteUp(int maxCount, int onTime, int offTime);
    void test_blinkSingleRedUp(int maxCount, int onTime, int offTime);
    void test_blinkSingleRedDown(int maxCount, int onTime, int offTime);
    void test_blinkRed(int maxCount, int onTime, int offTime);
    void test_blinkWhite(int maxCount, int onTime, int offTime);

    // private interface
  private:

    int _bankFloat;
    int _bankCount;
    int _ledState;
    int _cycleState;  // variable to determine if the ON OFF cycle is complete
    int _subState;    // counter for the components of state completion
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

