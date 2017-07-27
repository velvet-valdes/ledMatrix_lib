/*
  	LedMatrix.cpp - A Library I made to learn how to make libraries.
  	This drives a 2x4 LED matrix with animation functions
  	Copyright (c) 2017 Temistocles Valdes.  All right reserved.
*/

#include "Arduino.h"
#include "LedMatrix.h"
	
// Matrix Constructor - We need to define the pins here for the 2x4 matrix

Matrix::Matrix(int bank01, int bank02, int bank03, int bank04, int bank05, int bank06, int bank07, int bank08)

{

	pinMode(bank01, OUTPUT);
	pinMode(bank02, OUTPUT);
	pinMode(bank03, OUTPUT);
	pinMode(bank04, OUTPUT);
	pinMode(bank05, OUTPUT);
	pinMode(bank06, OUTPUT);
	pinMode(bank07, OUTPUT);
	pinMode(bank08, OUTPUT);
	
	// Here is where we hand of the variables that we passed into the object to private variables only available to the object

	_bank01 = bank01;
	_bank02 = bank02;
	_bank03 = bank03;
	_bank04 = bank04;
	_bank05 = bank05;
	_bank06 = bank06;
	_bank07 = bank07;
	_bank08 = bank08;

}

void Matrix::turnOn()

{
	// Turn on the bank assigned to the private floating variable
	digitalWrite(_bankFloat, HIGH);
	
}

void Matrix::turnOff()

{
	// Turn off the bank assigned to the private floating variable
	digitalWrite(_bankFloat, LOW);

}
void Matrix::turnOnAll()

{

	digitalWrite(_bank01, HIGH);
	digitalWrite(_bank02, HIGH);
	digitalWrite(_bank03, HIGH);
	digitalWrite(_bank04, HIGH);
	digitalWrite(_bank05, HIGH);
	digitalWrite(_bank06, HIGH);
	digitalWrite(_bank07, HIGH);
	digitalWrite(_bank08, HIGH); 
	
}

void Matrix::turnOffAll()

{

	digitalWrite(_bank01, LOW);
	digitalWrite(_bank02, LOW);
	digitalWrite(_bank03, LOW);
	digitalWrite(_bank04, LOW);
	digitalWrite(_bank05, LOW);
	digitalWrite(_bank06, LOW);
	digitalWrite(_bank07, LOW);
	digitalWrite(_bank08, LOW);
	
}

void Matrix::downHorizontal(int count, int time)

{

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {
	
		_bankFloat = 1;
	
		for (_bankFloat; _bankFloat < 9 && _bankFloat >= 1; _bankFloat++) {
    
			digitalWrite(_bankFloat, HIGH);
			delay(time);
			digitalWrite(_bankFloat, LOW);
			delay(time);

		}  
	}      
}

void Matrix::upHorizontal(int count, int time)

{
	
	_bankState =0;

	for (_bankState; _bankState < count; _bankState++) {
	
		_bankFloat = 9;
	
		for (_bankFloat; _bankFloat <= 9 && _bankFloat >1; _bankFloat--) {
    
			digitalWrite(_bankFloat, HIGH);
			delay(time);
			digitalWrite(_bankFloat, LOW);
			delay(time);
 
		}     
	}   
}


    
void Matrix::downLeft(int count, int time)

{

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

		_bankFloat = 1;

		for (_bankFloat; _bankFloat < 9 && _bankFloat >= 1; _bankFloat++) {
    
			if ((_bankFloat % 2) == 0) {
      
				digitalWrite(_bankFloat, HIGH);      
				delay(time);      
				digitalWrite(_bankFloat, LOW);      
				delay(time);

			}        
		}
	}
}

void Matrix::upRight(int count, int time)

