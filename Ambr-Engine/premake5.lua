project "Ambr-Engine"
	kind "SharedLib"
	language "C++"
	cppdialect "C++20"
	staticruntime "off"

	targetdir ("../bin/" .. outputdir .. "/%{prj.name}")
	objdir ("../bin-int/" .. outputdir .. "/%{prj.name}")

	files { "src/**.h", "src/**.cpp" }
	includedirs { "src" }

	links { "opengl32.lib", "user32", "gdi32" }

	filter "system:windows"
		systemversion "latest"
		defines { "GLCORE_PLATFORM_WINDOWS", "AMBR_ENGINE_EXPORT", "AMBR_WINDOW_WIN32" }

	filter "configurations:Debug"
		defines "GLCORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLCORE_RELEASE"
		runtime "Release"
		optimize "on"