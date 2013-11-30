#include "map.h"

Map::Map(int x, int y)
{
    textures.load(Resource::ID::Earth, std::string("Terraria/Tiles_0.png"));
    textures.load(Resource::ID::Stone, std::string("Terraria/Tiles_1.png"));

    ss.init(textures.get(Resource::Earth), Resource::Earth, 16, 16, 2, 2, true);

    mapSize = sf::Vector2i(x, y);

    map = (sf::Sprite***) malloc(sizeof(sf::Sprite) * x);

    int top[] = {5, 10, 15};
    int middle[] = {6, 11, 16};

    for(int i = 0; i<x; i++) {
        map[i] = (sf::Sprite**) malloc(sizeof(sf::Sprite) * y);
        for(int j = 0; j<y; j++) {
            map[i][j] = 0;
            if(j > 27) {
                sf::Sprite *s = new sf::Sprite();
                s->setPosition(i*16, j*16);
                s->setTexture(ss.getTexture());
                int nb = rand() % 2;

                if(j == 28)
                    s->setTextureRect(*(ss.getPositionFromIndex(top[nb])));
                else
                    s->setTextureRect(*(ss.getPositionFromIndex(middle[nb])));

                map[i][j] = s;
            }
        }
    }

}

void Map::Draw(sf::RenderWindow& window) {
    for(int i = 0; i<mapSize.x; i++) {
        for(int j = 0; j<mapSize.y; j++) {
            if(map[i][j] != 0)
                window.draw(*(map[i][j]));
        }
    }
}
