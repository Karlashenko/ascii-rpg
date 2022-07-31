cmake_minimum_required(VERSION 3.22)
project(Roguelike)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(
        Roguelike
        src/Core/Core.pch
        src/main.cpp
        src/Gameplay/Tilemap.hpp
        src/Gameplay/Tilemap.cpp
        src/Gameplay/Scene.hpp
        src/Gameplay/Scene.cpp
        src/Core/Collections/List.hpp
        src/Core/Numerics/Vector2f.hpp
        src/Core/Numerics/Vector2i.hpp
        src/Views/IView.hpp src/Graphics/Console.cpp
        src/Graphics/Console.hpp src/Input/IInput.hpp
        src/Input/ConsoleInput.cpp src/Input/ConsoleInput.hpp
        src/Events/Event.hpp src/Events/InputEvent.hpp
        src/Input/InputKey.hpp
        src/Core/Math.hpp
        src/Graphics/Color.hpp
        src/Gameplay/Game.cpp
        src/Gameplay/Game.hpp
        src/Gameplay/States/IGameState.hpp
        src/Gameplay/States/MainMenuGameState.cpp
        src/Gameplay/States/MainMenuGameState.hpp
        src/Gameplay/Systems/IGameSystem.hpp
        src/Gameplay/Systems/ConsoleRenderingSystem.cpp
        src/Gameplay/Systems/ConsoleRenderingSystem.hpp
        src/Gameplay/Components/ColoredTextComponent.hpp
        src/Gameplay/Components/PositionComponent.hpp
        src/Gameplay/Components/TileComponent.hpp
        src/Gameplay/Components/TranslationComponent.hpp
        src/Core/Entities.hpp
        src/Gameplay/Systems/CollisionSystem.cpp
        src/Gameplay/Systems/CollisionSystem.hpp
        src/Core/Random.hpp
        src/Gameplay/Systems/TranslationSystem.cpp
        src/Gameplay/Systems/TranslationSystem.hpp)

target_precompile_headers(${PROJECT_NAME} PUBLIC src/Core/Core.pch)

target_link_libraries(Roguelike ${CURSES_LIBRARIES})