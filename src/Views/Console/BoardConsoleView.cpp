#include "BoardConsoleView.hpp"

void BoardConsoleView::Render()
{
    const std::vector<Cell>& cells = m_Board->Cells();

    for (auto cell : cells)
    {
        RenderCell(cell);
    }
}

void BoardConsoleView::RenderCell(const Cell& cell) const
{
    m_Console->Draw(cell.X, cell.Y, "+");
}
