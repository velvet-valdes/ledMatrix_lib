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
		void downHorizontal(int maxCount, int time);
		void upHorizontal(int maxCount, int time);
		void downLeft(int maxCount, int time);
		void upRight(int maxCount, int time);
		void upLeft(int maxCount, int time);
		void downRight(int maxCount, int time);
		void snakeDown(int maxCount, int time);
		void snakeUp(int maxCount, int time);
		void randomOne(int maxCount, int time);
		void randomTwo(int maxCount, int time);
		void randomThree(int maxCount, int time);
		void blinkRed(int maxCount, int time);
		void blinkWhite(int maxCount, int time);
		void rowDown(int maxCount, int time);
		void rowUp(int maxCount, int time);
		void blinkSingleWhiteDown(int maxCount, int time);
		void blinkSingleRedDown(int maxCount, int time);
		void blinkSingleWhiteUp(int maxCount, int time);
		void blinkSingleRedUp(int maxCount, int time);
		void turnOnAllButOne(int maxCount, int time);
		void turnOnAllButTwo(int maxCount, int time);
		void test(int maxCount, int time);
		void test_downHorizontal(int maxCount, int time);
		void test_upHorizontal(int maxCount, int time);
				
	// private interface
	private:
	
		int _bankFloat;
		int _bankCount;
		int _ledState;
		int _cycleState;	// boolean to determine if the ON OFF cycle is complete
		int _subState; 		// working integer for the boolean determination
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
		long _dwell;
	
		
};

#endif

