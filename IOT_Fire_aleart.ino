/* Comment this out to disable prints and save space */
#define BLYNK_PRINT Serial

/* Fill in information from Blynk Device Info here */
#define BLYNK_TEMPLATE_ID "TMPL3nW1QfkfN"
#define BLYNK_TEMPLATE_NAME "Quickstart Template"
#define BLYNK_AUTH_TOKEN "9BtHsdcEmc8dXqigdhKcH9xKz5H1pWMO"

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

// Your WiFi credentials
char ssid[] = "JAY";
char pass[] = "87654321";

// IR Sensor pin
#define IR_SENSOR_PIN 19  // Replace with your IR sensor pin

void setup()
{
  // Debug console
  Serial.begin(9600);
  
  // Blynk connection
  Blynk.begin(BLYNK_AUTH_TOKEN, ssid, pass);

  // Initialize IR sensor pin
  pinMode(IR_SENSOR_PIN, INPUT);
}

void loop()
{
  Blynk.run();
  checkFire();
}

void checkFire()
{
  // Read IR sensor value
  int fireDetected = digitalRead(IR_SENSOR_PIN);

  if (fireDetected == LOW) {
    // Fire detected
    Serial.println("Fire Detected!");
    
    // Send '1' to Blynk app (indicating fire detected)
    Blynk.virtualWrite(V1, 1);
  } 
  else {
    // No fire detected
    Serial.println("No Fire Detected.");

    // Send '0' to Blynk app (indicating no fire detected)
    Blynk.virtualWrite(V1, 0);
  }
  
  delay(1000); // Check every second
}
