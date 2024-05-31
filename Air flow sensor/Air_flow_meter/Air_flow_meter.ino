/*
  ReadAirFlowRate

  Reads an analog input on pin A1, converts it to a voltage, maps it to the air flow rate,
  and prints the result to the Serial Monitor.

*/

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
  // Ensure initial air flow rate is appropriate
  Serial.println("Starting air flow rate measurement...");
}

// the loop routine runs over and over again forever:
void loop() {
  // read the input on analog pin A1:
  int sensorValue = analogRead(A1);
  // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Map the voltage to the air flow rate
  float airFlowRate;
  if (voltage < 1.0) {
    airFlowRate = 0.0; // Set air flow rate to 0 when voltage is below 1V
  } else {
    airFlowRate = map(voltage, 1.0, 5.0, 20.0, 200.0);
  }
  
  // Print out the values you read:
  Serial.print("Voltage: ");
  Serial.print(voltage);
  Serial.print(" V, Air Flow Rate: ");
  Serial.print(airFlowRate);
  Serial.println(" L/min");

  // Delay for a moment before the next reading
  delay(50); // 50 milliseconds delay
}

// Custom map function to handle float values
float map(float x, float in_min, float in_max, float out_min, float out_max) {
  return (x - in_min) * (out_max - out_min) / (in_max - in_min) + out_min;
}
