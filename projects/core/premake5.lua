project "core"
    kind "StaticLib"
    language "C++"
    cppdialect "C++17"

    targetdir (binaries)
    objdir (intermediate)

    dependson {
        "glfw",
        "glad"
    }

    links {
        "glfw",
        "glad"
    }
    
    defines {
        "GLFW_INCLUDE_NONE"
    }

    files {
        "include/**.h",
        "src/**.cpp"
    }
    
    includedirs {
        "%{IncludeDir.core}",
        "%{IncludeDir.glfw}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.json}",
        "%{IncludeDir.SML}",
        "%{IncludeDir.stb}",
        "%{IncludeDir.spdlog}"
    }

    libdirs {
    }

    bindirs {
    }

    flags {
        "MultiProcessorCompile"
    }

    filter "system:windows"
        toolset "msc-ClangCL"
        systemversion "latest"
        staticruntime "Off"

        ignoredefaultlibraries {
            "LIBCMT",
            "LIBCMTD"
        }

        defines {
            "APOLLO_PLATFORM_WINDOWS",
            "_CRT_SECURE_NO_WARNINGS",
            "PLATFORM_WIN32"
        }
    
    filter "system:linux"
        toolset "clang"

        staticruntime "Off"

        defines {
            "APOLLO_PLATFORM_LINUX"
        }

        buildoptions {
            "-Wall",
            "-Wextra",
            "-Werror"
        }

        linkoptions {
            "-ldl"
        }

    filter "configurations:Debug"
        defines { 
            "APOLLO_DEBUG",
            "APOLLO_ENABLE_ASSERTS"
        }

        staticruntime "Off"
        runtime "Debug"

        symbols "On"

    filter "configurations:Release"
        defines { 
            "APOLLO_RELEASE",
            "NDEBUG"
        }

        optimize "Full"
        runtime "Release"
        staticruntime "Off"
        symbols "Off"
