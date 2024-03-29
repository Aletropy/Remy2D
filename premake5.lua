workspace "Remy"
    architecture "x64"
    configurations
    {
        "Debug",
        "Release"
    }

outputdir = "%{cfg.buildcfg}/%{cfg.system}-%{cfg.architecture}"

include "RemyEngine/vendor/glfw"
include "RemyEngine/vendor/glad"

include "RemyEngine"
include "Sandbox"