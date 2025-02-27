
/*
    Microchip 64 taps Single Digital Potentiometer
    Simple two-wire UP/DOWN interface
    Author: dzalf - Daniel Melendrez
    Date: March 2020 (COVID-19 Vibes)
    Version: 1.1.1  - Initial deployment
             1.1.2  - General cleanup. Implemented new and overloaded methods that allow
                    to select the desired tap. It is now possible to select the nominal 
                    resistance value or override it by setting the measured value

*/

#include "MCP40xx.h"

// Constructor

MCP40xx::MCP40xx(uint8_t CS, uint8_t UD) {

    _CSPin = CS;
    _UDPin = UD;
    _debug = false;
}

MCP40xx::MCP40xx(uint8_t CS, uint8_t UD, bool DEBUG) {

    _CSPin = CS;
    _UDPin = UD;
    _debug = DEBUG;
}

// Methods

void MCP40xx::setup() {

    pinMode(_UDPin, OUTPUT);
    pinMode(_CSPin, OUTPUT);

    digitalWrite(_CSPin, HIGH);  // _CSPin is active low, keep it HIGH at the beginning
    digitalWrite(_UDPin, HIGH);  // _UDPin -> U is active HIGH, keep it LOW at the beginning
}

void MCP40xx::begin() {
    _tapPointer = MCP40xx_DEFAULT_TAP_COUNT;
    _nominalResistance = MCP40xx_NOMINAL_RESISTANCE;

    if(_debug){
      Serial.println(F("Initializing MCP40xx..."));
    }
}

void MCP40xx::begin(float nomRes) {
    _tapPointer = MCP40xx_DEFAULT_TAP_COUNT;
    _nominalResistance = nomRes;

    if(_debug){
      Serial.println(F("Initializing MCP40xx..."));
    }
}

float MCP40xx::wiper() {
    return (_tapPointer / MCP40xx_TAP_NUMBER);
}

void MCP40xx::inc() {  // return wiper count!

    if ((_tapPointer < MCP40xx_TAP_NUMBER)) {
        // Note: The digitalWrite command is slow enough for the device. No additional delays are needed

        unsigned long _startIncTime = micros();
        digitalWrite(_UDPin, HIGH);  // We want the wiper to go UP

        //After at least 500 ns bring _CSPin low
        digitalWrite(_CSPin, LOW);  // Start the command

        // /*  Increment command*/
        //*Subsequent rising edges of _UDPin move the wiper */
        // One tap
        digitalWrite(_UDPin, LOW);

        digitalWrite(_UDPin, HIGH);  // Last _UDPin state is HIGH
        // Here the wiper should have increased already

        // Leave the _CSPin pin ready for next instruction
        digitalWrite(_CSPin, HIGH);  // Release _CSPin to avoid changing the Pot

        _tapPointer++;

        if (_tapPointer >= MCP40xx_TAP_NUMBER)
            _tapPointer = MCP40xx_TAP_NUMBER;

        _incDelay = micros() - _startIncTime;
    }
}

void MCP40xx::dec() {

    if ((_tapPointer > 0)) {

        unsigned long _startDecTime = micros();

        digitalWrite(_UDPin, LOW);  // We want the wiper to go DOWN

        //After at least 500 ns bring _CSPin low
        digitalWrite(_CSPin, LOW);  // Start the "move wiper" command

        // /*  Decrement command*/
        // One tap
        digitalWrite(_UDPin, HIGH);

        digitalWrite(_UDPin, LOW);
        // Here the wiper should have decreased already
        //*Subsequent falling edges of _UDPin move the wiper */

        // Leave the _CSPin pin ready for next instruction
        digitalWrite(_CSPin, HIGH);

        _tapPointer--;

        if (_tapPointer <= 0)
            _tapPointer = 0;

        _decDelay = micros() - _startDecTime;

    }
}

unsigned long MCP40xx::incMicros() {
    return _incDelay;
}

unsigned long MCP40xx::decMicros() {
    return _decDelay;
}

unsigned long MCP40xx::setMicros() {
    return _setDelay;
}

int MCP40xx::taps() {
    return _tapPointer;  // value within [1-64] that points to the taps between resistors [0,63]
}

uint8_t MCP40xx::setValue(float desiredR) {

    float _currentValue;
    float _distance;
    int _tapTarget;

    unsigned long _startSetTime = micros();

    _tapTarget = round((desiredR * MCP40xx_TAP_NUMBER) / (_nominalResistance));
    _distance = abs(_tapPointer - _tapTarget);

    if (_debug) {
        Serial.print("Distance to target: ");
        Serial.println(_distance);

        Serial.print("Target tap: ");
        Serial.println(_tapTarget);
    }

    if (_tapTarget < _tapPointer) {
        for (int i = _tapPointer; i > _tapTarget; i--) {
            dec();
        }

    } else if (_tapTarget > _tapPointer) {
        for (int i = _tapPointer; i < _tapTarget; i++) {
            inc();
        }

    } else {
        // Leave everything where it is
    }

    _setDelay = micros() - _startSetTime;

    return _tapTarget;
}

uint8_t MCP40xx::setTap(uint8_t desiredTap) {

    float _currentValue;
    float _distance;
    int _tapTarget;

    unsigned long _startSetTime = micros();

    _tapTarget = desiredTap;
    _distance = abs(_tapPointer - _tapTarget);

    if (_debug) {
        Serial.print("Distance to target: ");
        Serial.println(_distance);

        Serial.print("Target tap: ");
        Serial.println(_tapTarget);
    }

    if (_tapTarget < _tapPointer) {
        for (int i = _tapPointer; i > _tapTarget; i--) {
            dec();
        }

    } else if (_tapTarget > _tapPointer) {
        for (int i = _tapPointer; i < _tapTarget; i++) {
            inc();
        }

    } else {
        // No touchy...Leave everything where it is...drink beer or coffee
    }

    _setDelay = micros() - _startSetTime;

    return _tapTarget;
}

void MCP40xx::zeroWiper() {

    // It is possible to do this with the latest setTap() method
    /*

    for (int i = MCP40xx_DEFAULT_TAP_COUNT ; i >= 0; i--) {
        dec();
    }

    */

   setTap(0);

    _tapPointer = 0;
}

void MCP40xx::maxWiper() {

     // It is possible to do this with the latest setTap() method
    /*

     for (int i = _tapPointer; i <= MCP40xx_TAP_NUMBER; i++) {
        inc();
    }

    */
    setTap(MCP40xx_TAP_NUMBER);

    _tapPointer = MCP40xx_TAP_NUMBER;
}

float MCP40xx::readValue() {
    return (_tapPointer / MCP40xx_TAP_NUMBER) * (_nominalResistance);
}
