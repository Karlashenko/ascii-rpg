#pragma once

#include <vector>

class Cell;

class Board
{
public:
    [[nodiscard]] static int Distance(const Cell& a, const Cell& b);
    [[nodiscard]] static int PositionToIndex(int x, int y, int height);
    [[nodiscard]] static std::tuple<int, int> IndexToPosition(int index, int height);

public:
    Board() = delete;
    Board(int width, int height);

    [[nodiscard]] int Width() const;
    [[nodiscard]] int Height() const;
    [[nodiscard]] const Cell& CellAt(int index) const;
    [[nodiscard]] const Cell& CellAt(int x, int y) const;
    [[nodiscard]] const std::vector<Cell>& Cells() const;

private:
    int m_Width;
    int m_Height;

    std::vector<Cell> m_Cells;
};
