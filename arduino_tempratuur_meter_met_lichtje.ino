#include <OneWire.h>
#include <DallasTemperature.h>

float temp = 0.0;
int oneWireBus(oneWireBus);
OneWire oneWire = 12;
DallasTemperature sensors(&oneWire);

void setup(void) {
  Serial.begin(9600);
  pinMode(LED_BUILTIN, OUTPUT);
  Serial.println("dit lijkt te werken");
  sensors.begin();
}

void loop(void){
  sensors.requestTemperatures();
  temp = sensors.getTempCByIndex(0);
  Serial.print("tempretuur is: ");
  Serial.println(temp);
  delay(2000);

  if (temp <= 22){
   Serial.println("de tempratuur is minder dan 22Cº");
   digitalWrite(LED_BUILTIN, HIGH);   // turn the LED on (HIGH is the voltage level)
   delay(500);                       // wait for a second
   digitalWrite(LED_BUILTIN, LOW);    // turn the LED off by making the voltage LOW
   delay(500);                       // wait for a 
  }
}
