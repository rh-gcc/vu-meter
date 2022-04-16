/* 
  VU Meter for Arduino Uno
  April 2022, Glasgow Clyde College

  Circuit: 
    * 6 LEDs connected to pins 1, 2, 3, 4, 5, 6 through 330R resistors
      * LEDs 1 and 2 - yellow
      * LEDs 3 and 4 - green
      * LEDs 5 and 6 - red
    * Microphone module connected to analogue input pin A0
    * Optionally, output of microphone module is fed through envelope detector made up of a diode and 100pF capacitor
*/

// Sets how sensitive the volume meter is to sound
// The lower the sensitivty, it will react to louder sounds 
// The higher the sensitivty, it will react to quiter sounds
#define SENSITIVITY   3

// Tell the MCU what pins the LEDs are connected to
#define led1          1
#define led2          2
#define led3          3
#define led4          4
#define led5          5
#define led6          6

// Tell the MCU what pin the microphone is connected to
#define microphone    A0

void setup() {
  // Setup the LEDs as outputs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(led4, OUTPUT);
  pinMode(led5, OUTPUT);
  pinMode(led6, OUTPUT);

  // Setup microphone as an input
  pinMode(microphone, INPUT);
}

void loop() {
  // Turn the microphone's output into a digital number
  int microphoneOutput = analogRead(microphone);

  // And then turn that digital number into a percentage, taking into account a DC offset of 2.5V
  int audioLevel = ((abs(microphoneOutput - 521) / 521.0) * 100) * SENSITIVITY;
  
  // If the audio level is above 30%, turn on the first LED
  // Otherwise, turn it off
  if(audioLevel > 20) {
    digitalWrite(led1, HIGH);
  } else {
    digitalWrite(led1, LOW);
  }
  
  // If the audio level is above 40%, turn on the second LED
  // Otherwise, turn it off
  if(audioLevel > 30) {
    digitalWrite(led2, HIGH);
  } else {
    digitalWrite(led2, LOW);
  }

  // And so on...
  if(audioLevel > 40) {
    digitalWrite(led3, HIGH);
  } else {
    digitalWrite(led3, LOW);
  }

  if(audioLevel > 50) {
    digitalWrite(led4, HIGH);
  } else {
    digitalWrite(led4, LOW);
  }

  if(audioLevel > 60) {
    digitalWrite(led5, HIGH);
  } else {
    digitalWrite(led5, LOW);
  }

  if(audioLevel > 80) {
    digitalWrite(led6, HIGH);
  } else {
    digitalWrite(led6, LOW);
  }
}
