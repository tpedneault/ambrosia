workspace "Ambr-Sandbox"
	architecture "x64"
	startproject "Ambr-Sandbox"

	configurations { "Debug", "Release" }
  platforms { "Win32", "GLFW" }
		
	flags { "MultiProcessorCompile" }

	outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
group ""
	include "Ambr-Engine"
	include "Ambr-Sandbox"