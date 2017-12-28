#!lua

-- solution_builder.lua

SolutionBuilder = {}

function SolutionBuilder:build()
    workspace "EdenCraft"
        language "C++"
        location ""
        includedirs { "../extlibs/include", "../include" }
        configurations {"Debug", "Release"}
        platforms {"Win32", "Win64", "Unix32", "Unix64", "OSX"}

        filter {"platforms:Win32"}
            architecture "x86"
            system "windows"
            libdirs {"../extlibs/lib/msvc/x86"}
			buildoptions {"/W4", "/std:c++17"}

        filter {"platforms:Win64"}
            architecture "x86_64"
            system "windows"
            libdirs {"../extlibs/lib/msvc/x64"}
			buildoptions {"/W4", "/std:c++17"}

        filter {"platforms:Unix32"}
            architecture "x86"
            system "linux"
            libdirs {"../extlibs/lib/gmake/x32"}
			buildoptions {"-W4", "-std=c++17", "-ansi", "-pedantic"}

        filter {"platforms:Unix64"}
            architecture "x86_64"
            system "linux"
            libdirs {"../extlibs/lib/gmake/x64"}
			buildoptions {"-W4", "-std=c++17", "-ansi", "-pedantic"}

        filter {"platforms:OSX"}
            architecture "x86_64"
            system "macosx"
            libdirs {"../extlibs/lib/gmake/x64"}
			buildoptions {"-W4", "-std=c++17", "-ansi", "-pedantic"}

        filter {"configurations:Debug"}
            symbols "Default"

        filter {"configurations:Release"}
    		optimize "On"
    		symbols "Off"

        filter {}
end

return SolutionBuilder
