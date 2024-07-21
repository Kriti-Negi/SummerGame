#include "DrawableObj.cpp"
#include "Collision.cpp"
#include "player.cpp"

class Enemy: public DrawableObj{
    private:
        float position[3] = {0.0f, 0.0f, 0.0f};
        float height = 0.0f;
        float width = 0.0f;

        int type = 0; // 0 is slime
        const CollisionRect collider;
        bool isAlive = true;

        bool canMove = false;
        float velocity[2] = {0.0f, 0.0f}; // no accel for enemies

    public:
        Enemy(){
            collider = new CollisionRect(position[0], position[1], height, width);
        }

        //getters and setters
        void setType(int t){
            type = t;
        }
        void setPosition(float px,  float py, float pz){
            position[0] = px;
            position[1] = py;
            position[2] = pz;
        }
        float getPositionX(){
            return position[0];
        }
        float getPositionY(){
            return position[1];
        }
        float getPositionZ(){
            return position[2];
        }
        void setDim(float w, float h){
            height = h;
            width = w;
        }
        void setCanMove(bool m){
            canMove = m;
        }
        void kill(){
            isAlive = false;
        }
        bool getIsAlive(){
            return isAlive;
        }

        void updateMovement(float timePassed){
            position[0] = velocity[0] * timePassed + position[0];
            position[1] = velocity[1] * timePassed + position[1];
        }
        void setVelocityX(float vx){
            velocity[0] = vx;
        }
        void setVelocityY(float vy){
            velocity[1] = vy;
        }
        //other methods
        bool hasCollidedWith(Player p){
            
        }
};

class Slime: public Enemy{
    private: 
        // something
    public:
        Slime(){

        }

};

class Spider: public DrawableObj {
    private:
        // hellow
    public:
        Spider(){

        }
};
