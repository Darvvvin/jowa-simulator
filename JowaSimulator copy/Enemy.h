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
#include <vector>
#include <SFML/Graphics.hpp>

#include "Projectile.h"

using namespace std;

class Enemy {
private:
    int IDindex;
    
    sf::Color color;
    sf::RectangleShape shape;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Sprite sprite;
    
    sf::Texture texture;
    sf::Texture texture2;
    
    sf::Texture textureR;
    sf::Texture textureStand;
    
    sf::Texture dead;
    
    sf::RectangleShape healthBarGreen;
    sf::RectangleShape healthBarRed;
    
    int rowNum;
    int enemyHp;
    
    sf::Clock icedClock;
    sf::Time icedTime;
    
    float enemySpeed;
    
    bool isAlive = true;
    bool isIced = false;
    
    sf::Clock spriteTurn;

public:
    Enemy(sf::Vector2f newSize, sf::Vector2f newPosition, sf::Color newColor) {
        static int IDcount;

        size = newSize;
        position = newPosition;
        color = newColor;
        
        texture.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/enemy-justin.png");
        texture2.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/enemy-justin-2.png");
        
        dead.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/enemy-justin-dead.png");
        
        textureR.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/enemy-justin-r.png");
        textureStand.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/enemy-justin-stand.png");
            
        //set drawing parameters
        shape.setSize({100, 140});
        shape.setPosition(position);
        //shape.setTexture(&texture);
        
        //healthbar drawing parameters
        healthBarGreen.setSize({100,10});
        healthBarGreen.setFillColor(sf::Color::Green);
        healthBarGreen.setPosition({position.x, position.y + 110});
        
        //healthbar drawing parameters red
        healthBarRed.setSize({100,10});
        healthBarRed.setFillColor(sf::Color::Red);
        healthBarRed.setPosition({position.x, position.y + 110});
        
        enemyHp = healthBarRed.getSize().x;
        enemySpeed = -0.25;
        
        IDindex = IDcount++;
        
        //sf::Clock iceTimer;
    }
    ~Enemy(){
    }
    
    bool youAliveBruh(){
        return isAlive;
    }
    
    void textureSetter() {
        if(isAlive == true){
            if(rowNum % 2 == 0) {
                shape.setTexture(&textureStand);
            }
            
            if(rowNum == 1 || rowNum == 5 || rowNum == 9) {
                //cout << spriteTurn.getElapsedTime().asMilliseconds() << endl;
               // if(int(spriteTurn.getElapsedTime().asMilliseconds()) <= 100 ) {
                    shape.setTexture(&texture);
               //}
                //else if(int(spriteTurn.getElapsedTime().asMilliseconds()) <= 150 &&
                //        int(spriteTurn.getElapsedTime().asMilliseconds()) > 100) {
                //    shape.setTexture(&texture2);
               // }
               // if(int(spriteTurn.getElapsedTime().asMilliseconds()) > 300 ) {
               //     spriteTurn.restart();
               // }
            }
            
            if(rowNum == 3 || rowNum == 7) {
                shape.setTexture(&textureR);
            }
        }
    }
    
    void updateRow() {
        if(isAlive == true) {
            if(position.x >= 1980 && position.x < 1981 && position.y >= 15 && position.y < 16)
                rowNum = 1;
            if(position.x >= 600 && position.x < 601 && position.y >= 15 && position.y < 16)
                rowNum = 2;
            if(position.x >= 600 && position.x < 601 && position.y >= 300 && position.y < 301)
                rowNum = 3;
            if(position.x >= 1840 && position.x < 1841 &&  position.y >= 300 && position.y < 301)
                rowNum = 4;
            if(position.x >= 1840 && position.x < 1841 && position.y >= 580 && position.y < 581)
                rowNum = 5;
            if(position.x >= 600 && position.x < 601 && position.y >= 580 && position.y < 581)
                rowNum = 6;
            if(position.x >= 600 && position.x < 601 && position.y >= 860 && position.y > 861)
                rowNum = 7;
            if(position.x >= 1840 && position.x < 1841 && position.y >= 860 && position.y > 861)
                rowNum = 8;
            if(position.x >= 1840 && position.x < 1841 && position.y <= 1140 && position.y > 1141)
                rowNum = 9;
        }
    }
    
