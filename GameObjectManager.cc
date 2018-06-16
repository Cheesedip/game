#include "GameObjectManager.h"

using Map = std::map<std::string, VisibleGameObject*>;

GameObjectManager::GameObjectManager()
{
}

GameObjectManager::~GameObjectManager()
{
    std::for_each(m_gameObjects.begin(),m_gameObjects.end(),GameObjectDeallocator());
}

void GameObjectManager::Add(std::string name, VisibleGameObject* gameObject)
{
    m_gameObjects.insert(std::make_pair(name,gameObject));
}

void GameObjectManager::Remove(std::string name)
{
    Map::iterator results = m_gameObjects.find(name);
    if(results != m_gameObjects.end() )
    {
        delete results->second; //use of this delete??
        m_gameObjects.erase(results);
    }
}

VisibleGameObject* GameObjectManager::Get(std::string name) const
{
    Map::const_iterator results = m_gameObjects.find(name);
    if(results == m_gameObjects.end() )
        return NULL;
    return results->second;

}

int GameObjectManager::GetObjectCount() const
{
    return m_gameObjects.size();
}


void GameObjectManager::DrawAll(sf::RenderWindow& renderWindow)
{
    Map::const_iterator itr = m_gameObjects.begin();
    while(itr != m_gameObjects.end())
    {
        itr->second->Draw(renderWindow);
        itr++;
    }
}

void GameObjectManager::UpdateAll(sf::Time& time)
{
    Map::const_iterator itr = m_gameObjects.begin();
    //float timeDelta = Game::GetWindow().GetFrameTime();

    while(itr != m_gameObjects.end())
    {
        itr->second->Update(time.asSeconds());
        itr++;
    }

}
