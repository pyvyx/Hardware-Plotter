#pragma once
#include <iostream>
#include <ostream>
#define End std::endl

#ifdef DEBUG
struct Logger
{
private:
    const char* const m_LogInfo;
    mutable bool newLine = true;
public:
    inline explicit Logger(const char* info) noexcept : m_LogInfo(info) {}

    inline const Logger& operator<<(std::ostream& (*osmanip)(std::ostream&)) const noexcept
    {
        std::cout << *osmanip;
        newLine = true;
        return *this;
    }

    template <class T>
    inline const Logger& operator<<(const T& mess) const noexcept
    {
        if (newLine)
        {
            std::cout << m_LogInfo;
            newLine = false;
        }
        std::cout << mess;
        return *this;
    }
};
inline const Logger Log("[INFO] ");
inline const Logger Err("[ERROR] ");

#else
struct Logger
{
    inline const Logger& operator<<(std::ostream& (*)(std::ostream&)) const noexcept
    {
        return *this;
    }

    template <class T>
    inline const Logger& operator<<(const T&) const noexcept
    {
        return *this;
    }
};
inline const Logger Log;
inline const Logger Err;
#endif