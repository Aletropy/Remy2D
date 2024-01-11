#pragma once

#include <glm/glm.hpp>

namespace RY
{
    class Camera2D
    {
    public:
        Camera2D(float width, float height, float zoomSize = 5.0f);

        void SetPosition(const glm::vec3& position);
        void SetZoom(float zoomSize);
        void SetSize(float width, float height);

        glm::mat4 GetViewProjMatrix() { return m_ProjMatrix * m_ViewMatrix; }

    private:
        void RecalculateProjMatrix();

    private:
        float m_AspectRatio = 0.0f;
        float m_ZoomSize = 5.0f;
        glm::mat4 m_ViewMatrix;
        glm::mat4 m_ProjMatrix;
    };
}