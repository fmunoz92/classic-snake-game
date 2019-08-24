#include "Game.h"

#include <SFML/Graphics.hpp>

#include "Director.h"
#include "models/Level.h"
#include "models/Snake.h"
#include "scenes/GameScene.h"

Game::Game()
{
    Director* director = Director::getInstance();

    Level* level = new Level("levels/level1.txt", '1');

    director->setLevel(level);
    director->setSnake(new Snake(level));

    director->setWindow(new sf::RenderWindow(sf::VideoMode(390, 390), "Snake"));
    director->setClock(new sf::Clock());
    director->setScene(new GameScene());
}

//TODO: modularizar
void Game::run()
{
    Director* director = Director::getInstance();
    sf::RenderWindow* window = director->getWindow();
    Scene* scene = NULL;

    while (window->isOpen())
    {
        scene = director->getScene();


        sf::Event e;
        while (window->pollEvent(e))
        {
            scene->processEvent(e);

            if (e.type == sf::Event::KeyPressed && e.key.code == sf::Keyboard::Escape)
                window->close();
            else if (e.type == sf::Event::Closed)
                window->close();
        }

        scene->updateState();

        window->clear(sf::Color(0, 0, 0, 255));
        scene->draw();
        window->display();
    }
}

Game::~Game()
{}
