#include <SFML/Graphics.hpp>
#include <iostream>

#include "world.h"
#include "Enemy.h"
#include "Towers.h"

int main() {
    //LOAD TEXTURES
    sf::Texture tSplash;
    sf::Sprite  sSplash;
    tSplash.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/SPLASH/menu.png");
    sSplash.setTexture  (tSplash);
    sSplash.setPosition ({ 0,0 });
    sSplash.setScale    ({ 1,1 });
    //-------------------------------------------------// SPLASH
    sf::Texture tGrid;
    sf::Sprite  sGrid;
    tGrid.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/grid.png");
    sGrid.setTexture  (tGrid);
    sGrid.setPosition ({ 0,0 });
    sGrid.setScale    ({ 1,1 });
    //-------------------------------------------------// GRID
    sf::Texture tTowerChix;
    sf::Sprite  sTowerChix;
    tTowerChix.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/chix.png");
    sTowerChix.setTexture  (tTowerChix);
    sTowerChix.setPosition ({ 380,1260 });
    sTowerChix.setScale    ({ 1,1 });
    //-------------------------------------------------// CHIX
    sf::Texture tTowerJuul;
    sf::Sprite  sTowerJuul;
    tTowerJuul.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/juul.png");
    sTowerJuul.setTexture  (tTowerJuul);
    sTowerJuul.setPosition ({ 600,1260 });
    sTowerJuul.setScale    ({ 1,1 });
    //-------------------------------------------------// JUUL
    sf::Texture tTowerBar;
    sf::Sprite  sTowerBar;
    tTowerBar.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/bar.png");
    sTowerBar.setTexture  (tTowerBar);
    sTowerBar.setPosition ({ 820,1260 });
    sTowerBar.setScale    ({ 1,1 });
    //-------------------------------------------------// BAR
    
    bool gameStart = false;
    sf::Vector2f test;
    
    sf::RenderWindow window(sf::VideoMode(2560,1440), "Jowa Simulator 4K", sf::Style::Close);
    
    //LOAD GAME OBJECTS
    Enemy *enemyGrunt[10];
    int nEnemyCount = 0;
    
    //LOAD CLOCK
    sf::Clock clock;
    clock.restart();
    
    //SPAWN ENEMIES
    /*
    for(int i = 0; i < 10; i++) {
        enemyGrunt[i] = new Enemy({100,100}, {1980, 20}, sf::Color::White);
    }
    */
    
    //Enemy enemyGrunt({100,100}, {1980, 20}, sf::Color::White);

    while(window.isOpen()) {
        sf::Event event;
        window.clear();
        window.draw(sGrid);
        
        sf::Time elapsed = clock.getElapsedTime();
        cout << elapsed.asSeconds() << endl;
        
        if(gameStart == true) {
        // TOWER BUTTONS
        window.draw(sTowerChix);
        window.draw(sTowerJuul);
        window.draw(sTowerBar);
        // TOWER BUTTONS =====|
            
        //EVERYTHING ENEMIES
        if(elapsed.asSeconds() >= 2.0f) {
            enemyGrunt[nEnemyCount] = new Enemy({100,100}, {1980, 20}, sf::Color::White);
            clock.restart();
            nEnemyCount++;
        }
        
        for(int i = 0; i < nEnemyCount; i++) {
            enemyGrunt[i]->move(-0.5);
            enemyGrunt[i]->updateRow();
            enemyGrunt[i]->drawToWindow(window);
        }
            //FUKK~
        //EVERYTHING ENEMIES =====|
            
        }
        if(gameStart == false) {
            window.draw(sSplash);
        }
        
        window.display();
        
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            
            window.setKeyRepeatEnabled(false);
            
            if(gameStart == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    gameStart = true;
                }
            }
        }
    }
}
