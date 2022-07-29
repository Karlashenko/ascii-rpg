#pragma once

#include <unordered_set>
#include "IInput.hpp"
#include "../Graphics/Console.hpp"

class ConsoleInput: IInput
{
private:
    static InputKey ConvertKeyCode(int keyCode);

public:
    explicit ConsoleInput(const Console* console);

    bool IsKeyDown(const InputKey& key) override;
    void Update();
    void Clear();

private:
    std::unordered_set<InputKey> m_Keys;
    const Console* m_Console;
};
