#include <math.h>
int sensorPin = A5; // select the input pin for the potentiometer double
double Thermistor(int RawADC)
{ 
  double Temp;

Temp = log(10000.0*((1024.0/RawADC-1)));
Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp
))* Temp );
Temp = Temp - 273.15; // Convert Kelvin to Celcius
//Temp = (Temp * 9.0)/ 5.0 + 32.0; // Convert Celcius to Fahrenheit 
return Temp; 

}

void setup()
{
  pinMode(13,OUTPUT);
  Serial.begin(9600); 
}
void loop() {
int readVal=analogRead(sensorPin); 
double temp =Thermistor(readVal);
 //displaytempaturesss
//Serial.println(readVal); // display tempature
delay(500); 
Serial.println(temp);
 if (	temp < 20){
  	digitalWrite(13,HIGH);
  
  }else {
    	digitalWrite(13,LOW);
  }
}

  
