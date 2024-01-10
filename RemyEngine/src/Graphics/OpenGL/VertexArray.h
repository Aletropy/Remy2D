#pragma once

#include <stdint.h>

#include "VertexBuffer.h"
#include "IndexBuffer.h"

#include "Core/Base.h"

namespace RY
{
    namespace GL
    {
        class VertexArray
        {
        public:
            VertexArray();
            ~VertexArray();

            void Bind();

            void SetVertexBuffer(const Ref<VertexBuffer>& vb, const VertexBufferLayout& layout);
            void SetIndexBuffer(const Ref<IndexBuffer>& ib);

        private:
            uint32_t m_Id;
        };
    }
}