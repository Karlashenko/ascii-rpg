#include "ConsoleInput.hpp"

InputKey ConsoleInput::ConvertKeyCode(int keyCode)
{
    switch (keyCode)
    {
        case 97: return InputKey::Left; // A
        case 100: return InputKey::Right; // D
        case 119: return InputKey::Up; // W
        case 115: return InputKey::Down; // S
        case 32: return InputKey::Act; // Space
        case 27: return InputKey::Cancel; // Escape
        default: return InputKey::Unknown;
    }
}

ConsoleInput::ConsoleInput(const Console* console) : m_Console(console)
{
    m_Keys = std::unordered_set<InputKey>();
}

bool ConsoleInput::IsKeyDown(const InputKey& key)
{
    return m_Keys.count(key);
}

void ConsoleInput::Update()
{
    int keyCode = m_Console->ReadKey();

    m_Keys.insert(ConvertKeyCode(keyCode));
}

void ConsoleInput::Clear()
{
    m_Keys.clear();
}
