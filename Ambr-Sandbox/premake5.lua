project "Ambr-Sandbox"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files { "src/**.h", "src/**.cpp" }
	includedirs { "src", "../Ambr-Engine/src" }

	links { "Ambr-Engine" }

	postbuildcommands {
    "{COPY} %{cfg.targetdir}/../Ambr-Engine/Ambr-Engine.dll %{cfg.targetdir}"
	}

	filter "system:windows"
		systemversion "latest"
		defines { "GLCORE_PLATFORM_WINDOWS", "AMBR_SYSTEM_WINDOWS" }
    links { "user32", "gdi32" }

	filter "configurations:Debug"
		defines "GLCORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLCORE_RELEASE"
		runtime "Release"
		optimize "on"

  filter "platforms:Win32"
	  kind "WindowedApp"
    defines { "AMBR_WINDOW_WIN32" }

  filter "platforms:GLFW"
    kind "ConsoleApp"
    defines { "AMBR_WINDOW_GLFW" }
