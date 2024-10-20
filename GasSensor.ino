// GasDetection.ino

#define GAS_SENSOR_PIN 32  // Pin for MQ-2 gas sensor
#define LED_PIN 26         // Pin for LED
#define GAS_THRESHOLD 600  // Example gas threshold, adjust as needed

void setup() {
  Serial.begin(115200);      // Initialize serial communication
  pinMode(GAS_SENSOR_PIN, INPUT);  // Setup gas sensor pin
  pinMode(LED_PIN, OUTPUT);        // Setup LED pin
}

void loop() {
  float gasLevel = analogRead(GAS_SENSOR_PIN);  // Read the gas sensor value
  Serial.print("Gas Level: ");
  Serial.println(gasLevel);  // Print gas level to Serial Monitor

  if (gasLevel > GAS_THRESHOLD) {
    // Gas detected - Blink LED at 1 second interval (1000 ms)
    blinkLED(1000);
  } else {
    // No gas detected - Turn off LED
    digitalWrite(LED_PIN, LOW);
  }

  delay(1000);  // Delay for 1 second between readings
}

// Function to blink LED at a specific interval
void blinkLED(int interval) {
  static unsigned long lastTime = 0;
  unsigned long currentTime = millis();

  if (currentTime - lastTime >= interval) {
    lastTime = currentTime;
    // Toggle LED state
    digitalWrite(LED_PIN, !digitalRead(LED_PIN));
  }
}
