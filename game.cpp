#include "game.h"

Game::Game() :
    map(50, 38),
    WIDTH(800),
    HEIGHT(600),
    TITLE("SFML"),
    window(sf::VideoMode(WIDTH, HEIGHT), TITLE, sf::Style::Default)
{
    timePerFrame = sf::seconds(1.f / 60.f);
}

void Game::Go() {
    sf::Clock clock;
    sf::Time lastUpdate = sf::Time::Zero;
    while(window.isOpen())
    {
        lastUpdate += clock.restart();
        while(lastUpdate > timePerFrame) {
            lastUpdate -= timePerFrame;
            processEvent();
            update(timePerFrame);
        }
        render();
    }
}

void Game::processEvent() {
    sf::Event event;
    while (window.pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window.close();
    }
}

void Game::update(sf::Time delta) {

}

void Game::render() {
    window.clear(sf::Color(122, 164, 248));
    map.Draw(window);
    window.display();
}
