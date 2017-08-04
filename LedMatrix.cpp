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
  // Turn on the bank assigned to the private floating variable -- this is redundant
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


void Matrix::downHorizontal(int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank01;
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank01;
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


void Matrix::upHorizontal(int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank08;
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank08;
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


void Matrix::rowDown (int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank01; // We are starting from the lowest bank number
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank01;
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


void Matrix::rowUp (int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank08;  // We are starting from the highest bank number
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank08;
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


void Matrix::downLeft (int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank01; // We are starting from the lowest bank number
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank01;
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


void Matrix::downRight (int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank02; // We are starting from the lowest even bank number
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank02;
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


void Matrix::upRight (int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank08; // We are starting from the highest bank number
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank08;
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


void Matrix::upLeft (int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank07; // We are starting from the highest odd bank number
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank07;
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


void Matrix::snakeDown (int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank01; // We are starting from the lowest bank number
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank01;
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      _bankFloat++;
      _bankCount++; // incrementing the bank count variable that controls the 'do while' condition
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
      digitalWrite(_bankFloat + 1, _ledState); // Update the actual LED bank with the state
      digitalWrite(_bankFloat + 2, _ledState);
      _subState++; // increment the variable that tells us when the cycle is complete
    }
    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {
      _subState = 0; _cycleState = 1;
    }
  } while (_bankCount < (8 * maxCount));
  _bankCount = 0; // Leaving the function by setting the bank count variable back to zero
}


void Matrix::snakeUp (int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank08; // We are starting from the highest bank number
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank08;
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we decrement the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      _bankFloat--;
      _bankCount++; // incrementing the bank count variable that controls the 'do while' condition
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
      digitalWrite(_bankFloat - 1, _ledState); // Update the actual LED bank with the state
      digitalWrite(_bankFloat - 2, _ledState);
      _subState++; // increment the variable that tells us when the cycle is complete
    }
    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {
      _subState = 0; _cycleState = 1;
    }
  } while (_bankCount < (8 * maxCount));
  _bankCount = 0; // Leaving the function by setting the bank count variable back to zero
}


void Matrix::randomOne(int maxCount, int onTime, int offTime)
{
  _bankFloat = random(_bank01, _bank08);
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bounds to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = random(_bank01, _bank08);
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      _bankFloat = random(_bank01, _bank08); // we shouldn't need to increment the bank float.  this is a random function
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


void Matrix::randomTwo(int maxCount, int onTime, int offTime)
{
  _bankFloat = random(_bank01, _bank08);
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bounds to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = random(_bank01, _bank08);
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      _bankFloat = random(_bank01, _bank08); // we shouldn't need to increment the bank float.  this is a random function
      _bankCount++;
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
  } while (_bankCount < (8 * maxCount));
  _bankCount = 0;
}


void Matrix::randomThree(int maxCount, int onTime, int offTime)
{
  _bankFloat = random(_bank01, _bank08);
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bounds to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = random(_bank01, _bank08);
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // this is a random function so we will set the variable here
    _bankFloat = random(_bank01, _bank08);
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      // _bankFloat++; // we shouldn't need to increment the bank float.  this is a random function
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


void Matrix::blinkSingleWhiteDown(int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank01;
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank01;
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      // test to see if the bank variable is an even or odd number that isn't 4 or 8 ??
      if  ((_bankCount % 2 == 0) && (_bankFloat == _bank01 || _bankFloat == _bank05)) {
        _bankFloat = _bankFloat + 3; // increment the current bank float by three if its an even number ??
        _bankCount++; // increment the while loop variable
        _cycleState = 0; // reset the cycle state
      }
      else {
        _bankFloat++; // increment the current bank float by one if it doesn't meet the above test
        _bankCount++; // increment the while loop variable
        _cycleState = 0; // reset the cycle state
      }
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
  } while (_bankCount < (4 * maxCount));
  _bankCount = 0;
}


void Matrix::blinkSingleWhiteUp(int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank08;
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank08;
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      // test to see if the bank variable is an even or odd number that isn't 4 or 8
      if  ((_bankCount % 2 == 0) && (_bankFloat == _bank04 || _bankFloat == _bank08)) {
        _bankFloat = _bankFloat - 3; // decrement the current bank float by three if its an odd number
        _bankCount++; // increment the while loop variable
        _cycleState = 0; // reset the cycle state
      }
      else {
        _bankFloat--; // decrement the current bank float by one if it doesn't meet the above test
        _bankCount++; // increment the while loop variable
        _cycleState = 0; // reset the cycle state
      }
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
  } while (_bankCount < (4 * maxCount));
  _bankCount = 0;
}


void Matrix::blinkSingleRedUp(int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank07;
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank07;
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      // test to see if the bank variable is an even or odd number that isn't 4 or 8 (??)
      if  ((_bankCount % 2 != 0) && (_bankFloat == _bank02 || _bankFloat == _bank06)) {
        _bankFloat = _bankFloat - 3; // decrement the current bank float by three if its an odd number
        _bankCount++; // increment the while loop variable
        _cycleState = 0; // reset the cycle state
      }
      else {
        _bankFloat--; // decrement the current bank float by one if it doesn't meet the above test
        _bankCount++; // increment the while loop variable
        _cycleState = 0; // reset the cycle state
      }
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
  } while (_bankCount < (4 * maxCount));
  _bankCount = 0;
}


void Matrix::blinkSingleRedDown(int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank02;
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank02;
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      // test to see if the bank variable is an even or odd number that isn't 4 or 8
      if  ((_bankCount % 2 != 0) && (_bankFloat == _bank03 || _bankFloat == _bank07)) {
        _bankFloat = _bankFloat + 3; // decrement the current bank float by three if its an odd number
        _bankCount++; // increment the while loop variable
        _cycleState = 0; // reset the cycle state
      }
      else {
        _bankFloat++; // decrement the current bank float by one if it doesn't meet the above test
        _bankCount++; // increment the while loop variable
        _cycleState = 0; // reset the cycle state
      }
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
  } while (_bankCount < (4 * maxCount));
  _bankCount = 0;
}


void Matrix::blinkRed(int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank07;
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank07;
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      _bankCount++; // increment the while loop variable
      _cycleState = 0; // reset the cycle state
    }
    if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime)) {
      _ledState = LOW; // Turn the LED bank off
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      digitalWrite(_bankFloat - 1, _ledState);
      digitalWrite(_bankFloat - 4, _ledState);
      digitalWrite(_bankFloat - 5, _ledState);
      _subState++; // increment the variable that tells us when the cycle is complete
    }
    else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime)) {
      _ledState = HIGH; // Turn the LED bank on
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      digitalWrite(_bankFloat - 1, _ledState);
      digitalWrite(_bankFloat - 4, _ledState);
      digitalWrite(_bankFloat - 5, _ledState);
      _subState++; // increment the variable that tells us when the cycle is complete
    }
    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {
      _subState = 0; _cycleState = 1;
    }
  } while (_bankCount < (4 * maxCount));
  _bankCount = 0;
}


