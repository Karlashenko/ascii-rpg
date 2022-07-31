#pragma once

class IGameSystem
{
public:
    virtual ~IGameSystem() = default;

    virtual void Update()
    {
    }
};