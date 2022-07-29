#pragma once

#include "InputKey.hpp"

class IInput
{
public:
    virtual bool IsKeyDown(const InputKey& key) = 0;
};