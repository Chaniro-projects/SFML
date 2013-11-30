#ifndef MAPSPRITESHEET_H
#define MAPSPRITESHEET_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
#include "spritesheet.h"
#include <memory>

class MapSpriteSheet : public SpriteSheet
{
    enum DIRECTION {
        t,
        r,
        b,
        l,
        tl,
        tr,
        bl,
        br,
        m,
        o
    };

public:
    MapSpriteSheet();
    DIRECTION getDirectionFromString(std::string &str);
private:
    void init(sf::Texture& t, Resource::ID id, int width, int height, int separatorX, int separatorY, bool hasSeparatorInEnd, std::string data);
};

#endif // MAPSPRITESHEET_H
