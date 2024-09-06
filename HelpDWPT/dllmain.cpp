/*
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS HEADER.
 * 
 * Copyright 2024 Office-Excel, 13392621401@189.cn
 * 
 * This file is a part of DWPT.
 * DWPT is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 * 
 * DWPT is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public License
 * along with DWPT.  If not, see <http://www.gnu.org/licenses/>.
 * 
 * ����ļ���DWPT��һ���֡�
 * �����Ե���ʹ�û�ַ�����ļ������벻Ҫ�Ƴ����ͷ��������Ϣ.
 * DWPT��һ��������������������ɷַ����޸����е�Դ����������·�������
 * �µ��κ��޸ĺ�����·��������ͬ��������LGPL3��������İ汾Э���·���.
 * ����LGPLЭ���ϸ����ο�COPYING��COPYING.LESSER�ļ���
 * ��������DWPT�����Ŀ¼�л��LGPLЭ��ĸ�����
 * ���û���ҵ��������ӵ� http://www.gnu.org/licenses/ �鿴��
 * 
 *  - Author: Office-Excel
 *  - Email Address: 13392621401@189.cn
 *  - License: GNU Lesser General Public License (LGPL)
*/

/* Replace "dll.h" with the name of your header */
#include <windows.h>
#include <stdio.h>
#include "dll.h"
#define key_press(key) ((GetAsyncKeyState(key)&0x8000)?1:0)//���尴����⺯�� 
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
//HFONT hFont = CreateFont(25, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("˼Դ"));//Ĭ������ 
HWND hWND,ChooseWindow;
HDC hdc=GetDC(0);
HFONT hFont1;
HINSTANCE hinst;
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
					//LoadString(hinst,)
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),"DWPT���ŵ㣺\n\r1.���\r\n\
    DWPT��Windows7���ϵİ汾�г���WinAPI�Ŀ��HelpDWPT.dll������Ҫ���������Ӱ˵Ŀ⣬��DWPT���������200��KiB��������iostream��дһ��Hello World��������ĳ���С�����Ҳ�����Visual C++���п�\r\n\
2.������\r\n\
    DWPT���û��������ҽ���1��ѡ��ؼ���1����Ͽ�ؼ���GroupBox����1��HotKey�ؼ���5����̬�ı��ؼ���2������5�����ڣ�Tab Control�����þ����˱���������10����ť����û���κεĹ�棬Ҳ��������ĵ��Ա����俨������Ҫʱ�����Խ�����ͼ�����ص�ϵͳ�����У�ʮ�����Ի�\r\n\
\r\n3.���õ�֧����\r\n\
    DWPT����Ƶ���Ź�����mshta.exe��Microsoft HTMLӦ�ó��򣩣���Ҫ����Ϊʲô��Ҫ���������Ϊ�Ҳ���д����������������ffplay.exe��ԭ����ffplay.exeȷʵ��̫���ˣ�100��MiB����������Ҫ�󣬲�����ѡ����32λ���룬����������x86��WindowsҲ����\r\n\
\r\n���ԣ������Ҫѡ��һ����㡢�򵥡��޹��Ķ�̬��ֽ�������ѡDWPT�ɣ� \
");
					break;
				}
				case 2:{
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),"DWPT�Ĵ򿪷����ܼ򵥣���һ�����򿪳��򣬵ڶ������������ԱȨ�ޣ����ģ����������Ը�ʲô�����˱��޸Ĺ��ģ�\r\n\
һ.���������̬��ֽ��\r\n\
 1.���\"���������ļ�\"��ť\r\n\
 2.ѡ��һ������λ�ã��ǵ����뱣����ļ����ƣ�\r\n\
 3.ѡ�����һ����Ƶ���ǵõ���Ǹ���Ƶһ���������ڱ�ѡ��״̬\r\n\
 4.ѯ�����Ƿ���Ҫ����������Ե��\"��\"����\"��\"�����û���������\r\n\
 5.����������ļ��ʹ�������ˣ�������ڽ������ĵ��\"��\"������ʹ����������ļ������ߵ��\"��\"������ļ��ȷ���\r\n\r\n\
��.���ϴδ����������ļ��ˣ����ʹ���ϴε����ã�\r\n\
 1.���\"�������ļ�\"��ť\r\n\
 2.ѡ�����ϴδ����������ļ�\r\n\
 3.�ڵ����������Ƿ���������ʱ����ȷ�����Ƿ��������ĺ�DWPT�޹ص�mshta.exe���������У����û�о͵�\"��\"���еĻ���ȥ�����ز���Ҫ������Ҫ�ľ͹��ˣ��������Ҫ�ľ��ȱ�\r\n\r\n\
��.�����޸������ļ���������ô�죺\r\n\
 1.���\"�޸������ļ�\"��ť\r\n\
 2.ѡ����������ļ�\r\n\
 3.���뵽�༭ҳ�棬���ʱ����Ϳ��Կ�ʼ�޸��ˣ����Ե��\"��\"��\"��\"���޸ģ�\"ȡ��\"����ֹͣ�޸�\r\n\
 4.����������ֱ���޸����\r\n\
 5.ѡ���Ƿ񱣴�\r\n\
 6.��ɣ�\r\n\r\n\
��.�Ҳ�������Ҫͣ����ô�죺\r\n\
 1.ȷ����ĵ�����û����DWPT����ɵ�mshta.exe������\r\n\
 2.���\"ֹͣ��̬��ֽ\"\r\n\
 3.���ȷ�ϲ��ڵ����Ŀ��ѡ\"��\"������ֹͣ��̬��ֽ\r\n\r\n\
��.��� ����\\�޸� Ĭ�����λ�ã�\r\n\
 1.���\"ȫ������\"\r\n\
 2.���\"�༭\"��ѡ����Ҫ����ΪĬ����������ļ������ȷ������\r\n\r\n\
��.����Ҫ������������̬��ֽ��ô�죺\r\n\
 1.��ȷ�����Ѿ�������Ĭ������û���뿴\"��\"\r\n\
 2.���\"ȫ������\"\r\n\
 3.ѡ��\"����������\"���򼴿�\r\n\
");
					break;
				}
				case 3:{
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),"���� & �ش�\n\r�ʣ�Ϊʲô�㲻��CLR�������ڣ�\r\n\
����ΪҪ�չ�һЩװ����Visual C++���п��������Ⱥ������She_Fa21�������ѣ��������װVC����ʾ��dll������gcc����ĸ�С\r\n\r\n\
�ʣ��㴴�������Ĵ��ںͿؼ�Ϊʲô����Win11��ʽ����DPI������������Ҳ��У�\r\n\
�����������Ҳ������Ҵ����ϴ����Ѽ�������ʵ���˺ܾò���ĥ�����ַ����������������⣬�������½��������\r\n\
    ���ڿؼ��Ǿɰ�����⣺\r\n\
        Visual Studio:����ǰ��������´��룺\r\n\
            #ifdef _UNICODE\r\n\
            #if defined _M_IX86\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #elif defined _M_X64\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #else\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #endif\r\n\
            #endif\r\n\
        Dev-C++:�����Visual Studio��˵��Dev�Ĳ������򵥣��� ��Ŀ[P]->��Ŀ����[O] ���湴ѡ��\"֧�� Windows XP ����\"����\r\n\
    ����DPI��ʾ����ȷ�����⣺\r\n\
        Visual Studio:ֱ���ڳ�����ʼ�ĵط����ϴ��룺SetProcessDPIAware();\r\n\
        Dev-C++:���ڳ�����ʼ�ĵط��������´��룺\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID);\r\n\
            SPDA SetProcessDPIAware;\r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\");\r\n\
            SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");\r\n\
            if(SetProcessDPIAware) SetProcessDPIAware();\r\n\
            //�Ҳ�֪��Ϊʲô������Dev-C++�Դ���gcc�Ŀ�����û��������������������û�У�\r\n\
    �����ͽ������\r\n\
