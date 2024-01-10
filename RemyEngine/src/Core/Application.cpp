#include "Application.h"

#include "Log.h"

namespace RY
{
    Application::Application(int width, int height, const std::string& name)
        : m_Name(name)
    {
        Log::Initialize(name);
        RY_CORE_INFO("Initializing application: %s(%d, %d)", name.c_str(), width, height);
    }

    void Application::Run()
    {
        while(m_IsRunning)
        {
            OnUpdate();
        }
    }

    void Application::Terminate()
    {
        m_IsRunning = false;
    }
}