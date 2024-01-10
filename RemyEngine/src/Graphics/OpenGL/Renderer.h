#pragma once

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

            static void ClearColor(float r, float g, float b, float a = 1.0f);
            static void Clear();
        };
    }
}