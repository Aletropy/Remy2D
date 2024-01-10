#pragma once

#include <string>

namespace RY
{
    class Application
    {
    public:
        Application(int width, int height, const std::string& name);
        
        void Run();

        void Terminate();

        virtual void OnUpdate() = 0;

    private:
        std::string m_Name;
        bool m_IsRunning;
    };
}