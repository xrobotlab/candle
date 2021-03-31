#ifndef _MD80_H_
#define _MD80_H_

#include "canalizator.hpp"

#include <cstdint>
#include <vector>

enum md80_mode
{
    POSITION_PID = 0x01,
    VELOCITY_PID = 0x02,
    CASCADE_PID = 0x03,
    TORQUE_CTL = 0x04,
    IMPEDANCE_CTL = 0x05
};

class Md80
{
private:
    int id;
    float position;
    float velocity;
    float torque;
    uint16_t errorVector;
    Canalizator *pCan;
    float posTarget;
    float velTarget;
    float kp;
    float kd;
    float tqFf;
    float maxOutput;
public:
    Md80(Canalizator *can, int id);
    void parseResponse(char rxBuffer[]);
    bool enableMotor(bool enable);
    bool setMode(int mode);
    bool setImpedance();
    bool setImpedance(float _kp, float _kd, float _posTarget, float _velTarget, float _torque, float _maxOutput);
    static std::vector<int> sendPing(Canalizator*pCan, int idStart, int idEnd);
    void printInfo();
};

#endif