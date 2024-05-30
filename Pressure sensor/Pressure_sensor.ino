const int sensorPin = A0;

const int offset = 201; // zero pressure adjust
const int fullScale = 1023; // max pressure adjust

float sensorType = 1000.0; // kPa, change this if your sensor type is different
float pressure; // final pressure in kPa
float pressureInBars; // final pressure in bars
const float atmosphericPressure = 1.0; // atmospheric pressure in bars

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Calculate pressure in kPa
  pressure = (analogRead(sensorPin) - offset) * sensorType / (fullScale - offset);

  // Convert pressure to bars and add atmospheric pressure
  pressureInBars = (pressure / 100.0) + atmosphericPressure;

  // Print the pressure in bars with the unit
  Serial.print(pressureInBars, 4); // Print pressure in bars with 4 decimal places
  Serial.println(" bars"); // Print the unit

  delay(100);
}
