#include "RemyEngine.h"
#include "Core/EntryPoint.h"

#include "MainLayer.h"

namespace RY
{
    class SandboxApp : public Application
    {
    public:
        SandboxApp()
            : Application(800, 600, "SandboxApp")
        {
            PushLayer(new MainLayer);
        }
    };
}

RY::Application* RY::CreateApplication()
{
    return new SandboxApp;
}