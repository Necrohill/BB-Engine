workspace "BBEngine"
	architecture "x64"
	
	
	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}
	
outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
	
project "BBEngine"
	location "BBEngine"
	kind "SharedLib"
	language "C++"
	
	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")
	
	pchheader "BBPCH.h"
	pchsource "BBEngine/src/BBPCH.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"%{prj.name}/Vendor/SPDLOG/include",
		"%{prj.name}/src"
	}
	
	filter "system:windows"
		cppdialect "C++latest"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"BB_PLATFORM_WINDOWNS",
			"BB_BUILD_DLL"
		}
		
		postbuildcommands
		{
			("{copy} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "BB_Debug"
		symbols "On"
	filter "configurations:Release"
		defines "BB_Release"
		optimize "On"
	filter "configurations:Dist"
		defines "BB_Dist"
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
		"%{prj.name}/src/**.cpp"
	}
	
	includedirs
	{
		"BBEngine/Vendor/SPDLOG/include",
		"BBEngine/src"
	}
	
	links
	{
		"BBEngine"
	}
	
	filter "system:windows"
		cppdialect "C++latest"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"BB_PLATFORM_WINDOWNS"
		}
		
	filter "configurations:Debug"
		defines "BB_Debug"
		symbols "On"
	filter "configurations:Release"
		defines "BB_Release"
		optimize "On"
	filter "configurations:Dist"
		defines "BB_Dist"
		optimize "On"