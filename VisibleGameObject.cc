#include "VisibleGameObject.h"


VisibleGameObject::VisibleGameObject()
    : m_isLoaded(false) //false or true??
{
    //m_isLoaded = false;
}


VisibleGameObject::~VisibleGameObject()
{
}

void VisibleGameObject::Load(std::string filename)
{
    if(m_image.loadFromFile(filename) == false)
    {
        m_filename = "";
        m_isLoaded = false;
    }
    else
    {
        m_filename = filename;
        m_sprite.setTexture(m_image);
        m_isLoaded = true;
    }
}

void VisibleGameObject::Update(float elapsedTime)
{
}

void VisibleGameObject::Draw(sf::RenderWindow & renderWindow)
{
    if(m_isLoaded)
    {
        renderWindow.draw(m_sprite);
    }
}

void VisibleGameObject::SetPosition(float x, float y)
{
    if(m_isLoaded)
    {
        m_sprite.setPosition(x,y);
    }
}

sf::Vector2f VisibleGameObject::GetPosition() const
{
    if(m_isLoaded)
    {
        return m_sprite.getPosition();
    }
    return sf::Vector2f();
}


sf::Sprite& VisibleGameObject::GetSprite()
{
    return m_sprite;
}

bool VisibleGameObject::IsLoaded() const
{
    return m_isLoaded;
}
