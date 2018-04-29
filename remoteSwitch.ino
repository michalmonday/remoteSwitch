#define RELAY_INPUT_PIN 10

#include <SoftwareSerial.h>

SoftwareSerial bt(9, 8);

void setup() {
  pinMode(RELAY_INPUT_PIN, OUTPUT);
  digitalWrite(RELAY_INPUT_PIN, HIGH);
  Serial.begin(9600);
  bt.begin(9600);
}

void loop() {

  if (bt.available()) {
    char c = bt.read();
    Serial.write(c);

    if(c == '1'){     
      digitalWrite(RELAY_INPUT_PIN, HIGH);
      bt.println("Activated");
      Serial.println("Activated");
    }else if(c == '0'){
      digitalWrite(RELAY_INPUT_PIN, LOW);
      Serial.println("Deactivated");
      bt.println("Deactivated");
    }else if(c == '2'){
      digitalWrite(RELAY_INPUT_PIN, LOW);
      delay(600);
      digitalWrite(RELAY_INPUT_PIN, HIGH);
      Serial.println("Resetted");
      bt.println("Resetted");
    }
  }

  if (Serial.available()) {
    bt.write(Serial.read());
  }
}
