#pragma once

#include "Core/Base.h"
#include "VertexArray.h"

namespace RY
{
    namespace GL
    {
        class Renderer
        {
        public:
            Renderer() = delete;
            Renderer(const Renderer&&) = delete;

            static void Initialize();
            static void Terminate();

            static void Viewport(int width, int height);
            static void DrawVa(const Ref<VertexArray>& va, uint32_t count);

            static void ClearColor(float r, float g, float b, float a = 1.0f);
            static void Clear();
        };
    }
}