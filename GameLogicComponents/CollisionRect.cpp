#pragma once
#include "CollisionRound.cpp"
#include "Collision.cpp"

class CollisionRect: public Collision{

    private:
        float center[2] = {0.0f, 0.0f};
        float height = 0.0f;
        float width = 0.0f;

    public:
        CollisionRect(float cx, float cy, float w, float h) {
            center[0] = cx;
            center[1] = cy;
            height = h;
            width = w;
        }

        float getCenterX() const override{
            return center[0];
        }
        float getCenterY() const override{
            return center[1];
        }
        float getHeight(){
            return height;
        }
        float getWidth(){
            return width;
        }

        bool hasCollided(Collision &c) const override{

             if(CollisionRect* cRect = dynamic_cast<CollisionRect*>(&c)) {
                float farLeft = center[0] - width/2.0f;
                float farRight = center[0] + width/2.0f;
                float farLeftOther = c.getCenterX() - cRect -> getWidth()/2.0f;
                float farRightOther = c.getCenterX() + cRect -> getWidth()/2.0f;

                // height vars (to make life easier)
                float top = center[1] + height/2.0f;
                float bottom = center[1] - height/2.0f;
                float topOther = c.getCenterY() + cRect -> getHeight()/2.0f;
                float bottomOther = c.getCenterY() - cRect -> getHeight()/2.0f;

                // this rect smaller

                if( (farLeft > farLeftOther && farLeft < farRightOther) ||
                    (farRight > farLeftOther && farRight < farRightOther)
                    ){
                        if((top > bottomOther && top < topOther) ||
                            (bottom > bottomOther && bottom < topOther)
                        ){
                            return true;
                        } 
                }

                // other rect smaller
                if( (farLeftOther > farLeft && farLeftOther < farRight) ||
                    (farRightOther > farLeft && farRight < farRight)
                    ){
                        if((topOther > bottom && topOther < top) ||
                            (bottomOther > bottom && bottomOther < top)
                        ){
                            return true;
                        }
                }
             }else if(CollisionRound* cRound = dynamic_cast<CollisionRound*>(&c)){
                return false; // fix later for collisionRound
             }

            // width vars (to make life easier)
            return false;
        }
};
