#include "Window.h"
#include "Core/Log.h"

#include "Core/Application.h"
#include "OpenGL/Renderer.h"

#include <GLFW/glfw3.h>


namespace RY
{
    static bool glfwInitialized = false;

    Window::Window(int width, int height, const char* title)
    {
        if(!glfwInitialized)
        {
            RY_CORE_TRACE(glfwInit(), "GLFW could not be initialized.");
        }

        glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
        glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);

        m_Handle = glfwCreateWindow(width, height, title, nullptr, nullptr);

        glfwMakeContextCurrent(m_Handle);

        GL::Renderer::Initialize();

        glfwSetWindowCloseCallback(m_Handle, [](GLFWwindow* w)
        {
            Application::Instance->Terminate();
        });

        glfwSetWindowSizeCallback(m_Handle, [](GLFWwindow* w, int width, int height)
        {
            GL::Renderer::Viewport(width, height);
        });
    }

    void Window::UpdateWindow()
    {        
        glfwPollEvents();
        glfwSwapBuffers(m_Handle);
    }
}