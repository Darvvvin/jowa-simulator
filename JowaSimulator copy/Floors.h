#pragma once

#include "Restricted.h"
#include <vector>

using namespace sf;

class Floors {
public:
    Floors(vector<Restricted> *restricteds, Restricted *restricted) {
        //4th floor
        float x = 790;
        float y = 206;
        for (int i = 0;i < 9;i++) {
            restricted->newrestricted({ x,y });
            restricteds->push_back(Restricted(*restricted));
            x += 138;
        }
        restricteds->erase(restricteds->begin() + 0);
        
        //3rd floor
        x = 652;
        y = 483;
        for (int i = 0;i < 9;i++) {
            restricted->newrestricted({ x,y });
            restricteds->push_back(Restricted(*restricted));
            x += 138;
        }
        //2nd floor
        x = 790;
        y = 756;
        for (int i = 0;i < 9;i++) {
            restricted->newrestricted({ x,y });
            restricteds->push_back(Restricted(*restricted));
            x += 138;
        }
        //1st floor
        x = 652;
        y = 1030;
        for (int i = 0;i < 9;i++) {
            restricted->newrestricted({ x,y });
            restricteds->push_back(Restricted(*restricted));
            x += 138;
        }
        //5th floor
        /*
        x = 485;
        y = 33;
        for (int i = 0;i < 10;i++) {
            restricted->newrestricted({ x,y });
            restricteds->push_back(Restricted(*restricted));
            x += 102;
        }
         */
    }
};
