/* Replace "dll.h" with the name of your header */
#include "dll.h"
#include <windows.h>
#include <uxtheme.h>
#include <stdio.h>
struct V{
	int Main;
	int Sub;
	int Release;
	int Make; 
};
typedef V *LPV;
typedef VOID (*GVF)(LPV);
char Message[114514];
HFONT hFont=CreateFont(20,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,NULL,"Consolas");
DWORD WINAPI MainThread(LPVOID lparam){
	HWND mainWnd=(HWND)lparam;
	SetDlgItemText(mainWnd,1,"Message: Checking version...");
	strcat(Message,"[Version Checker:MSG] Checking version...\r\n");
	SetDlgItemText(mainWnd,3,Message);
	HMODULE hModule=LoadLibrary("WallpaperCore.dll");
	if(hModule==NULL){
		V LatestVersion;
		UpdateWithNoVersion:
		SetDlgItemText(mainWnd,1,"Error: Library 'WallpaperCore.dll' loaded failed!");
		strcat(Message,"[Version Checker:ERR] Library 'WallpaperCore.dll' loaded failed!\r\n");
		SetDlgItemText(mainWnd,3,Message);
		
		char str[1145],DownloadUrl[11451];
		GetTempPath(1140,str);
		if(str[strlen(str)-1]=='\\') strcat(str,"Version.ini");
		else strcat(str,"\\Version.ini");
		SetDlgItemText(mainWnd,1,"Message: Getting version profile from github.");
		strcat(Message,"[Version Checker:MSG] Getting version profile from github.\r\n");
		SetDlgItemText(mainWnd,3,Message);
		
		DeleteFileA(str);
		URLDownloadToFile(NULL,"https://boffice-excel.github.io/Website/DWPT/Version.ini",str,NULL,NULL);
		LatestVersion.Main=GetPrivateProfileInt("Version","Main",NULL,str);
		LatestVersion.Sub=GetPrivateProfileInt("Version","Sub",NULL,str);
		LatestVersion.Release=GetPrivateProfileInt("Version","Release",NULL,str);
		LatestVersion.Make=GetPrivateProfileInt("Version","Make",NULL,str);
		GetPrivateProfileString("Version","DownUrl",NULL,DownloadUrl,11440,str);
		
		GetTempPath(1140,str);
		if(str[strlen(str)-1]=='\\') strcat(str,"Installer.exe");
		else strcat(str,"\\Installer.exe");
		DeleteFileA(str);
		URLDownloadToFile(NULL,DownloadUrl,str,NULL,NULL);
		if(GetFileAttributesA(str)==INVALID_FILE_ATTRIBUTES){
			SetDlgItemText(mainWnd,1,"Error: Failed to download the installer of the latest version!");
			strcat(Message,"[Updator:ERR] Failed to download the installer of the latest version!\r\n");
			SetDlgItemText(mainWnd,3,Message);
			
			strcat(Message,"[Updator:ERR] Please try restarting this program to retry update.\r\n");
			SetDlgItemText(mainWnd,3,Message);
		}
		else{
			SetDlgItemText(mainWnd,1,"Message: Downloaded the installer successfully.");
			strcat(Message,"[Updator:MSG] Downloaded the installer successfully.\r\n");
			SetDlgItemText(mainWnd,3,Message);
			
			strcat(Message,"[Updator:MSG] Updating...\r\n");
			SetDlgItemText(mainWnd,3,Message);
			WinExec(str,SW_SHOW);
			Sleep(100);
			SendMessage(mainWnd,WM_DESTROY,NULL,NULL);
		}
	}
	else{
		V Ver,LatestVersion;
		GVF GetVer;
		GetVer=(GVF)GetProcAddress(hModule,"GetVer");
		if(GetVer){
			GetVer(&Ver);
			char str[1145],DownloadUrl[11451];
			SetDlgItemText(mainWnd,1,"Message: Current version was got successfully.");
			sprintf(str,"[Version Checker:MSG] Current version: %d.%d.%d.%d\r\n",Ver.Main,Ver.Sub,Ver.Release,Ver.Make);
			strcat(Message,str);
			SetDlgItemText(mainWnd,3,Message);
			
			GetTempPath(1140,str);
			if(str[strlen(str)-1]=='\\') strcat(str,"Version.ini");
			else strcat(str,"\\Version.ini");
			SetDlgItemText(mainWnd,1,"Message: Getting version profile from github.");
			strcat(Message,"[Version Checker:MSG] Getting version profile from github.\r\n");
			SetDlgItemText(mainWnd,3,Message);
			
			DeleteFileA(str);
			URLDownloadToFile(NULL,"https://boffice-excel.github.io/Website/DWPT/Version.ini",str,NULL,NULL);
			LatestVersion.Main=GetPrivateProfileInt("Version","Main",NULL,str);
			LatestVersion.Sub=GetPrivateProfileInt("Version","Sub",NULL,str);
			LatestVersion.Release=GetPrivateProfileInt("Version","Release",NULL,str);
			LatestVersion.Make=GetPrivateProfileInt("Version","Make",NULL,str);
			GetPrivateProfileString("Version","DownUrl",NULL,DownloadUrl,11440,str);
			
			SetDlgItemText(mainWnd,1,"Message: Latest version was got successfully.");
			sprintf(str,"[Version Checker:MSG] Latest version: %d.%d.%d.%d\r\n[Version Checker:MSG] Latest version download url: %s\r\n",LatestVersion.Main,LatestVersion.Sub,LatestVersion.Release,LatestVersion.Make,DownloadUrl);
			strcat(Message,str);
			SetDlgItemText(mainWnd,3,Message);
			
			if(Ver.Main!=LatestVersion.Main||Ver.Make!=LatestVersion.Make||Ver.Release!=LatestVersion.Release||Ver.Sub!=LatestVersion.Sub){
				SetDlgItemText(mainWnd,1,"Message: Downloading the installer of the latest version.");
				strcat(Message,"[Updator:MSG] Downloading the installer of the latest version.\r\n");
				SetDlgItemText(mainWnd,3,Message);
				
				GetTempPath(1140,str);
				if(str[strlen(str)-1]=='\\') strcat(str,"Installer.exe");
				else strcat(str,"\\Installer.exe");
				DeleteFileA(str);
				URLDownloadToFile(NULL,DownloadUrl,str,NULL,NULL);
				if(GetFileAttributesA(str)==INVALID_FILE_ATTRIBUTES){
					SetDlgItemText(mainWnd,1,"Error: Failed to download the installer of the latest version!");
					strcat(Message,"[Updator:ERR] Failed to download the installer of the latest version!\r\n");
					SetDlgItemText(mainWnd,3,Message);
					
					strcat(Message,"[Updator:ERR] Please try restarting this program to retry update.\r\n");
					SetDlgItemText(mainWnd,3,Message);
				}
				else{
					SetDlgItemText(mainWnd,1,"Message: Downloaded the installer successfully.");
					strcat(Message,"[Updator:MSG] Downloaded the installer successfully.\r\n");
					SetDlgItemText(mainWnd,3,Message);
					
					strcat(Message,"[Updator:MSG] Updating...\r\n");
					SetDlgItemText(mainWnd,3,Message);
					WinExec(str,SW_SHOW);
					Sleep(100);
					SendMessage(mainWnd,WM_DESTROY,NULL,NULL);
				}
			}
			else{
				SetDlgItemText(mainWnd,1,"Message: No update.");
				sprintf(str,"[Version Checker:MSG] No new version to update DWPT.\r\n");
				strcat(Message,str);
				SetDlgItemText(mainWnd,3,Message);
			}
		}
		else goto UpdateWithNoVersion;
	}
	strcat(Message,"Update has ended.\r\n");
	SetDlgItemText(mainWnd,3,Message);
	SetDlgItemText(mainWnd,4,"&OK");
}
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {
	switch(Message) {
		case WM_CREATE:{
			CreateWindowEx(NULL,
				WC_STATIC,"Progress: Checking version...",
				WS_CHILD|WS_VISIBLE,
				50,70,530,30,
				hwnd,(HMENU)1,NULL,NULL
			);
			SendDlgItemMessage(hwnd,1,WM_SETFONT,(WPARAM)hFont,NULL);
			SetWindowTheme(CreateWindowEx(NULL,
					PROGRESS_CLASS,NULL,
					WS_CHILD|WS_VISIBLE|PBS_MARQUEE|PBS_SMOOTH,
					50,100,530,20,
					hwnd,(HMENU)2,NULL,NULL
				),
				L"DarkMode_Explorer",
				NULL
			);
			SendMessage(GetDlgItem(hwnd,2),PBM_SETMARQUEE,(WPARAM)TRUE,(LPARAM)45);
			SendMessage(GetDlgItem(hwnd,2),PBM_SETBARCOLOR,0,(LPARAM)RGB(6,176,37));
			SetWindowTheme(CreateWindowEx(NULL,
					WC_EDIT,NULL,
					WS_CHILD|WS_VISIBLE|ES_READONLY|WS_BORDER|ES_MULTILINE|WS_VSCROLL,
					50,150,530,200,
					hwnd,(HMENU)3,NULL,NULL
				),
				L"DarkMode_Explorer",
				NULL
			);
			SendDlgItemMessage(hwnd,3,WM_SETFONT,(WPARAM)hFont,NULL);
			SetWindowTheme(CreateWindowEx(NULL,
					WC_BUTTON,"&Cancel",
					WS_CHILD|WS_VISIBLE,
					500,380,100,30,
					hwnd,(HMENU)4,NULL,NULL
				),
				L"DarkMode_Explorer",
				NULL
			);
			SendDlgItemMessage(hwnd,4,WM_SETFONT,(WPARAM)hFont,NULL);
			SetTimer(hwnd,1,200,NULL);
			break;
		}
		case WM_TIMER:{
			KillTimer(hwnd,1);
			CreateThread(NULL,NULL,MainThread,(LPVOID)hwnd,NULL,NULL);
			break;
		}
		case WM_DESTROY: {
			PostQuitMessage(0);
			break;
		}
		case WM_COMMAND:{
			switch(LOWORD(wParam)){
				case 4:{
					PostMessage(hwnd,WM_DESTROY,NULL,NULL);
					break;
				}
			}
			break;
		}
		case WM_SIZE:{
			RECT rect;GetWindowRect(hwnd,&rect);
			SetWindowPos(GetDlgItem(hwnd,1),NULL,50,70,rect.right-rect.left-110,30,SWP_NOZORDER);
			SetWindowPos(GetDlgItem(hwnd,2),NULL,50,100,rect.right-rect.left-110,20,SWP_NOZORDER);
			SetWindowPos(GetDlgItem(hwnd,3),NULL,50,150,rect.right-rect.left-110,rect.bottom-rect.top-280,SWP_NOZORDER);
			SetWindowPos(GetDlgItem(hwnd,4),NULL,rect.right-rect.left-140,rect.bottom-rect.top-100,100,30,SWP_NOZORDER);
			break;
		}
		case WM_CTLCOLORBTN: 
		case WM_CTLCOLORSTATIC:
		case WM_CTLCOLOREDIT:
		case WM_CTLCOLORMSGBOX:
		case WM_CTLCOLORDLG:
		case WM_CTLCOLORLISTBOX:
		case WM_CTLCOLORSCROLLBAR:{
			static HBRUSH hbrBkgnd=NULL;
	        HDC hdcStatic=(HDC)wParam;
	        SetTextColor(hdcStatic, RGB(255,255,255));
	        SetBkColor(hdcStatic, RGB(25,25,25));
	    	if (hbrBkgnd==NULL){
	            hbrBkgnd=CreateSolidBrush(RGB(25,25,25));
	        }
	        return (INT_PTR)hbrBkgnd;
	        break;
        }
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);
	}
	return 0;
}

