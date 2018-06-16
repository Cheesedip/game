#include "MainMenu.h"
#include <iostream>


MainMenu::MenuResult MainMenu::Show(sf::RenderWindow& window)
{

    //Load menu image from file
    sf::Texture texture;
    if (texture.loadFromFile("/home/maikel/cpp_course/engine_project/engine/images/Mainmenu.png") != true){
        std::cout <<"unable to load mainmenu from file..."<< std::endl;
        exit(1);
    }
    sf::Sprite sprite(texture);

    //Setup clickable regions

    //Play menu item coordinates
    MenuItem playButton(sf::Rect<int>(0,145,1023,235), Play);
    MenuItem exitButton(sf::Rect<int>(0, 383, 1023, 177), Exit);
    /*
    playButton.rect.Top= 145;
    playButton.rect.Bottom = 380;
    playButton.rect.Left = 0;
    playButton.rect.Right = 1023;
    playButton.action = Play;

    //Exit menu item coordinates
    MenuItem exitButton;
    exitButton.rect.Left = 0;
    exitButton.rect.Right = 1023;
    exitButton.rect.Top = 383;
    exitButton.rect.Bottom = 560;
    exitButton.action = Exit;
    */

    _menuItems.push_back(playButton);
    _menuItems.push_back(exitButton);

    window.draw(sprite);
    window.display();

    return GetMenuResponse(window);
}

MainMenu::MenuResult MainMenu::HandleClick(int x, int y)
{
    std::list<MenuItem>::iterator it;

    for ( it = _menuItems.begin(); it != _menuItems.end(); it++)
    {
        sf::Rect<int> menuItemRect = (*it).m_rect;
        if( menuItemRect.top + menuItemRect.height > y
            && menuItemRect.top < y
            && menuItemRect.left < x
            && menuItemRect.left + menuItemRect.width > x)
            {
                return (*it).m_action;
            }
    }

    return Nothing;
}

MainMenu::MenuResult  MainMenu::GetMenuResponse(sf::RenderWindow& window)
{
    sf::Event menuEvent;

    while(42 != 43)
    {

        while(window.pollEvent(menuEvent))
        {
            if(menuEvent.type == sf::Event::MouseButtonPressed)
            {
                return HandleClick(menuEvent.mouseButton.x,menuEvent.mouseButton.y);
            }
            if(menuEvent.type == sf::Event::Closed)
            {
                return Exit;
            }
        }
    }
}
