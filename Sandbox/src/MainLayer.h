#pragma once

#include "RemyEngine.h"

namespace RY
{
    class MainLayer : public Layer
    {
    public:
        MainLayer()
            : Layer("MainLayer") { }

        void OnAttach() override;
        void OnUpdate() override;
        void OnRender() override;

    private:
        Ref<Camera2D> m_Camera;
    };
}