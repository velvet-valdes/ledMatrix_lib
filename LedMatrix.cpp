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
  _bankCount = 0;

}


// DEPRECATE AFTER TESTING
void Matrix::downHorizontal(int maxCount, int time)

{

  _bankCount = 0;


  for (_bankCount; _bankCount < maxCount; _bankCount++) {

    _bankFloat = 1; // this variable is the bank we are turning on and off.  place your on off code inside the curly brackets

    for (_bankFloat; _bankFloat < 9 && _bankFloat >= 1; _bankFloat++) {

      digitalWrite(_bankFloat, HIGH);
      delay(time);
      digitalWrite(_bankFloat, LOW);
      delay(time);

    }
  }
}


// DEPRECATE AFTER TESTING
void Matrix::upHorizontal(int maxCount, int time)

{

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

    _bankFloat = 9;

    for (_bankFloat; _bankFloat <= 9 && _bankFloat > 1; _bankFloat--) {

      digitalWrite(_bankFloat, HIGH);
      delay(time);
      digitalWrite(_bankFloat, LOW);
      delay(time);

    }
  }
}


// DEPRECATE AFTER TESTING
void Matrix::downLeft(int maxCount, int time)

{

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


// DEPRECATE AFTER TESTING
void Matrix::upRight(int maxCount, int time)

{

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


// DEPRECATE AFTER TESTING
void Matrix::upLeft(int maxCount, int time)

{

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


// DEPRECATE AFTER TESTING
void Matrix::downRight(int maxCount, int time)

{

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


void Matrix::snakeDown(int maxCount, int time)

{

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

    _bankFloat = 1;

    for (_bankFloat; _bankFloat < 9 && _bankFloat >= 1; _bankFloat++) {

      digitalWrite(_bankFloat, HIGH);
      digitalWrite(_bankFloat + 1, HIGH);
      delay(time);
      digitalWrite(_bankFloat + 2, HIGH);
      delay(time);
      digitalWrite(_bankFloat, LOW);
      digitalWrite(_bankFloat + 1, LOW);

    }
  }
}


void Matrix::snakeUp(int maxCount, int time)

{

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

    _bankFloat = 9;

    for (_bankFloat; _bankFloat <= 9 && _bankFloat > 1; _bankFloat--) {

      digitalWrite(_bankFloat, HIGH);
      digitalWrite(_bankFloat - 1, HIGH);
      delay(time);
      digitalWrite(_bankFloat - 2, HIGH);
      delay(time);
      digitalWrite(_bankFloat, LOW);
      digitalWrite(_bankFloat - 1, LOW);

    }
  }
}


void Matrix::randomOne(int maxCount, int time)

{

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

    _bankFloat = random(2, 9);
    digitalWrite(_bankFloat, HIGH);
    delay(time);
    digitalWrite(_bankFloat, LOW);
    delay(time);

  }
}


void Matrix::randomTwo(int maxCount, int time)

{

  _bankCount = 0;

  for ( _bankCount; _bankCount < maxCount; _bankCount++) {

    _bankFloat = random(2, 9);
    digitalWrite(_bankFloat, HIGH);
    digitalWrite(_bankFloat + 1, HIGH);
    delay(time);
    digitalWrite(_bankFloat, LOW);
    digitalWrite(_bankFloat + 1, LOW);
    delay(time);
  }
}


void Matrix::randomThree(int maxCount, int time)

{

  _bankCount = 0;

  for ( _bankCount; _bankCount < maxCount; _bankCount++) {

    _bankFloat = random(2, 9);
    digitalWrite(_bankFloat, HIGH);
    delay(time);

    _bankFloat = random(2, 9);
    digitalWrite(_bankFloat, LOW);
    delay(time);
  }
}


void Matrix::blinkRed(int maxCount, int time) {

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


void Matrix::blinkWhite(int maxCount, int time) {

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


// DEPRECATE AFTER TESTING
void Matrix::rowDown(int maxCount, int time) {

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


// DEPRECATE AFTER TESTING
void Matrix::rowUp(int maxCount, int time) {

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


void Matrix::blinkSingleWhiteDown(int maxCount, int time) {

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


void Matrix::blinkSingleRedDown(int maxCount, int time) {

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


void Matrix::blinkSingleWhiteUp(int maxCount, int time) {

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


void Matrix::blinkSingleRedUp(int maxCount, int time) {

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount++) {

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


void Matrix::turnOnAllButTwo(int maxCount, int time)

{

  _bankCount = 0;

  for (_bankCount; _bankCount < maxCount; _bankCount) {

    digitalWrite(_bank01, HIGH);
    digitalWrite(_bank02, HIGH);
    digitalWrite(_bank03, HIGH);
    digitalWrite(_bank04, HIGH);
    digitalWrite(_bank05, HIGH);
    digitalWrite(_bank06, HIGH);
    digitalWrite(_bank07, HIGH);
    digitalWrite(_bank08, HIGH);
    digitalWrite(random(1, 8), LOW);
    digitalWrite(random(1, 8), LOW);
    delay(time);

  }
}


//////  TESTING


void Matrix::test_downHorizontal(int maxCount, int onTime, int offTime)

{
  _bankFloat = 2;
  _onTime = onTime;
  _offTime = offTime;

  do {

    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > 9 || _bankFloat < 2 ) {

      _bankFloat = 2;

    }

    // read the current time value and store it for comparison
    _currentMillis = millis();

    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {

      _bankFloat++;
      _bankCount++;
      _cycleState = 0;

    }

    if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime)) {

      _ledState = LOW; // Turn the LED bank off
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime)) {

      _ledState = HIGH; // Turn the LED bank on
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {

      _subState = 0; _cycleState = 1;

    }

  } while (_bankCount < (8 * maxCount));

  _bankCount = 0;

}


void Matrix::test_upHorizontal(int maxCount, int onTime, int offTime)

{

  _bankFloat = 9;
  _onTime = onTime;
  _offTime = offTime;

  do {

    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > 9 || _bankFloat < 2 ) {

      _bankFloat = 9;

    }

    // read the current time value and store it for comparison
    _currentMillis = millis();

    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {

      _bankFloat--;
      _bankCount++;
      _cycleState = 0;

    }

    if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime)) {

      _ledState = LOW; // Turn the LED bank off
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime)) {

      _ledState = HIGH; // Turn the LED bank on
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {

      _subState = 0; _cycleState = 1;

    }

  } while (_bankCount < (8 * maxCount));

  _bankCount = 0;

}


void Matrix::test_rowDown (int maxCount, int onTime, int offTime)

{

  _bankFloat = 2; // We are starting from the lowest bank number
  _onTime = onTime;
  _offTime = offTime;

  do {

    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > 9 || _bankFloat < 2 ) {

      _bankFloat = 2;

    }
    // read the current time value and store it for comparison
    _currentMillis = millis();

    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {

      _bankFloat++;
      _bankFloat++; // we intend to increment the bank we are writing to by two values instead of just one
      _bankCount++; // incrementing the bank count variable that controls the 'do while' condition
      _cycleState = 0;

    }

    if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime)) {

      _ledState = LOW; // Turn the LED bank off
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime)) {

      _ledState = HIGH; // Turn the LED bank on
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {

      _subState = 0; _cycleState = 1;

    }

  } while (_bankCount < (4 * maxCount));

  _bankCount = 0; // Leaving the function by setting the bank count variable back to zero

}


