#pragma once

#include "Event.hpp"
#include "../Input/InputKey.hpp"

class InputEvent : public Event
{
public:
    const InputKey& Key;

    InputEvent() = delete;
    InputEvent(const InputEvent& other) = delete;
    InputEvent(InputEvent&& other) = delete;

    explicit InputEvent(const InputKey& key) : Event(), Key(key)
    {
    }
};