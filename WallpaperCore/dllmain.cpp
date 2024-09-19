/* Replace "dll.h" with the name of your header */
#include "dll.h"
char Path[114514],res[114514];
int LangID=IL_UNSET/*语言ID*/;
bool quietMode=false;//是否启用安静模式（在启动dp文件中） 
extern "C"{
	DLLIMPORT char* GetString4ThisLang(UINT index){
		if(LangID==IL_UNSET){
			switch(PRIMARYLANGID(GetUserDefaultLangID())){//获取语言ID并设置当前语言 
				case LANG_CHINESE_SIMPLIFIED:LangID=IL_Simplified_Chinese;break;
				case LANG_CHINESE_TRADITIONAL:LangID=IL_Traditional_Chinese;break;
				default:LangID=IL_ENGLISH;break;
			}
		}
		return MUIText[index][LangID];
	}
	
	DLLIMPORT BOOL CALLBACK StopDWPProc(_In_ HWND hWnd,_In_ LPARAM lparam){//停止动态壁纸的回调函数（Enum遍历） 
		char Text[1145];
		GetClassName(hWnd,Text,sizeof(Text));
		//GetWindowText(hWnd,Text,GetWindowTextLength(hWnd)+1);
		if(strcmp(Text,"HTML Application Host Window Class")==0) PostMessage(hWnd,WM_CLOSE,0,0);
		return FALSE;
	}
	
	DLLIMPORT BOOL CALLBACK EnumWindowProc(_In_ HWND hwnd, _In_ LPARAM Lparam)//核心！！！动态壁纸的嵌入窗口过程 
	{
	    HWND hDefView = FindWindowEx(hwnd, 0, "SHELLDLL_DefView", 0);
	    if (hDefView != 0) {
	        HWND hWorkerw = FindWindowEx(0, hwnd, "WorkerW", 0);
	        HWND SCREEN = FindWindowEx(hWorkerw,0,"SysListView32",0);
	        ShowWindow(hWorkerw, SW_HIDE);
	        return FALSE;
	    }
	    return TRUE;
	}
	
	DLLIMPORT WINBOOL PutToDesktop(HWND Wallpaper){//将Wallpaper窗口放进桌面里 
		if(!Wallpaper){//...
			MessageBox(Wallpaper,"将桌面放进桌面里？你在这套娃呢","Error",MB_ICONINFORMATION|MB_OK);
			return FALSE;
		}
		int width=GetDeviceCaps(GetDC(0), DESKTOPHORZRES),height=GetDeviceCaps(GetDC(0), DESKTOPVERTRES);//获取屏幕设备分辨率 
		HWND hProgman = FindWindow("Progman", 0), hFfplay = Wallpaper;
		SendMessageTimeout(hProgman, 0x52C, 0, 0, 0, 100, 0);//延时发送消息 
		SetWindowPos(hFfplay, NULL, 0, 0, width, height, SWP_NOZORDER);//设置窗口大小和位置 
		SetParent(hFfplay, hProgman);//设置父窗口 
		EnumWindows(EnumWindowProc, 0);//将这个窗口放到桌面的后边 
	    //Shell_NotifyIcon(NIM_SETVERSION, &nid);//Toast Message Box
		return TRUE;
	}
	
	DLLIMPORT DWORD WINAPI DwpThread(LPVOID lparam){//核心线程 
		if((!quietMode)&&MessageBox(NULL,GetString4ThisLang(6),"Warning",MB_YESNO|MB_ICONWARNING)!=6) return 0; //警告 
		char cmd[1145]=" \"",sound,VP[1145],TmpPath[MAX_PATH+20],str1[MAX_PATH*4];//初始化一堆文本 
		STARTUPINFO si = {0};
		PROCESS_INFORMATION pi = {0};//设置启动进程的结构体 
		HWND PROGMAN=FindWindow("Progman", 0);
		if(PROGMAN) EnumChildWindows(PROGMAN,StopDWPProc,NULL);
		
		/*SHELLEXECUTEINFO sei = {0};
	    sei.cbSize = sizeof(SHELLEXECUTEINFO);
	    sei.fMask = SEE_MASK_NOCLOSEPROCESS;
	    sei.lpFile = "taskkill.exe";
	    sei.nShow = SW_HIDE;
	    sei.lpParameters = "/F /IM mshta.exe";
	    if (ShellExecuteEx(&sei)) CloseHandle(sei.hProcess);//启动并结束mshta.exe */
	    
		strcpy(str1,"<html>\
	<META http-equiv=\"content-type\" content=\"text/html; charset=GBK\">\
	<meta http-equiv=\"x-ua-compatible\" content=\"IE=9\"/>\
	<head><title>VideoPlayer</title><HTA:APPLICATION APPLICATIONNAME=\"VideoPlayer\"ID=\"VideoPlayer\" BORDER=\"none\" SHOWINTASKBAR=\"no\" VERSION=\"0.0\"/></head>\
	<body><video style=\"width:100%;height:100%;left:0px;top:0px;position:fixed\" autoplay loop");//设置文本 
		Sleep(500);
		
		DWORD dw=0;
		HANDLE hFile=CreateFile(Path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);//打开文件句柄 
		ReadFile(hFile,&sound,1,&dw,NULL);
		ReadFile(hFile,VP,GetFileSize(hFile,NULL)-1,&dw,NULL);
		int i=strlen(VP);
		while(!(VP[i]<='Z'&&VP[i]>='A'||VP[i]<='z'&&VP[i]>='a'||VP[i]<='9'&&VP[i]>='0')) VP[i]=NULL,i--;//读入文件的数据 
		
		//使用mshta.exe播放
		GetTempPath(MAX_PATH,TmpPath);//获取临时目录并创建Temporary.hta临时文件 
		strcat(TmpPath,"Temporary.hta");
		if(TmpPath[strlen(TmpPath)-1]=='\r') TmpPath[strlen(TmpPath)-1]=NULL;
		freopen(TmpPath,"w",stdout);
		while(_access(VP,0)==-1) VP[strlen(VP)-1]=NULL;
		printf("%s%s><source src=\"%s",str1,(sound=='t'?"":" muted"),VP);
		strcpy(str1,"\" type=\"video/mp4\">ERROR</video></body></html>");
		printf("%s",str1);
		fclose(stdout);//退出写入 
		
		memset(&si,NULL,sizeof si);
		memset(&pi,NULL,sizeof pi);
	    strcat(cmd,TmpPath);
	    strcat(cmd,"\"");
	    GetSystemDirectory(str1,MAX_PATH);//获取系统的目录（System32） 
	    strcat(str1,"\\mshta.exe");
		if(!CreateProcess(str1,cmd,NULL,NULL,NULL,NULL,NULL,NULL,&si,&pi)){//启动进程 
			if(!quietMode) MessageBox(NULL,GetString4ThisLang(5),NULL,MB_ICONERROR);
			if(quietMode) ExitProcess(0);
			else return 0;
		}
		
		while(FindWindow("HTML Application Host Window Class", 0)==NULL) Sleep(500);//找mshta的窗口 
		PutToDesktop(FindWindow("HTML Application Host Window Class", 0));
		return 0;
	}
	
	DLLIMPORT void StartDwp(const char PathA[],BOOL Quiet){//创建启动Dwp进程 
		quietMode=Quiet;
		strcpy(Path,PathA);
		CreateThread(NULL,NULL,DwpThread,NULL,NULL,NULL);
		return;
	}
	
	DLLIMPORT bool SGetQuietMode(bool Set,bool beQuiet){
		bool res=quietMode;
		if(Set) quietMode=beQuiet;
		return res;
	}
	DLLIMPORT int SGetLangId(bool Set,int LangId){
		int res=LangID;
		if(Set) LangID=LangId;
		return res;
	}
	DLLIMPORT char* SGetVidPath(bool Set,char Source[]){
		strcpy(res,Path);
		if(Set) strcpy(Path,Source);
		return res;
	}
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
