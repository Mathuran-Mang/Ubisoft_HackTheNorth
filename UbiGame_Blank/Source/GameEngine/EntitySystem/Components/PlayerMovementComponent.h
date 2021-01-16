#pragma once

#include "GameEngine/EntitySystem/Component.h"

namespace GameEngine
{
    class PlayerMovementComponent : public GameEngine::Component
    {
    public:
        virtual void Update() override;
        virtual void OnAddToWorld() override;
    };
}