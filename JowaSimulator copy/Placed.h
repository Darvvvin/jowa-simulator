#pragma once

#include <SFML/Graphics.hpp>
#include <math.h>

#include "Projectile.h"
#include "Enemy.h"

using namespace sf;

class Placed {
private:
    RectangleShape shape;
    Color color;
    Vector2f size;
    Vector2f position;
    
    float angledegree;
    
public:
    Placed(Vector2f newposition, Vector2f newsize, Color newcolor) {
        shape.setPosition(newposition);
        shape.setSize(newsize);
        shape.setFillColor(newcolor);
    }
    ~Placed() {
    }
    
    void rotate(float angle) {
        angledegree = angle;
        shape.setRotation(angle);
    }
    double getrotate() {
        return shape.getRotation();
    }
    
    void drawtowindow(RenderWindow& window) {
        window.draw(shape);
    }
    
    void setorigin() {
        shape.setOrigin({ shape.getLocalBounds().width / 2,shape.getLocalBounds().height/2});
    }
    
    Vector2f getPosition() {
        return shape.getPosition();
    }
    
    void movebullet(Vector2f move) {
        shape.move(move);
    }
    double getangle() {
        return shape.getRotation();
    }
    
    void towerRotation(sf::Vector2f direction, vector<Enemy> enemies, sf::Vector2f norm, double angle) {
        rotate(50.f * atan2f(shape.getPosition().x - enemies[0].getPosition().x,  enemies[0].getPosition().y - shape.getPosition().y ));
        
        direction = enemies[0].getPosition() - shape.getPosition();
        
        norm.x = direction.x / sqrt(pow(direction.x, 2.0) + pow(direction.y, 2));
        norm.y = direction.y / sqrt(pow(direction.x, 2.0) + pow(direction.y, 2));
        
        angle = shape.getRotation();
    }
};
