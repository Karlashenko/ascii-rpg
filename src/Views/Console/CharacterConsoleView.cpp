#include "CharacterConsoleView.hpp"

void CharacterConsoleView::Render()
{
    const Vector2i& position = m_Character->Position;

    m_Console->Draw(position.X, position.Y, "@", Color::Green);
}
