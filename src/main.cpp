#include <Arduino.h>
#include <Wire.h>
#include <Plane.h>

Plane myPlane;
MPU6050 planeMPU;
Servo leftServo;
Servo rightServo;
Servo rudder;

enum planeState {
  INITIALIZING,
  FLYING,
  LOCKOUT,
};

planeState currentState = INITIALIZING;

void setup() {
  Serial.begin(9600);
  Serial.println("Beginning Initialization Process");

  leftServo.attach(1);
  rightServo.attach(2);
  rudder.attach(3);


}

void loop() {
  switch (currentState)
  {
    case INITIALIZING:
    {
      Serial.println("In State INITIALIZING");
      delay(2000);

      currentState = FLYING;
    }

    case FLYING:
    {
      Serial.println("In State Flying");

      myPlane.recordAcc_X(planeMPU);
      myPlane.recordAcc_Y(planeMPU);
      myPlane.recordAcc_Z(planeMPU);

    }
    
    case LOCKOUT:
    {
      myPlane.solveVelocity();
    }
  }
}