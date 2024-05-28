/* Replace "dll.h" with the name of your header */
#define DLLIMPORT __declspec(dllexport)
#include <windows.h>
#include "dll.h"
typedef BOOL WINAPI (*SPDA)(VOID);
typedef HFONT WINAPI (*CreateFontP)(int,int,int,int,int,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,DWORD,LPCSTR);
SPDA SetProcessDPIAwarev;
CreateFontP CreateFontL;
#pragma comment (lib,"libgdiplus.a")
#pragma comment (lib,"libgdi32.a")
//HFONT hFont = CreateFont(25, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("思源"));//默认字体 
bool CONTINUE=true;
LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
	switch(msg){
		case WM_CREATE:{
			PostMessage(hWnd,WM_COMMAND,(WPARAM)1,NULL);
			break;
		}
		case WM_CLOSE:
		case WM_DESTROY:{
			PostQuitMessage(0); 
			ShowWindow(hWnd,SW_HIDE); 
			return 0;
		}
		case WM_COMMAND: {
			switch(LOWORD(wParam)){
				case 1:{
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),"DWPT的优点：\n\r1.轻便\r\n\
    DWPT在Windows7及上的版本中除了WinAPI的库和HelpDWPT.dll，不需要其他杂七杂八的库，且DWPT主程序仅有200多KiB，比你用iostream库写一个Hello World编译出来的程序还小，并且不依赖Visual C++运行库\r\n\
2.界面简洁\r\n\
    DWPT的用户界面有且仅有1个选项卡控件、1个静态文本控件、1个检查框、3个窗口（Tab Control不会用就用了笨方法）、6个按钮，且没有任何的广告，也不会让你的电脑变慢变卡，不需要时还可以将程序图标隐藏到系统托盘中，十分人性化\r\n\
\r\n3.更好的支持性\r\n\
    DWPT的视频播放工具是mshta.exe（Microsoft HTML应用程序），不要质疑为什么我要用这个（因为我不会写播放器），而不用ffplay.exe的原因是ffplay.exe确实是太大了，100多MiB，比主程序还要大，并且我选的是32位编译，所以理论上x86的Windows也能用\r\n\
\r\n所以，如果你要选择一款轻便、简单、无广告的动态壁纸软件，就选DWPT吧！ \
");
					break;
				}
				case 2:{
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),"DWPT的打开方法很简单，第一步：打开程序，第二步：允许管理员权限（放心，不会对你电脑干什么，除了被修改过的）\r\n\
一.如何启动动态壁纸：\r\n\
 1.点击\"创建配置文件\"按钮\r\n\
 2.选择一个保存位置（记得输入保存的文件名称）\r\n\
 3.选择你的一个视频，记得点击那个视频一下让它处于被选中状态\r\n\
 4.询问你是否需要声音，你可以点击\"是\"或者\"否\"来禁用或启用声音\r\n\
 5.到这里，配置文件就创建完成了，你可以在接下来的点击\"是\"来立即使用这个配置文件，或者点击\"否\"把这个文件先放着\r\n\r\n\
二.我上次创建了配置文件了，如何使用上次的配置：\r\n\
 1.点击\"打开配置文件\"按钮\r\n\
 2.选择你上次创建的配置文件\r\n\
 3.在弹出的问你是否继续，这个时候请确定你是否有其它的和DWPT无关的mshta.exe进程在运行，如果没有就点\"是\"，有的话就去看看重不重要，不重要的就关了，如果有重要的就先别开\r\n\r\n\
三.我想修改配置文件的内容怎么办：\r\n\
 1.点击\"修改配置文件\"按钮\r\n\
 2.选择你的配置文件\r\n\
 3.进入到编辑页面，这个时候你就可以开始修改了，可以点击\"是\"或\"否\"来修改，\"取消\"则是停止修改\r\n\
 4.继续第三步直到修改完成\r\n\
 5.选择是否保存\r\n\
 6.完成！\r\n\r\n\
四.我不想用了要停下怎么办：\r\n\
 1.确认你的电脑上没有与DWPT不相干的mshta.exe在运行\r\n\
 2.点击\"停止动态壁纸\"\r\n\
 3.点击确认并在弹出的框框选\"是\"，即可停止动态壁纸\r\n\r\n\
五.如何 设置\\修改 默认项的位置：\r\n\
 1.点击\"全局设置\"\r\n\
 2.点击\"编辑\"，选择你要设置为默认项的配置文件，点击确定即可\r\n\r\n\
六.我想要开机自启动动态壁纸怎么办：\r\n\
 1.请确保您已经设置了默认项，如果没有请看\"五\"\r\n\
 2.点击\"全局设置\"\r\n\
 3.选中\"开机自启动\"检查框即可\r\n\
");
					break;
				}
				case 3:{
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),"问题 & 回答：\n\r问：为什么你不用CLR创建窗口？\r\n\
答：因为要照顾一些装不上Visual C++运行库的特殊人群，就像She_Fa21，如果不装VC会提示少dll，并且gcc编译的更小\r\n\r\n\
问：你创建出来的窗口和控件为什么都是Win11样式的且DPI不会有问题而我不行？\r\n\
答：这个问题我也想过，我从网上大量搜集资料且实践了很久才琢磨出这种方法，对于您的问题，我有以下解决方法：\r\n\
    对于控件是旧版的问题：\r\n\
        Visual Studio:请在前面加上以下代码：\r\n\
            #ifdef _UNICODE\r\n\
            #if defined _M_IX86\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #elif defined _M_X64\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #else\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #endif\r\n\
            #endif\r\n\
        Dev-C++:相对于Visual Studio来说，Dev的操作更简单，在 项目[P]->项目属性[O] 里面勾选上\"支持 Windows XP 主题\"即可\r\n\
    对于DPI显示不正确的问题：\r\n\
        Visual Studio:直接在程序起始的地方加上代码：SetProcessDPIAware();\r\n\
        Dev-C++:请在程序起始的地方加入以下代码：\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID);\r\n\
            SPDA SetProcessDPIAware;\r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\");\r\n\
            SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");\r\n\
            if(SetProcessDPIAware) SetProcessDPIAware();\r\n\
            //我不知道为什么，反正Dev-C++自带的gcc的库里面没有这个函数（反正我这个没有）\r\n\
    这样就解决啦！\r\n\
