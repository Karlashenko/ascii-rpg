#pragma once

#include "../IView.hpp"
#include "../../Gameplay/Character.hpp"
#include "../../Graphics/Console.hpp"

class CharacterConsoleView : public IView
{
public:
    explicit CharacterConsoleView(const Character* character, const Console* console)
        : m_Character(character), m_Console(console)
    {
    }

    void Render() override;

private:
    const Character* m_Character;
    const Console* m_Console;
};