void Matrix::test_rowUp (int maxCount, int onTime, int offTime)

{

  _bankFloat = 9;  // We are starting from the highest bank number
  _onTime = onTime;
  _offTime = offTime;

  do {

    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > 9 || _bankFloat < 2 ) {

      _bankFloat = 9;

    }
    // read the current time value and store it for comparison
    _currentMillis = millis();

    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {

      _bankFloat--;
      _bankFloat--; // we intend to decrement the bank we are writing to by two values instead of just one
      _bankCount++; // incrementing the bank count variable that controls the 'do while' condition
      _cycleState = 0;

    }

    if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime)) {

      _ledState = LOW; // Turn the LED bank off
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      digitalWrite(_bankFloat - 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime)) {

      _ledState = HIGH; // Turn the LED bank on
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      digitalWrite(_bankFloat - 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {

      _subState = 0; _cycleState = 1;

    }

  } while (_bankCount < (4 * maxCount));

  _bankCount = 0; // Leaving the function by setting the bank count variable back to zero

}


void Matrix::test_downLeft (int maxCount, int onTime, int offTime)

{

  _bankFloat = 2; // We are starting from the lowest bank number
  _onTime = onTime;
  _offTime = offTime;

  do {

    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > 9 || _bankFloat < 2 ) {

      _bankFloat = 2;

    }
    // read the current time value and store it for comparison
    _currentMillis = millis();

    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {

      _bankFloat++;
      _bankFloat++; // we intend to increment the bank we are writing to by two values instead of just one
      _bankCount++; // incrementing the bank count variable that controls the 'do while' condition
      _cycleState = 0;

    }

    if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime)) {

      _ledState = LOW; // Turn the LED bank off
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      //digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime)) {

      _ledState = HIGH; // Turn the LED bank on
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      //digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {

      _subState = 0; _cycleState = 1;

    }

  } while (_bankCount < (4 * maxCount));

  _bankCount = 0; // Leaving the function by setting the bank count variable back to zero

}


