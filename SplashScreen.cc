#include "SplashScreen.h"
#include <iostream>

void SplashScreen::Show(sf::RenderWindow & renderWindow)
{
    sf::Texture texture;
    if(texture.loadFromFile("/home/maikel/cpp_course/engine_project/engine/images/Splashscreen.png") != true)
    {
        std::cout <<"unable to load splashscreen..." << std::endl;
        return;
    }

    sf::Sprite sprite(texture);

    renderWindow.draw(sprite);
    renderWindow.display();

    sf::Event event;
    while(true)
    {
        while(renderWindow.pollEvent(event))
        {
            if(event.type == sf::Event::EventType::KeyPressed
                || event.type == sf::Event::EventType::MouseButtonPressed
                || event.type == sf::Event::EventType::Closed )
            {
                return;
            }
        }
    }
}
