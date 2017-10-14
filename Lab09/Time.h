#ifndef TIME_H
#define TIME_H
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;
class Time {
    int h;
    int m;
    int s;

    void eq(){
        if(s > 60){
            s -= 60;
            m++;
        }
        if(m > 60){
            m -= 60;
            h++;
        }
        if(h > 24){
            h -= 24;
        }
        
    }
public:
    Time(){
        this->h = 0;
        this->m = 0;
        this->s = 0;
    }
    Time(int hours, int minutes, int seconds){
        this->h = hours;
        this->m = minutes;
        this->s = seconds;
    }
    ~Time(){
}
    void add(const Time& that){
        this->h += that.h;
        this->m += that.m;
        this->s += that.s;
        eq();
    }
    void getAngles(float& a, float& b, float& c){
        float theta = 2 * M_PI / 60;
        float rAng = M_PI / 2;
        float rH = (float)h + (float)m / 60;
        a = -rAng;
        b = -rAng;
        c = -rAng;
        if(rH <= 6)
            a += theta * 5 * (6 - rH);
        else
            a += theta * 5 * (12 - rH) + M_PI;

        if(m <= 30)
            b += theta * (30 - m);
        else
            b += theta * (60 - m) + M_PI;

        if(s <= 30)
            c += theta * (30 - s);
        else
            c += theta * (60 - s) + M_PI;
    }
    void getHourCoords(float& x, float& y){
        float a;
        float theta = 2 * M_PI / 60;
        float rH = (float)h + (float)m / 60;
        if(rH <= 6)
            a = theta * 5 * (6 - rH) - M_PI / 2;
        else
            a = theta * 5 * (12 - rH) + M_PI / 2;  

        x = cos(a);
        y = sin(a);
    }
    void getMinuteCoords(float& x, float& y){
        float a;
        float theta = 2 * M_PI / 60;
        if(m <= 30)
            a = theta * (30 - m) - M_PI / 2;
        else
            a = theta * (60 - m) + M_PI / 2;

        x = cos(a);
        y = sin(a);
    }
    void getSecondsCoords(float& x, float& y){
        float a;
        float theta = 2 * M_PI / 60;
        if(m <= 30)
            a = theta * (30 - s) - M_PI / 2;
        else
            a = theta * (60 - s) + M_PI / 2;

        x = cos(a);
        y = sin(a);
    }
    int getHours(){ return h;}
    int getMinutes(){ return m;}
    int getSeconds(){ return s;}
    int setHours(int hours){ this->h = hours;}
    int setMinutes(int minutes){ this->m = minutes;}
    int setSeconds(int seconds){ this->s = seconds;}
};
#endif
