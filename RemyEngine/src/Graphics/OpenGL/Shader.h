#pragma once

#include <string>
#include <stdint.h>

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

        private:
            static std::string ReadFile(const std::string& filepath);
            static uint32_t CompileShader(uint32_t type, const std::string& sourceCode);

        private:
            uint32_t m_Id;
        };
    }
}