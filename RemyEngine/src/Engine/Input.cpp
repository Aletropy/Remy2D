#include "Input.h"

#include "Core/Application.h"

#include <GLFW/glfw3.h>

namespace RY
{
    bool Input::GetKey(int key)
    {
        GLFWwindow* window = Application::Instance->GetWindow().GetWindowPtr();
        return glfwGetKey(window, key) == GLFW_PRESS;
    }

    std::pair<float, float> Input::GetMousePosition()
    {
        GLFWwindow* window = Application::Instance->GetWindow().GetWindowPtr();
        double x, y;
        
        glfwGetCursorPos(window, &x, &y);

        return std::make_pair((float)x, (float)y);
    }
}