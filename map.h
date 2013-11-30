#ifndef MAP_H
#define MAP_H

#include <SFML/Graphics.hpp>
#include <spritesheet.h>
#include <time.h>
#include <iostream>
#include <resourceholder.h>
#include "resourceholder.h"

class Map
{
public:
    Map(int x, int y);
    void loadContent();
    void Draw(sf::RenderWindow& window);

private:
    SpriteSheet ss;
    sf::Vector2i mapSize;
    sf::Sprite ***map;
    Resource::Holder<sf::Texture, Resource::ID> textures;
};

#endif // MAP_H
