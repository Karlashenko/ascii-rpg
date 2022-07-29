#pragma once

enum class InputKey
{
    Unknown = 0,
    Left = 1 << 1,
    Right = 1 << 2,
    Up = 1 << 3,
    Down = 1 << 4,
    Act = 1 << 5,
    Cancel = 1 << 6,
};