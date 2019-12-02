//
//  Enemy.h
//  JowaSimulator
//
//  Created by Jacob Darvin on 11/20/19.
//  Copyright © 2019 Jacob Darvin. All rights reserved.
//

#ifndef Enemy_h
#define Enemy_h

#pragma once
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;

class Enemy {
private:
    sf::Color color;
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f size;
    
    int rowNum;
    
public:
    Enemy(sf::Vector2f newSize, sf::Vector2f newPosition, sf::Color newColor) {
        size = newSize;
        position = newPosition;
        color = newColor;
            
        //set drawing parameters
        shape.setSize(size);
        shape.setFillColor(color);
        shape.setPosition(position);
    }
    ~Enemy(){
    }
    
    void updateRow() {
        if(position.x == 1980 && position.y == 20)
            rowNum = 1;
        if(position.x == 600 && position.y == 20)
            rowNum = 2;
        if(position.x == 600 && position.y == 300)
            rowNum = 3;
        if(position.x == 1840 && position.y == 300)
            rowNum = 4;
        if(position.x == 1840 && position.y == 580)
            rowNum = 5;
        if(position.x == 600 && position.y == 580)
            rowNum = 6;
        if(position.x == 600 && position.y == 860)
            rowNum = 7;
        if(position.x == 1840 && position.y == 860)
            rowNum = 8;
        if(position.x == 1840 && position.y == 1140)
            rowNum = 9;
    }
    
    void move(float distance) {
        if(rowNum == 1) {
            shape.move({distance, 0});
            position += {distance,0};
        } else if(rowNum == 2) {
            shape.move({0, -distance});
            position += {0,-distance};
        } else if(rowNum == 3) {
            shape.move({-distance, 0});
            position += {-distance, 0};
        } else if(rowNum == 4) {
            shape.move({0, -distance});
            position += {0, -distance};
        } else if(rowNum == 5) {
            shape.move({distance, 0});
            position += {distance,0};
        } else if(rowNum == 6) {
            shape.move({0, -distance});
            position += {0,-distance};
        } else if(rowNum == 7) {
            shape.move({-distance, 0});
            position += {-distance, 0};
        } else if(rowNum == 8) {
            shape.move({0, -distance});
            position += {0, -distance};
        } else if(rowNum == 9) {
            shape.move({distance, 0});
            position += {distance,0};
        }
        cout << rowNum << " " ;
        cout << "[" << position.x << " " << position.y << "]" << endl;
    }
    
    sf::Vector2f getPosition(){
        return position;
    }
    
    sf::RectangleShape getRectangleShape() {
        return shape;
    }
    
    void drawToWindow(sf::RenderWindow &window) {
        window.draw(shape);
    }
};

#endif /* Enemy_h */
