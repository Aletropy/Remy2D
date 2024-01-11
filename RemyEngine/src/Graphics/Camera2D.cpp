#include "Camera2D.h"

#include <glm/gtc/matrix_transform.hpp>

namespace RY
{
    Camera2D::Camera2D(float width, float height, float zoomSize)
        : m_AspectRatio(width / height), m_ZoomSize(zoomSize)
    {
        float aspectRatio = width / height;
        m_ViewMatrix = glm::mat4(1.0f);
        m_ProjMatrix = glm::ortho(-aspectRatio * zoomSize, aspectRatio * zoomSize, -zoomSize, zoomSize);
    }

    void Camera2D::SetPosition(const glm::vec3& position)
    {
        m_ViewMatrix = glm::translate(glm::mat4(1.0f), position);
    }

    void Camera2D::SetZoom(float zoomSize)
    {
        m_ZoomSize = zoomSize;
        RecalculateProjMatrix();
    }

    void Camera2D::SetSize(float width, float height)
    {
        m_AspectRatio = width / height;
        RecalculateProjMatrix();
    }

    void Camera2D::RecalculateProjMatrix()
    {
        m_ProjMatrix = glm::ortho(-m_AspectRatio * m_ZoomSize, m_AspectRatio * m_ZoomSize, -m_ZoomSize, m_ZoomSize);
    }
}