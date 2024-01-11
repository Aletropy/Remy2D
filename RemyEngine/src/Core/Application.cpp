#include "Application.h"

#include "Log.h"
#include "Graphics/OpenGL/Renderer.h"

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
            for(auto layer : m_Layers)
                layer->OnUpdate();

            GL::Renderer::Clear();

            for(auto layer : m_Layers)
                layer->OnRender();

            m_Window.UpdateWindow();
        }
    }

    void Application::Terminate()
    {
        m_IsRunning = false;

        for(auto layer : m_Layers)
        {
            delete layer;
        }

        m_Layers.clear();
    }

    void Application::PushLayer(Layer *layer)
    {
        m_Layers.push_back(layer);
        layer->OnAttach();
    }

    void Application::PopLayer(Layer *layer)
    {
        for(int i = 0; i < m_Layers.size(); i++)
        {
            auto l = m_Layers[i];
            if(l == layer)
            {
                layer->OnDetach();
                delete m_Layers[i];
                m_Layers.erase(std::next(m_Layers.begin(), i));
            }
        }
    }
}