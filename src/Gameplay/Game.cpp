#include "Game.hpp"

Game::Game()
{
    // ...
}

Game::~Game()
{
    // ...
}

void Game::Update()
{
    if (m_State == nullptr)
    {
        return;
    }

    m_State->Update();
}

void Game::SwitchState(IGameState* state)
{
    if (m_State != nullptr)
    {
        m_State->Exit();
        delete m_State;
    }

    m_State = state;
    m_State->Enter();
}
