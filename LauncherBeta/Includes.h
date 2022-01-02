#pragma once
#include <iostream>
#include <Windows.h>
#include <string>
#include <vector>
#include <WinInet.h>
#include <stdlib.h> //colors to menu
#include <tchar.h> //includes for the login system
#include <intrin.h>
#include <algorithm>
#include <TlHelp32.h> //basic Database for login
#include <thread>
#include <chrono>//We will use chrono for the elapsed time.
#include <cstdint>

#pragma comment(lib,"Wininet.lib")  //Check internet
#pragma comment(lib, "winmm.lib")   //Check internet

#pragma comment(lib, "glew32s.lib")
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h> //OpenGL

#include "imgui/imgui.h" //ImGUI
#include "imgui/imgui_impl_glfw.h"
#include "imgui/imgui_impl_opengl3.h"
#include <stdio.h>
#if defined(IMGUI_IMPL_OPENGL_ES2)
#include <GLES2/gl2.h>
#endif
#include <GLFW/glfw3.h> // Will drag system OpenGL headers


#include "Helpers.h"
#include "Communication.h"
#include "Kernel_Interface.h"