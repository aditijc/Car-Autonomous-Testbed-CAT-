#include <SoftwareSerial.h>

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
  delay(5000); // wait for Serial1 to be ready
  if (!Serial1.available()) {
    Serial.println("Error initializing Serial1");
  } else {
    Serial.println("Serial1 initialized successfully");
  }
}

void loop() {
  // Send "AT+ADDR?" command to HC-05 module
  Serial1.println("AT+ADDR?");

  // Read response from HC-05 module
  String incomingData = "";
  while (Serial1.available()) {
    incomingData += ((char)((uint8_t)Serial1.read()));
  }

  if (incomingData.length() > 0) {
    Serial.println("HC-05 address: " + incomingData);
  }
}
