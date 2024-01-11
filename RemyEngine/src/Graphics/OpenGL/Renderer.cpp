#include "Renderer.h"
#include "Core/Log.h"

#include "Graphics/Batch2D.h"
#include <glad/glad.h>


namespace RY
{
    namespace GL
    {
        void Renderer::Initialize()
        {
            RY_CORE_TRACE(gladLoadGL(), "Glad could not be initialized.");

            glEnable(GL_DEPTH_TEST);

            Batch2D::Initialize();
        }

        void Renderer::Terminate()
        {
            Batch2D::Terminate();
        }

        void Renderer::DrawVa(const Ref<VertexArray> &va, uint32_t count)
        {
            va->Bind();
            glDrawElements(GL_TRIANGLES, count, GL_UNSIGNED_INT, nullptr);
        }

        void Renderer::Viewport(int width, int height)
        {
            glViewport(0, 0, width, height);
        }

        void Renderer::ClearColor(float r, float g, float b, float a)
        {
            glClearColor(r,g,b,a);
        }

        void Renderer::Clear()
        {
            glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
        }

    }
}