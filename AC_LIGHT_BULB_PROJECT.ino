#include <IRremote.hpp>

#define IR_RECEIVE_PIN 11
#define RELAY_PIN 7

void setup() {
  Serial.begin(9600);

  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW);

  IrReceiver.begin(IR_RECEIVE_PIN, ENABLE_LED_FEEDBACK);

  Serial.println("IR Remote Light Control Ready");
}

void loop() {
  if (IrReceiver.decode()) {

    uint8_t command = IrReceiver.decodedIRData.command;

    Serial.print("Command: 0x");
    Serial.println(command, HEX);

    // BUTTON 1 = LIGHT ON
    if (command == 0x18) {
      digitalWrite(RELAY_PIN, HIGH);
      Serial.println("BUTTON 1 -> LIGHT OFF");
    }

    // BUTTON 2 = LIGHT OFF
    else if (command == 0x0C) {
      digitalWrite(RELAY_PIN, LOW);
      Serial.println("BUTTON 2 -> LIGHT ON");
    }

    IrReceiver.resume();
  }
}