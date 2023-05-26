#include "USB.h"
#include "USBHIDKeyboard.h"
USBHIDKeyboard Keyboard;

#define SHORTCUT_1 15
#define SHORTCUT_2 16

void setup() {
  // put your setup code here, to run once:
  pinMode(SHORTCUT_1, INPUT);
  pinMode(SHORTCUT_2, INPUT);

  Serial.begin(9600);
  Keyboard.begin();
  USB.begin();

}

void loop() {
  // put your main code here, to run repeatedly:

  if (digitalRead(SHORTCUT_1) == LOW){
    Serial.println("Shorcut 1 is active");
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('c');
    delay(100);
    Keyboard.releaseAll();

  }

  if (digitalRead(SHORTCUT_2) == LOW){
    Serial.println("Shorcut 2 is active");
    Keyboard.press(KEY_LEFT_CTRL);
    Keyboard.press('v');
    delay(100);
    Keyboard.releaseAll();

  }

  delay(150);

}
