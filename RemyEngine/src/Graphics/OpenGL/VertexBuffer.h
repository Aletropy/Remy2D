#pragma once

#include <stdint.h>
#include <vector>

namespace RY
{
    namespace GL
    {
        class VertexBuffer
        {
        public:
            VertexBuffer(void* data, uint32_t size);
            VertexBuffer(uint32_t size);
            ~VertexBuffer();

            void Bind();
            void SubData(void* data, uint32_t size);

        private:
            uint32_t m_Id;
        };

        class VertexBufferLayout
        {
        public:
            struct Element
            {
                uint32_t Count;
                uint32_t Type;
                bool Normalized;
                uint32_t Offset;
            };

            void PushFloat(uint32_t count)
            {
                static const uint32_t GlFloat = 0x1406;

                m_Elements.push_back({ count, GlFloat, false, m_Stride });

                m_Stride += count * sizeof(float);
            }

            const std::vector<Element>& GetElements() const { return m_Elements; }
            uint32_t GetStride() const { return m_Stride; }

        private:
            uint32_t m_Stride = 0;
            std::vector<Element> m_Elements;
        };
    }
}