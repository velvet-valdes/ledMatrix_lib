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
		void downHorizontal(int count, int time);
		void upHorizontal(int count, int time);
		void downLeft(int count, int time);
		void upRight(int count, int time);
		void upLeft(int count, int time);
		void downRight(int count, int time);
		void snakeDown(int count, int time);
		void snakeUp(int count, int time);
		void randomOne(int count, int time);
		void randomTwo(int count, int time);
		void randomThree(int count, int time);
		void blinkRed(int count, int time);
		void blinkWhite(int count, int time);
		void rowDown(int count, int time);
		void rowUp(int count, int time);
		void blinkSingleWhiteDown(int count, int time);
		void blinkSingleRedDown(int count, int time);
		void blinkSingleWhiteUp(int count, int time);
		void blinkSingleRedUp(int count, int time);
		void turnOnAllButOne(int count, int time);
		void turnOnAllButTwo(int count, int time);
				
	// private interface
	private:
	
		int _bankFloat;
		int _bankState;
		int _bank01;
		int _bank02;
		int _bank03;
		int _bank04;
		int _bank05;
		int _bank06;
		int _bank07;
		int _bank08;
		
};

#endif

