#pragma once

#include "IGameSystem.hpp"

class TranslationSystem final : public IGameSystem
{
public:
    explicit TranslationSystem(EntityRegistry* registry);

    void Update() override;

private:
    EntityRegistry* m_Registry;
};
