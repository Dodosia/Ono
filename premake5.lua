workspace "Ono"
	architecture "x64"

	configurations
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Ono/vendor/GLFW/include"
IncludeDir["GLAD"] = "Ono/vendor/GLAD/include"
IncludeDir["ImGui"] = "Ono/vendor/imgui"
IncludeDir["Vulkan"] = "Ono/vendor/VulkanSDK/include"

include "Ono/vendor/GLAD"
include "Ono/vendor/GLFW"
include "Ono/vendor/imgui"

project "Ono"
	location "Ono"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	pchheader "onopch.h"
	pchsource "Ono/src/onopch.cpp"

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLAD}",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.ImGui}",
		"%{IncludeDir.Vulkan}"
	}

	libdirs
	{
		"Ono/vendor/VulkanSDK/lib"
	}

	links
	{
		"GLAD",
		"GLFW",
		"ImGui",
		"vulkan-1"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"ONO_PLATFORM_WINDOWS",
			"ONO_BUILD_DLL",
			"ONO_ENABLE_ASSERTS",
			"GLFW_INCLUDE_VULKAN"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ONO_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ONO_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ONO_DIST"
		buildoptions "/MD"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin/int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Ono/vendor/spdlog/include",
		"Ono/src",
		"%{IncludeDir.GLAD}"
	}
	
	links
	{
		"Ono"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"ONO_PLATFORM_WINDOWS",
			"ONO_ENABLE_ASSERTS"
		}

	filter "configurations:Debug"
		defines "ONO_DEBUG"
		buildoptions "/MDd"
		symbols "On"

	filter "configurations:Release"
		defines "ONO_RELEASE"
		buildoptions "/MD"
		optimize "On"

	filter "configurations:Dist"
		defines "ONO_DIST"
		buildoptions "/MD"
		optimize "On"