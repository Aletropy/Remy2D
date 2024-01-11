#pragma once
#include "Core/Base.h"

#include "Camera2D.h"

#include <glm/glm.hpp>

namespace RY
{
    
    class Batch2D
    {
    public:
        Batch2D() = delete;
        Batch2D(const Batch2D&&) = delete;

        static void Initialize();
        static void Terminate();

        static void AddQuad(const glm::vec3& pos, const glm::vec3& scale, const glm::vec4& color = glm::vec4(1.0f));

        static void Flush(const Ref<Camera2D>& camera = nullptr);
    private:
        static void PrepareNextBatch();
    };

} // namespace RY
