#include <Game.h>
#include <SplashScreen.h>
#include <MainMenu.h>
#include <GameBall.h>
#include <iostream>
#include <chrono>
#include <thread>

void Game::Start(void)
{
  if(m_gameState != Uninitialized)
    return;

  const int FPS = 60.0f;

  m_mainWindow.create(sf::VideoMode(1024,768,32),"Pang!");
  m_mainWindow.setFramerateLimit(FPS);

  PlayerPaddle *player1 = new PlayerPaddle();
  GameBall *ball = new GameBall();

  player1->SetPosition((1024/2)-45,700);
  ball->SetPosition((SCREEN_WIDTH/2),(SCREEN_HEIGHT/2)-15);

  m_gameObjectManager.Add("Paddle1",player1);
  m_gameObjectManager.Add("Ball",ball);

  m_gameState = Game::ShowingSplash;

  while(!IsExiting())
  {
    GameLoop();
  }

  m_mainWindow.close();
}

bool Game::IsExiting()
{
  if(m_gameState == Game::Exiting)
    return true;
  else
    return false;
}

void Game::GameLoop()
{

    sf::Event currentEvent;

    while(m_mainWindow.isOpen())
    {
        while(m_mainWindow.pollEvent(currentEvent)){

            switch(m_gameState)
            {
              case Game::ShowingSplash:
            {
                ShowSplashScreen();
                break;
            }
              case Game::ShowingMenu:
            {
                ShowMenu();
                break;
            }
              case Game::Playing:
            {
                if(currentEvent.type == sf::Event::Closed)
                {
                m_gameState = Game::Exiting;
                }
                if(currentEvent.type == sf::Event::KeyPressed)
                {
                    if(currentEvent.key.code == sf::Keyboard::Escape){
                        m_gameState = Game::ShowingMenu;
                     }
                }

                break;
            }
            case Game::Exiting:
            {
                exit(0);
            }
            }
        }
        sf::Time time = m_clock.restart();
        m_mainWindow.clear(sf::Color(0,0,0));
        m_gameObjectManager.UpdateAll(time);
        m_gameObjectManager.DrawAll(m_mainWindow);
        m_mainWindow.display();
     }
}

void Game::ShowSplashScreen()
{
    SplashScreen splashScreen;
    splashScreen.Show(m_mainWindow);
    m_gameState = Game::ShowingMenu;
}

void Game::ShowMenu()
{
    MainMenu mainMenu;
    MainMenu::MenuResult result = mainMenu.Show(m_mainWindow);
    switch(result)
    {
    case MainMenu::Exit:
            m_gameState = Game::Exiting;
            break;
        case MainMenu::Play:
            m_gameState = Game::Playing;
            break;
    }
}

/*
const sf::Input& Game::GetInput()
{
    return _mainWindow.GetInput();
}
*/

sf::RenderWindow& Game::GetWindow()
{
    return m_mainWindow;
}

Game::GameState Game::m_gameState = Uninitialized;
sf::RenderWindow Game::m_mainWindow;
sf::Clock Game::m_clock;
GameObjectManager Game::m_gameObjectManager;
