#ifndef MAINMENU_H_
#define MAINMENU_H_
#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"
#include <list>

class MainMenu
{

public:
    enum MenuResult { Nothing, Exit, Play };

    struct MenuItem
        {
        MenuItem(sf::Rect<int> rect, MenuResult action)
            : m_rect(rect),
              m_action(action) {}

        public:
            sf::Rect<int> m_rect;
            MenuResult m_action;
        };

    MenuResult Show(sf::RenderWindow& window);

private:
    MenuResult GetMenuResponse(sf::RenderWindow& window);
    MenuResult HandleClick(int x, int y);
    std::list<MenuItem> _menuItems;
};

#endif
