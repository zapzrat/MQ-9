void setup() {
  Serial.begin(9600);
  Serial.println("Micro Project Thailand ~^.^~ ");
}

void loop() {
  float sensor_volt;
  float RS_air; //  Get the value of RS via in a clear air
  float R0;  // Get the value of R0 via in LPG
  float sensorValue;




  /*--- Get a average data by testing 100 times ---*/
  //  for (int x = 0 ; x < 100 ; x++)
  //  {
  //    sensorValue = sensorValue += analogRead(A0);
  //  }
  //  sensorValue = sensorValue / 100.0;

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


  delay(1000);

}
