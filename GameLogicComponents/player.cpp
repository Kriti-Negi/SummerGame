#include <string>

#include "Collision.cpp"
#include "DrawableObj.cpp"

class Player : public DrawableObj  {
    private:
        bool isAlive = true;
        CollisionRect* collider;
        float HEIGHT = 10.0f;
        float WIDTH = 10.0f;

        DrawableObj ground; // there has to be a better way

        float currPos[3] = {0.0f, 0.0f, 0.0f}; // change to start pos
        float currVel[2] = {0.0f, 0.0f}; // first is x, second is y
        float currAccel[2] = {-1.0f, -10.0f}; // first is x, second is y (default is friction, gravity)
        float timeBetweenFrames = 0.001;
        
        //animations (should we have an animation class?)

        std::string stand[4] = {
            "", 
            "",
            "",
            ""
        }; // default

        std::string move[4] = {
            "", 
            "",
            "",
            ""
        }; // run

    public:
        Player(float posx, float posy, float posz, DrawableObj d) {
            currPos[0] = posx;
            currPos[1] = posy;
            currPos[2] = posz;

            ground = d; 

            DrawableObj::setNewPos(posx, posy, posz);
            DrawableObj::setHeight(HEIGHT);
            DrawableObj::setWidth(WIDTH);

            DrawableObj::setSprite(stand[0]);
        }

        void applyAcceleration(float accelX, float accelY){
            currAccel[0] = accelX + currAccel[0];
            currAccel[1] = accelY + currAccel[1];
        }

        void applyVelocity(float velX, float velY){
            currVel[0] = velX + currVel[0];
            currVel[1] = velY + currVel[1];
        }

        void teleport(float pos[2]){
            // only changes position
            currPos[0] = pos[0];
            currPos[1] = pos[1];
        }

        void updateMovement(float timeElapsed){
            // updates speed, velocity by applying acceleration
            currVel[0] = currVel[0] + currAccel[0] * timeElapsed;
            currVel[1] = currVel[1] + currAccel[1] * timeElapsed;

            currPos[0] = currVel[0] * timeElapsed + currPos[0];
            currPos[1] = currVel[1] * timeElapsed + currPos[1];
        }

        void getUserInput(int action){ // change later
            if(action == 0){
                //go left
                applyVelocity(-1.0f, 0.0);
            }else if(action == 1){
                // go right
                applyVelocity(1.0f, 0.0);
            }else if(action == 2){
                // jump
                applyVelocity(0.0f, 6.0);
                applyAcceleration(0.0f, -10.0f);
            }
        }

        void updateSprite(){
            DrawableObj::setNewPos2D(currPos[0], currPos[1]);
            
        }

        void nextFrame(){
            // applies next 'second'
            updateMovement(timeBetweenFrames);
            updateSprite();

            // check collisions with enemies

            // check collision with ground(?)

        }

        
};