{

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {
	    
		_bankFloat = 9;
	    
		for (_bankFloat; _bankFloat <= 9 && _bankFloat > 1; _bankFloat--) {
    
			if ((_bankFloat % 2) != 0) {
      
				digitalWrite(_bankFloat, HIGH);
				delay(time);
				digitalWrite(_bankFloat, LOW);
				delay(time);
      
			}
		}
	}
}


void Matrix::upLeft(int count, int time)

{

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

		_bankFloat = 9;
	
		for (_bankFloat; _bankFloat <= 9 && _bankFloat > 1; _bankFloat--) {
    
			if ((_bankFloat % 2) == 0) {
      
				digitalWrite(_bankFloat, HIGH);      
				delay(time);      
				digitalWrite(_bankFloat, LOW);      
				delay(time);
        
			}
		}      
	}
}

void Matrix::downRight(int count, int time)

{
	
	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

		_bankFloat = 2;
		
		for (_bankFloat; _bankFloat <= 9 && _bankFloat >= 1; _bankFloat++) {
    
			if ((_bankFloat % 2) != 0) {
      
				digitalWrite(_bankFloat, HIGH);
				delay(time);
				digitalWrite(_bankFloat, LOW);
				delay(time);

			}      
		}
	}
}



void Matrix::snakeDown(int count, int time)

{

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

		_bankFloat = 1;
	
		for (_bankFloat; _bankFloat < 9 && _bankFloat >= 1; _bankFloat++) {
    
			digitalWrite(_bankFloat, HIGH);
			digitalWrite(_bankFloat+1, HIGH);
			delay(time);
			digitalWrite(_bankFloat+2, HIGH);
			delay(time);
			digitalWrite(_bankFloat, LOW);
			digitalWrite(_bankFloat+1,LOW);

		}  
	}
}

void Matrix::snakeUp(int count, int time)

{
	
	_bankState = 0;
	
	for (_bankState; _bankState < count; _bankState++) {
	
		_bankFloat = 9;
	
		for (_bankFloat; _bankFloat <= 9 && _bankFloat > 1; _bankFloat--) {
    
      		digitalWrite(_bankFloat, HIGH);
      		digitalWrite(_bankFloat-1, HIGH);
      		delay(time);
      		digitalWrite(_bankFloat-2, HIGH);
      		delay(time);
      		digitalWrite(_bankFloat, LOW);
      		digitalWrite(_bankFloat-1,LOW);
      
      	}
	}   
}

void Matrix::randomOne(int count, int time)

{

	_bankState = 0;
	
	for (_bankState; _bankState < count; _bankState++) {
	
		_bankFloat = random(2,9);
		digitalWrite(_bankFloat, HIGH);
		delay(time);
		digitalWrite(_bankFloat, LOW);
		delay(time);
	
	}	
}	

void Matrix::randomTwo(int count, int time)

{

	_bankState = 0;
	
	for ( _bankState; _bankState < count; _bankState++) {
	 
		_bankFloat = random(2,9);
		digitalWrite(_bankFloat, HIGH);
		digitalWrite(_bankFloat+1, HIGH);
		delay(time);
		digitalWrite(_bankFloat, LOW);
		digitalWrite(_bankFloat+1, LOW);
		delay(time);
	}
}	

void Matrix::randomThree(int count, int time)

{

	_bankState = 0;
	
	for ( _bankState; _bankState < count; _bankState++) {
	 
		_bankFloat = random(2,9);
		digitalWrite(_bankFloat, HIGH);
		delay(time);
		
		_bankFloat = random(2,9);
		digitalWrite(_bankFloat, LOW);
		delay(time);
	}
}

