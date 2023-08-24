// Define the LED pin
const int ledPin = 13; // You can change this to your desired pin

// Define the push button pin
const int buttonPin = A7; // You can change this to your desired pin

// Morse code dictionary (letters A-Z)
const char* morseCode[] = 
{
  ".-",   // A
  "-...", // B
  "-.-.", // C
  "-..",  // D
  ".",    // E
  "..-.", // F
  "--.",  // G
  "....", // H
  "..",   // I
  ".---", // J
  "-.-",  // K
  ".-..", // L
  "--",   // M
  "-.",   // N
  "---",  // O
  ".--.", // P
  "--.-", // Q
  ".-.",  // R
  "...",  // S
  "-",    // T
  "..-",  // U
  "...-", // V
  ".--",  // W
  "-..-", // X
  "-.--", // Y
  "--.."  // Z
};

int currentLetter = 0; // Index of the current letter being blinked
bool blinking = false; // Flag to track if blinking is ongoing

void setup() // This will set LED as output and button as input
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLDOWN);
}

void loop() 
{
  // This will check if the button is pressed or not
  if (digitalRead(buttonPin) == HIGH) 
  {
    // Button is pressed, start/reset blinking
    blinking = !blinking;
    currentLetter = 0;
    delay(300); // Debounce delay
  }

  // If button is pressed then given morse code will execute.
  if(blinking){
  blinkMorseCode(".--.");  // P
  delay(1000);
  blinkMorseCode(".-.");   // R
  delay(1000);
  blinkMorseCode(".-");    // A
  delay(1000);
  blinkMorseCode("....");  // H
  delay(1000);
  blinkMorseCode(".---");  // J
  delay(1000);
  blinkMorseCode("---");   // O
  delay(1000);
  blinkMorseCode("-");     // T

  blinking = !blinking;
  }
}

void blinkMorseCode(const char* code) 
{
  // This for loop will iterate through the given morse code and then blink LED accordingly.
  for (int i = 0; code[i] != '\0'; i++) 
  {
    if (code[i] == '.') 
    {
      digitalWrite(ledPin, HIGH);
      delay(200); // Dot duration
      digitalWrite(ledPin, LOW);
      delay(200); // Inter-element gap
    } 
    
    else if (code[i] == '-') 
    {
      digitalWrite(ledPin, HIGH);
      delay(600); // Dash duration
      digitalWrite(ledPin, LOW);
      delay(200); // Inter-element gap
    }
  }
  delay(800); // Gap between letters
}
