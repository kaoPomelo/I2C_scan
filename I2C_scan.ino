# include <Wire.h>
byte error, address;
int nDevices;

void setup() {
  Wire.begin();
  Serial.begin(115200);
  Serial.println("nI2C Scanner");

  Serial.println("Scanning...");
  nDevices = 0;

}

void loop() {
  for (address = 1; address < 127; address++ ) {
    Wire.beginTransmission(address);
    error = Wire.endTransmission();
    if (error == 0) {
      Serial.print("I2C device found at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
      nDevices++;
    }
    else if (error == 4) {
      Serial.print("Unknown error at address 0x");
      if (address < 16) {
        Serial.print("0");
      }
      Serial.println(address, HEX);
    }
  }
  if (nDevices == 0) {
    Serial.println("No I2C devices foundn");
  }
  else {
    Serial.println("donen");
  }
  delay(5000);
  Serial.print("i2c devices found:");
  Serial.println(nDevices);
  nDevices = 0;
}
