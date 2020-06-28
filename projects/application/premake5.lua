project "application"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++17"

    targetdir (binaries)
    objdir (intermediate)
    debugdir("%{sln.location}")

    dependson {
        "core",
        "glad",
        "glfw"
    }

    links {
        "glfw",
        "glad",
        "core",
    }

    files {
        "include/**.h",
        "src/**.cpp"
    }

    includedirs {
        "%{IncludeDir.application}",
        "%{IncludeDir.core}",
        "%{IncludeDir.json}",
        "%{IncludeDir.glad}",
        "%{IncludeDir.stb}",
        "%{IncludeDir.spdlog}",
        "%{IncludeDir.SML}"
    }

    libdirs {
    }

    bindirs {
    }

    defines {
    	"GLFW_INCLUDE_NONE"
    }
    
    filter "system:windows"
        toolset "msc-ClangCL"
        systemversion "latest"
        staticruntime "Off"

        ignoredefaultlibraries {
            "LIBCMT",
            "LIBCMTD"
        }

        buildoptions {
            "-Wno-missing-braces",
        }

        defines {
            "APOLLO_PLATFORM_WINDOWS",
            "PLATFORM_WIN32"
        }

    filter "system:linux"
        toolset "clang"

        defines {
            "APOLLO_PLATFORM_LINUX"
        }

        linkoptions {
            "-ldl",
            "-lX11",
            "-pthread"
        }

        links {
            "glad",
            "glfw",
        }

    filter "configurations:Debug"
        defines { 
            "APOLLO_DEBUG",
            "APOLLO_ENABLE_ASSERTS"
        }

        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { 
            "APOLLO_RELEASE",
            "NDEBUG"
        }

        optimize "Full"
        runtime "Release"
        symbols "Off"