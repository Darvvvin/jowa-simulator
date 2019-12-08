#pragma once
#include <SFML/Graphics.hpp>

#include <math.h>
#include <vector>

#include "Enemy.h"

using namespace sf;
using namespace std;

class Projectile {
private:
    RectangleShape shape;
    Color color;
    Vector2f size;
    Vector2f position;
    Texture texture;
    Texture texture2;
    Sprite sprite;
    
    float angle;
    Vector2f velocity;
    float speed;
    
public:
    Projectile(Vector2f newposition, Vector2f newsize, Color newcolor) {
        texture.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/uniqlo-shirt.png");
        texture2.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/uniqlo-shirt-2.png");
        
        //sprite.setTexture(texture);
        
        sprite.setPosition(newposition);
        sprite.scale({ 1,1 });
        
        shape.setPosition(newposition);
        shape.setSize(newsize);
        shape.setTexture(&texture);
        
        velocity = { 5.0f,5.0f };
        speed = 1.0f;
        
    }
    ~Projectile() {
    }
    
    void changeUp(int shotNum) {
        if(shotNum % 2 == 0) {
            sprite.setTexture(texture2);
        } else
            sprite.setTexture(texture);
    }
    
    void getangle(float angle) {
        shape.setRotation(angle);
    }
    double getrotate() {
        return shape.getRotation();
    }
    
    void drawtowindow(RenderWindow& window) {
        window.draw(shape);
    }
    
    void setorigin() {
        shape.setOrigin({ shape.getLocalBounds().width / 2,shape.getLocalBounds().top });
    }
    
    Vector2f getposition() {
        return shape.getPosition();
    }
    
    void setposition(Vector2f pos) {
        shape.setPosition(pos);
    }
    
    void moveprojectile(Vector2f move) {
        shape.move(move);
    }
    
    double getangle() {
        return shape.getRotation();
    }
    
    void rotate(float angle) {
        shape.setRotation(angle);
    }
    
    void setvelocity(Vector2f newvelocity) {
        velocity = newvelocity;
    }
    
    Vector2f getvelocity() {
        return velocity;
    }
    
    float getspeed() {
        return speed;
    }
    
    FloatRect getbounds() {
        return shape.getGlobalBounds();
    }
};
