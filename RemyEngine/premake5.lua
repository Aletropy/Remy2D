project "RemyEngine"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"

    targetdir ("%{wks.location}/bin/" .. outputdir .. "/%{prj.name}/")
    objdir ("%{wks.location}/bin-int/" .. outputdir .. "/%{prj.name}/")

    files
    {
        "src/**.cpp",
        "src/**.h"
    }

    includedirs
    {
        "%{wks.location}/RemyEngine/vendor/glfw/include",
        "%{wks.location}/RemyEngine/vendor/glad/include",
        "%{wks.location}/vendor/glm/include",
        "src/"
    }

    links
    {
        "gdi32",
        "opengl32",
        "glad",
        "glfw"
    }

    filter "configurations:Debug"
        defines { "_DEBUG" }
        runtime "Debug"
        symbols "on"

    filter "configurations:Release"
        defines { "NDEBUG" }
        runtime "Release"
        optimize "on"