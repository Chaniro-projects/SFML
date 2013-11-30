#include "mapspritesheet.h"

MapSpriteSheet::MapSpriteSheet()
{

}

void MapSpriteSheet::init(sf::Texture& t, Resource::ID id, int width, int height, int separatorX, int separatorY, bool hasSeparatorInEnd, std::string data) {
    SpriteSheet::init(t, id, width, height, separatorX, separatorY, hasSeparatorInEnd);

    std::ifstream f(data);
    if(f) {
        std::cout <<
    }
}


MapSpriteSheet::DIRECTION MapSpriteSheet::getDirectionFromString(std::string &str) {
    if(str == "t")
                     return MapSpriteSheet::t;
    if(str == "r")
                     return MapSpriteSheet::r;
    if(str == "b")
                     return MapSpriteSheet::b;
    if(str == "l")
                     return MapSpriteSheet::l;
    if(str == "tl")
                     return MapSpriteSheet::tl;
    if(str == "tr")
                     return MapSpriteSheet::tr;
    if(str == "bl")
                     return MapSpriteSheet::bl;
    if(str == "br")
                     return MapSpriteSheet::br;
    if(str == "m")
                     return MapSpriteSheet::m;
    if(str == "o")
                     return MapSpriteSheet::o;

    return MapSpriteSheet::o;
}
