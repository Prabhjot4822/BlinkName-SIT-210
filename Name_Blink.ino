// Define the LED pin
const int ledPin = 13; // You can change this to your desired pin

// Define the push button pin
const int buttonPin = 2; // You can change this to your desired pin

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

void setup() 
{
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

void loop() 
{
  if (digitalRead(buttonPin) == LOW) 
  {
    // Button is pressed, start/reset blinking
    blinking = !blinking;
    currentLetter = 0;
    delay(300); // Debounce delay
  }
  
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

  delay(3000); // Gap between repeating name autometically
}

void blinkMorseCode(const char* code) 
{
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