void Matrix::blinkWhite(int maxCount, int onTime, int offTime)
{
  _bankFloat = _bank01;
  _onTime = onTime;
  _offTime = offTime;
  do {
    // change the range of the _bankFloat variable if it is out of bound to the starting bank number
    if ( _bankFloat > _bank08 || _bankFloat < _bank01 ) {
      _bankFloat = _bank01;
    }
    // read the current time value and store it for comparison
    _currentMillis = millis();
    // Here we are checking to see if the ON OFF cycle has completed.  If it has we increment the variable we intend to digitalWrite(); to.  When we have completed that we reset the cycle variable to incomplete.
    if (_cycleState == 1) {
      _bankCount++; // increment the while loop variable
      _cycleState = 0; // reset the cycle state
    }
    if ((_ledState == HIGH) && (_currentMillis - _previousMillis >= _onTime)) {
      _ledState = LOW; // Turn the LED bank off
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      digitalWrite(_bankFloat + 3, _ledState);
      digitalWrite(_bankFloat + 4, _ledState);
      digitalWrite(_bankFloat + 7, _ledState);
      _subState++; // increment the variable that tells us when the cycle is complete
    }
    else if ((_ledState == LOW) && (_currentMillis - _previousMillis >= _offTime)) {
      _ledState = HIGH; // Turn the LED bank on
      _previousMillis = _currentMillis; // Remember the time
      digitalWrite(_bankFloat, _ledState); // Update the actual LED bank with the state
      digitalWrite(_bankFloat + 3, _ledState);
      digitalWrite(_bankFloat + 4, _ledState);
      digitalWrite(_bankFloat + 7, _ledState);
      _subState++; // increment the variable that tells us when the cycle is complete
    }
    // Here we are a variable to track if the cycle is complete.  Each subcomponent of the cycle increments the variable.  We are testing if the cycle is done with an integer.
    if (_subState >= 2) {
      _subState = 0; _cycleState = 1;
    }
  } while (_bankCount < (4 * maxCount));
  _bankCount = 0;
}