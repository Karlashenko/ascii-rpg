#pragma once

#include "../../Graphics/Color.hpp"

struct ColoredTextComponent final
{
    std::string Text;
    Color Color;

    ColoredTextComponent(std::string text, enum Color color)
        : Text(std::move(text)), Color(color)
    {
    }
};