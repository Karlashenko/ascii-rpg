#pragma once

#include "Board.hpp"

struct Cell
{
    Cell(int index, int x, int y) : Index(index), X(x), Y(y)
    {
    }

    int Index;
    int X;
    int Y;
};
