// C++ code
//
#include <Adafruit_LiquidCrystal.h>

int seconds = 0;


Adafruit_LiquidCrystal lcd_1(0);

const int tsensor= A5;
const int trigPin = 2;
const int echoPin = 3;
float voltage, T;

  void setup()
{
   lcd_1.begin(16, 2);
   lcd_1.print("Orlando Project");
   delay(5000);
   lcd_1.clear();
   
   pinMode(trigPin, OUTPUT);
   pinMode(echoPin, INPUT);
   
   Serial.begin(9600);
}

void loop()
{
 
  // Read the voltage from the sensor
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  
  
  long duration = pulseIn(echoPin, HIGH);
  // Unity Meters/second
  float speed_ofsound= 331.3*sqrt((273.15+T)/273.15);
  
  //Unity ms/cm
  float sensorunity= 2*(1/(0.0001*speed_ofsound));
  
  //Indicates the distance
  float distance = duration/sensorunity;
  
  
  lcd_1.setCursor(0,0);
  lcd_1.print("Distance:");
  lcd_1.print(distance);
  
  voltage = analogRead(tsensor) * 0.00488;

  // Convert the voltage to degrees Celsius
  T = (voltage - 0.5) * 100.0;
  
  lcd_1.setCursor(0,1);
  lcd_1.print("Temperature:");
  lcd_1.print(T);
  lcd_1.print("ºC");
  
  
  delay(1000);  // Wait for 1
}
