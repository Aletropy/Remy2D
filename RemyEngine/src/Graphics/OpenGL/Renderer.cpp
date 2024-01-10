#include "Renderer.h"
#include "Core/Log.h"

#include <glad/glad.h>


namespace RY
{
    namespace GL
    {
        void Renderer::Initialize()
        {
            if(gladLoadGL())
            {
                RY_CORE_INFO("OpenGL Initialized");
            }
        }

        void Renderer::Terminate()
        {

        }

        void Renderer::ClearColor(float r, float g, float b, float a)
        {
            glClearColor(r,g,b,a);
        }

        void Renderer::Clear()
        {
            glClear(GL_COLOR_BUFFER_BIT);
        }

    }
}