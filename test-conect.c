// este codigo detecta si esta
#include <Wire.h>

void setup() {
  Wire.begin(21, 22);  // SDA, SCL
  Serial.begin(115200);
  delay(1000);
  Serial.println("Escaneo I2C iniciado...");
}

void loop() {
  byte error, address;
  int nDevices = 0;

  for(address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();

    if (error == 0) {
      Serial.print("Dispositivo encontrado en 0x");
      if(address<16) Serial.print("0");
      Serial.println(address, HEX);
      nDevices++;
    }
  }

  if(nDevices == 0) Serial.println("No se encontró ningún dispositivo I2C");
  else Serial.println("Escaneo terminado");

  delay(5000); // Escanea cada 5 segundos
}
