#include <Keyboard.h>

const int NUM_KEYS = 6;
const int keyPins[NUM_KEYS] = {D0, D1, D2, D3, D4, D5};

const char keyMap[NUM_KEYS] = {'a', 'c', 'v', 'z', 'y', 's'};

bool keyState[NUM_KEYS] ={false};  

void setup() {
  for (int i = 0; i < NUM_KEYS; i++){
    pinMode(keyPins[i], INPUT_PULLUP);
  }
  Keyboard.begin();
}

void sendShortcut(char key){
  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press(key);
  delay(10);
  Keyboard.release(key);
  Keyboard.release(KEY_LEFT_CTRL);
}

void loop() {
  for (int i = 0; i < NUM_KEYS; i++){
    bool pressed = (digitalRead(keyPins[i]) == LOW);

    if (pressed && !keyState[i]){
      sendShortcut(keyMap[i]);
      keyState[i] = true;
    }
    else if (!pressed){
      keyState[i] = false;
    }
  }
  delay(5);
}
