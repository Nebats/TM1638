

#pragma once

#include <stdint.h>

// ----------------------------------------------------------------------------
//
// PIN / PORT configuration
//
// NOTE: All three pins used must be bits on the same PORT register (ex. PORTB)
//
// ----------------------------------------------------------------------------

#define TM_OUT          PORTB
#define TM_IN           PINB
#define TM_DDR          DDRB
#define TM_BIT_STB      _BV(PB0)
#define TM_BIT_CLK      _BV(PB1)
#define TM_BIT_DAT      _BV(PB2)

// ----------------------------------------------------------------------------
// Functions and parameters
// ----------------------------------------------------------------------------

// Parameters for setLED()
#define TM_OFF          0x0
#define TM_GREEN        0x1
#define TM_RED          0x2

// Parameters for setNumber()
#define TM_RIGHT        0x01
#define TM_LEFT         0x00

// Parameters for setNumberPad()
#define TM_PAD_SPACE    0x00
#define TM_PAD_0        0x3F

// Class to control a 8x 7-segment, 8x dual-color LED, 8x button module
// powered by the TM1638 chip set.
class TM1638
{
public:

    // Construct a TM1638 object and initialize all the pins/ports used.
    TM1638();


    // Clear the 7-segment displays (only)
    void clear();

    // Set a single 7-segment display to the given byte value.
    // This allows direct control of the elements to do spinning animations etc.
    void setByte(const uint8_t pos, const uint8_t value);

    // Display a single digit at the given position.
    // Position is left-to-right, starting with 0.
    void setDigit(const uint8_t pos, const uint8_t value);

    // Display an unsigned number at a given offset and alignment.
    void setNumber(uint32_t number, uint8_t offset = 7, const uint8_t align = TM_RIGHT);

    // Display an unsigned number at a given offset and pad it with 0's or
    // spaces to a desired with. This function is helpful when the numbers can
    // fluctuate in length (ex. 100, 5, 1000) to avoid flickering segments.
    void setNumberPad(uint32_t number, uint8_t offset, uint8_t width, const uint8_t pad = TM_PAD_SPACE);

    // Display an unsigned number in hex format at a given offset and pad it
    // with 0's or spaces to a desired with.
    void setNumberHex(uint32_t number, uint8_t offset, uint8_t width, const uint8_t pad = TM_PAD_SPACE);

    // Draw a character at a given position.
    // Not all characters are supported, check TM1638Font.h for an overview.
    void setChar(const uint8_t pos, const char value);

    // Display a string starting at a given offset.
    void setChars(const char* value, uint8_t offset = 0);

    // Set which "dots" should be enabled.
    // Mask is mapped right to left (ex. 0x01 = right-most dot)
    void setDots(const uint8_t mask);


    // Turn off all LEDs
    void clearLEDs();

    // Set an LED at the given position to the specified color.
    // LEDs are numbered 0-7, left to right
    void setLED(const uint8_t pos, const uint8_t color);


    void setLEDs(uint8_t green, uint8_t red);

    // Returns a bitmask containing all button states.
    uint8_t getButtons();

protected:
    uint8_t _dotMask;
};

