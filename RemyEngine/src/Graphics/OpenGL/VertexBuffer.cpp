#include "VertexBuffer.h"

#include <glad/glad.h>

namespace RY
{
    namespace GL
    {
        VertexBuffer::VertexBuffer(void* data, uint32_t size)
        {
            glCreateBuffers(1, &m_Id);
            glBindBuffer(GL_ARRAY_BUFFER, m_Id);
            glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
        }

        VertexBuffer::VertexBuffer(uint32_t size)
        {
            glCreateBuffers(1, &m_Id);
            glBindBuffer(GL_ARRAY_BUFFER, m_Id);
            glBufferData(GL_ARRAY_BUFFER, size, nullptr, GL_DYNAMIC_DRAW);
        }

        VertexBuffer::~VertexBuffer()
        {
            glDeleteBuffers(1, &m_Id);
        }

        void VertexBuffer::Bind()
        {
            glBindBuffer(GL_ARRAY_BUFFER, m_Id);
        }

        void VertexBuffer::SubData(void* data, uint32_t size)
        {
            glBindBuffer(GL_ARRAY_BUFFER, m_Id);
            glBufferSubData(GL_ARRAY_BUFFER, 0, size, data);
        }
    }
}