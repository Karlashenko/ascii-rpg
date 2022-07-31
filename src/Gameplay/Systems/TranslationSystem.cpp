#include "TranslationSystem.hpp"
#include "../Components/PositionComponent.hpp"
#include "../Components/TranslationComponent.hpp"

TranslationSystem::TranslationSystem(EntityRegistry* registry) : m_Registry(registry)
{
}

void TranslationSystem::Update()
{
    const auto& view = m_Registry->view<PositionComponent, TranslationComponent>();

    for (auto entity : view)
    {
        auto& position = view.get<PositionComponent>(entity);
        auto& translation = view.get<TranslationComponent>(entity);

        position.Vector += translation.Vector;
        translation.Vector = Vector2i(0);
    }
}
