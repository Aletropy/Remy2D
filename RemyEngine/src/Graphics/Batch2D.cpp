#include "Batch2D.h"

#include "OpenGL/VertexArray.h"
#include "OpenGL/VertexBuffer.h"
#include "OpenGL/IndexBuffer.h"
#include "OpenGL/Shader.h"

#include "OpenGL/Renderer.h"

#include <glm/gtc/matrix_transform.hpp>
#include <vector>

namespace RY
{
    static const glm::vec4 QuadVertexPositions[] = 
    {
        { -1.0f, -1.0f, 0.0f, 1.0f },
        { -1.0f, 1.0f, 0.0f, 1.0f },
        { 1.0f, 1.0f, 0.0f, 1.0f },
        { 1.0f, -1.0f, 0.0f, 1.0f }
    };

    struct Vertex
    {
        glm::vec4 Position;
        glm::vec4 Color;
    };

    struct BatchData
    {
        static const uint32_t MaxQuads = 1000;
        static const uint32_t MaxQuadVertices = MaxQuads * 4;
        static const uint32_t MaxQuadIndices = MaxQuads * 6;

        Ref<GL::VertexArray> Va;

        Ref<GL::VertexBuffer> Vb;
        Ref<GL::IndexBuffer> Ib;
        Ref<GL::Shader> QuadShader;

        std::vector<Vertex> QuadVertices;

        uint32_t IndicesCount = 0;
        uint32_t VerticesCount = 0;
    };

    static BatchData s_Data{};
    void Batch2D::Initialize()
    {
        s_Data.Va = CreateRef<GL::VertexArray>();

        s_Data.Vb = CreateRef<GL::VertexBuffer>(BatchData::MaxQuads * sizeof(Vertex));

        GL::VertexBufferLayout layout;
        layout.PushFloat(4);
        layout.PushFloat(4);

        uint32_t* indices = new uint32_t[BatchData::MaxQuadIndices];
        uint32_t offset = 0;
        for(uint32_t i = 0; i < BatchData::MaxQuadIndices; i+=6)
        {
            indices[i + 0] = offset + 0;
            indices[i + 1] = offset + 1;
            indices[i + 2] = offset + 2;

            indices[i + 3] = offset + 2;
            indices[i + 4] = offset + 3;
            indices[i + 5] = offset + 0;

            offset += 4;
        }

        s_Data.Ib = CreateRef<GL::IndexBuffer>((void*)indices, BatchData::MaxQuadIndices * sizeof(uint32_t));
        delete[] indices;

        s_Data.Va->SetVertexBuffer(s_Data.Vb, layout);
        s_Data.Va->SetIndexBuffer(s_Data.Ib);

        s_Data.QuadShader = CreateRef<GL::Shader>("assets/shaders/SimpleVertex.glsl", "assets/shaders/SimpleFrag.glsl");

        PrepareNextBatch();
    }

    void Batch2D::Terminate()
    {
        delete &s_Data;
    }

    void Batch2D::PrepareNextBatch()
    {
        s_Data.IndicesCount = 0;
        s_Data.VerticesCount = 0;
        s_Data.QuadVertices.clear();
    }

    void Batch2D::AddQuad(const glm::vec3& pos, const glm::vec3& scale, const glm::vec4& color)
    {
        glm::mat4 transform = glm::translate(glm::mat4(1.0f), pos)
            * glm::scale(glm::mat4(1.0f), scale);

        for(uint32_t i = 0; i < 4; i++)
        {
            s_Data.QuadVertices.push_back({
                transform * QuadVertexPositions[i],
                color
            });

            s_Data.VerticesCount++;
        }

        s_Data.IndicesCount += 6;
    }

    void Batch2D::Flush(const Ref<Camera2D>& camera)
    {
        s_Data.Vb->SubData((void*)s_Data.QuadVertices.data(), s_Data.VerticesCount * sizeof(Vertex));

        s_Data.Va->Bind();
        s_Data.QuadShader->Use();

        if(camera != nullptr)
            s_Data.QuadShader->SetUniformMatrix4("uViewProjMatrix", camera->GetViewProjMatrix());
        else
            s_Data.QuadShader->SetUniformMatrix4("uViewProjMatrix", glm::mat4(1.0f));

        GL::Renderer::DrawVa(s_Data.Va, s_Data.IndicesCount);
        PrepareNextBatch();
    }
}