#include "Board.hpp"
#include "Cell.hpp"

int Board::Distance(const Cell& a, const Cell& b)
{
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int Board::PositionToIndex(int x, int y, int height)
{
    return x + y * height;
}

std::tuple<int, int> Board::IndexToPosition(int index, int height)
{
    int x = index / height;
    int y = index % height;

    return {x, y};
}

Board::Board(int width, int height) : m_Width(width), m_Height(height)
{
    for (int y = 0; y < m_Height; ++y)
    {
        for (int x = 0; x < m_Width; ++x)
        {
            int index = x + y * m_Height;

            m_Cells.emplace_back(index, x, y);
        }
    }
}

int Board::Width() const
{
    return m_Width;
}

int Board::Height() const
{
    return m_Height;
}

const std::vector<Cell>& Board::Cells() const
{
    return m_Cells;
}

const Cell& Board::CellAt(int index) const
{
    return m_Cells[index];
}

const Cell& Board::CellAt(int x, int y) const
{
    int index = PositionToIndex(x, y, m_Height);
    return m_Cells[index];
}
