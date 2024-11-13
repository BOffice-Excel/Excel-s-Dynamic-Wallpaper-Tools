#ifndef _DLL_H_
#define _DLL_H_
#ifndef DLLIMPORT
#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif
#endif
#include <windows.h>//非常重要啊啊啊！！！ 
#include <stdio.h>
#include <io.h>
#define IL_UNSET -1 //未设置 
#define IL_ENGLISH 0 //英文 
#define IL_Simplified_Chinese 1 //简体中文 
#define IL_Traditional_Chinese 2 //繁体中文 
extern "C"{
	DLLIMPORT BOOL CALLBACK EnumWindowProc(_In_ HWND hwnd, _In_ LPARAM Lparam);
	DLLIMPORT WINBOOL PutToDesktop(HWND Wallpaper);
	DLLIMPORT DWORD WINAPI DwpThread(LPVOID lparam);
	DLLIMPORT void StartDwp(const char PathA[],BOOL Quiet);
	DLLIMPORT BOOL CALLBACK StopDWPProc(_In_ HWND hWnd,_In_ LPARAM lparam);
	//DLLIMPORT char* GetString4ThisLang(UINT index);
	DLLIMPORT bool SGetQuietMode(bool Set,bool beQuiet);
	DLLIMPORT int SGetLangId(bool Set,int LangId);
	DLLIMPORT char* SGetVidPath(bool Set,char Source[]);
}
#endif
