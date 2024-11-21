#include <Servo.h>

const int sensorIRPin = A0; 
const int sensorProxPin = 2; 

const int servoAluminioPin = 9; 
const int servo2Pin = 10; 

int valorIR = 0;
int valorProximidad = 0;

Servo servoAluminio;
Servo servo2;

void setup() {

  Serial.begin(9600);
  
  pinMode(sensorProxPin, INPUT);

  servoAluminio.attach(servoAluminioPin);
  servo2.attach(servo2Pin);

  servoAluminio.write(0); 
  servo2.write(0); 
}

void loop() {
  
  valorIR = analogRead(sensorIRPin);
  
  valorProximidad = digitalRead(sensorProxPin);
  
  Serial.print("Valor IR: ");
  Serial.print(valorIR);
  Serial.print(" | Sensor inductivo: ");
  Serial.println(valorProximidad);
  
  if (valorIR > 700 && valorProximidad == LOW) {
    Serial.println("Aluminio detectado.");
    
    abrirCompuertaAluminio();
  }
  
  else if (valorIR > 700 && valorProximidad == HIGH) {
    Serial.println("Material detectado. No es aluminio.");
    
    abrirCompuerta2();
  }
  else {
    Serial.println("No se detecta material.");
  }
  
  delay(1000); 
}

void abrirCompuertaAluminio() {
  servoAluminio.write(90); 
  delay(2000); 
  servoAluminio.write(0);
}

void abrirCompuerta2() {
  servo2.write(90); 
  delay(2000); 
  servo2.write(0); 
}
