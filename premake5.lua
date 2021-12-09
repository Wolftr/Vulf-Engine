workspace "VulfEngine"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist",
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Vulf"
    location "Vulf"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Vulf/src",
        "Vulf/vendor/spdlog/include",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "VULF_PLATFORM_WINDOWS",
            "VULF_BUILD_DLL",
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
        }
    
    filter "configurations:Debug"
        defines "VULF_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "VULF_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "VULF_DIST"
        optimize "On"

project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    files
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Vulf/vendor/spdlog/include",
        "Vulf/src",
    }

    links
    {
        "Vulf",
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines 
        {
            "VULF_PLATFORM_WINDOWS",
        }
    
    filter "configurations:Debug"
        defines "VULF_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "VULF_RELEASE"
        optimize "On"
        
    filter "configurations:Dist"
        defines "VULF_DIST"
        optimize "On"    