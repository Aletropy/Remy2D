#pragma once

#include "Application.h"

namespace RY
{
    extern Application* CreateApplication();
}

int main()
{
    auto app = RY::CreateApplication();
    app->Run();
    delete app;
}