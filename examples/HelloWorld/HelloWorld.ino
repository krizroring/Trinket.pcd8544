/*
 * PCD8544 - Interface the Adafruit Trinket 3.3V with Philips PCD8544 (or compatible) LCDs.
 *
 * Copyright (c) 2010 Carlos Rodrigues <cefrodrigues@gmail.com>
 * Copyright (c) 2014 Christian Roring <degrotebozewolf@gmail.com>
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */

/*
 * This sketch was created for the 3.3V Trinket
 *
 * To use this sketch, connect the Trinket to the display like this:
 *
 * Vcc  -> +3V
 * Gnd  -> GND
 * SCE  -> GND
 * RST  -> Trinket digital pin #3
 * DC   -> Trinkel digital pin #1
 * DN   -> Trinkel digital pin #0
 * SCLK -> Trinkel digital pin #2
 */

/*
 * !! VERY IMPORTANT !!
 *
 * Because the Trinket uses pin #3 and #4 for uploading sketches through USB,
 * disconnect pin #3 and #4 before uploading your sketches.
 */


#include <PCD8544.h>


// A custom glyph (a smiley)...
static const byte glyph[] = { B00010000, B00110100, B00110000, B00110100, B00010000 };


static PCD8544 lcd;


void setup() {
  // PCD8544-compatible displays may have a different resolution...
  lcd.begin(84, 48);
  
  // Add the smiley to position "0" of the ASCII table...
  lcd.createChar(0, glyph);
}


void loop() {
  // Just to show the program is alive...
  static int counter = 0;

  // Write a piece of text on the first line...
  lcd.setCursor(0, 0);
  lcd.print("Hello, World!");

  // Write the counter on the second line...
  lcd.setCursor(0, 1);
  lcd.print(counter, DEC);
  lcd.write(' ');
  lcd.write(0);  // write the smiley

  delay(500);  
  counter++;
}


/* EOF - HelloWorld.ino */
