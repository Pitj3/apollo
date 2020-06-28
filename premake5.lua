-- Main Premake
workspace "apollo"
    configurations {
        "Debug",
        "Release",
    }

    filter "configurations:Debug"
        runtime "Debug"

    filter "configurations:Release"
        runtime "Release"

    filter{}

    architecture "x64"

    sln = solution()
    binaries = "%{sln.location}/bin/%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}"
    intermediate = "%{sln.location}/bin-int/%{cfg.buildcfg}/%{cfg.system}/%{cfg.architecture}"

    -- Dependencies
    include "dependencies/glad"
    include "dependencies/glfw"
    include "dependencies/googletest"
    
    -- Projects
    include "projects/core"
    include "projects/tests"
    include "projects/application"

    -- Include Directories
    IncludeDir = {}
    IncludeDir["core"] = "%{sln.location}/projects/core/include"
    IncludeDir["glad"] = "%{sln.location}/dependencies/glad/include"
    IncludeDir["glfw"] = "%{sln.location}/dependencies/glfw/include"
    IncludeDir["gtest"] = "%{sln.location}/dependencies/googletest/include"
    IncludeDir["json"] = "%{sln.location}/dependencies/json/include"
    IncludeDir["SML"] = "%{sln.location}/dependencies/SML/include"
    IncludeDir["stb"] = "%{sln.location}/dependencies/stb/include"
    IncludeDir["spdlog"] = "%{sln.location}/dependencies/spdlog/include"
