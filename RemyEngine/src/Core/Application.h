#pragma once
#include <string>

#include "Graphics/Window.h"

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

        virtual void OnUpdate() = 0;

        Window& GetWindow() { return m_Window; }

    private:
        std::string m_Name;
        Window m_Window;
        bool m_IsRunning;
    };
}