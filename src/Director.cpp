#include "Director.h"

void Director::run()
{
    _currentScene->run();
}

void Director::showGameOver()
{
}

void Director::showMenu()
{
}

void Director::showPauseMenu()
{
}

void Director::showGame()
{
}

Scene* Director::getScene()  const
{
    return _currentScene;
}

Level* Director::getLevel()  const
{
    return _level;
}

Snake* Director::getSnake()  const
{
    return _snake;
}

sf::RenderWindow* Director::getWindow() const
{
    return _window;
}

sf::Clock* Director::getClock() const
{
    return _clock;
}

void Director::setScene(Scene* scene)
{
    _currentScene = scene;
}

void Director::setLevel(Level* level)
{
    delete _level;
    _level = level;
}

void Director::setSnake(Snake* snake)
{
    _snake = snake;
}

void Director::setWindow(sf::RenderWindow* window)
{
    _window = window;
}

void Director::setClock(sf::Clock* clock)
{
    _clock = clock;
}

void Director::goToNextLevel()
{
    char nextLevelId = _level->getId();
    nextLevelId++;

    std::string map = "";
    map += _level->getPatch();
    map += nextLevelId;
    map += _level->getExt();

    delete _level;

    _level = new Level(map, nextLevelId);
    _snake->setLevel(_level);
    _snake->reset();
}

Director::~Director()
{
    delete _snake;
    delete _level;
    delete _window;
    delete _currentScene;
    delete _clock;
}
