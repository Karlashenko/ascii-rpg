#pragma once

#include <cmath>

struct Vector2f
{
    float X;
    float Y;

    Vector2f() : Vector2f(0, 0)
    {
    }

    explicit Vector2f(float scale) : Vector2f(scale, scale)
    {
    }

    Vector2f(float x, float y) : X(x), Y(y)
    {
    }

    Vector2f(const Vector2f& other) : Vector2f(other.X, other.Y)
    {
    }

    [[nodiscard]] float Magnitude() const
    {
        return sqrt((float) (X * X + Y * Y));
    }

    [[nodiscard]] Vector2f Normalized() const
    {
        float magnitude = Magnitude();

        return {X / magnitude, Y / magnitude};
    }

    Vector2f operator*(const Vector2f& other) const
    {
        return {X * other.X, Y * other.Y};
    }

    Vector2f operator*(const float& scale) const
    {
        return {X * scale, Y * scale};
    }

    bool operator==(const Vector2f& other) const
    {
        float epsilon = std::numeric_limits<float>::epsilon();

        return abs(X - other.X) < epsilon && abs(Y - other.Y) < epsilon;
    }

    bool operator!=(const Vector2f& other) const
    {
        return !(other == *this);
    }
};
