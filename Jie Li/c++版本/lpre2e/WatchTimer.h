#pragma once
#ifndef _WIN32
#error CWatchTimer just work on Windows Platform
#endif

#include <windows.h> 

class CWatchTimer
{
public:
    CWatchTimer()
    {
        QueryPerformanceFrequency(&m_frequency);
        m_quadpart = (double)m_frequency.QuadPart; 
    }

    LARGE_INTEGER start()
    {
        QueryPerformanceCounter(&m_timeStart);
        return m_timeStart;
    }

    double elapsed() //返回上一次start到此时所花费的时间，单位:秒,精度:微秒
    {
        LARGE_INTEGER timeEnd;      //结束时间  
        QueryPerformanceCounter(&timeEnd);
        if (m_quadpart == 0)
            return 0;

        return (timeEnd.QuadPart - m_timeStart.QuadPart) / m_quadpart /** 1000000*/;
    }

private:
    LARGE_INTEGER m_timeStart;
    LARGE_INTEGER m_frequency;       
    double        m_quadpart;        

};