void Matrix::blinkRed(int count, int time) {

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

	digitalWrite(_bank01, LOW);
	digitalWrite(_bank02, HIGH);
	digitalWrite(_bank03, HIGH);
	digitalWrite(_bank04, LOW);
	digitalWrite(_bank05, LOW);
	digitalWrite(_bank06, HIGH);
	digitalWrite(_bank07, HIGH);
	digitalWrite(_bank08, LOW);
	delay(time);
	digitalWrite(_bank01, LOW);
	digitalWrite(_bank02, LOW);
	digitalWrite(_bank03, LOW);
	digitalWrite(_bank04, LOW);
	digitalWrite(_bank05, LOW);
	digitalWrite(_bank06, LOW);
	digitalWrite(_bank07, LOW);
	digitalWrite(_bank08, LOW);
	delay(time);

	}	
}

void Matrix::blinkWhite(int count, int time) {

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

    	digitalWrite(_bank01, HIGH);
    	digitalWrite(_bank02, LOW);
    	digitalWrite(_bank03, LOW);
    	digitalWrite(_bank04, HIGH);
    	digitalWrite(_bank05, HIGH);
    	digitalWrite(_bank06, LOW);
    	digitalWrite(_bank07, LOW);
    	digitalWrite(_bank08, HIGH);
    	delay(time);
    	digitalWrite(_bank01, LOW);
    	digitalWrite(_bank02, LOW);
    	digitalWrite(_bank03, LOW);
    	digitalWrite(_bank04, LOW);
    	digitalWrite(_bank05, LOW);
    	digitalWrite(_bank06, LOW);
    	digitalWrite(_bank07, LOW);
    	digitalWrite(_bank08, LOW);
    	delay(time);

	}	
}

void Matrix::rowDown(int count, int time) {

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

		digitalWrite(_bank01, HIGH);
		digitalWrite(_bank02, HIGH);
		digitalWrite(_bank03, LOW);
		digitalWrite(_bank04, LOW);
		digitalWrite(_bank05, LOW);
		digitalWrite(_bank06, LOW);
		digitalWrite(_bank07, LOW);
		digitalWrite(_bank08, LOW);
		delay(time);
		digitalWrite(_bank01, LOW);
		digitalWrite(_bank02, LOW);
		digitalWrite(_bank03, HIGH);
		digitalWrite(_bank04, HIGH);
		digitalWrite(_bank05, LOW);
		digitalWrite(_bank06, LOW);
		digitalWrite(_bank07, LOW);
		digitalWrite(_bank08, LOW);
		delay(time);
		digitalWrite(_bank01, LOW);
		digitalWrite(_bank02, LOW);
		digitalWrite(_bank03, LOW);
		digitalWrite(_bank04, LOW);
		digitalWrite(_bank05, HIGH);
		digitalWrite(_bank06, HIGH);
		digitalWrite(_bank07, LOW);
		digitalWrite(_bank08, LOW);
		delay(time);
		digitalWrite(_bank01, LOW);
		digitalWrite(_bank02, LOW);
		digitalWrite(_bank03, LOW);
		digitalWrite(_bank04, LOW);
		digitalWrite(_bank05, LOW);
		digitalWrite(_bank06, LOW);
		digitalWrite(_bank07, HIGH);
		digitalWrite(_bank08, HIGH);
		delay(time);
		digitalWrite(_bank07, LOW);
		digitalWrite(_bank08, LOW);

	}
}

void Matrix::rowUp(int count, int time) {

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

		digitalWrite(_bank01, LOW);
		digitalWrite(_bank02, LOW);
		digitalWrite(_bank03, LOW);
		digitalWrite(_bank04, LOW);
		digitalWrite(_bank05, LOW);
		digitalWrite(_bank06, LOW);
		digitalWrite(_bank07, HIGH);
		digitalWrite(_bank08, HIGH);
		delay(time);
		digitalWrite(_bank01, LOW);
		digitalWrite(_bank02, LOW);
		digitalWrite(_bank03, LOW);
		digitalWrite(_bank04, LOW);
		digitalWrite(_bank05, HIGH);
		digitalWrite(_bank06, HIGH);
		digitalWrite(_bank07, LOW);
		digitalWrite(_bank08, LOW);
		delay(time);
		digitalWrite(_bank01, LOW);
		digitalWrite(_bank02, LOW);
		digitalWrite(_bank03, HIGH);
		digitalWrite(_bank04, HIGH);
		digitalWrite(_bank05, LOW);
		digitalWrite(_bank06, LOW);
		digitalWrite(_bank07, LOW);
		digitalWrite(_bank08, LOW);
		delay(time);
		digitalWrite(_bank01, HIGH);
		digitalWrite(_bank02, HIGH);
		digitalWrite(_bank03, LOW);
		digitalWrite(_bank04, LOW);
		digitalWrite(_bank05, LOW);
		digitalWrite(_bank06, LOW);
		digitalWrite(_bank07, LOW);
		digitalWrite(_bank08, LOW);
		delay(time);
		digitalWrite(_bank01, LOW);
		digitalWrite(_bank02, LOW);

	}
}

