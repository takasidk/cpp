/* Header for Moving 3D Points with int coords (MovablePoint.h) */
#ifndef MOVING_POINT_H
#define MOVING_POINT_H

#include "Point.h" // Include header of the base class

class MovablePoint : public Point
{ // MovablePoint is a subclass of Point public inheritance
private:
    int xSpeed, ySpeed;

public:
    MovablePoint(int x, int y, int xSpeed = 0, int ySpeed = 0);
    int getXSpeed() const;
    int getYSpeed() const;
    void setXSpeed(int xSpeed);
    void setYSpeed(int ySpeed);
    void move();
    void print() const;
};

#endif