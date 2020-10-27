// This code was written by Nicholas Bira, August 24, 2020. It builds on example sketches from the EnableInterrupt library.
// This code allows for six constantly updating sensors, tracking rotations of six wheels. This is easily scalable. 
// More elegant methods are possible; refer to https://github.com/GreyGnome/EnableInterrupt/wiki/Usage#Summary
// Library downloaded from: https://bintray.com/greygnome/generic/EnableInterrupt/view#files

#include <EnableInterrupt.h>

volatile uint16_t interruptCount1=0;
volatile uint16_t interruptCount2=0;
volatile uint16_t interruptCount3=0;
volatile uint16_t interruptCount4=0; 
volatile uint16_t interruptCount5=0; 
volatile uint16_t interruptCount6=0; 

// For all variables, the count will go back to 0 after hitting 65535. Account for this in post-processing.

void interruptFunction1() {
  interruptCount1++;
}

void interruptFunction2() {
  interruptCount2++;
}

void interruptFunction3() {
  interruptCount3++;
}

void interruptFunction4() {
  interruptCount4++;
}

void interruptFunction5() {
  interruptCount5++;
}

void interruptFunction6() {
  interruptCount6++;
}

void setup() {
  Serial.begin(115200);

  pinMode(4, INPUT_PULLUP);  // See http://arduino.cc/en/Tutorial/DigitalPins
  pinMode(5, INPUT_PULLUP); 
  pinMode(6, INPUT_PULLUP); 
  pinMode(8, INPUT_PULLUP); 
  pinMode(9, INPUT_PULLUP); 
  pinMode(10, INPUT_PULLUP); 

  enableInterrupt(4, interruptFunction1, RISING);
  enableInterrupt(5, interruptFunction2, RISING);
  enableInterrupt(6, interruptFunction3, RISING);
  enableInterrupt(8, interruptFunction4, RISING);
  enableInterrupt(9, interruptFunction5, RISING);
  enableInterrupt(10, interruptFunction6, RISING);
}

// The loop prints the number of rotations for each sensor every 2 seconds. The value is updated by the interrupt routine.
void loop() {
  Serial.print(interruptCount1);
  Serial.print(", ");
  Serial.print(interruptCount2);
  Serial.print(", ");
  Serial.print(interruptCount3);
  Serial.print(", ");
  Serial.print(interruptCount4);
  Serial.print(", ");
  Serial.print(interruptCount5);
  Serial.print(", ");
  Serial.println(interruptCount6);
  delay(2000);
}
