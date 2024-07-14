#include <iostream>

#include "player.cpp"

class Game{
    private: 
        int currentLevel = 0;
        int maxLevels = 1;
        // add glbal vars here
    public: 
        void getNextLevel() {
            if(currentLevel + 1 < maxLevels){
                currentLevel++;
            }else if (currentLevel == maxLevels){
                // starting cutscene
            }else{
                //ending cutscene
            }
        }

        
};

