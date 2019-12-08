//
//  Jowa.h
//  JowaSimulator
//
//  Created by Jacob Darvin on 12/8/19.
//  Copyright © 2019 Jacob Darvin. All rights reserved.
//

#ifndef Jowa_h
#define Jowa_h

#include <SFML/Graphics.hpp>
#include "Enemy.h"

class Jowa {
private:
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Sprite sprite;
    
    sf::Texture texture;
    sf::Texture textureDead;
        
    sf::RectangleShape healthBarGreen;
    sf::RectangleShape healthBarRed;
    
    int jowaHp;
    
public:
    Jowa(sf::Vector2f newSize, sf::Vector2f newPosition) {
        size = newSize;
        position = newPosition;
        
        texture.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/jowa.png");
        
        //set drawing parameters
        shape.setSize({100, 140});
        shape.setPosition(position);
        shape.setTexture(&texture);
        
        //healthbar drawing parameters
        healthBarGreen.setSize({100,10});
        healthBarGreen.setFillColor(sf::Color::Green);
        healthBarGreen.setPosition({position.x, position.y + 110});
        
        //healthbar drawing parameters red
        healthBarRed.setSize({100,10});
        healthBarRed.setFillColor(sf::Color::Red);
        healthBarRed.setPosition({position.x, position.y + 110});
        
        jowaHp = healthBarRed.getSize().x;
    }
    
    ~Jowa(){
    }
    
    void drawToWindow(sf::RenderWindow &window) {
        window.draw(shape);
        window.draw(healthBarRed);
        window.draw(healthBarGreen);
    }
};

#endif /* Jowa_h */
