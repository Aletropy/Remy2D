#include "Shader.h"
#include "Core/Log.h"

#include <fstream>
#include <sstream>
#include <glad/glad.h>

#include <glm/gtc/type_ptr.hpp>

namespace RY
{
    namespace GL
    {
        Shader::Shader(const std::string& vertexPath, const std::string& fragmentPath)
        {
            uint32_t vs = CompileShader(GL_VERTEX_SHADER, ReadFile(vertexPath));
            uint32_t fs = CompileShader(GL_FRAGMENT_SHADER, ReadFile(fragmentPath));

            m_Id = glCreateProgram();

            glAttachShader(m_Id, vs);
            glAttachShader(m_Id, fs);

            glLinkProgram(m_Id);

            int success;
            glGetProgramiv(m_Id, GL_LINK_STATUS, &success);
            if(!success)
            {
                char* msg = new char[256];
                glGetProgramInfoLog(m_Id, 256, nullptr, msg);
                RY_CORE_ERROR("Cannot link program: %s", msg);
            }

            glDeleteShader(vs);
            glDeleteShader(fs);
        }

        Shader::~Shader()
        {
            glDeleteProgram(m_Id);
        }

        void Shader::Use()
        {
            glUseProgram(m_Id);
        }

        void Shader::SetUniformMatrix4(const std::string &name, const glm::mat4 &matrix)
        {
            int location = glGetUniformLocation(m_Id, name.c_str());
            glUniformMatrix4fv(location, 1, GL_FALSE, glm::value_ptr(matrix));
        }

        std::string Shader::ReadFile(const std::string& filepath)
        {
            std::ifstream file(filepath);

            if(!file.is_open())
            {
                RY_CORE_ERROR("Cannot open file: %s", filepath.c_str());
                return std::string();
            }

            std::stringstream ss;
            std::string line;

            while(getline(file, line))
            {
                ss << line << "\n";
            }

            return ss.str();
        }

        uint32_t Shader::CompileShader(uint32_t type, const std::string& sourceCode)
        {
            uint32_t id = glCreateShader(type);
            const char* src = sourceCode.c_str();

            glShaderSource(id, 1, &src, nullptr);

            glCompileShader(id);

            int success;
            glGetShaderiv(id, GL_COMPILE_STATUS, &success);
            if(!success)
            {
                char* msg = new char[256];
                glGetShaderInfoLog(id, 256, nullptr, msg);
                RY_CORE_INFO("Cannot compile shader: %s", msg);
            }

            return id;
        }
    }
}