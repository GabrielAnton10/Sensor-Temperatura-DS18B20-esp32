#include <OneWireESP32.h>
#include <OneWire.h>
#include <DallasTemperature.h>

const int PINO_ONEWIRE = 12;
OneWire oneWire(PINO_ONEWIRE); 
DallasTemperature sensor(&oneWire);
DeviceAddress endereco_temp;  

void setup() {
  Serial.begin(9600); 
  Serial.println("Medindo Temperatura"); 
  sensor.begin();
}
  
void loop() {
  sensor.requestTemperatures();  
  if (!sensor.getAddress(endereco_temp, 0)) {
    Serial.println("SENSOR NAO CONECTADO"); 
  } else {
    Serial.print("Temperatura = "); 
    Serial.println(sensor.getTempC(endereco_temp), 1); 
  }
  delay(1000);  
}
