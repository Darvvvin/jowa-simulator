//
//  Waves.h
//  JowaSimulator
//
//  Created by Jacob Darvin on 12/8/19.
//  Copyright © 2019 Jacob Darvin. All rights reserved.
//

#include <SFML/Graphics.hpp>
#include "Enemy.h"

#ifndef Waves_h
#define Waves_h

class Waves {
private:
    int waveCounter = 1;
    int enemiesWave = 0;
    int enemiesLeft;
    
    sf::Time waveTime;
    
public:
    Waves(){
    }
    
    ~Waves(){
    }
    
    void spawnEnemies(vector<Enemy> *enemies, Enemy *enemyVectors, sf::Clock *waveClock){
        if(waveCounter == 1) { // wave 1
            waveTime = waveClock->getElapsedTime();
            cout << waveTime.asSeconds() << endl;
            if(waveTime.asSeconds() >= 2.0f && enemiesWave < 10) {
                enemies->push_back(Enemy(*enemyVectors));
                waveClock->restart();
                enemiesWave++;
            }
        }
    }
};

#endif /* Waves_h */
