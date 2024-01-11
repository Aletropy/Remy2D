#pragma once

#include <string>
#include <stdint.h>

#include <glm/glm.hpp>

namespace RY
{
    namespace GL
    {
        class Shader
        {
        public:
            Shader(const std::string& vertexPath, const std::string& fragmentPath);
            ~Shader();

            void Use();
            void SetUniformMatrix4(const std::string& name, const glm::mat4& matrix);

        private:
            static std::string ReadFile(const std::string& filepath);
            static uint32_t CompileShader(uint32_t type, const std::string& sourceCode);

        private:
            uint32_t m_Id;
        };
    }
}