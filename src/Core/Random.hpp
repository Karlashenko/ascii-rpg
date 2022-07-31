#pragma once

#include <random>

class Random
{
public:
    explicit Random(int seed) : m_Seed(seed)
    {
    }

    [[nodiscard]] float range(float p_min, float p_max) const
    {
        static std::default_random_engine random_engine(m_Seed);
        static std::uniform_real_distribution<> distribution(p_min, p_max);
        return (float) distribution(random_engine);
    }

    [[nodiscard]] int range(int p_min, int p_max) const
    {
        static std::default_random_engine random_engine(m_Seed);
        static std::uniform_real_distribution<> distribution(p_min, p_max);
        return (int) distribution(random_engine);
    }

private:
    int m_Seed;
};
