#pragma once

#include <vector>
#include "../Core/Numerics/Vector2i.hpp"
#include "Components/TileComponent.hpp"

class Tilemap
{
public:
    [[nodiscard]] static int Distance(const Vector2i& a, const Vector2i& b);

public:
    Tilemap() = delete;
    Tilemap(int width, int height, EntityRegistry* registry);

    [[nodiscard]] int PositionToIndex(const Vector2i& position) const;
    [[nodiscard]] int PositionToIndex(int x, int y) const;
    [[nodiscard]] Vector2i IndexToPosition(int index) const;

    [[nodiscard]] int Width() const;
    [[nodiscard]] int Height() const;
    [[nodiscard]] const Vector2i& Size() const;

    [[nodiscard]] bool TileAt(const Vector2i& position, TileComponent& result) const;
    [[nodiscard]] bool TileAt(int index, TileComponent& result) const;

private:
    Vector2i m_Size;
    EntityRegistry* m_Registry;
    EntityId* m_TileEntities;
};
