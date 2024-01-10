#include "Application.h"

#include "Log.h"

namespace RY
{
    Application* Application::Instance = nullptr;

    Application::Application(int width, int height, const std::string& name)
        : m_Name(name), m_Window(width, height, name.c_str())
    {
        Log::Initialize(name);
        RY_CORE_INFO("Initializing application: %s(%d, %d)", name.c_str(), width, height);

        if(Instance == nullptr)
            Instance = this;
    }

    void Application::Run()
    {
        m_IsRunning = true;

        while(m_IsRunning)
        {
            OnUpdate();
            m_Window.UpdateWindow();
        }
    }

    void Application::Terminate()
    {
        m_IsRunning = false;
    }
}