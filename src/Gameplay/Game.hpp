#pragma once

#include "States/IGameState.hpp"

class Game final
{
public:
    Game();
    ~Game();

    void Update();

private:
    IGameState* m_State;

    void SwitchState(IGameState* state);
};
