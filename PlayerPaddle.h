#ifndef PLAYERPADDLE_H_
#define PLAYERPADDLE_H_

#include <VisibleGameObject.h>

class PlayerPaddle :
    public VisibleGameObject
{
public:
    PlayerPaddle();
    ~PlayerPaddle();

    void Update(float elapsedTime);
    void Draw(sf::RenderWindow& rw);

    float GetVelocity() const;

private:
    float m_velocity;  // -- left ++ right
    float m_maxVelocity;
};

#endif
