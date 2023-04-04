project "Ambr-Sandbox"
	kind "ConsoleApp"
	language "C++"
	cppdialect "C++20"
	staticruntime "on"

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

		defines { "GLCORE_PLATFORM_WINDOWS" }

	filter "configurations:Debug"
		defines "GLCORE_DEBUG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "GLCORE_RELEASE"
		runtime "Release"
		optimize "on"