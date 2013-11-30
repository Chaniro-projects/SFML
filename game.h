#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <string>
#include "map.h"
#include "resourceholder.h"

class Game
{
public:
    Game();
    void Go();
    void processEvent();
    void update(sf::Time delta);
    void render();

private:
    Map map;
    int WIDTH;
    int HEIGHT;
    std::string TITLE;
    sf::RenderWindow window;
    sf::Time timePerFrame;
};

#endif // GAME_H
