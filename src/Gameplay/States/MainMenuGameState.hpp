#pragma once

#include "IGameState.hpp"
#include "../../Graphics/Console.hpp"

class MainMenuGameState : public IGameState
{
public:
    void Enter() override;
    void Exit() override;
    void Update() override;

private:
    const Console* m_Console;
};
