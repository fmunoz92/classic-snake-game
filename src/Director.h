#ifndef DIRECTOR_H
#define DIRECTOR_H

#include <SFML/Graphics.hpp>

#include "Scene.h"
#include "models/Level.h"
#include "models/Snake.h"

class Director
{
public:
    static const unsigned int WIDHT_CELL  = 26;
    static const unsigned int HEIGHT_CELL = 26;

    static Director* getInstance()
    {
        static Director instance;

        return &instance;
    }

    void run();
    void showGameOver();
    void showMenu();
    void showPauseMenu();
    void showGame();

    Scene*            getScene()  const;
    Level*            getLevel()  const;
    Snake*            getSnake()  const;
    sf::RenderWindow* getWindow() const;
    sf::Clock* getClock() const;

    void setScene(Scene* scene);
    void setLevel(Level* level);
    void setSnake(Snake* snake);
    void setWindow(sf::RenderWindow* window);
    void setClock(sf::Clock* clock);

    void goToNextLevel();

    ~Director();//delete all members class
private:
    Director() {};

    sf::RenderWindow* _window;
    sf::Clock* _clock;

    Scene* _currentScene;
    Level* _level;
    Snake* _snake;
};


#endif
