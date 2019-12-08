#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.h"

#include <stack>
#include <vector>
#include <queue>

using namespace sf;


class Range {
private:
    RectangleShape shape;
    Color color;
    Vector2f size;
    Vector2f position;
    
    vector<Enemy> targetIDs;
    
    FloatRect bounds;
    
    
public:
    Range(Vector2f newposition) {
        bounds = shape.getGlobalBounds();
        shape.setOrigin({ bounds.width / 2, bounds.height / 2 });
        shape.setPosition(newposition);
        shape.setFillColor(Color::White);
        shape.setSize({ 450 , 100});
        bounds = shape.getGlobalBounds();
    }
    ~Range() {
        
    }
    
    bool doescontain(Vector2f enemy) {
        if (bounds.contains(enemy)) {
            return true;
        }
        else {
            return false;
        }
    }
    
    void newrange(Vector2f newposition) {
        bounds = shape.getGlobalBounds();
        shape.setOrigin({ bounds.width / 2, bounds.height / 2 });
        shape.setPosition(newposition);
        shape.setFillColor(Color::Transparent);
        shape.setSize({ 307 , 100 });
        bounds = shape.getGlobalBounds();
    }
    
    void drawtowindow(RenderWindow& window) {
        window.draw(shape);
    }
    
    
};
