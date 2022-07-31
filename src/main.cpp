#include "Input/ConsoleInput.hpp"
#include "Graphics/Console.hpp"
#include "Gameplay/Tilemap.hpp"
#include "Gameplay/Systems/ConsoleRenderingSystem.hpp"
#include "Gameplay/Components/PositionComponent.hpp"
#include "Gameplay/Components/TranslationComponent.hpp"
#include "Gameplay/Components/ColoredTextComponent.hpp"
#include "Gameplay/Systems/CollisionSystem.hpp"
#include "Gameplay/Systems/TranslationSystem.hpp"

int main()
{
    // todo Keybinds class that converts keycodes to keys

    Console console = Console();
    ConsoleInput input = ConsoleInput(&console);

    auto* registry = new EntityRegistry();

    auto character = registry->create();
    registry->emplace<PositionComponent>(character, Vector2i::Zero());
    registry->emplace<ColoredTextComponent>(character, "@", Color::Green);
    registry->emplace<TranslationComponent>(character, Vector2i::Zero());

    auto* tilemap = new Tilemap(150, 20, registry);

    ConsoleRenderingSystem renderingSystem = ConsoleRenderingSystem(registry, &console);
    CollisionSystem collisionSystem = CollisionSystem(registry, tilemap);
    TranslationSystem translationSystem = TranslationSystem(registry);

    while (true)
    {
        input.Update();

        auto& translation = registry->get<TranslationComponent>(character);

        if (input.IsKeyDown(InputKey::Left))
            translation.Vector.X = -1;

        if (input.IsKeyDown(InputKey::Right))
            translation.Vector.X = 1;

        if (input.IsKeyDown(InputKey::Up))
            translation.Vector.Y = -1;

        if (input.IsKeyDown(InputKey::Down))
            translation.Vector.Y = 1;

        collisionSystem.Update();
        translationSystem.Update();
        renderingSystem.Update();

        const auto& position = registry->get<PositionComponent>(character);

        console.Draw(0, 21, ("                                               "));
        console.Draw(0, 21, ("Position: " + position.Vector.ToString()).c_str());

        console.Draw(0, 22, ("                                               "));
        console.Draw(0, 22, ("Translation: " + translation.Vector.ToString()).c_str());

        console.Draw(0, 23, ("                                               "));

        TileComponent tile;

        if (tilemap->TileAt(position.Vector, tile))
        {
            const char* string = tile.IsWalkable ? "Yes" : "No";
            std::string temp = "Walkable: " + std::string(string);
            console.Draw(0, 23, temp.c_str());
        }
        else
        {
            console.Draw(0, 23, "Walkable: Out of bounds");
        }

        console.Flush();

        input.Clear();
    }
}