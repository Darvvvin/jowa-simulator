//
//  Towers.h
//  JowaSimulator
//
//  Created by Jacob Darvin on 11/17/19.
//  Copyright © 2019 Jacob Darvin. All rights reserved.
//

#ifndef Towers_h
#define Towers_h

#include <iostream>
#include <string>
#include <sstream>

#include <SFML/Graphics.hpp>

using namespace std;

class Towers {
private:
    int hp;
    sf::Texture tTower;
    sf::Sprite sTower;
    sf::RectangleShape shape;
    sf::CircleShape cRange;
    sf::Vector2i tPosition;
    
    bool bState;
    
public:
    Towers(int newHp, sf::Texture newTexTower, sf::Sprite newSprTower, sf::CircleShape newCirRange, sf::Vector2i newTowPosition, bool newBooState) {
        hp = newHp;
        tTower = newTexTower;
        sTower = newSprTower;
        cRange = newCirRange;
        bState = newBooState;
        tPosition = newTowPosition;
    }
    
    ~Towers(){
    }
    
    void select() {
        if(sf::Mouse::isButtonPressed(sf::Mouse::Left) && tPosition == sf::Mouse::getPosition()) {
            cout << "clicked on tower";
        }
    }
};

#endif /* Towers_h */
