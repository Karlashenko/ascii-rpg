#pragma clang diagnostic push
#pragma ide diagnostic ignored "readability-convert-member-functions-to-static"

#include <curses.h>
#include <iostream>
#include "Console.hpp"

Console::Console()
{
    initscr();

    if (!has_colors())
    {
        endwin();
        std::cout << "Your terminal does not support color" << std::endl;
        exit(1);
    }

    // Disable hotkeys
    // raw();

    noecho();
    curs_set(0);
    start_color();

    init_pair((short) Color::Black, COLOR_BLACK, COLOR_BLACK);
    init_pair((short) Color::Red, COLOR_RED, COLOR_BLACK);
    init_pair((short) Color::Green, COLOR_GREEN, COLOR_BLACK);
    init_pair((short) Color::Yellow, COLOR_YELLOW, COLOR_BLACK);
    init_pair((short) Color::Blue, COLOR_BLUE, COLOR_BLACK);
    init_pair((short) Color::Magenta, COLOR_MAGENTA, COLOR_BLACK);
    init_pair((short) Color::Cyan, COLOR_CYAN, COLOR_BLACK);
    init_pair((short) Color::White, COLOR_WHITE, COLOR_BLACK);
}

Console::~Console()
{
    endwin();
}

int Console::ReadKey() const
{
    int keyCode = getch();
    return keyCode;
}

void Console::Draw(int x, int y, const char* symbol) const
{
    Draw(x, y, symbol, Color::White);
}

void Console::Draw(int x, int y, const char* symbol, const Color& color) const
{
    short colorPairIndex = ConvertColorToColorPairIndex(color);

    attron(COLOR_PAIR(colorPairIndex));

    mvprintw(y, x, symbol);

    attroff(COLOR_PAIR(colorPairIndex));
}

void Console::Flush() const
{
    refresh();
}

short Console::ConvertColorToColorPairIndex(const Color& color) const
{
    switch (color)
    {
        case Color::Black: return COLOR_BLACK;
        case Color::Red: return COLOR_RED;
        case Color::Green: return COLOR_GREEN;
        case Color::Yellow: return COLOR_YELLOW;
        case Color::Blue: return COLOR_BLUE;
        case Color::Magenta: return COLOR_MAGENTA;
        case Color::Cyan: return COLOR_CYAN;
        case Color::White: return COLOR_WHITE;
        default: return COLOR_BLACK;
    }
}

#pragma clang diagnostic pop