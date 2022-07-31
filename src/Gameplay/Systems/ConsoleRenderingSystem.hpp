#pragma once

#include "IGameSystem.hpp"
#include "../../Graphics/Console.hpp"

class ConsoleRenderingSystem : public IGameSystem
{
public:
    ConsoleRenderingSystem(const EntityRegistry* registry, const Console* console);
    ~ConsoleRenderingSystem() override = default;

    void Update() override;

private:
    const EntityRegistry* m_Registry;
    const Console* m_Console;
};