问：如果出现创建窗口失败、窗口类注册失败之类的该怎么办？\r\n\
答：请尝试重新下载本程序，如果还是不行，那我就没办法了\r\n\
问：为什么字体那么丑？\r\n\
答：我写代码时嵌入的是\"黑体细体\"和\"思源\"这两种字体，如果不是这两种，你也许可以去试着重新下载一下这两个字体，我是用CreateFont来搞的，所以可以去看看Microsoft开发文档里面的CreateFont函数");
					break;
				}
				case 4:{
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),"关于DWPT：\n\r作者、窗口设计：Office-Excel\r\n\
参考视频（哔哩哔哩视频编号）：BV1HZ4y1978a，地址：https://www.bilibili.com/video/BV1HZ4y1978a/\r\n\
使用的代码编辑工具：Dev-C++ 使用的代码语言：C++ 用得最多的库：windows.h\r\n\
窗口创建：Windows API（不是资源文件里的对话框，因为我不会用）\r\n\
DWPT项目属性：\r\n\
    名称：DWPT（全称Dynamic Wallpaper Tools，翻译：动态壁纸工具）\r\n\
    项目开始日期：2024/04/21\r\n\
    项目目标：做一个纯净简单的动态壁纸工具\r\n\
    作者为什么要做这个破玩意：只是为了好玩随便写了600多行的代码\r\n\
    dwp文件结构：\r\n\
        如果你用记事本打开dwp文件\r\n\
            你会发现第一个字符总是't'或者'f'，这代表了是否启用声音，f=不启用，t=启用\r\n\
            后面的则是视频的绝对路径，文本按理说应该是使用GBK编码存储的，所以支持中文\r\n\
\r\n\
    DWPT启动动态壁纸的原理：\r\n\
        1.读入文件\r\n\
        2.查看是否启用声音\r\n\
        3.将视频绝对路径存入VP（char数组）\r\n\
        4.拼接预设的文本并写入%temp%\\Temporary.hta文件\r\n\
        5.启动进程mshta.exe\r\n\
        6.向类名为Progman的窗口发送0x52C信号\r\n\
        7.找到第二个WorkerW窗口并隐藏它\r\n\
        8.将类名为Progman的窗口设置为mshta.exe窗口的父窗口\r\n\
        9.完成！\r\n\r\n\
作者的哔哩哔哩账号：Office-Excel（地址：https://space.bilibili.com/1439352366/）\r\n\
");
					break;
				}
				case 5:{
					system("start https://space.bilibili.com/1439352366/");
					break;
				}
				case 6:{
					system("start https://www.bilibili.com/video/BV1HZ4y1978a/");
					break;
				} 
				case 7:{
					WndProc(hWnd,WM_CLOSE,NULL,NULL);
					break;
				}
			}
			break;
		}
		default:return DefWindowProc(hWnd,msg,wParam,lParam);
	}
}
extern "C" DLLIMPORT void HelpWindow(HINSTANCE hInstance,HWND hwnd){
	if(!hInstance) hInstance=GetModuleHandle(0);
	
	CONTINUE=true;
	HFONT hFont;
	HMODULE hM=LoadLibrary("gdi32.dll");
	if(hM){
		CreateFontL=(CreateFontP)GetProcAddress(hM,"CreateFontA");
		if(CreateFontL) hFont=CreateFontL(18, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("黑体细体"));
	}
	
	HMODULE hModule = LoadLibrary("user32.dll");
	SetProcessDPIAwarev = (SPDA)GetProcAddress(hModule,"SetProcessDPIAware");
	SetProcessDPIAwarev();//清晰！！！
	
	WNDCLASSEX wcex;
	memset(&wcex,0,sizeof wcex);
	MSG msg;
	wcex.cbSize=sizeof(WNDCLASSEX);
	wcex.hInstance=hInstance;
	wcex.lpszClassName="Help_DWPT";
	wcex.hIcon=LoadIcon(hInstance,"A")/*LoadIcon(NULL,IDI_QUESTION)*/; 
	wcex.hIconSm=wcex.hIcon /*LoadIcon(NULL,IDI_QUESTION)*/; 
	wcex.style=CS_DBLCLKS|CS_SAVEBITS|CS_GLOBALCLASS;
	wcex.lpfnWndProc=WndProc;
	wcex.hbrBackground=(HBRUSH)(COLOR_BTNFACE+1);
	wcex.hCursor=LoadCursor(NULL,IDC_ARROW);
	RegisterClassEx(&wcex);
	
	HWND hWnd=CreateWindowEx(WS_EX_ACCEPTFILES, "Help_DWPT", "How to use Dynamic Wallpaper Tools?",
		WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | DS_FIXEDSYS | DS_3DLOOK | DS_SETFONT | DS_MODALFRAME | DS_NOIDLEMSG,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		1400, /* width */
		800/*60*/, /* height */
		hwnd, NULL, wcex.hInstance, NULL);//创建窗口 
	
	if(!hWnd){
		MessageBox(hwnd,"Cannot create the main window","ERORR",MB_ICONWARNING);
		return;
	}
	
	EnableWindow(hwnd,false);
	SendMessage(CreateWindow("EDIT",NULL,WS_CHILD|WS_VISIBLE|ES_NOHIDESEL|ES_AUTOVSCROLL|WS_BORDER|ES_MULTILINE|ES_READONLY,200,0,1190,780,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","为什么选择我们",WS_CHILD|WS_VISIBLE,20,20,150,30,hWnd,(HMENU)1,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","如何用",WS_CHILD|WS_VISIBLE,20,60,150,30,hWnd,(HMENU)2,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","问题 && 回答",WS_CHILD|WS_VISIBLE,20,100,150,30,hWnd,(HMENU)3,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","关于DWPT",WS_CHILD|WS_VISIBLE,20,140,150,30,hWnd,(HMENU)4,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","打开作者主页",WS_CHILD|WS_VISIBLE,20,180,150,30,hWnd,(HMENU)5,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","打开参考视频",WS_CHILD|WS_VISIBLE,20,220,150,30,hWnd,(HMENU)6,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","关闭",WS_CHILD|WS_VISIBLE,20,260,150,30,hWnd,(HMENU)7,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	
	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);
	while(GetMessage(&msg, NULL, 0, 0) > 0){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	EnableWindow(hwnd,true);
	return;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	switch(fdwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			break;
		}
		case DLL_THREAD_ATTACH:
		{
			break;
		}
		case DLL_THREAD_DETACH:
		{
			break;
		}
	}
	
	/* Return TRUE on success, FALSE on failure */
	return TRUE;
}
