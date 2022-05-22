/* 
  VU Meter for Arduino Uno
  May 2022, Glasgow Clyde College
  Circuit: 
    * 6 LEDs connected to pins 1, 2, 3, 4, 5, 6 through 330R resistors
      * LEDs 1 and 2 - yellow
      * LEDs 3 and 4 - green
      * LEDs 5 and 6 - red
    * Microphone module connected to analogue input pin A0 and powered over regulated 3.3V
*/

// Sets how sensitive the volume meter is to sound
// The lower the sensitivty, it will react to louder sounds 
// The higher the sensitivty, it will react to quiter sounds
#define SENSITIVITY   0.75

// Tell the MCU what pins the LEDs are connected to
#define ledA          6
#define ledB          5
#define ledC          4
#define ledD          3
#define ledE          2
#define ledF          1

// Tell the MCU what pin the microphone is connected to
#define microphone    A0


void setup() {
  // Setup the LEDs as outputs
  pinMode(ledA, OUTPUT);
  pinMode(ledB, OUTPUT);
  pinMode(ledC, OUTPUT);
  pinMode(ledD, OUTPUT);
  pinMode(ledE, OUTPUT);
  pinMode(ledF, OUTPUT);

  // Setup microphone as an input
  pinMode(microphone, INPUT);
}

void loop() {
  // Turn the microphone's output into a digital number
  int microphoneOutput = analogRead(microphone);

  // And then turn that digital number into a percentage, taking into account a DC offset of 1.65V
  int audioLevel = ((abs(microphoneOutput - 270.1) / 270) * 100);

  // Take into account sensitivity setting
  audioLevel *= SENSITIVITY;
  
  // If the audio level is above 20%, turn on the first LED
  // Otherwise, turn it off
  if(audioLevel > 20) {
    digitalWrite(ledA, HIGH);
  } else {
    digitalWrite(ledA, LOW);
  }
  
  // If the audio level is above 30%, turn on the second LED
  // Otherwise, turn it off
  if(audioLevel > 30) {
    digitalWrite(ledB, HIGH);
  } else {
    digitalWrite(ledB, LOW);
  }

  // And so on...
  if(audioLevel > 50) {
    digitalWrite(ledC, HIGH);
  } else {
    digitalWrite(ledC, LOW);
  }

  if(audioLevel > 70) {
    digitalWrite(ledD, HIGH);
  } else {
    digitalWrite(ledD, LOW);
  }

  if(audioLevel > 80) {
    digitalWrite(ledE, HIGH);
  } else {
    digitalWrite(ledE, LOW);
  }

  if(audioLevel > 90) {
    digitalWrite(ledF, HIGH);
  } else {
    digitalWrite(ledF, LOW);
  }
}
