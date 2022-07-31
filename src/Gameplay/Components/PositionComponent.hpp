#pragma once

#include "../../Core/Numerics/Vector2i.hpp"

struct PositionComponent final
{
    Vector2i Vector;

    explicit PositionComponent(const Vector2i& vector) : Vector(vector)
    {
    }
};