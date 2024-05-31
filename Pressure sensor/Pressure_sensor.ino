const int sensorPin = A1; // Analog pin where the sensor is connected

// New constants for the pressure calculation
const float voltageLowerLimit = 1.0; // Voltage lower limit in volts
const float voltageUpperLimit = 5.0; // Voltage upper limit in volts
const float pressureRangePsi = 100.0; // Pressure range of the sensor in psi
const float psiToBar = 0.0689476; // Conversion factor from psi to bars
const float atmosphericPressureOffset = 1.0; // Offset for atmospheric pressure in bars

float voltageReading; // Variable to store the voltage reading
float pressure; // Variable to store pressure in bars
float calfac = 1.68; // Calibration factor calculated by taking the average ratio between the bicycle pump measurement to arduino sensor measurement

void setup() {
  Serial.begin(9600); // Initialize serial communication at 9600 bps
}

void loop() {
  // Read the analog value from the sensor and convert to voltage
  voltageReading = analogRead(sensorPin) * (5.0 / 1023.0);

  // Calculate pressure in bars using the converted formula and apply calibration factor
  pressure = psiToBar * pressureRangePsi * (voltageReading - voltageLowerLimit) / (voltageUpperLimit - voltageLowerLimit);
  pressure = pressure * calfac;



  // Print the pressure in bars with the unit
  Serial.print(pressure, 4); // Print pressure in bars with 4 decimal places
  Serial.println(" bars"); // Print the unit

  delay(100); // Wait for 100 milliseconds before the next reading
}
