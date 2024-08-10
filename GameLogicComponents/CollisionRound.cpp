#pragma once
#include "Collision.cpp"

class CollisionRound: public Collision{
    private:
        float center[2] = {0.0f, 0.0f};
        float radiusX = 0.0f;
        float radiusY = 0.0f;

    public:
        CollisionRound(float cx, float cy, float rx, float ry){
            center[0] = cx;
            center[1] = cy;
            radiusX = rx;
            radiusY = ry;
        }

        float getCenterX() const override{
            return center[0];
        }
        float getCenterY() const override{
            return center[1];
        }
        float getRadiusX(){
            return radiusX;
        }
        float getRadiusY(){
            return radiusY;
        }

        bool hasCollided(Collision &c) const override{
            return false; // fix later
        }

        /*bool hasCollided(CollisionRound &c) const override{
            float maxX = radiusX + c.getRadiusX();
            float maxY = radiusY + c.getRadiusY();
            float distX = center[0] - c.getCenterX();
            float distY = center[1] - c.getCenterY();

            //float odist = sqrt((distX * distX) + distY * distY);

            //overall dist: oDist=sqrt((xdist/W)*(xdist/W)+ydist*ydist)

            // need to fix

            if(distX < maxX && distY < maxY){
                return true;
            }

            return false;
        }*/
};