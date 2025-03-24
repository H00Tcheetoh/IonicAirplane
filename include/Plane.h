#ifndef PLANE_H
#define PLANE_H

#include <Arduino.h>
#include <vector>
#include <MPU6050.h>
#include <ESP32Servo.h>
#include <SD.h>
#include <SPI.h>

class Plane {
    public:
        std::vector<float> vectorAcc_X;
        std::vector<float> vectorAcc_Y;
        std::vector<float> vectorAcc_Z;
        std::vector<unsigned long> timeStamp;

        size_t maxMeasurements = 100;

        void recordAcc_X(MPU6050 planeMPU);
        void recordAcc_Y(MPU6050 planeMPU);
        void recordAcc_Z(MPU6050 planeMPU);

        void saveSD();
        void solveVelocity();
        void clearVector();
        void startTimer();

        void moveLeft(Servo leftServo);
        void moveRight(Servo rightServo);
        void moveRudder(Servo rudder);
};

#endif
