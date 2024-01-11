#pragma once

#include <string>
#include <iostream>
#include <format>

namespace RY
{
    class Log
    {
    public:
        static Log* Instance;
    public:
        Log(const std::string& applicationName)
            : m_ApplicationName(applicationName)
        {
        }

        static void Initialize(const std::string& name)
        {
            Instance = new Log(name);
        }

        template<typename ... Args>
        void EngineInfo(const std::string_view& format, Args&&... args)
        {
            constexpr size_t bufferSize = 2056;  // Escolha um tamanho apropriado
            char buffer[bufferSize];
            std::snprintf(buffer, bufferSize, format.data(), std::forward<Args>(args)...);

            std::cout << "[Remy - Info]: " << buffer << std::endl;
        }

        template<typename ... Args>
        void EngineWarn(const std::string_view& format, Args&&... args)
        {
            constexpr size_t bufferSize = 2056;  // Escolha um tamanho apropriado
            char buffer[bufferSize];
            std::snprintf(buffer, bufferSize, format.data(), std::forward<Args>(args)...);

            std::cout << "[Remy - Warn]: " << buffer << std::endl;
        }

        template<typename ... Args>
        void EngineError(const std::string_view& format, Args&&... args)
        {
            constexpr size_t bufferSize = 2056;  // Escolha um tamanho apropriado
            char buffer[bufferSize];
            std::snprintf(buffer, bufferSize, format.data(), std::forward<Args>(args)...);

            std::cout << "[Remy - Error]: " << buffer << std::endl;
        }

        template<typename ... Args>
        void ApplicationInfo(const std::string_view& format, Args&&... args)
        {
            constexpr size_t bufferSize = 2056;  // Escolha um tamanho apropriado
            char buffer[bufferSize];
            std::snprintf(buffer, bufferSize, format.data(), std::forward<Args>(args)...);

            std::cout << "[" << m_ApplicationName << " - Info]: " << buffer << std::endl;
        }

        template<typename ... Args>
        void ApplicationWarn(const std::string_view& format, Args&&... args)
        {
            constexpr size_t bufferSize = 2056;  // Escolha um tamanho apropriado
            char buffer[bufferSize];
            std::snprintf(buffer, bufferSize, format.data(), std::forward<Args>(args)...);

            std::cout << "[" << m_ApplicationName << " - Warn]: " << buffer << std::endl;
        }

        template<typename ... Args>
        void ApplicationError(const std::string_view& format, Args&&... args)
        {
            constexpr size_t bufferSize = 2056;  // Escolha um tamanho apropriado
            char buffer[bufferSize];
            std::snprintf(buffer, bufferSize, format.data(), std::forward<Args>(args)...);

            std::cout << "[" << m_ApplicationName << " - Error]: " << buffer << std::endl;
        }

        void SetApplicationName(const std::string& name)
        {
            m_ApplicationName = name;
        }

    private:
        std::string m_ApplicationName;
    };
}

#ifdef _DEBUG

#define RY_CORE_INFO(...) RY::Log::Instance->EngineInfo(__VA_ARGS__)
#define RY_CORE_WARN(...) RY::Log::Instance->EngineWarn(__VA_ARGS__)
#define RY_CORE_ERROR(...) RY::Log::Instance->EngineError(__VA_ARGS__)
#define RY_CORE_TRACE(a, ...) if(!a) RY::Log::Instance->EngineError(__VA_ARGS__)

#define RY_INFO(...) RY::Log::Instance->ApplicationInfo(__VA_ARGS__)
#define RY_WARN(...) RY::Log::Instance->ApplicationWarn(__VA_ARGS__)
#define RY_ERROR(...) RY::Log::Instance->ApplicationError(__VA_ARGS__)
#define RY_TRACE(a, ...) if(!a) RY::Log::Instance->ApplicationError(__VA_ARGS__)

#elif

#define RY_CORE_INFO(...)
#define RY_CORE_WARN(...)
#define RY_CORE_ERROR(...)

#define RY_INFO(...)
#define RY_WARN(...)
#define RY_ERROR(...)

#endif