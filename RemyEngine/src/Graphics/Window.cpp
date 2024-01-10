#include "Window.h"
#include "Core/Log.h"

#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace RY
{
    static bool glfwInitialized = false;

    Window::Window(int width, int height, const char* title)
    {
        if(!glfwInitialized)
        {
            if(glfwInit())
                RY_CORE_INFO("Initialized GLFW.");
        }

        glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

        m_Handle = glfwCreateWindow(width, height, title, nullptr, nullptr);

        glfwSetWindowCloseCallback(m_Handle, [](GLFWwindow* w)
        {
            Application::Instance->Terminate();
        });
    }

    void Window::UpdateWindow()
    {
        glfwPollEvents();
        glfwSwapBuffers(m_Handle);
    }
}