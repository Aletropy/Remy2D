#include "MainLayer.h"

#include <GLFW/glfw3.h>

namespace RY
{
    void MainLayer::OnAttach()
    {
        m_Camera = CreateRef<Camera2D>(800.0f, 600.0f);
    }

    void MainLayer::OnUpdate()
    {
        
    }

    void MainLayer::OnRender()
    {
        GL::Renderer::ClearColor(0.8f, 0.34f, 1.0f);

        //                Posição { x, y ,z}     Tamanho { x, y ,z }   Cor { r, g, b, a }
        Batch2D::AddQuad({ -3.0f, 0.0f, 0.0f },  { 1.0f, 1.0f, 1.0f }, { 1.0f, 0.0f, 0.0f, 1.0f });
        Batch2D::AddQuad({  0.0f, 0.0f, 0.0f },  { 1.0f, 1.0f, 1.0f }, { 0.0f, 1.0f, 0.0f, 1.0f });
        Batch2D::AddQuad({  3.0f, 0.0f, 0.0f },  { 1.0f, 1.0f, 1.0f }, { 0.0f, 0.0f, 1.0f, 1.0f });

        Batch2D::Flush(m_Camera); // Desenha os quadrados de acordo com a câmera que você quer
    }
}