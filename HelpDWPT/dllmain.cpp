/* Replace "dll.h" with the name of your header */
#include <windows.h>
#include <stdio.h>
#include "dll.h"
#define key_press(key) ((GetAsyncKeyState(key)&0x8000)?1:0)//定义按键检测函数 
typedef BOOL WINAPI (*SPDA)(VOID);
SPDA SetProcessDPIAwarev;
#pragma comment (lib,"libgdiplus.a")
#pragma comment (lib,"libgdi32.a")
#define IDC_SLTBTN 1
#define IDC_TEXT 2
#define IDC_CLSNAME 3
#define IDC_PARENT 4
#define IDC_HANDLE 5
#define IDC_WNDBOX 6
#define IDC_STYLE 7
#define IDC_EXSTYLE 8
#define IDC_CLSSYE 9
#define IDC_HCURSOR 10
#define IDC_PROCESSID 11
#define IDC_MSGWTR 12
//HFONT hFont = CreateFont(25, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("思源"));//默认字体 
HWND hWND,ChooseWindow;
HDC hdc=GetDC(0);
HFONT hFont1;
HINSTANCE hinst;
typedef char* (*GS4TL)(UINT);
typedef VOID (*SWT)(HWND,LPCWSTR,LPCWSTR);
typedef VOID (*DSWA)(HWND,DWORD,LPCVOID,DWORD);
GS4TL GetString4ThisLang;
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
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),GetString4ThisLang(83));
					break;
				}
				case 2:{
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),GetString4ThisLang(84));
					break;
				}
				case 3:{
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),GetString4ThisLang(85));
					break;
				}
				case 4:{
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),GetString4ThisLang(86));
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
		default:return DefWindowProc(hWnd,msg,wParam,lParam);
	}
}

extern "C" DLLIMPORT DWORD WINAPI KeyWatchThread(LPVOID lparam){
	
}

