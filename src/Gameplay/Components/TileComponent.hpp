#pragma once

struct TileComponent final
{
    bool IsWalkable;

    TileComponent() : IsWalkable(false)
    {
    }

    explicit TileComponent(bool isWalkable) : IsWalkable(isWalkable)
    {
    }
};