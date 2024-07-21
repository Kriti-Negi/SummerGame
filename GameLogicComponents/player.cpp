#include <string>

#include "Collision.cpp"
#include "DrawableObj.cpp"
#include "WorldConstants.cpp"

class Player : public DrawableObj  {
    private:
        bool isAlive = true;
        CollisionRect *collider;
        float HEIGHT = 10.0f;
        float WIDTH = 10.0f;

        int facing = 0; // starts facing left (0); 1 is facing right

        float currPos[3] = {0.0f, 0.0f, 0.0f}; // change to start pos
        float currVel[2] = {0.0f, 0.0f}; // first is x, second is y
        float currAccel[2] = {0.0f, GRAVITY}; // first is x, second is y (default is friction, gravity)
        float timeBetweenFrames = 0.001;
        
        //animations (should we have an animation class?)

        std::string stand[4] = {
            "", // facing left 1
            "", // facing left 2
            "", // facing right 1
            "" // facing right 2
        }; // default

        std::string move[4] = {
            "", // facing left 1
            "", // facing left 2
            "", // facing right 1
            "" // facing right 2
        }; // run

        std::string jump[4] = { // do we even want a jump animation
            "", // facing left 1
            "", // facing left 2
            "", // facing right 1
            "" // facing right 2
        }; // jump

    public:
        Player(float posx, float posy, float posz) {
            currPos[0] = posx;
            currPos[1] = posy;
            currPos[2] = posz;

            collider = new CollisionRect(posx, posy, WIDTH, HEIGHT);

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
            if(currVel[0] > 0.0){
                currVel[0] = currVel[0] + currAccel[0] * timeElapsed * (-1.0f) * FRICTION; 
            }else{
                currVel[0] = currVel[0] + currAccel[0] * timeElapsed * FRICTION; 
            }
            
            currVel[1] = currVel[1] + currAccel[1] * timeElapsed;

            currPos[0] = currVel[0] * timeElapsed + currPos[0]; 
            currPos[1] = currVel[1] * timeElapsed + currPos[1];
        }

        void getUserInput(int action){ // change later
            if(action == 0){
                //go left
                applyVelocity(-1.0f, 0.0);
                facing = 0;
            }else if(action == 1){
                // go right
                applyVelocity(1.0f, 0.0);
                facing = 1;
            }else if(action == 2){
                // jump
                if(facing == 0){
                    applyVelocity(-1.0f, 6.0);
                }else{
                    applyVelocity(-1.0f, 6.0);
                }
                applyAcceleration(0.0f, GRAVITY);
            }
        }

        void updateSprite(){
            DrawableObj::setNewPos2D(currPos[0], currPos[1]);
            if(facing == 0){
                
            }else {

            }
        }

        void nextFrame(){
            // applies next 'second'
            updateMovement(timeBetweenFrames);
            updateSprite();

            // check collisions with enemies

            // check collision with ground(?)

        }
};