workspace "Ono"
	architecture "x64"

	configurations
	{
		"Debug",
		"release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Ono"
	location "Ono"
	kind "SharedLib"
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
		"%{prj.name}/vendor/spdlog/include"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"
		
		defines
		{
			"ONO_PLATFORM_WINDOWS",
			"ONO_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "ONO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ONO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ONO_DIST"
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
		"Ono/src"
	}
	
	links
	{
		"Ono"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "10.0.22621.0"
		
		defines
		{
			"ONO_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "ONO_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "ONO_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ONO_DIST"
		optimize "On"