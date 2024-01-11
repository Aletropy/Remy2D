#pragma once

#include <utility>

namespace RY
{
    class Input
    {
    public:
        Input() = delete;
        Input(const Input&&) = delete;

        static bool GetKey(int key);
        static float GetScroll();
        static std::pair<float, float> GetMousePosition();
    };
}