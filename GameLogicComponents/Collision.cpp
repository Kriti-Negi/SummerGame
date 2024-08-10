#pragma once
#include <cmath>
#include <iostream>

using namespace std;

class Collision
{
public:
    virtual bool hasCollided(Collision &c) const = 0;  
    virtual float getCenterX() const = 0;
    virtual float getCenterY() const = 0;
};