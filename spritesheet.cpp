#include "spritesheet.h"

SpriteSheet::SpriteSheet()
{
}

void SpriteSheet::init(sf::Texture& t, Resource::ID id, int width, int height, int separatorX, int separatorY, bool hasSeparatorInEnd) {
    textureId = id;
    texture = t;
    spriteSize = new sf::Vector2i(width, height);

    spritesPositions = new std::vector<sf::IntRect*>();
    int x = hasSeparatorInEnd ? texture.getSize().x / (width + separatorX) : ceil(texture.getSize().x / (width + separatorX));
    int y = hasSeparatorInEnd ? texture.getSize().y / (height + separatorY) : ceil(texture.getSize().y / (height + separatorY));

    for(int i = 0; i<x; i++) {
        for(int j = 0; j<y; j++) {
            sf::IntRect *tmp = new sf::IntRect();
            tmp->left = (width + separatorX) * i;
            tmp->top = (height + separatorY) * j;
            tmp->width = width;
            tmp->height = height;
            spritesPositions->push_back(tmp);
        }
    }
    size = x*y;
}

int SpriteSheet::getSize() {
    return size;
}


sf::IntRect* SpriteSheet::getPositionFromIndex(int index) {
    return spritesPositions->at(index);
}

sf::Vector2i *SpriteSheet::getSpriteSize()
{
    return spriteSize;
}

sf::Texture& SpriteSheet::getTexture()
{
    return texture;
}
