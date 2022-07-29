#pragma once

#include "../IView.hpp"
#include "../../Gameplay/Cell.hpp"
#include "../../Graphics/Console.hpp"

class BoardConsoleView: public IView
{
public:
    explicit BoardConsoleView(const Console* console, const Board* board)
        : m_Board(board), m_Console(console)
    {
    }

    void Render() override;

private:
    const Board* m_Board;
    const Console* m_Console;

    void RenderCell(const Cell& cell) const;
};
