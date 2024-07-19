//Pins connected to the button and the LED
const uint8_t BTN_PIN = 2;
const uint8_t LED_PIN = 13;

//Variables to store the previous state of the button and the current state of the LED
uint8_t buttonPrevState = LOW;
uint8_t ledState = LOW;
uint32_t lastDebounceTime = 0;
const uint32_t debounceDelay = 50; // 50 milliseconds debounce delay

void setup()
{
  //Setting button pin as input with the pull-up resistor
  pinMode(BTN_PIN, INPUT_PULLUP);
  // Set the LED pin as output
  pinMode(LED_PIN, OUTPUT);
  //Initialising serial communication for debugging
  Serial.begin(9600);
}

void loop()
{
  //Reading current stte of the button
  uint8_t buttonState = digitalRead(BTN_PIN);

  //Printing states
  Serial.print(buttonState);
  Serial.print(buttonPrevState);
  Serial.print(ledState);
  Serial.println("");

  // Check if the button state has changed
  if(buttonState != buttonPrevState)
  {
    // Update the debounce timer
    lastDebounceTime = millis();
  }

  // Check if the debounce time has passed
  if((millis() - lastDebounceTime) > debounceDelay)
  {
    // If the button state has changed and the new state is pressed
    if(buttonState == LOW && buttonPrevState == HIGH)
    {
      
      ledState = !ledState;
      digitalWrite(LED_PIN, ledState);
    }
  }

  // Updates the previous button state
  buttonPrevState = buttonState;
}
