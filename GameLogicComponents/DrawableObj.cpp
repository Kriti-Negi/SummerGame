#include <string>

class DrawableObj{
    private:
        float position[3] = {0.0f, 0.0f, 0.0f};
        float height = 0.0f;
        float width = 0.0f;
        std::string sprite = ""; 

    public:
        DrawableObj(){}
        DrawableObj(float posx, float posy, float posz){
            position[0] = posx;
            position[1] = posy;
            position[2] = posz; // indicates how far it is in the background
        }
        DrawableObj(float posx, float posy, float posz, float w, float h){
            position[0] = posx;
            position[1] = posy;
            position[2] = posz; // indicates how far it is in the background
            height = h;
            width = w;
        }
        
        // getter and setter
        float getPositionX(){
            return position[0];
        }
        float getPositionY(){
            return position[1];
        }
        float getPositionZ(){
            return position[2];
        }

        void setNewPos(float posx, float posy, float posz){
            position[0] = posx;
            position[1] = posy;
            position[2] = posz; // indicates how far it is in the background
        }
        void setNewPos2D(float posx, float posy){
            position[0] = posx;
            position[1] = posy;
        }

        float getWidth(){
            return width;
        }
        float getHeigh(){
            return height;
        }
        void setWidth(float w){
            width = w;
        }
        void setHeight(float h){
            height = h;
        }

        //sprites
        void setSprite(std::string c){
            sprite = c;
        }
        std::string getSprite(){
            return sprite;
        }

        void draw(){} // figure out what to do with this later

};