    void killThisFucker() {
        isAlive = false;
        shape.setTexture(&dead);
    }
    
    void iceChecker(){
        if(isIced == true) {
            icedTime = icedClock.getElapsedTime();
            if(icedTime.asSeconds() >= 5.0f) {
                enemySpeed = -0.25;
                shape.setOutlineThickness(0);
                isIced = false;
            }
        }
    }
    
    void move(float distance) {
        if(isIced == true) {
            cout << position.x << " ";
            cout << position.y << endl;
        }
        
        if(isAlive == true) {
            if(rowNum == 1) {
                shape.move({enemySpeed, 0});
                healthBarRed.move({enemySpeed, 0});
                healthBarGreen.move({enemySpeed, 0});
                position += {enemySpeed,0};
            } else if(rowNum == 2) {
                shape.move({0, -enemySpeed});
                healthBarRed.move({0, -enemySpeed});
                healthBarGreen.move({0, -enemySpeed});
                position += {0,-enemySpeed};
            } else if(rowNum == 3) {
                shape.move({-enemySpeed, 0});
                healthBarRed.move({-enemySpeed, 0});
                healthBarGreen.move({-enemySpeed, 0});
                position += {-enemySpeed, 0};
            } else if(rowNum == 4) {
                shape.move({0, -enemySpeed});
                healthBarRed.move({0, -enemySpeed});
                healthBarGreen.move({0, -enemySpeed});
                position += {0, -enemySpeed};
            } else if(rowNum == 5) {
                shape.move({enemySpeed, 0});
                healthBarRed.move({enemySpeed, 0});
                healthBarGreen.move({enemySpeed, 0});
                position += {enemySpeed,0};
            } else if(rowNum == 6) {
                shape.move({0, -enemySpeed});
                healthBarRed.move({0, -enemySpeed});
                healthBarGreen.move({0, -enemySpeed});
                position += {0,-enemySpeed};
            } else if(rowNum == 7) {
                shape.move({-enemySpeed, 0});
                healthBarRed.move({-enemySpeed, 0});
                healthBarGreen.move({-enemySpeed, 0});
                position += {-enemySpeed, 0};
            } else if(rowNum == 8) {
                shape.move({0, -enemySpeed});
                healthBarRed.move({0, -enemySpeed});
                healthBarGreen.move({0, -enemySpeed});
                position += {0, -enemySpeed};
            } else if(rowNum == 9) {
                shape.move({enemySpeed, 0});
                healthBarRed.move({enemySpeed, 0});
                healthBarGreen.move({enemySpeed, 0});
                position += {enemySpeed,0};
            }
        }
    }
    
    sf::Vector2f getPosition(){
        return position;
    }
    
    sf::RectangleShape getRectangleShape() {
        return shape;
    }
    
    sf::FloatRect getBounds(){
        return shape.getGlobalBounds();
    }
    
    void healthBar() {
        healthBarGreen.setSize({static_cast<float>(healthBarGreen.getSize().x - 10), 10});
        enemyHp -= 10;
    }
    
    void hitByChicks() {
        healthBarGreen.setSize({static_cast<float>(healthBarGreen.getSize().x - 5), 10});
        
        enemyHp -= 5;
        enemySpeed = -0.05;
        
        
        shape.setOutlineColor(sf::Color::Blue);
        shape.setOutlineThickness(2.0f);
        //shape.setFillColor(sf::Color(10, 104, 255, 0.47});
        icedClock.restart();
        isIced = true;
    }
    
    int getHealth() {
        return enemyHp;
    }
    
    void drawToWindow(sf::RenderWindow &window) {
        window.draw(shape);
        window.draw(healthBarRed);
        window.draw(healthBarGreen);
    }
    
};

#endif /* Enemy_h */
