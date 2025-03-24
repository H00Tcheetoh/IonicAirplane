#include "Plane.h"

void Plane::saveSD()
{
    File dataLog = SD.open("plane_data.txt", FILE_WRITE);

    if (dataLog)
    {
        // Write the header
        dataLog.println("Acceleration X (m/s^2) | Acceleration Y (m/s^2) | Acceleration Z (m/s^2) | Timestamp (s)");

        char buffer[100];

        for (size_t i = 0; i < maxMeasurements; ++i)
        {
            Serial.println("-----Writing to SD CARD-----");
            sprintf(buffer, "%-22.2f | %-22.2f | %-22.2f | %.3f", vectorAcc_X[i], vectorAcc_Y[i], vectorAcc_Z[i], timeStamp[i] / 1000.0);
            dataLog.println(buffer);
        }
    }

    dataLog.close();
}

void Plane::solveVelocity()
{
    std::vector<float> storedAcc_x, storedAcc_y, storedAcc_z;
    std::vector<unsigned long> timeStamp;

    File dataLog = SD.open("plane_data.txt", FILE_READ);

    dataLog.readStringUntil('\n');

    while (dataLog.available())
    {
        String dataStream = dataLog.readStringUntil('\n');
        float accX, accY, accZ, time;

        sscanf(dataStream.c_str(), "%f | %f | %f | %f", &accX, &accY, &accZ, &time);

        storedAcc_x.push_back(accX);
        storedAcc_y.push_back(accY);
        storedAcc_z.push_back(accZ);

        timeStamp.push_back(static_cast<unsigned long>(time * 1000)); // Convert back to milliseconds
    }



    dataLog.close();
}

void Plane::clearVector()
{
    vectorAcc_X.clear();
    vectorAcc_Y.clear();
    vectorAcc_Z.clear();
    timeStamp.clear();
}

void Plane::startTimer()
{
    
}

void Plane::moveLeft(Servo leftServo)
{
    
}

void Plane::moveRight(Servo rightServo)
{
}

void Plane::moveRudder(Servo rudder)
{
}
