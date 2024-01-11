#pragma once

#include <string>

namespace RY
{
    class Layer
    {
    public:
        Layer(const std::string& name);

        virtual void OnAttach() { }
        virtual void OnUpdate() { }
        virtual void OnRender() { }
        virtual void OnDetach() { }

    protected:
        std::string m_DebugName;
    };
}