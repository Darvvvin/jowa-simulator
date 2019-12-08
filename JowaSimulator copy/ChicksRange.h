#pragma once

#include <SFML/Graphics.hpp>
#include "Enemy.h"

#include <vector>
using namespace sf;

class ChicksRange {
private:
    RectangleShape shape;
    Color color;
    Vector2f size;
    Vector2f position;
    
    vector<Enemy> targetIDs;
    
    FloatRect bounds;
    
public:
    ChicksRange(Vector2f newposition) {
        bounds = shape.getGlobalBounds();
        shape.setOrigin({ bounds.width / 2, bounds.height / 2 });
        shape.setPosition(newposition);
        shape.setFillColor(Color::White);
        shape.setSize({ 450 , 100});
        bounds = shape.getGlobalBounds();
    }
    ~ChicksRange() {
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
