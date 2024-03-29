#pragma once
#include <string>

struct PortSettings
{
    std::string Port;
    int BaudRate = 13; // 9600
    int DataBits = 3;
    int StopBits = 0;
    int Parity = 0;
};