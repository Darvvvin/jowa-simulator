#pragma once
#include <SFML/Graphics.hpp>
#include <math.h>
#include <iostream>

#include "Projectile.h"
#include "Range.h"
#include "Enemy.h"


using namespace sf;
using namespace std;
class Uniqlo {
private:
    Sprite sprite;
    Texture texture;
    Vector2f position;
    float angledegree;
    FloatRect bounds;
    
    RectangleShape towerRangeShape;
    Vector2f rangeSize;
    Vector2f rangePosition;
    vector<Enemy> targetIDs;
    
    FloatRect rangeBounds;
    
public:
    Uniqlo(Vector2f newposition) {
        texture.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/uniqlo.png");
        sprite.setTexture(texture);
        
        bounds = sprite.getGlobalBounds();
        sprite.setOrigin({ bounds.width /2,bounds.height /2});
        sprite.setPosition(newposition);
        sprite.scale({ 1,1 });
        bounds = sprite.getGlobalBounds();
        angledegree = 0;
        
        //SETUP RANGE PROPERTIES
        rangeBounds = towerRangeShape.getGlobalBounds();
        towerRangeShape.setOrigin({ rangeBounds.width / 2, rangeBounds.height / 2 });
        towerRangeShape.setPosition(rangePosition);
        towerRangeShape.setFillColor(Color::White);
        towerRangeShape.setSize({ 307 , 100});
        rangeBounds = towerRangeShape.getGlobalBounds();
    }
    ~Uniqlo() {
        
    }
    
    void rotate(float angle) {
        angledegree = angle;
        sprite.setRotation(angle);
    }
    double getrotate() {
        return sprite.getRotation();
    }
    
    void drawtowindow(RenderWindow& window) {
        window.draw(sprite);
    }
    
    Vector2f getPosition() {
        return sprite.getPosition();
    }
    
    void moveuniqlo(Vector2f move) {
        sprite.move(move);
    }
    double getangle() {
        return sprite.getRotation();
    }
    
    bool doescontain(Vector2f mousepos) {
        if (bounds.contains(mousepos)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    //RANGE/////
    bool rangeContain(Vector2f enemy) {
        if (bounds.contains(enemy)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    int distanceFromThis(Vector2f distance) {
        return sqrt(pow((distance.x - position.x), 2) + pow((distance.y - position.y), 2));
    }
    
    void newuniqlo(Vector2f newposition) {
        texture.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/uniqlo.png");
        sprite.setTexture(texture);
        
        bounds = sprite.getGlobalBounds();
        sprite.setOrigin({ bounds.width /2 ,bounds.height /2});
        sprite.setPosition({ newposition });
        bounds = sprite.getGlobalBounds();
        
        cout << "awesome" << endl;
    }
    
    
    
};
