#pragma once

#include "Color.hpp"

class Console final
{
public:
    Console();
    ~Console();

    [[nodiscard]] int ReadKey() const;

    void Draw(int x, int y, const char* symbol) const;
    void Draw(int x, int y, const char* symbol, const Color& color) const;
    void Flush() const;

private:
    [[nodiscard]] short ConvertColorToColorPairIndex(const Color& color) const;
};
