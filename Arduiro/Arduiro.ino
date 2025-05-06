#include <DHT.h>
#define DHTPIN 19         
#define DHTTYPE DHT11

const int flameSensorPin = 18;  
const int buzzerPin = 21;       
DHT dht(DHTPIN, DHTTYPE);  

void setup() {
  pinMode(flameSensorPin, INPUT); 
  pinMode(buzzerPin, OUTPUT);     
  Serial.begin(115200);
  dht.begin();                     
}

void loop() {
  int flameStatus = digitalRead(flameSensorPin);

  float humidity = dht.readHumidity();
  float temperature = dht.readTemperature(); 

  if (isnan(humidity) || isnan(temperature)) {
    Serial.println("Failed to read from DHT sensor!");
    return;
  }
  Serial.print("Humidity: ");
  Serial.print(humidity);
  Serial.print(" %\t");
  Serial.print("Temperature: ");
  Serial.print(temperature);
  Serial.println(" *C");
  Serial.print("Flame Sensor Status: ");
  Serial.println(flameStatus); 

  if (flameStatus == HIGH) {
    digitalWrite(buzzerPin, LOW);  
    Serial.println("Fire detected!");
    
    delay(1000);  
  }
 
  else {
    digitalWrite(buzzerPin, HIGH); 
    Serial.println("No fire.");
  }

  delay(1000); 
} 
