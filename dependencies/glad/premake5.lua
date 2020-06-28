project "glad"
    kind "StaticLib"
    language "C"
    cdialect "C11"

    targetdir (binaries)
    objdir (intermediate)

    files {
        "include/**.h",
        "src/**.c"
    }

    includedirs {
        "%{IncludeDir.glad}"
    }

    filter "system:windows"
        toolset "msc-ClangCL"
        systemversion "latest"
        staticruntime "Off"

    filter "system:linux"
        toolset "clang"
        staticruntime "Off"

    filter "configurations:Debug"
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        optimize "Full"
        runtime "Release"
        symbols "Off"

    filter {}