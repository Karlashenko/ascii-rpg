#pragma once

#include "../../Core/Numerics/Vector2i.hpp"

struct TranslationComponent final
{
    Vector2i Vector;

    explicit TranslationComponent(const Vector2i& vector) : Vector(vector)
    {
    }
};