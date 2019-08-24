#include "TextEndActor.h"

#include <stdexcept>
#include <iostream>

TextEndActor::TextEndActor()
{
    _director = Director::getInstance();

    if (!_cheeseburger.loadFromFile("font/cheeseburger.ttf"))
    {
        std::cerr << "File Not Found: cheeseburger.ttf" << std::endl;
        throw std::exception();
    }

    _textEnd.setFont(_cheeseburger);
    _textEnd.setCharacterSize(30.f);
    _textEnd.setColor(sf::Color(255, 255, 255));
    _textEnd.setPosition(65, 165);

    const std::string text = "     Game Over!     \n"
                             "(press escape to exit)";

    _textEnd.setString(text);
}

void TextEndActor::processEvent(sf::Event&)
{}

void TextEndActor::updateState()
{}

void TextEndActor::draw()
{
    Snake* snake = _director->getSnake();
    sf::RenderWindow* window = _director->getWindow();

    if (!snake->isLive())
        window->draw(_textEnd);
}
