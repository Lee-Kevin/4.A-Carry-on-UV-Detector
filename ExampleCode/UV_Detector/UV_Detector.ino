/*
    This is a demo to test Grove - Sunlight Sensor library

*/

#include <Wire.h>
#include "Arduino.h"
#include "SI114X.h"
#include <Grove_LED_Bar.h>
SI114X SI1145 = SI114X();

Grove_LED_Bar bar(5, 3, 0);  // Clock pin, Data pin, Orientation
uint16_t number[10] = {0x01,0x03,0x07,0x0f,0x1f,0x3f,0x7f,0xff,0x1ff,0x3ff};
float UVIndex = 0;
void setup() {
  Wire.begin();

  Serial.begin(115200);
  Serial.println("Beginning Si1145!");
  while (!SI1145.Begin()) {
    Serial.println("Si1145 is not ready!");
    delay(1000);
  }
}
void loop() {
  Serial.print("//--------------------------------------//\r\n");
  Serial.print("Vis: "); Serial.println(SI1145.ReadVisible());
  Serial.print("IR: "); Serial.println(SI1145.ReadIR());
  //the real UV value must be div 100 from the reg value , datasheet for more information.
  Serial.print("UV: ");  Serial.println((float)SI1145.ReadUV()/100);
  UVIndex = (float)SI1145.ReadUV()/100 + 0.5;
  bar.setBits(number[(int)(UVIndex)]);
  delay(1000);
}