extern "C" DLLIMPORT void Default(){
	typedef BOOL WINAPI (*SPDA)(VOID);
	SPDA SetProcessDPIAware;
	HMODULE hModule = LoadLibrary("user32.dll");
	if(hModule){//Exception handling
		SetProcessDPIAware = (SPDA)GetProcAddress(hModule,"SetProcessDPIAware");// Tip: The SetProcessDPIAware function was added to Windows Vista
		if(SetProcessDPIAware) SetProcessDPIAware();//Non abnormal state
	}
	WNDCLASSEX wc;
	HWND hwnd;
	MSG Msg;

	memset(&wc,0,sizeof(wc));
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.lpfnWndProc	 = WndProc; /* insert window procedure function here */
	wc.hInstance	 = GetModuleHandle(NULL);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = CreateSolidBrush(RGB(25,25,25));//(HBRUSH)(COLOR_WINDOW+1);
	wc.lpszClassName = "DWPT-Update-Checker";
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION); /* use "A" as icon name when you want to use the project icon */
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION); /* as above */

	if(!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return ;
	}

	hwnd = CreateWindowEx(NULL,"DWPT-Update-Checker","Checking update...",WS_VISIBLE|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX|WS_THICKFRAME,CW_USEDEFAULT,CW_USEDEFAULT,1500,800,NULL,NULL,wc.hInstance,NULL);
	if(hwnd == NULL) {
		MessageBox(NULL, "Window Creation Failed!","Error!",MB_ICONEXCLAMATION|MB_OK);
		return ;
	}
	
	ShowWindow(hwnd,SW_SHOW);
	UpdateWindow(hwnd);
	while(GetMessage(&Msg, NULL, 0, 0) > 0) {
		TranslateMessage(&Msg);
		DispatchMessage(&Msg);
	}
	return ;
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
