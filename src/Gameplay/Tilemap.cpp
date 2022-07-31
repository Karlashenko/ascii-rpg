#include "Tilemap.hpp"
#include "Components/PositionComponent.hpp"
#include "Components/ColoredTextComponent.hpp"
#include "../Core/Random.hpp"

Tilemap::Tilemap(int width, int height, EntityRegistry* registry) : m_Registry(registry)
{
    m_Size = Vector2i(width, height);
    m_TileEntities = new EntityId[m_Size.X * m_Size.Y];

    Random random(2);

    for (int x = 0; x < m_Size.X; x++)
    {
        for (int y = 0; y < m_Size.Y; y++)
        {
            auto entity = m_Registry->create();

            int index = PositionToIndex(x, y);
            m_TileEntities[index] = entity;

            bool isWalkable = random.range(0.0f, 1.0f) > 0.15f;

            m_Registry->emplace<PositionComponent>(entity, Vector2i(x, y));
            m_Registry->emplace<ColoredTextComponent>(entity, isWalkable ? " " : "x", Color::Yellow);
            m_Registry->emplace<TileComponent>(entity, isWalkable);
        }
    }
}

int Tilemap::Distance(const Vector2i& a, const Vector2i& b)
{
    return abs(a.X - b.X) + abs(a.Y - b.Y);
}

int Tilemap::PositionToIndex(const Vector2i& position) const
{
    return PositionToIndex(position.X, position.Y);
}

int Tilemap::PositionToIndex(int x, int y) const
{
    return x + (y * m_Size.X);
}

Vector2i Tilemap::IndexToPosition(int index) const
{
    int x = index / m_Size.Y;
    int y = index % m_Size.Y;

    return {x, y};
}

int Tilemap::Width() const
{
    return m_Size.X;
}

int Tilemap::Height() const
{
    return m_Size.Y;
}

const Vector2i& Tilemap::Size() const
{
    return m_Size;
}

bool Tilemap::TileAt(int index, TileComponent& result) const
{
    auto position = IndexToPosition(index);

    if (position.X < 0 || position.X > m_Size.X - 1 ||
        position.Y < 0 || position.Y > m_Size.Y - 1)
    {
        return false;
    }

    EntityId entity = m_TileEntities[index];
    result = m_Registry->get<TileComponent>(entity);

    return true;
}

bool Tilemap::TileAt(const Vector2i& position, TileComponent& result) const
{
    int index = PositionToIndex(position);

    return TileAt(index, result);
}
