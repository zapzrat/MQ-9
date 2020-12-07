const int ledStatus = 13;

void setup() {
  Serial.begin(9600);
  Serial.println("Micro Project Thailand ~^.^~ ");

  pinMode(ledStatus, OUTPUT);
}

void loop() {
  float sensor_volt;
  float RS_air; //  Get the value of RS via in a clear air
  float R0;  // Get the value of R0 via in LPG
  float sensorValue;


  sensorValue = analogRead(A0);
  /*-----------------------------------------------*/

  sensor_volt = sensorValue / 1024 * 5.0;
  RS_air = (5.0 - sensor_volt) / sensor_volt; // omit *RL
  R0 = RS_air / 9.9; // The ratio of RS/R0 is 9.9 in LPG gas


  Serial.print("sensorValue = ");
  Serial.print(sensorValue);

  Serial.print("    ");

  Serial.print("sensor_volt = ");
  Serial.print(sensor_volt);
  Serial.print("V");

  Serial.print("    ");
  Serial.print("R0 = ");
  Serial.print(R0);

  Serial.println("");

  if (sensor_volt >= 2) {
    digitalWrite(ledStatus, HIGH);
  }
  else if(sensor_volt < 2){
    digitalWrite(ledStatus, LOW);
  }


  delay(1000);

}
