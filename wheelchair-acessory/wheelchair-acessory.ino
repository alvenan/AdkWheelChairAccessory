#include "variant.h"
#include <stdio.h>
#include <adk.h>
#include <stdlib.h>

#define AXIS_X  66
#define AXIS_Y  67

const int centerValue = 152;
byte X_value, Y_value;

// Accessory descriptor. It's how Arduino identifies itself to Android.
char applicationName[] = "adk-wheel-chair"; // the app on your phone.
char accessoryName[] = "Arduino Due"; // your Arduino board.
char companyName[] = "engcomp-ufam";

// Make up anything you want for these
char versionNumber[] = "0.1";
char serialNumber[] = "1";
char url[] = "https://sites.google.com/site/alisonengineer/AndroidADK_0.1.apk?attredirects=0&d=1";

USBHost Usb;
ADK adk(&Usb, companyName, applicationName, accessoryName, versionNumber, url, serialNumber);

int led = 13;

void setup() {
  // start serial port at 9600 bps:
  Serial.begin(9600);
  cpu_irq_enable();

  pinMode(led, OUTPUT);
  //Indicate start of program
  for (int i = 0; i <= 3; i++) {
    digitalWrite(led, HIGH);
    delay(250);
    digitalWrite(led, LOW);
    delay(250);
  }

  analogWriteResolution(8);

  X_value = centerValue;
  Y_value = centerValue;

  analogWrite(AXIS_Y, centerValue);
  analogWrite(AXIS_X, centerValue);
}

void loop() {
  // put your main code here, to run repeatedly:

}
