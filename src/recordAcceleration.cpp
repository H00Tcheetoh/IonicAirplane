#include "Plane.h"

void Plane::recordAcc_X(MPU6050 planeMPU)
{
    vectorAcc_X.push_back(planeMPU.getAccelerationX());

    if(vectorAcc_X.size() >= maxMeasurements)
    {   
      saveSD();
      clearVector();
    }

    Serial.println(vectorAcc_X.back());
}

void Plane::recordAcc_Y(MPU6050 planeMPU)
{
    vectorAcc_Y.push_back(planeMPU.getAccelerationY());

    if(vectorAcc_Y.size() >= maxMeasurements)
    {   
      saveSD();
      clearVector();
    }

    Serial.println(vectorAcc_Y.back());
}

void Plane::recordAcc_Z(MPU6050 planeMPU)
{
    vectorAcc_Z.push_back(planeMPU.getAccelerationZ());

    if(vectorAcc_Z.size() >= maxMeasurements)
    {   
      saveSD();
      clearVector();
    }

    Serial.println(vectorAcc_Z.back());
}