/* Implementation for the Time Class (Time.cpp) */
#include <iostream>
#include <iomanip>
#include "Time.h" // include header of Time class
using namespace std;

// Constructor with default values. No input validation
Time::Time(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}
/*
we can use these ways as well
Time::Time(int hour, int minute, int second) {  // Constructor
   this->hour = hour;
   this->minute = minute;
   this->second = second;
}
 
Time::setHour(int hour) {   // Setter for hour
   this->hour = hour;
}
 
Time::getHour() const {  // Getter for hour
   return this->hour;    // this-> is the default, and hence optional
}
(or) member intializer list
Time::Time(int h, int m, int s) : hour(h), minute(m), second(s) { 
   // The body runs after the member initializer list
   // empty in this case
}
*/
// public getter for private data member hour
int Time::getHour() const
{
    return hour;
}

// public setter for private data member hour. No input validation
void Time::setHour(int h)
{
    if (h >= 0 && h < 24)
    {
        hour = h;
    }
    else
    {
        cout << "!Not a valid hour" << endl;
        this->hour = 0;
    }
}

// public getter for private data member minute
int Time::getMinute() const
{
    return minute;
}

// public setter for private data member minute. No input validation
void Time::setMinute(int m)
{
    if (m >= 0 && m < 60)
    {
        minute = m;
    }
    else
    {
        cout << "!Not a valid minute" << endl;
        this->minute = 0;
    }
}

// public getter for private data member second
int Time::getSecond() const
{
    return second;
}

// public setter for private data member second. No input validation
void Time::setSecond(int s)
{
    if (s >= 0 && s < 60)
    {
        second = s;
    }
    else
    {
        cout << "!Not a valid second" << endl;
        this->second = 0;
    }
}

// Set hour, minute and second. No input validation
void Time::setTime(int h, int m, int s)
{
    setHour(h);
    setMinute(m);
    setSecond(s);
}

// Print this Time instance in the format of "hh:mm:ss", zero filled
void Time::print() const
{
    cout << setfill('0');   // zero-filled, need <iomanip>, sticky
    cout << setw(2) << hour // set width to 2 spaces, need <iomanip>, non-sticky
         << ":" << setw(2) << minute
         << ":" << setw(2) << second << endl;
}

// Increase this instance by one second
void Time::nextSecond()
{
    ++second;
    if (second >= 60)
    {
        second = 0;
        ++minute;
    }
    if (minute >= 60)
    {
        minute = 0;
        ++hour;
    }
    if (hour >= 24)
    {
        hour = 0;
    }
}
