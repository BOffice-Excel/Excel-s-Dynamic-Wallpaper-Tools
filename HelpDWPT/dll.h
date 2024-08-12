#pragma once
#define DLLIMPORT __declspec(dllexport)
enum GETPERM{
	GP_FILEREAD=0,//允许读取文件 
	GP_FILEWRITE,//允许写入文件 
	GP_DLG,//允许创建对话框 
	GP_READREGISTRY,//允许读取注册表 
	GP_WRITEREGISTRY,//允许写注册表 
	GP_REGWNDCLS,//允许注册窗口类 
	GP_CRTWND,//允许创建窗口 
	GP_CRTPROCS,//允许创建进程 
	GP_ADMIN,//允许提升至管理员权限 
	GP_CRTMENU,//允许创建菜单 
	GP_WRITEPROFILE,//允许写配置文件 
	GP_READPROFILE,//允许读取配置文件 
	GP_GETFONT,//允许让用户选择字体 
	GP_LOADRES,//允许加载资源 
	GP_NOTEHIS,//允许历史记录 
};
extern "C" DLLIMPORT void WINAPI HelpWindow(/*HINSTANCE,*/HWND);
extern "C" DLLIMPORT void WinWatcher();
extern "C" DLLIMPORT bool GetPerm(short Type);