void Matrix::blinkSingleWhiteDown(int count, int time) {

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

		digitalWrite(_bank01, HIGH);
		delay(time);
		digitalWrite(_bank01, LOW);
		delay(time);
		digitalWrite(_bank04, HIGH);
		delay(time);
		digitalWrite(_bank04, LOW);
		delay(time);
		digitalWrite(_bank05, HIGH);
		delay(time);
		digitalWrite(_bank05, LOW);
		delay(time);
		digitalWrite(_bank08, HIGH);
		delay(time);
		digitalWrite(_bank08, LOW);
		delay(time);

	}
}

void Matrix::blinkSingleRedDown(int count, int time) {

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

		digitalWrite(_bank02, HIGH);
		delay(time);
		digitalWrite(_bank02, LOW);
		delay(time);
		digitalWrite(_bank03, HIGH);
		delay(time);
		digitalWrite(_bank03, LOW);
		delay(time);
		digitalWrite(_bank06, HIGH);
		delay(time);
		digitalWrite(_bank06, LOW);
		delay(time);
		digitalWrite(_bank07, HIGH);
		delay(time);
		digitalWrite(_bank07, LOW);
		delay(time);

	}
}

void Matrix::blinkSingleWhiteUp(int count, int time) {

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

		digitalWrite(_bank08, HIGH);
		delay(time);
		digitalWrite(_bank08, LOW);
		delay(time);
		digitalWrite(_bank05, HIGH);
		delay(time);
		digitalWrite(_bank05, LOW);
		delay(time);
		digitalWrite(_bank04, HIGH);
		delay(time);
		digitalWrite(_bank04, LOW);
		delay(time);
		digitalWrite(_bank01, HIGH);
		delay(time);
		digitalWrite(_bank01, LOW);
		delay(time);

	}
}

void Matrix::blinkSingleRedUp(int count, int time) {

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState++) {

		digitalWrite(_bank07, HIGH);
		delay(time);
		digitalWrite(_bank07, LOW);
		delay(time);
		digitalWrite(_bank06, HIGH);
		delay(time);
		digitalWrite(_bank06, LOW);
		delay(time);
		digitalWrite(_bank03, HIGH);
		delay(time);
		digitalWrite(_bank03, LOW);
		delay(time);
		digitalWrite(_bank02, HIGH);
		delay(time);
		digitalWrite(_bank02, LOW);
		delay(time);

	}
}

void Matrix::turnOnAllButTwo(int count, int time)

{

	_bankState = 0;

	for (_bankState; _bankState < count; _bankState) {

		digitalWrite(_bank01, HIGH);
		digitalWrite(_bank02, HIGH);
		digitalWrite(_bank03, HIGH);
		digitalWrite(_bank04, HIGH);
		digitalWrite(_bank05, HIGH);
		digitalWrite(_bank06, HIGH);
		digitalWrite(_bank07, HIGH);
		digitalWrite(_bank08, HIGH);
		digitalWrite(random(1,8), LOW);
		digitalWrite(random(1,8), LOW);
		delay(time); 
	
	}
}

