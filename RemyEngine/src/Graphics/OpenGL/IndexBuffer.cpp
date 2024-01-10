#include "IndexBuffer.h"

#include <glad/glad.h>

namespace RY
{
    namespace GL
    {
        IndexBuffer::IndexBuffer(void* data, uint32_t size)
        {
            glCreateBuffers(1, &m_Id);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
        }

        IndexBuffer::~IndexBuffer()
        {
            glDeleteBuffers(1, &m_Id);
        }

        void IndexBuffer::Bind()
        {
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_Id);
        }
    }
}