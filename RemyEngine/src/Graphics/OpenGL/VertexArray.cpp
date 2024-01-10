#include "VertexArray.h"

#include <glad/glad.h>

namespace RY
{
    namespace GL
    {
        VertexArray::VertexArray()
        {
            glCreateVertexArrays(1, &m_Id);
        }

        VertexArray::~VertexArray()
        {
            glDeleteVertexArrays(1, &m_Id);
        }

        void VertexArray::Bind()
        {
            glBindVertexArray(m_Id);
        }

        void VertexArray::SetVertexBuffer(const Ref<VertexBuffer> &vb, const VertexBufferLayout& layout)
        {
            glBindVertexArray(m_Id);
            vb->Bind();

            auto& elements = layout.GetElements();
            for(uint32_t i = 0; i < elements.size(); i++)
            {
                auto& element = elements[i];
                glEnableVertexAttribArray(i);
                glVertexAttribPointer(i,
                    element.Count,
                    element.Type,
                    element.Normalized,
                    layout.GetStride(),
                    (void*)element.Offset
                );
            }
        }

        void VertexArray::SetIndexBuffer(const Ref<IndexBuffer> &ib)
        {
            glBindVertexArray(m_Id);
            ib->Bind();
        }
    }
}