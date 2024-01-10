#pragma once

struct GLFWwindow;

namespace RY
{
    class Window
    {
    public:
        Window(int width, int height, const char* title);

        void UpdateWindow();

    private:
        int m_Width = 0, m_Height = 0;
        GLFWwindow* m_Handle;
    };
}