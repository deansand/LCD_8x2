#include <Arduino.h>
#include <LiquidCrystal_I2C.h>
#define int numRows = 2; // number of rows on the LCD
#define int numCols = 8; // number of columns on the LCD
#define buttonPin 2 // the number of the pushbutton pin 2
#define int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5; // LCD pins
unsigned long previousMillis = 0; // will store last time the message was displayed
const long interval = 1000; // interval at which to clear the message (milliseconds)

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(buttonPin, INPUT);  // initialize the pushbutton pin as an input:

  lcd.begin(numCols, numRows);  // initialize the LCD

  lcd.backlight();  // Turn on the backlight and print a message.

  lcd.setCursor(0, 0); //start at the first column, first row
}

void loop() {
  unsigned long currentMillis = millis(); // get the current time

    // Check if the button is pressed
  if (digitalRead(buttonPin) == LOW) {

      // Print from ASCII 'a' to 'z'
  for (int thisLetter = 'a'; thisLetter <= 'z'; thisLetter++) {

    //loop over the rows
    for (int thisRow = 0; thisRow < numsRows; thisRow++) {

      //loop over the columns
      for (int thisCol = 0; thisCol < numCols; thisCol++) {

        // set the cursor position
        lcd.setCursor(thisCol, thisRow);
        
        // print the letter
        lcd.print(thisLetter);
        if (currentMillis - previousMillis >= interval) {
          lcd.setCursor(0, 1);
          lcd.print("                ");
        }
      }
    }
  }
    previousMillis = currentMillis; // reset the timer
  }

  // Check if the interval has passed
  if (currentMillis - previousMillis >= interval) {
    lcd.setCursor(0, 1);
    lcd.print("                "); // clear the message
  }
}