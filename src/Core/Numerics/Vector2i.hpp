#pragma once

#include <cmath>
#include "../Math.hpp"

struct Vector2i
{
    static const Vector2i& Zero()
    {
        static auto zero = Vector2i(0);
        return zero;
    }

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

    Vector2i& Clamped(const Vector2i& min, const Vector2i& max)
    {
        Clamp(min, max);
        return *this;
    }

    void Clamp(const Vector2i& min, const Vector2i& max)
    {
        Clamp(min.X, max.X, min.Y, max.Y);
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

    Vector2i operator+(const Vector2i& other) const
    {
        return {X + other.X, Y + other.Y};
    }

    Vector2i& operator+=(const Vector2i& other)
    {
        X += other.X;
        Y += other.Y;

        return *this;
    }

    bool operator==(const Vector2i& other) const
    {
        return X == other.X && Y == other.Y;
    }

    bool operator!=(const Vector2i& other) const
    {
        return !(other == *this);
    }

    [[nodiscard]] std::string ToString() const
    {
        return "X: " + std::to_string(X) + " Y: " + std::to_string(Y);
    }
};