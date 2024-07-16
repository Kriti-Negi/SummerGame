class Collision
{
public:
    Collision(){}
    virtual ~Collision(){}
    virtual bool hasCollided(CollisionRect const &c) = 0;    
    virtual void hasCollided(CollisionRound const &c) = 0; 
    virtual float getCenterX() = 0;
    virtual float getCenterY() = 0;
};

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

        float getCenterX() {
            return center[0];
        }
        float getCenterY() {
            return center[1];
        }
        float getHeight(){
            return height;
        }
        float getWidth(){
            return width;
        }

        bool hasCollided(CollisionRect &c){

            // width vars (to make life easier)
            float farLeft = center[0] - width/2.0f;
            float farRight = center[0] + width/2.0f;
            float farLeftOther = c.getCenterX() - c.getWidth()/2.0f;
            float farRightOther = c.getCenterX() + c.getWidth()/2.0f;

            // height vars (to make life easier)
            float top = center[1] + height/2.0f;
            float bottom = center[1] - height/2.0f;
            float topOther = c.getCenterY() + c.getHeight()/2.0f;
            float bottomOther = c.getCenterY() - c.getHeight()/2.0f;

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

            return false;
        }

        bool hasCollided(CollisionRound &c){

        }
};

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

        float getCenterX() {
            return center[0];
        }
        float getCenterY() {
            return center[1];
        }
        float getRadiusX(){
            return radiusX;
        }
        float getRadiusY(){
            return radiusY;
        }

        bool hasCollided(CollisionRect &c){
            
        }

        bool hasCollided(CollisionRound &c){
            float maxX = getRadiusX() + c.getRadiusX();
            float maxY = getRadiusY() + c.getRadiusY();
            float distX = center[0] - c.getCenterX();
            float distY = center[1] - c.getCenterY();

            // need to fix

            if(distX < maxX && distY < maxY){
                return true;
            }

            return false;
        }
};