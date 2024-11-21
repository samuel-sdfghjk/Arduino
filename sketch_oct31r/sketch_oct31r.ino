#include <Servo.h>  
Servo servo;     

int trigPin = 5;    
int echoPin = 6;   
int servoPin = 7;
int signalPin = 2;
int conducPin = A0;

long duration, dist;
long aver[3];

void setup() {       
    servo.attach(servoPin);  
    pinMode(trigPin, OUTPUT);  
    pinMode(signalPin, OUTPUT);  
    pinMode(echoPin, INPUT); 
    pinMode(conducPin, INPUT); 
    servo.write(0);         
    delay(100);
    servo.detach(); 
    Serial.begin(9600);
}

void measure() {  
    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    
    duration = pulseIn(echoPin, HIGH);
    dist = (duration / 2) / 29.1;    
   // Serial.println(dist);
}

void loop() { 
    
    for (int i = 0; i < 3; i++) { // Distancia promedio
        measure();               
        aver[i] = dist;            
        delay(100);             
    }
    dist = (aver[0] + aver[1] + aver[2]) / 3;    

    if (dist < 15) { // Cambia la distancia según sea necesario

        leerConductividad();


        servo.attach(servoPin);
        delay(1);
        servo.write(90);  
        delay(5000);
        servo.write(0);    
        delay(300);
        servo.detach();      
    }

}

void leerConductividad(){
    digitalWrite(signalPin, HIGH);
    delay(200);
    int conduct = analogRead(conducPin);
    Serial.println(conduct);
    delay(200);O
    digitalWrite(signalPin, LOW);

}
