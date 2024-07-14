# SummerGame

```
{
	"version": "2.0.0",
	"tasks": [
		{
			"type": "cppbuild",
			"label": "C/C++: clang++ build active file",
			"command": "/usr/bin/clang++",
			"args": [
				"-std=c++17",
				"-fcolor-diagnostics",
				"-fansi-escape-codes",
				"-Wall",
				"-g",
				"-I${workspaceFolder}/SummerGame/dependencies/include",
				"-L${workspaceFolder}/SummerGame/dependencies/library",
				"${workspaceFolder}/SummerGame/dependencies/library/libglfw.3.dylib",
				"${workspaceFolder}/SummerGame/*.cpp",
				"${workspaceFolder}/SummerGame/glad.c",
				"-o",
				"${workspaceFolder}/SummerGame/app",
				"-framework",
				"OpenGL",
				"-framework",
				"Cocoa",
				"-framework",
				"IOKit",
				"-framework",
				"CoreVideo",
				"-framework",
				"CoreFoundation",
				"-Wno-deprecated"
			],
			"options": {
				"cwd": "${fileDirname}"
			},
			"problemMatcher": [
				"$gcc"
			],
			"group": {
				"kind": "build",
				"isDefault": true
			},
			"detail": "compiler: /usr/bin/clang++"
		}
	]
}
```
