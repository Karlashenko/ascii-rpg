#pragma once

#include "IGameSystem.hpp"
#include "../Tilemap.hpp"

class CollisionSystem : public IGameSystem
{
public:
    explicit CollisionSystem(EntityRegistry* registry, const Tilemap* tilemap);

    void Update() override;

private:
    EntityRegistry* m_Registry;
    const Tilemap* m_Tilemap;
};
