#include "Includes.h"
using namespace std;


HWND hwnd = nullptr;

#pragma region console_color
void setcolor(unsigned short color)
{
	HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hcon, color);
}
#pragma endregion console_color

/*


#if defined(_MSC_VER) && (_MSC_VER >= 1900) && !defined(IMGUI_DISABLE_WIN32_FUNCTIONS)
#pragma comment(lib, "legacy_stdio_definitions")
#endif

static void glfw_error_callback(int error, const char* description)
{
    fprintf(stderr, "Glfw Error %d: %s\n", error, description);
}

int main(int, char**)
{
    // Setup window
    glfwSetErrorCallback(glfw_error_callback);
    if (!glfwInit())
        return 1;

    GLFWmonitor* Monitor = glfwGetPrimaryMonitor();
    if (!Monitor)
    {
        return 0;
    }
    int Width = glfwGetVideoMode(Monitor)->width;
    int Height = glfwGetVideoMode(Monitor)->height;

    glfwWindowHint(GLFW_FLOATING, true);
    glfwWindowHint(GLFW_RESIZABLE, false);
    glfwWindowHint(GLFW_MAXIMIZED, true);
    glfwWindowHint(GLFW_TRANSPARENT_FRAMEBUFFER, true);

    // Create window with graphics context
    GLFWwindow* window = glfwCreateWindow(Width, Height, "Luna's special panties", NULL, NULL);
    if (window == NULL)
        return 1;

    glfwSetWindowAttrib(window, GLFW_DECORATED, false);

    glfwMakeContextCurrent(window);
    glfwSwapInterval(1); // Enable vsync

    if (glewInit() != GLEW_OK)
    {
        fprintf(stderr, "Failed to initialize OpenGL loader!\n");
        return 1;
    }

    // Setup Dear ImGui context
    IMGUI_CHECKVERSION();
    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO(); (void)io;

    // Setup Dear ImGui style
    ImGui::StyleColorsDark();
    //ImGui::StyleColorsClassic();

    // Setup Platform/Renderer backends
    ImGui_ImplGlfw_InitForOpenGL(window, true);
    ImGui_ImplOpenGL3_Init();

    bool bMenuVisible = true;


    // Main loop
    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();

        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        if (GetAsyncKeyState(VK_INSERT) & 1)
        {
            bMenuVisible = !bMenuVisible;
            if (bMenuVisible)
            {
                ShowMenu(window);
            }
            else
            {
                HideMenu(window);
            }
        }


        if (bMenuVisible)
        {
            //Draw here
            if (ImGui::Button("Exit"))
            {
                return 0;
            }
        }
        

        // Rendering
        ImGui::Render();
        int display_w, display_h;
        glfwGetFramebufferSize(window, &display_w, &display_h);
        glViewport(0, 0, display_w, display_h);
        glClear(GL_COLOR_BUFFER_BIT);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        glfwSwapBuffers(window);
    }

    // Cleanup
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();

    glfwDestroyWindow(window);
    glfwTerminate();

    return 0;
}

*/
int main()
{



	///

	GLFWwindow* window;

	
	if (!glfwInit())
		return -1;

	glewInit();



	KernelInterface Driver = KernelInterface("\\\\.\\mfk");

	ULONG address = Driver.GetClientAddress();
	ULONG processid = Driver.GetProcessId();

#pragma region checkInternet

	SetConsoleTitleA("Welcome to Luna's toolkit");

	setcolor(10); //green
	std::cout << "[+] Checking for updates...\n";  //Checking for updates from Server
	Sleep(2000);

	bool checkconnection = InternetCheckConnectionA("https://www.google.com/", FLAG_ICC_FORCE_CONNECTION, 0);  //Check for internet
	if (!checkconnection)
	{
		std::cout << "[+] Your are not connected to internet, closing...\n";
		Sleep(2000);
		exit(1);
	}

	std::cout << "[+] Latest update is already installed!\n";

#pragma endregion checkInternet

#pragma region checkHwid

	setcolor(5); //purple
	TCHAR volumeName[MAX_PATH + 1] = { 0 };
	TCHAR fileSystemName[MAX_PATH + 1] = { 0 };
	DWORD serialNumber = 0;
	DWORD maxComponentLen = 0;
	DWORD fileSystemFlags = 0;
	TCHAR computerName[MAX_COMPUTERNAME_LENGTH + 1];
	DWORD size = sizeof(computerName) / sizeof(computerName[0]);
	if (GetComputerName(
		computerName,
		&size))
	{
		cout << "Computer Name: " << computerName << std::endl;
	}
	int cpuinfo[4] = { 0, 0, 0, 0 }; //EAX, EBX, ECX, EDX
	__cpuid(cpuinfo, 0);
	char16_t hash = 0;
	char16_t* ptr = (char16_t*)(&cpuinfo[0]);
	for (char32_t i = 0; i < 8; i++)
		hash += ptr[i];
	cout << "CPU Hash: " << hash << std::endl;


	if (GetVolumeInformation(_T("C:\\"), volumeName, ARRAYSIZE(volumeName), &serialNumber, &maxComponentLen, &fileSystemFlags, fileSystemName, ARRAYSIZE(fileSystemName)))
	{
		cout << "Volume Name: " << volumeName << std::endl;
		cout << "HDD Serial: " << serialNumber << std::endl;
		cout << "File System Type: " << fileSystemName << std::endl;
		cout << "Max Component Length: " << maxComponentLen << std::endl;
	}

	setcolor(10); //purple
	std::cout << "[+] HWID check done! Please Wait...\n";
	Sleep(2000);

#pragma endregion checkHwid



	setcolor(1); //blue
	std::cout << "[+] Scanning for Remnant...\n [+] Make sure to open the game!\n [+] The game will automatically launch if program is run as administrator! (Not done yet)" << std::endl;

	while (!hwnd)
	{
		hwnd = FindWindowA(NULL, "Remnant");
	}

	setcolor(10);
	std::cout << "[+] Found Remnant running!" << std::endl;

	DWORD processID = 0;
	GetWindowThreadProcessId(hwnd, &processID);  //getiing pid on software side for debug

	std::cout << "[+] Process ID found by Software is: " << processID << std::endl;
	setcolor(5);

	std::cout << " [+] Process ID found by Driver is:" << processid << std::endl;
	std::cout << " [+] Client Address " << std::hex << address << std::endl;
	Sleep(9999);



}