#define MOTOR1_IN1 12
#define MOTOR1_IN2 13
#define MOTOR2_IN1 9
#define MOTOR2_IN2 10
#include <Servo.h>

Servo servo1;  // create servo object to control a servo
Servo servo2;
// twelve servo objects can be created on most boards

int pos = 0;  // variable to store the servo position

void rampMotor1();
void rampMotor2();
void pitchUp(int);
void pitchDown(int);



void setup() {
  Serial.begin(9600);

  Serial.println("DRV8871 test");
  
  pinMode(MOTOR1_IN1, OUTPUT);
  pinMode(MOTOR1_IN2, OUTPUT);
  pinMode(MOTOR2_IN1, OUTPUT);
  pinMode(MOTOR2_IN2, OUTPUT);
  servo1.attach(6);  // attaches the servo on pin 9 to the servo object
  servo2.attach(5);
}

void loop() {

  rampMotor1();
  rampMotor2();
  pitchUp(90);
  pitchDown(90);

}

void pitchUp(int cPos){
   for (pos = 0; pos <= cPos; pos += 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);  // tell servo to go to position in variable 'pos'
    servo2.write(pos);
    delay(15);  // waits 15ms for the servo to reach the position
  }

}
void pitchDown(int cPos){
  for (pos = cPos; pos >= 0; pos -= 1) {  // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);  // tell servo to go to position in variable 'pos'
    servo2.write(pos);
    delay(15);  // waits 15ms for the servo to reach the position
  }
}
void rampMotor1(){
  //ramp up 
  digitalWrite(MOTOR2_IN2, LOW);
  analogWrite(MOTOR2_IN1, 255);
}

void rampMotor2(){
  digitalWrite(MOTOR1_IN1,LOW);
  analogWrite(MOTOR1_IN2,255);
}