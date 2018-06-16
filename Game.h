#ifndef GAME_H_
#define GAME_H_
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <GameObjectManager.h>
#include <PlayerPaddle.h>


class Game
{

public:
  static void Start();
  static sf::RenderWindow& GetWindow();
  //const static sf::Input& GetInput();
  const static int SCREEN_WIDTH = 1024;
  const static int SCREEN_HEIGHT = 768;

private:
  static bool IsExiting();
  static void GameLoop();

  static void ShowSplashScreen();
  static void ShowMenu();

  enum GameState { Uninitialized, ShowingSplash, Paused,
          ShowingMenu, Playing, Exiting };

  static GameState m_gameState;
  static sf::RenderWindow m_mainWindow;
  static GameObjectManager m_gameObjectManager;
  static sf::Clock m_clock;
};

#endif
