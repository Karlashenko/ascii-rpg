#pragma once

class IGameState
{
public:
    virtual ~IGameState() = default;

    virtual void Enter() {};
    virtual void Exit() {};
    virtual void Update() {};
};