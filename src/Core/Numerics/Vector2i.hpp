#pragma once

#include <cmath>
#include "../Math.hpp"

struct Vector2i
{
    int X;
    int Y;

    Vector2i() : Vector2i(0, 0)
    {
    }

    explicit Vector2i(int scale) : Vector2i(scale, scale)
    {
    }

    Vector2i(int x, int y) : X(x), Y(y)
    {
    }

    Vector2i(const Vector2i& other) : Vector2i(other.X, other.Y)
    {
    }

    void Clamp(int minX, int maxX, int minY, int maxY)
    {
        X = Math::Clamp(X, minX, maxX);
        Y = Math::Clamp(Y, minY, maxY);
    }

    Vector2i operator*(const Vector2i& other) const
    {
        return {X * other.X, Y * other.Y};
    }

    Vector2i operator*(const int& scale) const
    {
        return {X * scale, Y * scale};
    }

    bool operator==(const Vector2i& other) const
    {
        return X == other.X && Y == other.Y;
    }

    bool operator!=(const Vector2i& other) const
    {
        return !(other == *this);
    }
};
