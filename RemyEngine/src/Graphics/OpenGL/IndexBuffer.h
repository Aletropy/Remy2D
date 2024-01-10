#pragma once

#include <stdint.h>

namespace RY
{
    namespace GL
    {
        class IndexBuffer
        {
        public:
            IndexBuffer(void* data, uint32_t size);
            ~IndexBuffer();

            void Bind();

        private:
            uint32_t m_Id;
        };
    }
}