extern "C" DLLIMPORT void HelpWindow(HWND hwnd){
	HFONT hFont;
	hFont=CreateFont(18, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("黑体细体"));
	
	HMODULE hModule = LoadLibrary("user32.dll");
	if(hModule){
		SetProcessDPIAwarev = (SPDA)GetProcAddress(hModule,"SetProcessDPIAware");
		if(SetProcessDPIAwarev) SetProcessDPIAwarev();//清晰！！！
	}
	
	WNDCLASSEX wcex;
	memset(&wcex,0,sizeof wcex);
	MSG msg;
	wcex.cbSize=sizeof(WNDCLASSEX);
	wcex.hInstance=hinst;
	wcex.lpszClassName="Help_DWPT";
	wcex.hIcon=LoadIcon(NULL,IDI_QUESTION)/*LoadIcon(NULL,IDI_QUESTION)*/; 
	wcex.hIconSm=wcex.hIcon /*LoadIcon(NULL,IDI_QUESTION)*/; 
	wcex.style=CS_DBLCLKS|CS_SAVEBITS|CS_GLOBALCLASS;
	wcex.lpfnWndProc=WndProc;
	wcex.hbrBackground=CreateSolidBrush(RGB(25,25,25));
	wcex.hCursor=LoadCursor(NULL,IDC_ARROW);
	RegisterClassEx(&wcex);
	
	HWND hWnd=CreateWindowEx(WS_EX_ACCEPTFILES, "Help_DWPT", "How to use Dynamic Wallpaper Tools?",
		WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | DS_FIXEDSYS | DS_3DLOOK | DS_SETFONT | DS_MODALFRAME | DS_NOIDLEMSG,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		1400, /* width */
		750/*60*/, /* height */
		hwnd, NULL, wcex.hInstance, NULL);//创建窗口 
	
	if(!hWnd){
		MessageBox(hwnd,"Cannot create the main window","ERORR",MB_ICONWARNING);
		return;
	}
	
	hModule = LoadLibrary("WallpaperCore.dll");
	if(hModule){
		GetString4ThisLang = (GS4TL)GetProcAddress(hModule,"GetString4ThisLang");
		if(!GetString4ThisLang){
			MessageBox(NULL,"Load function \"GetString4ThisLang\" failed!","System error.",MB_ICONERROR|MB_OK);
			return ;
		}
	} 
	else{
		MessageBox(NULL,"Load library \"WallpaperCore.dll\" failed!","System error.",MB_ICONERROR|MB_OK);
		return ;
	}
	
	EnableWindow(hwnd,false);
	char ConfigFile[114514];
	GetModuleFileName(NULL,ConfigFile,114510);
	for(int i=strlen(ConfigFile)-1;ConfigFile[i]!='\\';i--) ConfigFile[i]='\0';
	strcat(ConfigFile,"Config.ini");
	LOGFONTA lf;
	lf.lfCharSet=GetPrivateProfileInt("Font","lfCharSet",0,ConfigFile);
	lf.lfClipPrecision=GetPrivateProfileInt("Font","lfClipPrecision",0,ConfigFile);
	lf.lfEscapement=GetPrivateProfileInt("Font","lfEscapement",0,ConfigFile);
	GetPrivateProfileString("Font","lfFaceName",NULL,lf.lfFaceName,24,ConfigFile);
	lf.lfHeight=GetPrivateProfileInt("Font","lfHeight",0,ConfigFile);
	lf.lfItalic=GetPrivateProfileInt("Font","lfItalic",0,ConfigFile);
	lf.lfOrientation=GetPrivateProfileInt("Font","lfOrientation",0,ConfigFile);
	lf.lfOutPrecision=GetPrivateProfileInt("Font","lfOutPrecision",0,ConfigFile);
	lf.lfPitchAndFamily=GetPrivateProfileInt("Font","lfPitchAndFamily",0,ConfigFile);
	lf.lfQuality=GetPrivateProfileInt("Font","lfQuality",0,ConfigFile);
	lf.lfStrikeOut=GetPrivateProfileInt("Font","lfStrikeOut",0,ConfigFile);
	lf.lfUnderline=GetPrivateProfileInt("Font","lfUnderline",0,ConfigFile);
	lf.lfWeight=GetPrivateProfileInt("Font","lfWeight",0,ConfigFile);
	lf.lfWidth=GetPrivateProfileInt("Font","lfWidth",0,ConfigFile);
	hFont=CreateFont(lf.lfHeight,lf.lfWidth,
		lf.lfEscapement,
		lf.lfOrientation,
		lf.lfWeight,
		lf.lfItalic,
		lf.lfUnderline,
		lf.lfStrikeOut,
		lf.lfCharSet,
		lf.lfOutPrecision,
		lf.lfClipPrecision,
		lf.lfQuality,
		lf.lfPitchAndFamily,
		lf.lfFaceName
	);
	SendMessage(CreateWindow("EDIT",NULL,WS_CHILD|WS_VISIBLE|ES_NOHIDESEL|WS_VSCROLL|WS_BORDER|ES_MULTILINE|ES_READONLY,200,0,1140,700,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON",GetString4ThisLang(88),WS_CHILD|WS_VISIBLE,20,20,150,30,hWnd,(HMENU)1,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON",GetString4ThisLang(89),WS_CHILD|WS_VISIBLE,20,60,150,30,hWnd,(HMENU)2,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON",GetString4ThisLang(90),WS_CHILD|WS_VISIBLE,20,100,150,30,hWnd,(HMENU)3,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON",GetString4ThisLang(91),WS_CHILD|WS_VISIBLE,20,140,150,30,hWnd,(HMENU)4,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON",GetString4ThisLang(92),WS_CHILD|WS_VISIBLE,20,180,150,30,hWnd,(HMENU)5,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON",GetString4ThisLang(93),WS_CHILD|WS_VISIBLE,20,220,150,30,hWnd,(HMENU)6,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON",GetString4ThisLang(94),WS_CHILD|WS_VISIBLE,20,260,150,30,hWnd,(HMENU)7,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	
	hModule=LoadLibrary("uxtheme.dll");
	if(hModule){
		SWT SetWindowTheme=(SWT)GetProcAddress(hModule,"SetWindowTheme");
		if(SetWindowTheme){
			for(int i=1;i<=7;i++){
				HWND hTmp;
				hTmp=GetDlgItem(hWnd,i);
				if(hTmp) SetWindowTheme(hTmp,L"DarkMode_Explorer",NULL);
			}
			SetWindowTheme(FindWindowEx(hWnd,NULL,"EDIT",NULL),L"DarkMode_Explorer",NULL);
		}
	}
	
	hModule=LoadLibrary("dwmapi.dll");
	if(hModule){
		bool Dark=true;
		DSWA DwmSetWindowAttribute=(DSWA)GetProcAddress(hModule,"DwmSetWindowAttribute");
		if(DwmSetWindowAttribute) DwmSetWindowAttribute(hWnd, 20,  &Dark, 4);
	}
	
	ShowWindow(hWnd,SW_SHOW);
	UpdateWindow(hWnd);
	while(GetMessage(&msg, NULL, 0, 0) > 0){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	EnableWindow(hwnd,true);
	return;
}
DWORD WINAPI FindWindowProcess(LPVOID lparam){
	HWND hWND=(HWND)lparam;
	//MessageBox(NULL,NULL,NULL,NULL);
	SendDlgItemMessage(hWND,1,BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(GetModuleHandle(0),"IDI_SELECTUSING"));
	ChooseWindow=0;
	POINT cur;
	//HCURSOR hCursor=LoadCursor(GetModuleHandle(0),"IDC_SELECTCURSOR");
	HWND Find;
	RECT rect,DRect;
	char str[1145];
	//HBRUSH GBrush=CreateSolidBrush(RGB(0,255,0));
	while(key_press('S')&&key_press('C')&&(key_press(VK_LCONTROL)||key_press(VK_RCONTROL))){
        //SetCursor(hCursor);
		GetCursorPos(&cur);
		Find=WindowFromPoint(cur);
		if(Find!=ChooseWindow){
			if(ChooseWindow){
				GetWindowRect(ChooseWindow,&rect);
				BitBlt(hdc,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,hdc,rect.left,rect.top,DSTINVERT);
			}
			ChooseWindow=Find;
			GetWindowRect(ChooseWindow,&rect);
			BitBlt(hdc,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,hdc,rect.left,rect.top,DSTINVERT);
			char Text[1145];
			GetWindowText(ChooseWindow,Text,GetWindowTextLength(ChooseWindow)+1);
			SetDlgItemText(hWND,IDC_TEXT,Text);
			GetClassName(ChooseWindow,Text,sizeof(Text));
			SetDlgItemText(hWND,IDC_CLSNAME,Text);
			sprintf(Text,"0x%p",GetParent(Find));
			SetDlgItemText(hWND,IDC_PARENT,Text);
			
			RECT rect;
			GetWindowRect(Find,&rect);
			sprintf(Text,"left:%d top:%d bottom:%d right:%d",rect.left,rect.top,rect.bottom,rect.right);
			SetDlgItemText(hWND,IDC_WNDBOX,Text);
			
			sprintf(Text,"0x%p",Find);
			SetDlgItemText(hWND,IDC_HANDLE,Text);
			sprintf(Text,"0x%p",GetWindowLong(Find,GWL_STYLE));
			SetDlgItemText(hWND,IDC_STYLE,Text);
			sprintf(Text,"0x%p",GetWindowLong(Find,GWL_EXSTYLE));
			SetDlgItemText(hWND,IDC_EXSTYLE,Text);
			sprintf(Text,"0x%p",GetClassLong(Find,GCL_STYLE));
			SetDlgItemText(hWND,IDC_CLSSYE,Text);
			sprintf(Text,"0x%p",GetClassLong(Find,GCL_HCURSOR));
			SetDlgItemText(hWND,IDC_HCURSOR,Text);
			DWORD dw;
			GetWindowThreadProcessId(Find,&dw);
			sprintf(Text,"0x%p",dw);
			SetDlgItemText(hWND,IDC_PROCESSID,Text);
		}
	}
	SendDlgItemMessage(hWND,1,BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(GetModuleHandle(0),"IDI_SELECTUNUSE"));
} 

LRESULT CALLBACK WWatcherProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam){
	switch(msg){
		case WM_CREATE:{
			SendMessage(CreateWindowEx(0,"BUTTON",NULL,WS_CHILD|WS_VISIBLE|BS_ICON,50,50,70,70,hWnd,(HMENU)IDC_SLTBTN,NULL,NULL),BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(GetModuleHandle(0),"IDI_SELECTUNUSE"));
			SendMessage(CreateWindowEx(0,"STATIC","使用窗口选择器时按住Ctrl+C+S不放即可选择窗口，松开即选中该窗口",WS_CHILD|WS_VISIBLE,150,70,600,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","窗口标题：",WS_CHILD|WS_VISIBLE,50,140,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","窗口类名：",WS_CHILD|WS_VISIBLE,50,170,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","父窗口：",WS_CHILD|WS_VISIBLE,50,200,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","窗口句柄：",WS_CHILD|WS_VISIBLE,50,230,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","高宽左顶：",WS_CHILD|WS_VISIBLE,50,260,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","窗口样式：",WS_CHILD|WS_VISIBLE,50,290,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","扩展样式：",WS_CHILD|WS_VISIBLE,50,310,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","类样式：",WS_CHILD|WS_VISIBLE,50,340,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","光标句柄：",WS_CHILD|WS_VISIBLE,50,370,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","进程ID：",WS_CHILD|WS_VISIBLE,50,400,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			
			SendMessage(CreateWindowEx(0,"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_READONLY,180,140,750,25,hWnd,(HMENU)IDC_TEXT,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_READONLY,180,170,750,25,hWnd,(HMENU)IDC_CLSNAME,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_READONLY,180,200,750,25,hWnd,(HMENU)IDC_PARENT,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_READONLY,180,230,750,25,hWnd,(HMENU)IDC_HANDLE,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_READONLY,180,260,750,25,hWnd,(HMENU)IDC_WNDBOX,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_READONLY,180,290,750,25,hWnd,(HMENU)IDC_STYLE,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_READONLY,180,310,750,25,hWnd,(HMENU)IDC_EXSTYLE,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_READONLY,180,340,750,25,hWnd,(HMENU)IDC_CLSSYE,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_READONLY,180,370,750,25,hWnd,(HMENU)IDC_HCURSOR,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"EDIT",NULL,WS_CHILD|WS_VISIBLE|WS_BORDER|ES_READONLY,180,400,750,25,hWnd,(HMENU)IDC_PROCESSID,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON","启动窗口信息监听器（未使用）",WS_CHILD|WS_VISIBLE,710,80,215,40,hWnd,(HMENU)IDC_MSGWTR,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON","隐藏窗口",WS_CHILD|WS_VISIBLE,500,80,215,20,hWnd,(HMENU)13,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON","显示窗口",WS_CHILD|WS_VISIBLE,600,100,215,20,hWnd,(HMENU)14,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			
			HWND hTmp;
			HMODULE hModule=LoadLibrary("uxtheme.dll");
			if(hModule){
				typedef VOID (*SWT)(HWND,LPCWSTR,LPCWSTR);
				SWT SetWindowTheme1=(SWT)GetProcAddress(hModule,"SetWindowTheme");
				if(SetWindowTheme1){
					for(int i=12;i<=14;i++){
						hTmp=GetDlgItem(hWnd,i);
						if(hTmp) SetWindowTheme1(hTmp,L"DarkMode_Explorer",NULL);
					}
					hTmp=GetDlgItem(hWnd,1);
					if(hTmp) SetWindowTheme1(hTmp,L"DarkMode_Explorer",NULL);
				}
			}/*
			hModule=LoadLibrary("dwmapi.dll");
			if(hModule){
				bool Dark=true;
				DSWA DwmSetWindowAttribute1=(DSWA)GetProcAddress(hModule,"DwmSetWindowAttribute");
				if(DwmSetWindowAttribute1) DwmSetWindowAttribute1(hWnd, 20,  &Dark, 4);
			}*///If I enable this code, the progam will stop running.
			//SendDlgItemMessage(hWND,0,WM_SETFONT,(WPARAM)hFont1,NULL);
			break;
		}
		case WM_COMMAND:{
			switch(LOWORD(wParam)){
				case IDC_SLTBTN:{
					CreateThread(NULL,NULL,FindWindowProcess,hWnd,NULL,NULL); 
					break;
				}
				case IDC_MSGWTR:{
					
					break;
				}
				case 13:{
					ShowWindow(ChooseWindow,SW_HIDE);
					break;
				}
				case 14:{
					ShowWindow(ChooseWindow,SW_SHOW);
					break;
				}
			}
			break;
		}
		case WM_CLOSE:
		case WM_DESTROY:{
			PostQuitMessage(0); 
			ShowWindow(hWnd,SW_HIDE); 
			return 0;
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
		default:return DefWindowProc(hWnd,msg,wParam,lParam);
	}
}

extern "C" DLLIMPORT void WinWatcher(){
	HMODULE hModule = LoadLibrary("user32.dll");
	if(hModule){
		SetProcessDPIAwarev = (SPDA)GetProcAddress(hModule,"SetProcessDPIAware");
		if(SetProcessDPIAwarev) SetProcessDPIAwarev();//清晰！！！
	}
	hFont1=CreateFont(18, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("黑体细体"));
	WNDCLASSEX wcexWW;
	memset(&wcexWW,0,sizeof(wcexWW));
	wcexWW.cbSize=sizeof(wcexWW);
	wcexWW.hInstance=hinst;
	wcexWW.hbrBackground=CreateSolidBrush(RGB(25,25,25));
	wcexWW.hCursor=LoadCursor(NULL,IDC_ARROW);
	//wcexWW.hIcon=wcexWW.hIconSm=LoadIcon(wcexWW.hInstance,"IDI_WINWATCHER");
	wcexWW.hIcon=wcexWW.hIconSm=LoadIcon(NULL,IDI_APPLICATION);
	wcexWW.lpszClassName="WinWatcher";
	wcexWW.style=CS_DBLCLKS|CS_SAVEBITS|CS_GLOBALCLASS;
	wcexWW.lpfnWndProc=WWatcherProc;
	RegisterClassEx(&wcexWW);
	
	char ConfigFile[114514];
	GetModuleFileName(NULL,ConfigFile,114510);
	for(int i=strlen(ConfigFile)-1;ConfigFile[i]!='\\';i--) ConfigFile[i]='\0';
	strcat(ConfigFile,"Config.ini");
	LOGFONTA lf;
	lf.lfCharSet=GetPrivateProfileInt("Font","lfCharSet",0,ConfigFile);
	lf.lfClipPrecision=GetPrivateProfileInt("Font","lfClipPrecision",0,ConfigFile);
	lf.lfEscapement=GetPrivateProfileInt("Font","lfEscapement",0,ConfigFile);
	GetPrivateProfileString("Font","lfFaceName",NULL,lf.lfFaceName,24,ConfigFile);
	lf.lfHeight=GetPrivateProfileInt("Font","lfHeight",0,ConfigFile);
	lf.lfItalic=GetPrivateProfileInt("Font","lfItalic",0,ConfigFile);
	lf.lfOrientation=GetPrivateProfileInt("Font","lfOrientation",0,ConfigFile);
	lf.lfOutPrecision=GetPrivateProfileInt("Font","lfOutPrecision",0,ConfigFile);
	lf.lfPitchAndFamily=GetPrivateProfileInt("Font","lfPitchAndFamily",0,ConfigFile);
	lf.lfQuality=GetPrivateProfileInt("Font","lfQuality",0,ConfigFile);
	lf.lfStrikeOut=GetPrivateProfileInt("Font","lfStrikeOut",0,ConfigFile);
	lf.lfUnderline=GetPrivateProfileInt("Font","lfUnderline",0,ConfigFile);
	lf.lfWeight=GetPrivateProfileInt("Font","lfWeight",0,ConfigFile);
	lf.lfWidth=GetPrivateProfileInt("Font","lfWidth",0,ConfigFile);
	hFont1=CreateFont(lf.lfHeight,lf.lfWidth,
		lf.lfEscapement,
		lf.lfOrientation,
		lf.lfWeight,
		lf.lfItalic,
		lf.lfUnderline,
		lf.lfStrikeOut,
		lf.lfCharSet,
		lf.lfOutPrecision,
		lf.lfClipPrecision,
		lf.lfQuality,
		lf.lfPitchAndFamily,
		lf.lfFaceName
	);
	hWND=CreateWindowEx(0,"WinWatcher","DWPT - WinWatcher",WS_VISIBLE|WS_SYSMENU|WS_CAPTION|WS_MINIMIZEBOX,CW_USEDEFAULT,CW_USEDEFAULT,1000,500,NULL,NULL,NULL,NULL);
	if(!hWND){
		MessageBox(NULL,"Cannot create the main window","ERORR",MB_ICONWARNING);
		return;
	}
	
	MSG msg;
	ShowWindow(hWND,SW_SHOW);
	UpdateWindow(hWND);
	while(GetMessage(&msg, NULL, 0, 0) > 0){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	//EnableWindow(hwnd,true);
	return;
}

extern "C" DLLIMPORT bool GetPerm(short Type){
	return 1;//空函数，未被使用 
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL,DWORD fdwReason,LPVOID lpvReserved)
{
	hinst=hinstDLL;
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
