#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

using namespace std;
using namespace sf;

class Restricted {
private:
    Sprite sprite;
    Texture texture;
    FloatRect bounds;
    Vector2f position;
    bool isavailable = false;
    int price;
    
public:
    Restricted(Vector2f newposition) {
        texture.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/restrictedarea.png");
        sprite.setTexture(texture);
        
        bounds = sprite.getGlobalBounds();
        sprite.setOrigin({ bounds.width / 2, bounds.height / 2 });
        
        sprite.setPosition(newposition);
        
        sprite.setScale({ 1,1 });
        price = 100;
        bounds = sprite.getGlobalBounds();
    }
    
    ~Restricted() {
        
    }
    
    void newrestricted(Vector2f newposition) {
        texture.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/restrictedarea.png");
        sprite.setTexture(texture);
        
        bounds = sprite.getGlobalBounds();
        sprite.setOrigin({ bounds.width / 2, bounds.height / 2 });
        
        sprite.setPosition(newposition);
        
        sprite.setScale({ 1,1 });
        price = 100;
        bounds = sprite.getGlobalBounds();
    }
    
    FloatRect getbounds() {
        return bounds;
    }
    
    Vector2f getposition() {
        return sprite.getPosition();
    }
    
    bool canbuyland() {
        return isavailable;
    }
    
    void drawtowindow(RenderWindow& window) {
        window.draw(sprite);
    }
    
    bool doescontain(Vector2f position) {
        if (bounds.contains(position)) {
            return true;
        }
        else {
            return false;
        }
    }
};
