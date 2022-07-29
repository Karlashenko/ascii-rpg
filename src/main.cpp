#include <iostream>
#include "Input/ConsoleInput.hpp"
#include "Gameplay/Character.hpp"
#include "Graphics/Console.hpp"
#include "Views/Console/BoardConsoleView.hpp"
#include "Views/Console/CharacterConsoleView.hpp"

int main()
{
    Console console = Console();
    ConsoleInput input = ConsoleInput(&console);

    auto* board = new Board(30, 20);
    auto* boardView = new BoardConsoleView(&console, board);

    auto* character = new Character();
    auto* characterView = new CharacterConsoleView(character, &console);

    while (true)
    {
        input.Update();

        if (input.IsKeyDown(InputKey::Left))
            character->Position.X -= 1;

        if (input.IsKeyDown(InputKey::Right))
            character->Position.X += 1;

        if (input.IsKeyDown(InputKey::Up))
            character->Position.Y -= 1;

        if (input.IsKeyDown(InputKey::Down))
            character->Position.Y += 1;

        character->Position.Clamp(0, board->Width() - 1, 0, board->Height() - 1);

        boardView->Render();
        characterView->Render();

        console.Flush();

        input.Clear();
    }
}