#include "RemyEngine.h"

namespace RY
{
    class SandboxApp : public Application
    {
    public:
        SandboxApp()
            : Application(800, 600, "SandboxApp")
        {
            RY_INFO("Application custom log");
        }

        void OnUpdate() override
        {
            GL::Renderer::ClearColor(0.8f, 0.34f, 0.5f);
        }
    };
}

RY::Application* RY::CreateApplication()
{
    return new SandboxApp;
}