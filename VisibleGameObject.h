#ifndef VISIBLEGAMEOBJECT_H_
#define VISIBLEGAMEOBJECT_H_

#include "SFML/Window.hpp"
#include "SFML/Graphics.hpp"

class VisibleGameObject
{
public:
    VisibleGameObject();
    virtual ~VisibleGameObject();

    virtual void Load(std::string filename);
    virtual void Draw(sf::RenderWindow & window);
    virtual void Update(float elapsedTime);

    virtual void SetPosition(float x, float y);
    virtual sf::Vector2f GetPosition() const;
    virtual bool IsLoaded() const;

protected:
    sf::Sprite& GetSprite();

private:
    sf::Sprite  m_sprite;
    sf::Texture m_image;
    std::string m_filename;
    bool m_isLoaded;

};

#endif
