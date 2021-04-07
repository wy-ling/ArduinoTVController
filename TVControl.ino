#include <IRremote.h>

const int downbutton = 7;
const int upbutton = 6;
const int onoffbutton = 5;
 
// Define a variable for the button state
int upvolume = 0;
int downvolume = 0;
int onoff = 0;
 
// Create IR Send Object
IRsend irsend;
 
void setup()
{
  // Set Switch pin as Input
  pinMode(downbutton, INPUT);
  pinMode(upbutton, INPUT);
  pinMode(onoffbutton, INPUT);
}
 
void loop() {
  
  // Set button state depending upon switch position
  upvolume = digitalRead(upbutton);
  downvolume = digitalRead(downbutton);
  onoff = digitalRead(onoffbutton);
  
  // If button is pressed send power code command
   if (upvolume == HIGH) {
    irsend.sendNEC(0xE0E0E01F, 32); // TV power code
   }
   else if (downvolume == HIGH) {
    irsend.sendNEC(0xE0E0D02F, 32);
   }
   else if (onoff == HIGH) {
    irsend.sendNEC(0xE0E040BF, 32);
   }  
    // Add a small delay before repeating
  delay(200);
} 