�ʣ�������ִ�������ʧ�ܡ�������ע��ʧ��֮��ĸ���ô�죿\r\n\
���볢���������ر�����������ǲ��У����Ҿ�û�취��\r\n\
�ʣ�Ϊʲô������ô��\r\n\
����д����ʱǶ�����\"����ϸ��\"��\"˼Դ\"���������壬������������֣���Ҳ�����ȥ������������һ�����������壬������CreateFont����ģ����Կ���ȥ����Microsoft�����ĵ������CreateFont����");
					break;
				}
				case 4:{
					SetWindowText(FindWindowEx(hWnd,NULL,"EDIT",NULL),"����DWPT��\n\r���ߡ�������ƣ�Office-Excel\r\n\
�ο���Ƶ������������Ƶ��ţ���BV1HZ4y1978a����ַ��https://www.bilibili.com/video/BV1HZ4y1978a/\r\n\
ʹ�õĴ���༭���ߣ�Dev-C++ ʹ�õĴ������ԣ�C++ �õ����Ŀ⣺windows.h\r\n\
���ڴ�����Windows API��������Դ�ļ���ĶԻ�����Ϊ�Ҳ����ã�\r\n\
DWPT��Ŀ���ԣ�\r\n\
    ���ƣ�DWPT��ȫ��Dynamic Wallpaper Tools�����룺��̬��ֽ���ߣ�\r\n\
    ��Ŀ��ʼ���ڣ�2024/04/21\r\n\
    ��ĿĿ�꣺��һ�������򵥵Ķ�̬��ֽ����\r\n\
    ����ΪʲôҪ����������⣺ֻ��Ϊ�˺������д��600���еĴ���\r\n\
    dp�ļ��ṹ��\r\n\
        ������ü��±���dp�ļ�\r\n\
            ��ᷢ�ֵ�һ���ַ�����'t'����'f'����������Ƿ�����������f=�����ã�t=����\r\n\
            �����������Ƶ�ľ���·�����ı�����˵Ӧ����ʹ��GBK����洢�ģ�����֧������\r\n\
\r\n\
    DWPT������̬��ֽ��ԭ��\r\n\
        1.�����ļ�\r\n\
        2.�鿴�Ƿ���������\r\n\
        3.����Ƶ����·������VP��char���飩\r\n\
        4.ƴ��Ԥ����ı���д��%temp%\\Temporary.hta�ļ�\r\n\
        5.��������mshta.exe\r\n\
        6.������ΪProgman�Ĵ��ڷ���0x52C�ź�\r\n\
        7.�ҵ��ڶ���WorkerW���ڲ�������\r\n\
        8.������ΪProgman�Ĵ�������Ϊmshta.exe���ڵĸ�����\r\n\
        9.��ɣ�\r\n\r\n\
���ߵ����������˺ţ�Office-Excel����ַ��https://space.bilibili.com/1439352366/��\r\n\
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

extern "C" DLLIMPORT DWORD WINAPI KeyWatchThread(LPVOID lparam){
	
}

extern "C" DLLIMPORT void HelpWindow(HWND hwnd){
	HFONT hFont;
	hFont=CreateFont(18, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("����ϸ��"));
	
	HMODULE hModule = LoadLibrary("user32.dll");
	SetProcessDPIAwarev = (SPDA)GetProcAddress(hModule,"SetProcessDPIAware");
	SetProcessDPIAwarev();//����������
	
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
	wcex.hbrBackground=(HBRUSH)(COLOR_BTNFACE+1);
	wcex.hCursor=LoadCursor(NULL,IDC_ARROW);
	RegisterClassEx(&wcex);
	
	HWND hWnd=CreateWindowEx(WS_EX_ACCEPTFILES, "Help_DWPT", "How to use Dynamic Wallpaper Tools?",
		WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | DS_FIXEDSYS | DS_3DLOOK | DS_SETFONT | DS_MODALFRAME | DS_NOIDLEMSG,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		1400, /* width */
		750/*60*/, /* height */
		hwnd, NULL, wcex.hInstance, NULL);//�������� 
	
	if(!hWnd){
		MessageBox(hwnd,"Cannot create the main window","ERORR",MB_ICONWARNING);
		return;
	}
	
	EnableWindow(hwnd,false);
	SendMessage(CreateWindow("EDIT",NULL,WS_CHILD|WS_VISIBLE|ES_NOHIDESEL|ES_AUTOVSCROLL|WS_BORDER|ES_MULTILINE|ES_READONLY,200,0,1190,780,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","Ϊʲôѡ������",WS_CHILD|WS_VISIBLE,20,20,150,30,hWnd,(HMENU)1,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","�����",WS_CHILD|WS_VISIBLE,20,60,150,30,hWnd,(HMENU)2,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","���� && �ش�",WS_CHILD|WS_VISIBLE,20,100,150,30,hWnd,(HMENU)3,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","����DWPT",WS_CHILD|WS_VISIBLE,20,140,150,30,hWnd,(HMENU)4,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","��������ҳ",WS_CHILD|WS_VISIBLE,20,180,150,30,hWnd,(HMENU)5,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","�򿪲ο���Ƶ",WS_CHILD|WS_VISIBLE,20,220,150,30,hWnd,(HMENU)6,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","�ر�",WS_CHILD|WS_VISIBLE,20,260,150,30,hWnd,(HMENU)7,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	
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
			SendMessage(CreateWindowEx(0,"STATIC","ʹ�ô���ѡ����ʱ��סCtrl+C+S���ż���ѡ�񴰿ڣ��ɿ���ѡ�иô���",WS_CHILD|WS_VISIBLE,150,70,600,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","���ڱ��⣺",WS_CHILD|WS_VISIBLE,50,140,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","����������",WS_CHILD|WS_VISIBLE,50,170,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","�����ڣ�",WS_CHILD|WS_VISIBLE,50,200,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","���ھ����",WS_CHILD|WS_VISIBLE,50,230,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","�߿��󶥣�",WS_CHILD|WS_VISIBLE,50,260,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","������ʽ��",WS_CHILD|WS_VISIBLE,50,290,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","��չ��ʽ��",WS_CHILD|WS_VISIBLE,50,310,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","����ʽ��",WS_CHILD|WS_VISIBLE,50,340,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","�������",WS_CHILD|WS_VISIBLE,50,370,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"STATIC","����ID��",WS_CHILD|WS_VISIBLE,50,400,120,25,hWnd,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			
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
			SendMessage(CreateWindowEx(0,"BUTTON","����������Ϣ��������δʹ�ã�",WS_CHILD|WS_VISIBLE,710,80,215,40,hWnd,(HMENU)IDC_MSGWTR,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON","���ش���",WS_CHILD|WS_VISIBLE,500,80,215,20,hWnd,(HMENU)13,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON","��ʾ����",WS_CHILD|WS_VISIBLE,600,100,215,20,hWnd,(HMENU)14,NULL,NULL),WM_SETFONT,(WPARAM)hFont1,NULL);
			
			//SendDlgItemMessage(hWND,0,WM_SETFONT,(WPARAM)hFont1,NULL);
			break;
		}
		case WM_COMMAND:{
			switch(LOWORD(wParam)){
				case IDC_SLTBTN:{
					CreateThread(NULL,NULL,FindWindowProcess,NULL,NULL,NULL); 
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
		default:return DefWindowProc(hWnd,msg,wParam,lParam);
	}
}

extern "C" DLLIMPORT void WinWatcher(){
	HMODULE hModule = LoadLibrary("user32.dll");
	if(hModule){
		SetProcessDPIAwarev = (SPDA)GetProcAddress(hModule,"SetProcessDPIAware");
		if(SetProcessDPIAwarev) SetProcessDPIAwarev();//����������
	}
	hFont1=CreateFont(18, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("����ϸ��"));
	WNDCLASSEX wcexWW;
	memset(&wcexWW,0,sizeof(wcexWW));
	wcexWW.cbSize=sizeof(wcexWW);
	wcexWW.hInstance=hinst;
	wcexWW.hbrBackground=(HBRUSH)(COLOR_BTNFACE+1);
	wcexWW.hCursor=LoadCursor(NULL,IDC_ARROW);
	wcexWW.hIcon=wcexWW.hIconSm=LoadIcon(wcexWW.hInstance,"IDI_WINWATCHER");
	wcexWW.lpszClassName="WinWatcher";
	wcexWW.style=CS_DBLCLKS|CS_SAVEBITS|CS_GLOBALCLASS;
	wcexWW.lpfnWndProc=WWatcherProc;
	RegisterClassEx(&wcexWW);
	
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
	return 1;//�պ�����δ��ʹ�� 
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
