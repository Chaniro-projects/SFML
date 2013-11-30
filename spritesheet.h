#ifndef SPRITESHEET_H
#define SPRITESHEET_H

#include <SFML/Graphics.hpp>
#include <math.h>
#include "resourceholder.h"

class SpriteSheet
{
public:
    SpriteSheet();
    int getSize();
    sf::IntRect* getPositionFromIndex(int index);
    sf::Vector2i *getSpriteSize();
    sf::Texture &getTexture();
    void init(sf::Texture& texture, Resource::ID id,int width, int height, int separatorX, int separatorY, bool hasSeparatorInEnd);

private:
    sf::Vector2i *spriteSize;
    std::vector<sf::IntRect *> *spritesPositions;
    int size;
    sf::Texture texture;
    Resource::ID textureId;
};

#endif // SPRITESHEET_H
