#include <IRremote.h>

// Define pins for IR receiver and LEDs
int ir_receiver = 11;
int led_pin1 = 12;
int led_pin2 = 9;

// Define hex values to turn LEDs on/off
long led_onoff1 = 0xF720DF;
long led_onoff2 = 0xF7A05F;

// Create an IRremote object
IRrecv irrecv(ir_receiver);
decode_results results;

void setup() {
  // Initialize IR receiver
  irrecv.enableIRIn();
  
  // Initialize LED pins as outputs and turn both LEDs off
  pinMode(led_pin1, OUTPUT);
  digitalWrite(led_pin1, LOW);
  pinMode(led_pin2, OUTPUT);
  digitalWrite(led_pin2, LOW);
}

void loop() {
  if (irrecv.decode(&results)) {
    // Check received IR code and toggle corresponding LED on/off
    if (results.value == led_onoff1) {
      digitalWrite(led_pin1, !digitalRead(led_pin1));
    } else if (results.value == led_onoff2) {
      digitalWrite(led_pin2, !digitalRead(led_pin2));
    }
    
    irrecv.resume(); // receive the next value
  }
}
