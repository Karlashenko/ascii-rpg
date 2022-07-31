#include "ConsoleRenderingSystem.hpp"
#include "../Components/ColoredTextComponent.hpp"
#include "../Components/PositionComponent.hpp"

ConsoleRenderingSystem::ConsoleRenderingSystem(const entt::registry* registry, const Console* console)
    : m_Registry(registry), m_Console(console)
{
}

void ConsoleRenderingSystem::Update()
{
    auto view = m_Registry->view<const ColoredTextComponent, const PositionComponent>();

    for (auto entity : view)
    {
        const ColoredTextComponent& text = view.get<const ColoredTextComponent>(entity);
        const PositionComponent& position = view.get<const PositionComponent>(entity);

        m_Console->Draw(position.Vector, text.Text.c_str(), text.Color);
    }
}
