#include "PlayerPaddle.h"
#include "Game.h"
#include <cassert>


PlayerPaddle::PlayerPaddle() :
m_velocity(0),
m_maxVelocity(600.0f)
{
    Load("/home/maikel/cpp_course/engine_project/engine/images/paddle.png");
    assert(IsLoaded());

    GetSprite().setOrigin(GetSprite().getGlobalBounds().width /2, GetSprite().getGlobalBounds().height / 2);

}

PlayerPaddle::~PlayerPaddle()
{
}

void PlayerPaddle::Draw(sf::RenderWindow & rw)
{
    VisibleGameObject::Draw(rw);
}

float PlayerPaddle::GetVelocity() const
{
    return m_velocity;
}

void PlayerPaddle::Update(float elapsedTime)
{

    /*
    if(Game::GetInput().IsKeyDown(sf::Key::Left))
    {
        m_velocity-= 3.0f;
    }
    if(Game::GetInput().IsKeyDown(sf::Key::Right))
    {
        m_velocity+= 3.0f;
    }

    if(Game::GetInput().IsKeyDown(sf::Key::Down))
    {
        m_velocity= 0.0f;
    }
    */

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
    {
        m_velocity-= 3.0f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
    {
        m_velocity+= 3.0f;
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        m_velocity= 0.0f;
    }

    if(m_velocity > m_maxVelocity)
        m_velocity = m_maxVelocity;

    if(m_velocity < -m_maxVelocity)
        m_velocity = -m_maxVelocity;


    sf::Vector2f pos = GetPosition();

    if(pos.x  < GetSprite().getGlobalBounds().width /2
        || pos.x > (Game::SCREEN_WIDTH - GetSprite().getGlobalBounds().width/2))
    {
        m_velocity = -m_velocity; // Bounce by current velocity in opposite direction
    }

    GetSprite().move(m_velocity * elapsedTime, 0);
}
