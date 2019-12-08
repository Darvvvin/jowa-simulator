#include <SFML/Graphics.hpp>

#include <iostream>
#include <math.h>
#include <iostream>
#include <vector>
#include <stack>

#include "Enemy.h"
#include "Towers.h"
#include "Placed.h"
#include "Projectile.h"
#include "Uniqlo.h"
#include "Range.h"
#include "Available.h"
#include "Floors.h"
#include "Restricted.h"
#include "Waves.h"

#include "Jowa.h"

#include "Chicks.h"
#include "ChicksProjectile.h"
#include "ChicksRange.h"

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
    sf::Texture tTowerChixSelect;
    sf::Sprite  sTowerChix;
    bool bTowerChix = false;
    tTowerChixSelect.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/chix-selected.png");
    tTowerChix.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/chix.png");
    sTowerChix.setTexture  (tTowerChix);
    sTowerChix.setPosition ({ 380,1260 });
    sTowerChix.setScale    ({ 1,1 });
    //-------------------------------------------------// CHIX
    sf::Texture tTowerJuul;
    sf::Sprite  sTowerJuul;
    sf::Texture tTowerJuulSelect;
    bool bTowerJuul = false;
    tTowerJuulSelect.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/juul-selected.png");
    tTowerJuul.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/juul.png");
    sTowerJuul.setTexture  (tTowerJuul);
    sTowerJuul.setPosition ({ 600,1260 });
    sTowerJuul.setScale    ({ 1,1 });
    //-------------------------------------------------// JUUL
    sf::Texture tTowerBar;
    sf::Sprite  sTowerBar;
    sf::Texture tTowerBarSelect;
    bool bTowerBar = false;
    tTowerBarSelect.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/bar-selected.png");
    tTowerBar.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/bar.png");
    sTowerBar.setTexture  (tTowerBar);
    sTowerBar.setPosition ({ 820,1260 });
    sTowerBar.setScale    ({ 1,1 });
    //-------------------------------------------------// BAR
    sf::Texture tAffection;
    sf::Sprite  sAffection;
    sf::Texture tAffectionSelect;
    bool bAffection = false;
    tAffectionSelect.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/affection-selected.png");
    tAffection.loadFromFile("/Users/Jacob/Desktop/JowaSimulator/Sprites/affection.png");
    sAffection.setTexture  (tAffection);
    sAffection.setPosition ({ 2014, 1004 });
    sAffection.setScale    ({ 1,1 });
    //-------------------------------------------------// AFFECTION
    
    bool gameStart = false;
    sf::Vector2f test;
    
    sf::RenderWindow window(sf::VideoMode(2560,1440), "Jowa Simulator 4K", sf::Style::Close);
    
    //UNIQLO TOWER
    Uniqlo uniqloPlaced({-100,-100});
    vector<Uniqlo> VuniqloPlaced;
    
    //UNIQLO TOWER RANGE
    Range towerRange({-100,-100});
    vector<Range> vTowerRange;
    
    //UNIQLO VECTORS
    Projectile towerProjectile({0,0}, {50,50}, sf::Color::Red);
    vector<Projectile> projectiles;
    projectiles.push_back(Projectile(towerProjectile));
    
    //CHICKS TOWER
    Chicks chicksPlaced({-100,-100});
    vector<Chicks> VchicksPlaced;
    
    //CHICKS TOWER RANGE
    ChicksRange towerChicksRange({-100,-100});
    vector<ChicksRange> vTowerChicksRange;
    
    //CHICKS PROJECTILE VECTORS
    ChicksProjectile towerChicksProjectile({0,0}, {50,50}, sf::Color::Red);
    vector<ChicksProjectile> chicksProjectiles;
    chicksProjectiles.push_back(ChicksProjectile(towerChicksProjectile));
    
    //RESTRICTED
    Restricted restricted({0,0});
    vector<Restricted> vRestricted;
    
    vRestricted.push_back(Restricted(restricted));
    
    //LAND AND SHIT
    Available landAvailable({0,0});
    vector<Available> vLandAvailable;
    
    //FLOOR CREATOR
    Floors floor(&vRestricted, &restricted);
    
    //Enemy *enemyGrunt[10];
    int nEnemyCount = 0;
    
    //ANGLE VECTORS
    sf::Vector2f direction;
    sf::Vector2f norm;
    double angle = 0.0;
    
    //ENEMY VECTORS
    Enemy enemyVectors({100,100}, {1980, 15}, sf::Color::White);
    vector<Enemy> enemies;
    
    enemies.push_back(Enemy(enemyVectors));
    
    //BULLET COUNTER
    
    //LOAD CLOCK
    sf::Clock clock;
    sf::Clock bulletClock;
    sf::Clock chicksClock;
    
    //LOAD WAVE HANDLER
    Waves waveHandler;
    
    int enemiesWave = 0;
    int enemiesLeft = 0;
    int waveCounter = 1;
    
    //JOWA
    Jowa jowa({100,100}, {650,170});
    
    clock.restart();

    while(window.isOpen()) {
        sf::Event event;
        window.clear();
        
        window.draw(sGrid);
        
        sf::Time elapsed = clock.getElapsedTime();
        sf::Time bulletElapsed = bulletClock.getElapsedTime();
        sf::Time bulletElapsedChicks = chicksClock.getElapsedTime();
        
        if(gameStart == true) {
            
            if(waveCounter == 1) { // WAVE 1 ===== WAVE 1 ===== WAVE 1 ======
                if(elapsed.asSeconds() >= 1.0f && enemiesWave < 5) {
                    enemies.push_back(Enemy(enemyVectors));
                    clock.restart();
                    nEnemyCount++;
                    enemiesWave++;
                }
            }
            
            //DRAW LANDS TO WINDOW
            for (int i = 0;i < vRestricted.size(); i++) {
                vRestricted[i].drawtowindow(window);
            }
            
            //UNIQLO -- CODE -- UNIQLO -- CODE -- UNIQLO
            for (int i = 0; i < VuniqloPlaced.size(); i++) {
                for(int k = 0; k < enemies.size(); k++) {
                    if(enemies[k].youAliveBruh()) {
                        if (vTowerRange[i].doescontain(enemies[k].getPosition()) == true) {
                            for(int j = 0; j < VuniqloPlaced.size(); j++) {
                                VuniqloPlaced[j].rotate(50.f * atan2f( VuniqloPlaced[j].getPosition().x - enemies[k].getPosition().x ,  enemies[k].getPosition().y - VuniqloPlaced[j].getPosition().y ));
                            }
                        }
                    }
               }
                VuniqloPlaced[i].drawtowindow(window);
            }
            
            
            if(bulletElapsed.asSeconds() >= 0.5f) {
                for (int j = 0; j < VuniqloPlaced.size();j++) {
                    for(int k = 0; k < enemies.size(); k++) {
                        if(enemies[k].youAliveBruh()) {
                            if (vTowerRange[j].doescontain(enemies[k].getPosition()) == true) {
                                direction = enemies[k].getPosition() - uniqloPlaced.getPosition();
                                norm.x = direction.x / sqrt(pow(direction.x, 2.0) + pow(direction.y, 2));
                                norm.y = direction.y / sqrt(pow(direction.x, 2.0) + pow(direction.y, 2));
                                angle = VuniqloPlaced[j].getangle();
                                
                                towerProjectile.setposition(VuniqloPlaced[j].getPosition());
                                towerProjectile.setvelocity(norm);
                                towerProjectile.rotate(angle);
                                
                                projectiles.push_back(Projectile(towerProjectile));
                            }
                        }
                    }
                }
                bulletClock.restart();
            }
            
            for (int i = 1;i < projectiles.size();i++) {
                for(int j = 0; j < enemies.size(); j++) {
                    if(enemies[j].youAliveBruh()) {
                        projectiles[i].moveprojectile(projectiles[i].getvelocity());
                        if (projectiles[i].getposition().x < 0 || projectiles[i].getposition().x > window.getSize().x
                            || projectiles[i].getposition().y < 0 || projectiles[i].getposition().y > window.getSize().y) {
                            projectiles.erase(projectiles.begin() + i);
                            
                        } else if (projectiles[i].getbounds().intersects(enemies[j].getBounds())) {
                            enemies[j].healthBar();
                            
                            if(enemies[j].getHealth() <= 0) {
                                enemies[j].killThisFucker();
                            }
                            
                            projectiles.erase(projectiles.begin() + i);
                            break;
                        }
                    }
                }
            }
            //UNIQLO -- CODE -- UNIQLO -- CODE -- UNIQLO
            
            //CHICKS -- CODE -- CHICKS -- CODE -- CHICKS
            for (int i = 0; i < VchicksPlaced.size(); i++) {
                for(int k = 0; k < enemies.size(); k++) {
                    if(enemies[k].youAliveBruh()) {
                        if (vTowerChicksRange[i].doescontain(enemies[k].getPosition()) == true) {
                            for(int j = 0; j < VchicksPlaced.size(); j++) {
                                VchicksPlaced[j].rotate(50.f * atan2f( VchicksPlaced[j].getPosition().x - enemies[k].getPosition().x ,  enemies[k].getPosition().y - VchicksPlaced[j].getPosition().y ));
                            }
                        }
                    }
                }
                VchicksPlaced[i].drawtowindow(window);
            }
            
            
            if(bulletElapsedChicks.asSeconds() >= 2.5f) {
                for (int j = 0; j < VchicksPlaced.size();j++) {
                    for(int k = 0; k < enemies.size(); k++) {
                        if(enemies[k].youAliveBruh()) {
                            if (vTowerChicksRange[j].doescontain(enemies[k].getPosition()) == true) {
                                direction = enemies[k].getPosition() - chicksPlaced.getPosition();
                                norm.x = direction.x / sqrt(pow(direction.x, 2.0) + pow(direction.y, 2));
                                norm.y = direction.y / sqrt(pow(direction.x, 2.0) + pow(direction.y, 2));
                                angle = VchicksPlaced[j].getangle();
                                
                                towerChicksProjectile.setposition(VchicksPlaced[j].getPosition());
                                towerChicksProjectile.setvelocity(norm);
                                towerChicksProjectile.rotate(angle);
                                
                                chicksProjectiles.push_back(ChicksProjectile(towerChicksProjectile));
                            }
                        }
                    }
                }
                chicksClock.restart();
            }
            
            for (int i = 1; i < chicksProjectiles.size();i++) {
                for(int j = 0; j < enemies.size(); j++) {
                    if(enemies[j].youAliveBruh()) {
                        chicksProjectiles[i].moveprojectile(chicksProjectiles[i].getvelocity());
                        if (chicksProjectiles[i].getposition().x < 0 || chicksProjectiles[i].getposition().x > window.getSize().x
                            || chicksProjectiles[i].getposition().y < 0 || chicksProjectiles[i].getposition().y > window.getSize().y) {
                            chicksProjectiles.erase(chicksProjectiles.begin() + i);
                            
                        } else if (chicksProjectiles[i].getbounds().intersects(enemies[j].getBounds())) {
                            enemies[j].hitByChicks();
                            
                            if(enemies[j].getHealth() <= 0) {
                                enemies[j].killThisFucker();
                            }
                            
                            chicksProjectiles.erase(chicksProjectiles.begin() + i);
                            break;
                        }
                    }
                }
            }
            //CHICKS -- CODE -- CHICKS -- CODE -- CHICKS

            //DRAW LANDS BRUH
            for (int i = 0; i < vLandAvailable.size(); i++) {
                vLandAvailable[i].drawtowindow(window);
            }
            
            //UNIQLO -- CODE -- UNIQLO -- CODE -- UNIQLO
            for (int i = 1; i < projectiles.size(); i++) {
                projectiles[i].drawtowindow(window);
            }
            //UNIQLO -- CODE -- UNIQLO -- CODE -- UNIQLO
            
            //CHICKS -- CODE -- CHICKS -- CODE -- CHICKS
            for (int i = 1; i < chicksProjectiles.size(); i++) {
                chicksProjectiles[i].drawtowindow(window);
            }
            //CHICKS -- CODE -- CHICKS -- CODE -- CHICKS
             
            
            // TOWER BUTTONS
            window.draw(sTowerChix);
            window.draw(sTowerJuul);
            window.draw(sTowerBar);
            window.draw(sAffection);
            // TOWER BUTTONS =====|
            
            //DRAW TOWERS
            for(int i = 0; i < VuniqloPlaced.size(); i++) {
                VuniqloPlaced[i].drawtowindow(window);
                vTowerRange[i].drawtowindow(window);
            }
            
            for(int i = 0; i < VchicksPlaced.size(); i++) {
                VchicksPlaced[i].drawtowindow(window);
                vTowerChicksRange[i].drawtowindow(window);
            }
            
            //DRAW -- ENEMY -- DRAW -- ENEMY
            for(int i = 0; i < nEnemyCount; i++) {
                enemies[i].move(-0.25);
                enemies[i].updateRow();
                enemies[i].textureSetter();
                
                enemies[i].iceChecker();
                enemies[i].drawToWindow(window);
            }
            
            jowa.drawToWindow(window);
        }
        if(gameStart == false) {
            window.draw(sSplash);
        }
        window.display();
        
        while(window.pollEvent(event)) {
            if(event.type == sf::Event::Closed)
                window.close();
            
            window.setKeyRepeatEnabled(false);
            
            //BUTTONS
            if(sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
                sf::Vector2f mouse = window.mapPixelToCoords(sf::Mouse::getPosition(window));
                
                // retrieve the bounding box of the sprite
                sf::FloatRect boundsChix = sTowerChix.getGlobalBounds();
                sf::FloatRect boundsJuul = sTowerJuul.getGlobalBounds();
                sf::FloatRect boundsBar = sTowerBar.getGlobalBounds();
                sf::FloatRect boundsAffection = sAffection.getGlobalBounds();

                
                //BUYING LAND
                for(int i = 0; i < vRestricted.size(); i++) {
                    if(vRestricted[i].doescontain(mouse) && bAffection == true) {
                        landAvailable.newavailable(vRestricted[i].getposition());
                        vLandAvailable.push_back(Available(landAvailable));
                        
                        vRestricted.erase(vRestricted.begin() + i);
                        
                        bAffection = false;
                        sAffection.setTexture(tAffection);
                    }
                }
                
                //BUYING TOWER - UNIQLO
                for(int i = 0; i < vLandAvailable.size(); i++) {
                    if(vLandAvailable[i].doescontain(mouse) && bTowerJuul == true) {
                        uniqloPlaced.newuniqlo(vLandAvailable[i].getposition());
                        towerRange.newrange({vLandAvailable[i].getposition().x, vLandAvailable[i].getposition().y + 136});
                        
                        vTowerRange.push_back(Range(towerRange));
                        VuniqloPlaced.push_back(Uniqlo(uniqloPlaced));
                        vLandAvailable.erase(vLandAvailable.begin() + i);
                        
                        bTowerJuul = false;
                        sTowerJuul.setTexture(tTowerJuul);
                    }
                }
                
                //BUYING TOWER - CHICKS
                for(int i = 0; i < vLandAvailable.size(); i++) {
                    if(vLandAvailable[i].doescontain(mouse) && bTowerChix == true) {
                        chicksPlaced.newuniqlo(vLandAvailable[i].getposition());
                        towerChicksRange.newrange({vLandAvailable[i].getposition().x, vLandAvailable[i].getposition().y + 136});
                        
                        vTowerChicksRange.push_back(ChicksRange(towerChicksRange));
                        VchicksPlaced.push_back(Chicks(chicksPlaced));
                        vLandAvailable.erase(vLandAvailable.begin() + i);
                        
                        bTowerChix = false;
                        sTowerChix.setTexture(tTowerChix);
                    }
                }
                
                
                //BUTTONS === BUTTONS === BUTTONS === BUTTONS
                if (boundsAffection.contains(mouse)) {
                    if(bAffection == false) {
                        sAffection.setTexture(tAffectionSelect);
                        bAffection = true;
                    } else {
                        sAffection.setTexture(tAffection);
                        bAffection = false;
                    }
                    cout << "AFFECTION!" << endl;
                }
                
                else if (boundsChix.contains(mouse)) {
                    if(bTowerChix == false) {
                        sTowerChix.setTexture(tTowerChixSelect);
                        bTowerChix = true;
                    } else {
                        sTowerChix.setTexture(tTowerChix);
                        bTowerChix = false;
                    }
                    cout << "CHIX!" << endl;
                } else if (boundsJuul.contains(mouse)) {
                    if(bTowerJuul == false) {
                        sTowerJuul.setTexture(tTowerJuulSelect);
                        bTowerJuul = true;
                    } else {
                        sTowerJuul.setTexture(tTowerJuul);
                        bTowerJuul = false;
                    }
                    cout << "JUUL!" << endl;
                }
                
                else if (boundsBar.contains(mouse)) {
                    if(bTowerBar == false) {
                        sTowerBar.setTexture(tTowerBarSelect);
                        bTowerBar = true;
                    } else {
                        sTowerBar.setTexture(tTowerBar);
                        bTowerBar = false;
                    }
                    cout << "BAR!" << endl;
                }
            }
            
            if(gameStart == false) {
                if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {
                    gameStart = true;
                }
            }
        }
    }
}
