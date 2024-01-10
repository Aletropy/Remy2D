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
            Terminate();
        }
    };
}

RY::Application* RY::CreateApplication()
{
    return new SandboxApp;
}