void Matrix::test_downRight (int maxCount, int onTime, int offTime)

{

  _bankFloat = 3; // We are starting from the lowest odd bank number
  _onTime = onTime;
  _offTime = offTime;

  do {

    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > 9 || _bankFloat < 2 ) {

      _bankFloat = 3;

    }
    // read the current time value and store it for comparison
    _currentMillis = millis();

    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {

      _bankFloat++;
      _bankFloat++; // we intend to increment the bank we are writing to by two values instead of just one
      _bankCount++; // incrementing the bank count variable that controls the 'do while' condition
      _cycleState = 0;

    }

    if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime)) {

      _ledState = LOW; // Turn the LED bank off
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      //digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime)) {

      _ledState = HIGH; // Turn the LED bank on
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      //digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {

      _subState = 0; _cycleState = 1;

    }

  } while (_bankCount < (4 * maxCount));

  _bankCount = 0; // Leaving the function by setting the bank count variable back to zero

}


void Matrix::test_upRight (int maxCount, int onTime, int offTime)

{

  _bankFloat = 9; // We are starting from the highest bank number
  _onTime = onTime;
  _offTime = offTime;

  do {

    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > 9 || _bankFloat < 2 ) {

      _bankFloat = 9;

    }
    // read the current time value and store it for comparison
    _currentMillis = millis();

    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {

      _bankFloat--;
      _bankFloat--; // we intend to increment the bank we are writing to by two values instead of just one
      _bankCount++; // incrementing the bank count variable that controls the 'do while' condition
      _cycleState = 0;

    }

    if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime)) {

      _ledState = LOW; // Turn the LED bank off
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      //digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime)) {

      _ledState = HIGH; // Turn the LED bank on
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      //digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {

      _subState = 0; _cycleState = 1;

    }

  } while (_bankCount < (4 * maxCount));

  _bankCount = 0; // Leaving the function by setting the bank count variable back to zero

}


void Matrix::test_upLeft (int maxCount, int onTime, int offTime)

{

  _bankFloat = 8; // We are starting from the highest even bank number
  _onTime = onTime;
  _offTime = offTime;

  do {

    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > 9 || _bankFloat < 2 ) {

      _bankFloat = 8;

    }
    // read the current time value and store it for comparison
    _currentMillis = millis();

    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {

      _bankFloat--;
      _bankFloat--; // we intend to increment the bank we are writing to by two values instead of just one
      _bankCount++; // incrementing the bank count variable that controls the 'do while' condition
      _cycleState = 0;

    }

    if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime)) {

      _ledState = LOW; // Turn the LED bank off
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      //digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime)) {

      _ledState = HIGH; // Turn the LED bank on
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      //digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      _subState++; // increment the variable that tells us when the cycle is complete

    }

    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {

      _subState = 0; _cycleState = 1;

    }

  } while (_bankCount < (4 * maxCount));

  _bankCount = 0; // Leaving the function by setting the bank count variable back to zero

}