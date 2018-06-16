#include <cassert>
#include "GameBall.h"


GameBall::GameBall()
{
  Load("/home/maikel/cpp_course/engine_project/engine/images/ball.png");
  assert(IsLoaded());

  GetSprite().setOrigin(15,15);
}

GameBall::~GameBall()
{
}
