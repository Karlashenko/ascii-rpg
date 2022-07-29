cmake_minimum_required(VERSION 3.22)
project(Roguelike)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

add_executable(
        Roguelike
        src/main.cpp
        src/Gameplay/Cell.hpp
        src/Gameplay/Board.hpp
        src/Gameplay/Board.cpp
        src/Gameplay/Scene.hpp
        src/Gameplay/Scene.cpp
        src/Core/Collections/List.hpp
        src/Core/Numerics/Vector2f.hpp
        src/Core/Numerics/Vector2i.hpp
        src/Views/Console/BoardConsoleView.cpp
        src/Views/Console/BoardConsoleView.hpp
        src/Views/IView.hpp src/Graphics/Console.cpp
        src/Graphics/Console.hpp src/Input/IInput.hpp
        src/Input/ConsoleInput.cpp src/Input/ConsoleInput.hpp
        src/Events/Event.hpp src/Events/InputEvent.hpp
        src/Input/InputKey.hpp
        src/Views/Console/CharacterConsoleView.hpp
        src/Views/Console/CharacterConsoleView.cpp
        src/Gameplay/Character.cpp
        src/Gameplay/Character.hpp
        src/Core/Math.hpp
        src/Graphics/Color.hpp)

target_link_libraries(Roguelike ${CURSES_LIBRARIES})