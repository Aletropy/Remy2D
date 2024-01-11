#pragma once
#include <string>

#include "Graphics/Window.h"
#include "Layer/Layer.h"

#include <vector>

namespace RY
{
    class Application
    {
    public:
        static Application* Instance;
    public:
        Application(int width, int height, const std::string& name);
        
        void Run();
        void Terminate();

        void PushLayer(Layer* layer);
        void PopLayer(Layer* layer);

        Window& GetWindow() { return m_Window; }

    private:
        std::string m_Name;
        Window m_Window;
        bool m_IsRunning;
        std::vector<Layer*> m_Layers;
    };
}