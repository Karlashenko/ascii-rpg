#pragma once

class Math
{
public:
    template<typename T>
    static T Clamp(const T& value, const T& min, const T& max)
    {
        if (value > max)
            return max;

        if (value < min)
            return min;

        return value;
    }
};