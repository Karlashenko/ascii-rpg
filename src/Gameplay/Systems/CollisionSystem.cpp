#include "CollisionSystem.hpp"
#include "../Components/TranslationComponent.hpp"
#include "../Components/PositionComponent.hpp"

CollisionSystem::CollisionSystem(EntityRegistry* registry, const Tilemap* tilemap)
    : m_Registry(registry), m_Tilemap(tilemap)
{
}

void CollisionSystem::Update()
{
    const auto& view = m_Registry->view<TranslationComponent, const PositionComponent>();

    for (auto entity : view)
    {
        auto& translation = view.get<TranslationComponent>(entity);
        const auto& position = view.get<const PositionComponent>(entity);

        auto target = (position.Vector + translation.Vector).Clamped(Vector2i::Zero(), m_Tilemap->Size());
        TileComponent targetTile;

        if (!m_Tilemap->TileAt(target, targetTile) || !targetTile.IsWalkable)
        {
            translation.Vector = Vector2i(0);
        }
    }
}
