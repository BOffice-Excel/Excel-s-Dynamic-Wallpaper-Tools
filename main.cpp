#include "WallpaperCore\dll.h" //WallpaperCore.dll的库文件 
#include "HelpDWPT\dll.h" //HelpDWPT.dll的库文件 
#include <commctrl.h> 
#undef BS_OWNERDRAW
#define BS_OWNERDRAW 0 
//#pragma comment (lib,"HelpDWPT\libHelpDWPT.a") 
#define key_press(key) ((GetAsyncKeyState(key)&0x8000)?1:0)//定义按键检测函数 
//#include "C:\Users\ywh11\Desktop\MyUI\dll.h"
//#pragma comment (lib,"User32.lib")
//#pragma comment (lib,"C:\Users\ywh11\Desktop\MyUI\libMyUI.a") 
/*
#ifdef _UNICODE
#if defined _M_IX86
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\"")
#elif defined _M_X64
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\"")
#else
#pragma comment(linker,"/manifestdependency:\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\"")
#endif
#endif
*/
/*宏定义，BT=Button Type=按钮状态，在WndProc函数中被使用（已废除）*//*
#define BT_NORMAL 0 //鼠标未移到上方 
#define BT_MOUSEMOVE 1 //鼠标移到上方 
#define BT_CLICK 2 //被鼠标左键点击 
*/
/*宏定义，IL=Integer Language=整数型语言标识*/
#define IL_UNSET -1 //未设置 
#define IL_ENGLISH 0 //英文 
#define IL_Simplified_Chinese 1 //简体中文 
#define IL_Traditional_Chinese 2 //繁体中文 

const char BUTTON_CLASS[]="BUTTON";
const char EDIT_CLASS[]="EDIT";
const char STATIC_CLASS[]="STATIC";

HINSTANCE HInstance; //程序的句柄，使用GetModuleHandle函数即可获得 
WNDCLASSEX wc; //窗口类，创建窗口时需要注册一个类才可以创建窗口，否则报错 
char RETURN[1145],*programName,*NameOfPro,CmdLine[1145],ConfigFile[MAX_PATH+1];//一堆的字符串，大多都是临时的、在StartDwp函数中使用 
DWORD dw/*打开文件时的标记*//*,BtnType[5]={BT_MOUSEMOVE,BT_MOUSEMOVE,BT_MOUSEMOVE,BT_MOUSEMOVE,BT_MOUSEMOVE}/*记住所有按钮状态*/;
HANDLE hFile;//文件句柄 
HDC hdc=GetDC(0);//获取桌面的HDC（用来搞窗口选择器） 
int W /*桌面宽度*/,H /*桌面高度*/,BtnWparam[5]={1,2,3,5,6}/*引用按钮事件ID标记*/,isEditing=FALSE;
HWND /*hWnd,*/HWND_,hTab,hSet,hConfig,hAnyWindow,hStaticDef,hBossKey,hsti,ChooseWindow,hFB,hEditor;//hWnd=托盘图标窗口句柄，HWND_=主窗口句柄 
NOTIFYICONDATAA nid;//托盘图标数据 
HMENU FileMenu=CreatePopupMenu(),HistroyMenu=CreatePopupMenu(),FuncMenu=CreatePopupMenu(),LangMenu=CreatePopupMenu();//文件菜单，全局是因为托盘右键要用这个 
int WINAPI winMain(_In_ HINSTANCE,_In_opt_ HINSTANCE,_In_ LPSTR,_In_ int);
typedef BOOL WINAPI (*SPDA)(VOID);
typedef char* (*GS4TL)(UINT);
typedef void (*ISS_FT)();
SPDA SetProcessDPIAwarev;//设置该进程的DPI，不设会很丑且比例不太对 
GS4TL GetString4ThisLang;
ISS_FT InitStringSystem;
HFONT hFont = CreateFont(25, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("思源"));//默认字体 
//char BtnName[5][30]={"新建配置文件","编辑配置文件","应用配置文件","停止动态壁纸","关于Dynamic Wallpaper Tools"};//按钮文本 

/*
wchar_t NoteText[][3][250]={{L"\x53\x61\x76\x65\x20\x61\x20\x63\x6F\x6E\x66\x69\x67\x75\x72\x61\x74\x69\x6F\x6E\x20\x66\x69\x6C\x65\x20\x74\x6F\x20\x73\x61\x76\x65\x20\x77\x61\x6C\x6C\x70\x61\x70\x65\x72\x20\x73\x65\x74\x74\x69\x6E\x67\x73\x2E",
L"\xE4\xBF\x9D\xE5\xAD\x98\xE4\xB8\x80\xE4\xB8\xAA\xE9\x85\x8D\xE7\xBD\xAE\xE6\x96\x87\xE4\xBB\xB6\xE4\xBB\xA5\xE4\xBF\x9D\xE5\xAD\x98\xE5\xA3\x81\xE7\xBA\xB8\xE8\xAE\xBE\xE7\xBD\xAE\xE3\x80\x82",
L"\xE4\xBF\x9D\xE5\xAD\x98\xE4\xB8\x80\xE5\x80\x8B\xE8\xA8\xAD\xE5\xAE\x9A\xE6\xAA\x94\xE4\xBB\xA5\xE4\xBF\x9D\xE5\xAD\x98\xE6\xA1\x8C\xE9\x9D\xA2\xE8\xA8\xAD\xE5\xAE\x9A\xE3\x80\x82\x0D"},
{L"\x4D\x6F\x64\x69\x66\x79\x20\x61\x20\x63\x6F\x6E\x66\x69\x67\x75\x72\x61\x74\x69\x6F\x6E\x20\x66\x69\x6C\x65\x20\x74\x6F\x20\x63\x68\x61\x6E\x67\x65\x20\x77\x61\x6C\x6C\x70\x61\x70\x65\x72\x20\x73\x65\x74\x74\x69\x6E\x67\x73\x2E",
L"\xE4\xBF\xAE\xE6\x94\xB9\xE4\xB8\x80\xE4\xB8\xAA\xE9\x85\x8D\xE7\xBD\xAE\xE6\x96\x87\xE4\xBB\xB6\xE4\xBB\xA5\xE6\x9B\xB4\xE6\x94\xB9\xE5\xA3\x81\xE7\xBA\xB8\xE8\xAE\xBE\xE7\xBD\xAE\xE3\x80\x82",
L"\xE4\xBF\xAE\xE6\x94\xB9\xE4\xB8\x80\xE5\x80\x8B\xE8\xA8\xAD\xE5\xAE\x9A\xE6\xAA\x94\xE4\xBB\xA5\xE6\x9B\xB4\xE6\x94\xB9\xE6\xA1\x8C\xE9\x9D\xA2\xE8\xA8\xAD\xE5\xAE\x9A\xE3\x80\x82\x0D"},
{L"\x4F\x70\x65\x6E\x20\x61\x20\x63\x6F\x6E\x66\x69\x67\x75\x72\x61\x74\x69\x6F\x6E\x20\x66\x69\x6C\x65\x20\x74\x6F\x20\x73\x74\x61\x72\x74\x20\x64\x79\x6E\x61\x6D\x69\x63\x20\x77\x61\x6C\x6C\x70\x61\x70\x65\x72\x2E",
L"\xE6\x89\x93\xE5\xBC\x80\xE4\xB8\x80\xE4\xB8\xAA\xE9\x85\x8D\xE7\xBD\xAE\xE6\x96\x87\xE4\xBB\xB6\xE4\xBB\xA5\xE5\x90\xAF\xE5\x8A\xA8\xE5\x8A\xA8\xE6\x80\x81\xE5\xA3\x81\xE7\xBA\xB8\xE3\x80\x82",
L"\xE6\x89\x93\xE9\x96\x8B\xE4\xB8\x80\xE5\x80\x8B\xE8\xA8\xAD\xE5\xAE\x9A\xE6\xAA\x94\xE4\xBB\xA5\xE5\x95\x9F\xE5\x8B\x95\xE5\x8B\x95\xE6\x85\x8B\xE6\xA1\x8C\xE9\x9D\xA2\xE3\x80\x82\x0D\x0A\x43\x6C\x6F\x73\x65"},
{L"\x61\x6C\x6C\x20\x77\x69\x6E\x64\x6F\x77\x73\x20\x63\x72\x65\x61\x74\x65\x64\x20\x62\x79\x20\x6D\x73\x68\x74\x61\x2E\x65\x78\x65\x20\x74\x6F\x20\x73\x74\x6F\x70\x20\x64\x79\x6E\x61\x6D\x69\x63\x20\x77\x61\x6C\x6C\x70\x61\x70\x65\x72\x73\2E",
L"\xE5\x85\xB3\xE9\x97\xAD\xE6\x89\x80\xE6\x9C\x89\x6D\x73\x68\x74\x61\x2E\x65\x78\x65\xE5\x88\x9B\xE5\xBB\xBA\xE7\x9A\x84\xE7\xAA\x97\xE5\x8F\xA3\xE4\xBB\xA5\xE5\x81\x9C\xE6\xAD\xA2\xE5\x8A\xA8\xE6\x80\x81\xE5\xA3\x81\xE7\xBA\xB8\xE3\x80\x82",
L"\xE9\x97\x9C\xE9\x96\x89\xE6\x89\x80\xE6\x9C\x89\x6D\x73\x68\x74\x61\x2E\x65\x78\x65\xE5\x89\xB5\xE5\xBB\xBA\xE7\x9A\x84\xE8\xA6\x96\xE7\xAA\x97\xE4\xBB\xA5\xE5\x81\x9C\xE6\xAD\xA2\xE5\x8B\x95\xE6\x85\x8B\xE6\xA1\x8C\xE9\x9D\xA2\xE3\x80\x82\x0D"},
{L"\x4F\x70\x65\x6E\x20\x27\x41\x62\x6F\x75\x74\x27",
L"\xE6\x89\x93\xE5\xBC\x80\xE2\x80\x9C\xE5\x85\xB3\xE4\xBA\x8E\xE2\x80\x9D",
L"\xE6\x89\x93\xE9\x96\x8B\xE2\x80\x9C\xE9\x97\x9C\xE6\x96\xBC\xE2\x80\x9D"}};*/

//left->top->right->bottom
RECT BtnPos[5]={
	{20,20,220,80},{240,20,440,80},{460,20,660,80},{20,90,220,150},{240,90,660,150}
};//所有按钮的位置

char* StringCat(char *Str1,const char *Str2){//没用的东西 
	char* a;//复制字符串 
	strcpy(a,Str1);
	strcat(a,Str2);
	return a;
}

void ToastMessage(const char Title[],const char Info[],const char InfoTitle[],int time=0){
	nid.uTimeout=time;
	strcpy(nid.szInfo,Info);//复制信息 
	strcpy(nid.szTip,Title);
	strcpy(nid.szInfoTitle,InfoTitle);
    Shell_NotifyIcon(NIM_MODIFY, &nid);//修改图标  
    Shell_NotifyIcon(NIM_SETVERSION, &nid);//启动 
}

LONG GetRegValue(HKEY key,const char path[],const char keyname[],char value[]){//获取注册表的某个值 （无需管理员） 
    HKEY hKey;
    BYTE byData[255];//创建缓冲区 
    LONG status = RegOpenKeyExA(key, path, 0, KEY_READ, &hKey);//打开键 
    if (status != ERROR_SUCCESS) return status;
    DWORD dwSize = sizeof(byData),dwType;
    status = RegQueryValueExA(hKey, keyname, NULL, &dwType, byData, &dwSize);//获取数据 
    if (status != ERROR_SUCCESS) {//错误判定 
        RegCloseKey(hKey);
        return status;
    }
    strcpy(value,(char*)byData);//复制 
    RegCloseKey(hKey);//关闭键 
    return 0;
	/*使用原始方法需要管理员权限 
	LONG result;
    DWORD dwType,dwSize;
    HKEY hKey;
	result = RegOpenKeyEx(key, path, 0, KEY_READ, &hKey);
	if(result!=ERROR_SUCCESS) return result;
    result = RegGetValue(hKey,NULL,keyname,RRF_RT_REG_SZ,&dwType,value,&dwSize);
    RegCloseKey(hKey);
	return result;*/
}

LONG SetRegValue(HKEY key,const char path[],const char keyname[],char value[]){//设置注册表的某个值（需要管理员） 
 
    // 打开注册表项
    HKEY hKey;
    LONG result = RegOpenKeyExA(
        key, // 根键
        path, // 子键路径
        0, // 保留，必须是0
        KEY_SET_VALUE, // 访问权限
        &hKey // 返回打开的注册表项句柄
    );
 
    if (result == ERROR_SUCCESS) {
        // 设置注册表项的值
        result = RegSetValueExA(
            hKey, // 注册表项句柄
            keyname, // 值的名称
            0, // 保留，必须是0
            REG_SZ, // 值的类型
            (BYTE*)value, // 值的数据
            strlen(value)+1 // 数据的大小（包括结束符）
        );
 
        // 关闭注册表项
        RegCloseKey(hKey);
    }
    return result;
}

LONG DelRegValue(HKEY key,const char path[],const char keyname[]){//删除注册表中的某一项值 
    // 打开注册表项
    HKEY hKey;
    LONG result = RegOpenKeyExA(
        key, // 根键
        path, // 子键路径
        0, // 保留，必须是0
        KEY_SET_VALUE, // 访问权限
        &hKey // 返回打开的注册表项句柄
    );
 
    if (result == ERROR_SUCCESS) {
        result = RegDeleteValue(hKey,keyname);
        RegCloseKey(hKey);
    }
    return result;
}

char* NumToString(int n){//将数字转换为文本（返回值在RETURN数组中）
	sprintf(RETURN,"%d",n);
	return RETURN;
}
bool OpenFileDlg(HWND ParentWindow, LPCSTR FileType, char Output_Path[]) {//打开文件对话框 
	OPENFILENAME ofn;//打开文件结构体 
	TCHAR szFile[MAX_PATH] = {};

	ZeroMemory(&ofn, sizeof(ofn));//初始化打开文件的结构体 
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;//缓冲区（必要） 
	ofn.lpstrFile[0] = '\0';//文件名称设置为空 
	ofn.hwndOwner = ParentWindow;//父窗口（？） 
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = FileType;//设置筛选器 
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFileTitle = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;//设置标志 
	if (!GetOpenFileName(&ofn)) return false;//失败 或者 用户点击了取消 
	else strcpy(Output_Path,ofn.lpstrFile);
	if(strcmp(FileType,GetString4ThisLang(8))==0){
		char str[1145];
		for(int i=9;i>=1;i--){//记录历史 
			sprintf(RETURN,"File[%d]",i-1);
			GetPrivateProfileString("Histroy",RETURN,NULL,str,MAX_PATH,ConfigFile);
			sprintf(RETURN,"File[%d]",i);
			WritePrivateProfileString("Histroy",RETURN,str,ConfigFile);
		}
		WritePrivateProfileString("Histroy","File[0]",Output_Path,ConfigFile);//写入配置文件 
	}
	return true;//成功 
}
bool SaveFileDlg(HWND ParentWindow, LPCSTR FileType, char Output_Path[],const char typestr[]) {//保存文件对话框 
	OPENFILENAMEA ofn;
	char szFile[MAX_PATH] = {};

	ZeroMemory(&ofn, sizeof(ofn));//初始化保存文件的结构体 
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.hwndOwner = ParentWindow;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = FileType;
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFileTitle = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT;

	if (!GetSaveFileNameA(&ofn)) return false;//失败 \ 用户点击了取消 
	else strcpy(Output_Path,ofn.lpstrFile);//复制文本 
	int i = strlen(ofn.lpstrFile);
	while (i>0&&((Output_Path)[i]) != '.' && ((Output_Path)[i]) != '\\') i--;
	if (((Output_Path)[i]) == '\\') strcat((Output_Path),(char*)"."), strcat((Output_Path), (char*)typestr);//判定是否有后缀名，没有就加一个默认的 
	char str[1145];
	for(int i=1;i<=9;i++){
		sprintf(RETURN,"File[%d]",i-1);
		GetPrivateProfileString("Histroy",RETURN,NULL,str,MAX_PATH,ConfigFile);
		sprintf(RETURN,"File[%d]",i);
		WritePrivateProfileString("Histroy",RETURN,str,ConfigFile);
	}
	WritePrivateProfileString("Histroy","File[0]",Output_Path,ConfigFile);
	return true;//成功！ 
}

/*BOOL CALLBACK OutDWPProc(_In_ HWND hWnd,_In_ LPARAM lparam){
	char Text[1145];
	GetClassName(hWnd,Text,sizeof(Text));
	//GetWindowText(hWnd,Text,GetWindowTextLength(hWnd)+1);
	if(strcmp(Text,"SHELLDLL_DefView")!=0) PostMessage(hWnd,WM_CLOSE,NULL,NULL);
	return TRUE;
}*/
int SetDefFont(LOGFONTA *lpLogFont){//设置默认字体 
	CHOOSEFONTA cf;
	LOGFONTA lf;
	ZeroMemory(&cf, sizeof(cf));
	cf.lStructSize = sizeof (cf);
	cf.lpLogFont = &lf;
	cf.Flags = CF_EFFECTS|CF_SCREENFONTS | CF_FORCEFONTEXIST|CF_NOSCRIPTSEL|CF_NOVERTFONTS;
	WINBOOL RES=ChooseFont(&cf);
	*lpLogFont=lf;
	if(RES!=TRUE){
		return RES;
	}
	else{
		hFont=CreateFont(lf.lfHeight,lf.lfWidth,lf.lfEscapement,lf.lfOrientation,lf.lfWeight,lf.lfItalic,lf.lfUnderline,lf.lfStrikeOut,lf.lfCharSet,lf.lfOutPrecision,lf.lfClipPrecision,lf.lfQuality,lf.lfPitchAndFamily,lf.lfFaceName);
		char TempStr[1145];
		sprintf(TempStr,"%d",lf.lfCharSet);
		WritePrivateProfileString("Font","lfCharSet",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfClipPrecision);
		WritePrivateProfileString("Font","lfClipPrecision",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfEscapement);
		WritePrivateProfileString("Font","lfEscapement",TempStr,ConfigFile);
		WritePrivateProfileString("Font","lfFaceName",lf.lfFaceName,ConfigFile);
		sprintf(TempStr,"%d",lf.lfHeight);
		WritePrivateProfileString("Font","lfHeight",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfItalic);
		WritePrivateProfileString("Font","lfItalic",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfOrientation);
		WritePrivateProfileString("Font","lfOrientation",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfOutPrecision);
		WritePrivateProfileString("Font","lfOutPrecision",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfPitchAndFamily);
		WritePrivateProfileString("Font","lfPitchAndFamily",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfQuality);
		WritePrivateProfileString("Font","lfQuality",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfStrikeOut);
		WritePrivateProfileString("Font","lfStrikeOut",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfUnderline);
		WritePrivateProfileString("Font","lfUnderline",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfWeight);
		WritePrivateProfileString("Font","lfWeight",TempStr,ConfigFile);
		sprintf(TempStr,"%d",lf.lfWidth);
		WritePrivateProfileString("Font","lfWidth",TempStr,ConfigFile);
		return RES;
	}
	return RES;
}

bool isRunningAsAdmin() {//判定是否在管理员身份下运行 
    HANDLE hToken;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) return false;//获取令牌 
    TOKEN_ELEVATION elevation;
    DWORD size;
    if (GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &size)) {
        CloseHandle(hToken);
        return elevation.TokenIsElevated > 0;
    }
 
    CloseHandle(hToken);
    return false;
}
bool runAsAdmin() {//在管理员身份中运行 
	if(isRunningAsAdmin()) return true;
    SHELLEXECUTEINFO sei = {0};
    sei.cbSize = sizeof(SHELLEXECUTEINFO);
    sei.fMask = SEE_MASK_NOCLOSEPROCESS;
    sei.lpFile = NameOfPro; // 当前应用程序的完整路径
    sei.lpVerb = "runas"; // 请求管理员权限
    sei.nShow = SW_SHOWNORMAL;
    sei.lpParameters = CmdLine;

    if (ShellExecuteEx(&sei)) {//启动！ 
        CloseHandle(sei.hProcess);
        ExitProcess(0);
        return true;
    }
 	ExitProcess(0);
 	return false;
}
DWORD WINAPI FindWindowProcess(LPVOID lparam){//查找窗口的线程 //获取用户选择的窗口 
	SendMessage(hsti, BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(HInstance,"IDI_SELECTUSING"));//设置图标 
	ChooseWindow=0;//默认设置为空 
	POINT cur;//鼠标指针位置 
	//HCURSOR hCursor=LoadCursor(HInstance,"IDC_SELECTCURSOR");
	HWND Find;//当前选择的窗口句柄 
	RECT rect,DRect;
	char str[1145];
	HBRUSH GBrush=CreateSolidBrush(RGB(0,255,0));//预设笔刷 
	while(!key_press(VK_LBUTTON)){
        //SetCursor(hCursor);
		GetCursorPos(&cur);
		Find=WindowFromPoint(cur);
		while(GetParent(Find)) Find=GetParent(Find);
		if(Find!=ChooseWindow){
			//RedrawWindow(0,NULL,NULL,RDW_ERASE);
			if(ChooseWindow){
				GetWindowRect(ChooseWindow,&rect);
				BitBlt(hdc,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,hdc,rect.left,rect.top,DSTINVERT);
			}
			ChooseWindow=Find;
			GetWindowRect(ChooseWindow,&rect);
			BitBlt(hdc,rect.left,rect.top,rect.right-rect.left,rect.bottom-rect.top,hdc,rect.left,rect.top,DSTINVERT);
			/*DRect.left=rect.left-5;
			DRect.top=rect.top-5;
			DRect.bottom=rect.bottom+5;
			DRect.right=rect.left;
			FillRect(hdc,&DRect,GBrush);
			DRect.bottom=rect.top;
			DRect.right=rect.right+5;
			FillRect(hdc,&DRect,GBrush);
			DRect.bottom=rect.bottom+5;
			DRect.top=rect.bottom;
			FillRect(hdc,&DRect,GBrush);
			DRect.left=rect.right;
			DRect.right=rect.right+5;
			DRect.top=rect.top-5;
			DRect.bottom=rect.bottom+5;
			FillRect(hdc,&DRect,GBrush);*/
			char Text[1145];
			strcpy(str,GetString4ThisLang(49));
			GetWindowText(ChooseWindow,Text,GetWindowTextLength(ChooseWindow)+1);
			strcat(str,Text);//拼接提示文本 
			SetDlgItemText(hAnyWindow,1,str);
			strcpy(str,GetString4ThisLang(50));
			GetClassName(ChooseWindow,Text,sizeof(Text));
			strcat(str,Text);//拼接提示文本 
			SetDlgItemText(hAnyWindow,2,str);//设置窗口信息+文字 
		}
	}
	SendMessage(hsti, BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(HInstance,"IDI_SELECTUNUSE"));//设置图标 
	//RedrawWindow(0,NULL,NULL,RDW_ERASE);
	return 0; 
} 
/*
LRESULT CALLBACK DlgProc(HWND hwnd,UINT msg,WPARAM wParam,LPARAM lParam){
	static HWND static1=FindWindowEx(hwnd,0,"STATIC",0);
	static HWND static2=FindWindowEx(hwnd,static1,"STATIC",0);
	static bool beSound,beGet=false;
	static LPSTR filepath;
	static char VideoFilePath[MAX_PATH*2];
	if(!filepath&&beGet==false){
		GetWindowText(static1,filepath,GetWindowTextLength(static1)+1);
		freopen(filepath,"r",stdin);
		char a;
		scanf("%c",&a);
		beSound=(a=='t');
		if(beSound) CheckDlgButton(hwnd,2,BST_CHECKED);
		else CheckDlgButton(hwnd,3,BST_CHECKED);
		int count=0;
		while(a!='\0'){
			scanf("%c",&a);
			VideoFilePath[count++]=a;
		}
		fclose(stdin);
		char set[114514]="当前视频路径：";
		strcat(set,VideoFilePath);
		SetWindowText(static2,set);
	}
	switch(msg){
		case WM_DESTROY:{
			PostQuitMessage(0);
			break;
		}
		case WM_COMMAND:{
			switch(LOWORD(wParam)){
				case 1:{
					OpenFileDlg(hwnd,GetString4ThisLang(7),VideoFilePath);
					DlgProc(hwnd,NULL,NULL,NULL);
					break;
				}
				case 2:{
					CheckDlgButton(hwnd,3,BST_UNCHECKED);
					CheckDlgButton(hwnd,2,BST_CHECKED);
					break;
				}
				case 3:{
					CheckDlgButton(hwnd,2,BST_UNCHECKED);
					CheckDlgButton(hwnd,3,BST_CHECKED);
					break;
				}
			}
			break;
		}
		default:return DefWindowProc(hwnd,msg,wParam,lParam);	
	}
}

WINBOOL WINAPI EditProfile(LPSTR filepath){
	if(filepath==NULL) return FALSE;
	WNDCLASSEX wc_dlg;
	memset(&wc_dlg, 0, sizeof(wc_dlg));//注册主窗口类 
	wc_dlg.cbSize=sizeof(WNDCLASSEX);
	wc_dlg.hInstance=GetModuleHandle(0);
	wc_dlg.hbrBackground=(HBRUSH)(COLOR_BTNFACE + 1);
	wc_dlg.hIcon=LoadIcon(wc_dlg.hInstance,"A");
	wc_dlg.hIconSm=LoadIcon(wc_dlg.hInstance,"A");
	wc_dlg.hCursor=LoadCursor(NULL,IDC_ARROW);
	wc_dlg.lpszClassName="Dialog";
	wc_dlg.lpfnWndProc=DlgProc;
	wc_dlg.style=CS_DBLCLKS|CS_SAVEBITS|CS_GLOBALCLASS;
	RegisterClassEx(&wc_dlg);
	HWND Dlg=CreateWindow("Dialog","Edit Profile",WS_VISIBLE|WS_CAPTION|WS_SYSMENU|WS_MINIMIZEBOX,CW_USEDEFAULT,CW_USEDEFAULT,800,200,NULL,NULL,NULL,NULL);
	if(!Dlg) return FALSE;
	CreateWindow("STATIC",filepath,WS_CHILD,1000,300,1000,20,Dlg,NULL,NULL,NULL);
	SendMessage(CreateWindow("STATIC","当前视频路径：",WS_CHILD|WS_VISIBLE,20,20,650,30,Dlg,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","修改",WS_CHILD|WS_VISIBLE,700,20,70,30,Dlg,(HMENU)1,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("STATIC","是否启用声音：",WS_CHILD|WS_VISIBLE,20,70,190,30,Dlg,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","是",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON,200,70,100,30,Dlg,(HMENU)2,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","否",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON,310,70,650,30,Dlg,(HMENU)3,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	ShowWindow(Dlg,SW_SHOW);
	UpdateWindow(Dlg);
	MSG msg={0};
	while(GetMessage(&msg,NULL,0,0)>0){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return TRUE;
}*/

BOOL CALLBACK SetDPI(_In_ HWND hwnd, _In_ LPARAM Lparam){
	return SetProcessDPIAwarev();
}

/* This is where all the input to the window goes to */

char Editing[114514];
LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {//窗口过程 
	switch (Message) {
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {//销毁窗口 
			PostQuitMessage(0);
			break;
		}
		
		case WM_CLOSE: {//隐藏窗口 
			ShowWindow(hwnd,SW_HIDE);
			break;
		}
		
		case WM_CREATE:{//Dark Mode Menu+Titlebar
			//SetTimer(hwnd,1,100,NULL);
			HMODULE hModule=LoadLibrary("dwmapi.dll");
			if(hModule){
				bool Dark=true;
				typedef VOID (*DSWA)(HWND,DWORD,LPCVOID,DWORD);
				DSWA DwmSetWindowAttribute=(DSWA)GetProcAddress(hModule,"DwmSetWindowAttribute");
				if(DwmSetWindowAttribute) DwmSetWindowAttribute(hwnd, 20,  &Dark, 4);
			}
			hModule=LoadLibrary("uxtheme.dll");
			
			if(hModule){
				typedef VOID (*ADMW)(HWND,BOOLEAN);
				ADMW AllowDarkModeForWindow=(ADMW)GetProcAddress(hModule,MAKEINTRESOURCE(133));
				if(AllowDarkModeForWindow) for(int i=0;i<=114;i++)AllowDarkModeForWindow(GetDlgItem(hwnd,i),TRUE);
				typedef VOID (*SPAM)(BOOL);
				SPAM SetPreferredAppMode=(SPAM)GetProcAddress(hModule,MAKEINTRESOURCE(135));
				if(SetPreferredAppMode) SetPreferredAppMode(2);
				typedef VOID (*FMT)();
				FMT FlushMenuThemes=(FMT)GetProcAddress(hModule,MAKEINTRESOURCE(136));
				if(FlushMenuThemes) FlushMenuThemes();
			}
			break;
		}
		
		case WM_DRAWITEM:{
			DRAWITEMSTRUCT dis=*(LPDRAWITEMSTRUCT)lParam;
			SetWindowLong(dis.hwndItem,GWL_STYLE,GetWindowLong(dis.hwndItem,GWL_STYLE)&(~BS_OWNERDRAW));
			SendMessage(dis.hwndItem,WM_PAINT,NULL,NULL);
			UpdateWindow(dis.hwndItem);
			SetWindowLong(dis.hwndItem,GWL_STYLE,GetWindowLong(dis.hwndItem,GWL_STYLE)|(BS_OWNERDRAW));
			/*BitBlt(dis.hDC,
				0,0,
				dis.rcItem.right,dis.rcItem.bottom,
				dis.hDC,
				dis.rcItem.left,dis.rcItem.top,
				DSTINVERT
			);*/
			break;
		}
		
		/*case WM_MOUSEMOVE: {//当鼠标移动时 
			HDC DC=GetDC(hwnd);//获取HDC 
			SelectObject(DC,hFont);
			RECT WindowRect;//获取当前窗口位置 
			GetWindowRect(hwnd,&WindowRect);
			POINT mousePoint;
			GetCursorPos(&mousePoint);//获取当前鼠标位置 
			mousePoint.x-=WindowRect.left+10;
			mousePoint.y-=WindowRect.top;//计算使用左上角为0,0 
			mousePoint.y-=50;//计算误差 
			for(int i=0;i<5;i++){
				RECT Pos=BtnPos[i];
				if(mousePoint.x>=BtnPos[i].left&&mousePoint.y>=BtnPos[i].top&&mousePoint.x<=BtnPos[i].right&&mousePoint.y<=BtnPos[i].bottom){//寻找被鼠标碰到的按钮 
					if(BtnType[i]!=BT_MOUSEMOVE){//判断是否已经是这个状态，节约性能 
						RECT Pos1=Pos;
						Pos1.top+=18;
						FillRect(DC,&Pos,CreateSolidBrush(RGB(229,229,229)));//画矩形 
						SetBkColor(DC,RGB(229,229,229));
						DrawText(DC,BtnName[i],strlen(BtnName[i]),&Pos1,DT_CENTER|DT_VCENTER);//写入文本 
						MoveToEx(DC,Pos.left+5,Pos.bottom+1,NULL);//画线、搞出立体感 
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						MoveToEx(DC,Pos.right+1,Pos.top+5,NULL);
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						BtnType[i]=BT_MOUSEMOVE;//修改状态 
					}
				}
				else{
					if(BtnType[i]!=BT_NORMAL){//判断是否已经是这个状态，节约性能 
						RECT Pos1=Pos;
						Pos1.top+=18;
						FillRect(DC,&Pos,CreateSolidBrush(RGB(239, 239, 239)));//画矩形 
						SetBkColor(DC,RGB(239,239,239));
						DrawText(DC,BtnName[i],strlen(BtnName[i]),&Pos1,DT_CENTER|DT_VCENTER);//写文本 
						MoveToEx(DC,Pos.left+5,Pos.bottom+1,NULL);//画线，还是搞出立体感 
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						MoveToEx(DC,Pos.right+1,Pos.top+5,NULL);
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						BtnType[i]=BT_NORMAL;//修改标记状态 
					}
				}
			}
			break;
		}
		
		case WM_LBUTTONUP: {//当鼠标左键弹起时 
			HDC DC=GetDC(hwnd);//取HDC 
			SelectObject(DC,hFont);//设置字体 
			RECT WindowRect;//获取窗口位置 
			GetWindowRect(hwnd,&WindowRect);
			POINT mousePoint;//获取鼠标位置 
			GetCursorPos(&mousePoint);
			mousePoint.x-=WindowRect.left+10;
			mousePoint.y-=WindowRect.top;
			mousePoint.y-=50;//计算以窗口左上角为0,0的x,y坐标 
			for(int i=0;i<5;i++){
				RECT Pos=BtnPos[i];
				if(mousePoint.x>=BtnPos[i].left&&mousePoint.y>=BtnPos[i].top&&mousePoint.x<=BtnPos[i].right&&mousePoint.y<=BtnPos[i].bottom){//寻找被按下的按钮 
					if(BtnType[i]!=BT_MOUSEMOVE){//判断是否已经是这个状态，节约性能 
						RECT Pos1=Pos;
						Pos1.top+=18;
						FillRect(DC,&Pos,CreateSolidBrush(RGB(239,239,239)));//画矩阵 
						SetBkColor(DC,RGB(239,239,239));
						DrawText(DC,BtnName[i],strlen(BtnName[i]),&Pos1,DT_CENTER|DT_VCENTER);//画文本 
						MoveToEx(DC,Pos.left+5,Pos.bottom+1,NULL);//画线，仍然是立体感 
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						MoveToEx(DC,Pos.right+1,Pos.top+5,NULL);
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						BtnType[i]=BT_MOUSEMOVE;//更新状态 
						SendMessage(hwnd,WM_COMMAND,BtnWparam[i],NULL);//发送按下消息 
					}
					break;
				}
			}
			break;
		}
		
		case WM_LBUTTONDOWN: {//鼠标左键被按下 
			HDC DC=GetDC(hwnd);//获取HDC 
			SelectObject(DC,hFont);//设置字体 
			RECT WindowRect;
			GetWindowRect(hwnd,&WindowRect);//获取窗口坐标 
			POINT mousePoint;//获取鼠标坐标 
			GetCursorPos(&mousePoint);
			mousePoint.x-=WindowRect.left+10;
			mousePoint.y-=WindowRect.top;
			mousePoint.y-=50;//计算以主窗口的左上角为0,0时的鼠标坐标 
			for(int i=0;i<5;i++){
				RECT Pos=BtnPos[i];
				if(mousePoint.x>=BtnPos[i].left&&mousePoint.y>=BtnPos[i].top&&mousePoint.x<=BtnPos[i].right&&mousePoint.y<=BtnPos[i].bottom){//寻找被按下的按钮 
					if(BtnType[i]!=BT_CLICK){
						RECT Pos1=Pos;//复制RECT 
						Pos1.bottom+=5;
						Pos1.right+=5; 
						FillRect(DC,&Pos1,CreateSolidBrush(RGB(255,255,255)));//覆盖以前的 
						Pos1.bottom-=5;
						Pos1.right-=5;//恢复原始 
						Pos1.top+=20;
						Pos1.left+=2;//修改位置立体化 
						SetBkColor(DC,RGB(245,245,245));
						FillRect(DC,&Pos,CreateSolidBrush(RGB(239, 239, 239)));//画新的矩形 
						DrawText(DC,BtnName[i],strlen(BtnName[i]),&Pos1,DT_CENTER|DT_VCENTER);//画文本 
						MoveToEx(DC,Pos.left+2,Pos.top+2,NULL);//画两条线，立体 
						LineTo(DC,Pos.right-1,Pos.top+2); 
						MoveToEx(DC,Pos.left+2,Pos.top+2,NULL);
						LineTo(DC,Pos.left+2,Pos.bottom-2); 
						BtnType[i]=BT_CLICK;//修改状态 
						Sleep(100);
					}
					break;
				}
			}
			break;
		}*/
		case WM_COMMAND: {//当xxx被触发 
			switch (LOWORD(wParam)) {
				case 1:{//创建新的配置项 
					/*char Video[1145],SP[1145],chr;
					bool isSound=false;
					if(!SaveFileDlg(hwnd,GetString4ThisLang(8),SP,"dp")) break;//另存为某个dp文件 
					if(!OpenFileDlg(hwnd,GetString4ThisLang(7),Video)) break;//获取视频 
					isSound=(MessageBox(hwnd,GetString4ThisLang(9),"Question",MB_YESNO|MB_ICONQUESTION)==6);
					freopen(SP,"w",stdout);
					printf("%s",(isSound?"t":"f"));//写入信息 
					printf("%s",Video);
					fclose(stdout);
					if(MessageBox(hwnd,GetString4ThisLang(11),"Information",MB_YESNO|MB_ICONQUESTION)==6){
						StartDwp(SP,false);//启动！ 
						ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//提示启动完成 
					}*/
					char SP[1145];
					//if(!OpenFileDlg(hwnd,GetString4ThisLang(8),SP)) break;
					if(!SaveFileDlg(hwnd,GetString4ThisLang(8),SP,"dp")) break;
					TabCtrl_SetCurFocus(hTab,4);
					if(isEditing){
						int c=MessageBox(HWND_,GetString4ThisLang(101),"Question",MB_YESNOCANCEL|MB_ICONQUESTION);
						switch(c){
							case IDOK:{
								SendMessage(hEditor,WM_COMMAND,(WPARAM)43,NULL);
								break;
							}
							case IDNO:{
								break;
							}
							case IDCANCEL:{
								return 0;
								break;
							}
						}
					}
					strcpy(Editing,SP);
					CheckDlgButton(hEditor,45,BST_UNCHECKED);
					SetDlgItemText(hEditor,29,"");
					/*
					char sound,VP[1145],put;
					dw=0;
					hFile=CreateFile(SP, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
					ReadFile(hFile,&sound,1,&dw,NULL);
					ReadFile(hFile,VP,GetFileSize(hFile,NULL)-1,&dw,NULL);
					CloseHandle(hFile);
					if(VP[strlen(VP)-1]=='\r') VP[strlen(VP)-1]=NULL;
					SetDlgItemText(hEditor,29,VP);
					CheckDlgButton(hEditor,45,(sound=='t'||sound=='T')?BST_CHECKED:BST_UNCHECKED); */
					break;
				}
				case 2:{//编辑配置项 
					char SP[1145];
					if(!OpenFileDlg(hwnd,GetString4ThisLang(8),SP)) break;
					TabCtrl_SetCurFocus(hTab,4);
					if(isEditing){
						int c=MessageBox(HWND_,GetString4ThisLang(101),"Question",MB_YESNOCANCEL|MB_ICONQUESTION);
						switch(c){
							case IDOK:{
								SendMessage(hEditor,WM_COMMAND,(WPARAM)43,NULL);
								break;
							}
							case IDNO:{
								break;
							}
							case IDCANCEL:{
								return 0;
								break;
							}
						}
					}
					strcpy(Editing,SP);
					char sound,VP[1145],put;
					dw=0;
					hFile=CreateFile(SP, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
					ReadFile(hFile,&sound,1,&dw,NULL);
					ReadFile(hFile,VP,GetFileSize(hFile,NULL)-1,&dw,NULL);
					CloseHandle(hFile);
					if(VP[strlen(VP)-1]=='\r') VP[strlen(VP)-1]=NULL;
					SetDlgItemText(hEditor,29,VP);
					CheckDlgButton(hEditor,45,(sound=='t'||sound=='T')?BST_CHECKED:BST_UNCHECKED); 
					/*ChooseChangeObject:
					int c=MessageBox(hwnd,GetString4ThisLang(12),"Edit Profile",MB_YESNOCANCEL|MB_ICONQUESTION);
					switch(c){
						case 6:{
							char STR[114514];
							strcpy(STR,GetString4ThisLang(33));
							strcat(STR,VP);
							strcat(STR,GetString4ThisLang(34));
							if(MessageBox(hwnd,STR,GetString4ThisLang(35),MB_YESNO|MB_ICONQUESTION)==6){
								if(OpenFileDlg(hwnd,GetString4ThisLang(7),VP)) MessageBox(hwnd,GetString4ThisLang(36),"Information",MB_ICONINFORMATION);
								else MessageBox(hwnd,GetString4ThisLang(37),"Information",MB_ICONINFORMATION);
							}
							break;
						}
						case 7:{
							char STR[114514];
							strcpy(STR,GetString4ThisLang(38));
							strcat(STR,(sound=='t')?GetString4ThisLang(39):GetString4ThisLang(40));
							strcat(STR,GetString4ThisLang(41));
							sound=(MessageBox(hwnd,STR,"Change be play sound",MB_YESNO|MB_ICONQUESTION)==6)?'t':'f';
							break;
						}
						case 2:{
							goto DefExitChoose;
							break;
						}
					}
					goto ChooseChangeObject;
					DefExitChoose:
					if(MessageBox(hwnd,GetString4ThisLang(42),"Edit",MB_YESNO|MB_ICONQUESTION)==6){
						freopen(SP,"w",stdout);
						printf("%s",(sound?"t":"f"));
						printf("%s",VP);
						fclose(stdout);
						if(MessageBox(hwnd,GetString4ThisLang(11),"Edit",MB_YESNO|MB_ICONQUESTION)==6){
							StartDwp(SP,false);//启动！ 
							ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//提示启动完成 
							Sleep(1000);
						}
					}*/
					break;
				}
				case 3:{//启动配置项 
					char SP[1145];
					if(!OpenFileDlg(hwnd,GetString4ThisLang(8),SP)) break;
					StartDwp(SP,false);//启动！ 
					ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//提示启动完成 
					Sleep(1000);
					break;
				}
				case 4:{//退出 
					PostQuitMessage(0);
					break;
				}
				case 5:{//结束动态壁纸（暴力） 
					if(MessageBox(hwnd,GetString4ThisLang(6),"Warning",MB_ICONWARNING|MB_YESNO)==6){
						HWND PROGMAN=FindWindow("Progman", 0);
						if(PROGMAN) EnumChildWindows(PROGMAN,StopDWPProc,NULL);
						if(MessageBox(hwnd,GetString4ThisLang(19),"Stop Dynamic Wallpaper",MB_ICONQUESTION|MB_YESNO)==6){
							system("taskkill /F /IM explorer.exe");
							Sleep(1000);
							STARTUPINFOA StartupInfo;memset(&StartupInfo,0,sizeof(StartupInfo));
							PROCESS_INFORMATION ProcessInformation;memset(&ProcessInformation,0,sizeof(ProcessInformation));
							char buf[MAX_PATH+5],buf2[MAX_PATH+5];
							GetSystemDirectory(buf,MAX_PATH+1);
							sprintf(buf2,"%c:\\Windows\\explorer.exe",buf[0]);
							CreateProcess(buf2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&StartupInfo,&ProcessInformation);
							Sleep(2000); 
							MessageBox(hwnd,GetString4ThisLang(23),"Restart explorer.exe complete",MB_ICONINFORMATION); 
							Shell_NotifyIcon(NIM_ADD,&nid);
							ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(81));//提示重启完成 
						}
					}
					break;
				}
				case 6:{//关于 
					if(MessageBox(hwnd,GetString4ThisLang(10),"About",MB_YESNO|MB_ICONINFORMATION)!=6) system("start https://www.bilibili.com/video/BV1HZ4y1978a/");
					break;
				}
				case 7:{//设置默认启动项 
					char SP[1145],outText[1145];
					strcpy(outText,GetString4ThisLang(22));
					if(!OpenFileDlg(hwnd,GetString4ThisLang(8),SP)) break;
					strcat(outText,SP);
					if(MessageBox(hwnd,outText,"Question",MB_ICONQUESTION|MB_YESNO)==6){
						HKEY hKey; 
						DWORD disp;
						RegCreateKeyEx(
					        HKEY_CURRENT_USER,      // 根键
					        "Software\\DWPT",        // 子键路径
					        0,                       // 保留，必须为0
					        NULL,                    // 注册表项类型（我们不需要指定类型）
					        REG_OPTION_NON_VOLATILE, // 注册表项的类型
					        KEY_WRITE,               // 访问权限
					        NULL,                    // 如果类型和权限未指定，使用默认的安全描述符
					        &hKey,                   // 返回新创建或打开的注册表项的句柄
					        &disp                    // 返回值，指示注册表项是新创建还是已存在
					    );
						if(SetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",SP)==ERROR_SUCCESS){
							char str[1145];
							strcpy(str,GetString4ThisLang(16));
							strcat(str,SP);
							SetWindowText(hStaticDef,str);
							MessageBox(HWND_,GetString4ThisLang(21),"Set default item",MB_ICONINFORMATION);
						}
						else MessageBox(HWND_,GetString4ThisLang(18),"Set default item",MB_ICONERROR);
					}
					break;
				}
				case 8:{//修改启动的配置文件 
					char SP[1145];
					if(GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",SP)!=ERROR_SUCCESS) break;
					TabCtrl_SetCurFocus(hTab,4);
					if(isEditing){
						int c=MessageBox(HWND_,GetString4ThisLang(101),"Question",MB_YESNOCANCEL|MB_ICONQUESTION);
						switch(c){
							case IDOK:{
								SendMessage(hEditor,WM_COMMAND,(WPARAM)43,NULL);
								break;
							}
							case IDNO:{
								break;
							}
							case IDCANCEL:{
								return 0;
								break;
							}
						}
					}
					strcpy(Editing,SP);
					char sound,VP[1145],put;
					dw=0;
					hFile=CreateFile(SP, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
					ReadFile(hFile,&sound,1,&dw,NULL);
					ReadFile(hFile,VP,GetFileSize(hFile,NULL)-1,&dw,NULL);
					CloseHandle(hFile);
					if(VP[strlen(VP)-1]=='\r') VP[strlen(VP)-1]=NULL;
					SetDlgItemText(hEditor,29,VP);
					CheckDlgButton(hEditor,45,(sound=='t'||sound=='T')?BST_CHECKED:BST_UNCHECKED); 
					/*DefChooseChangeObject:
					int c=MessageBox(hwnd,GetString4ThisLang(12),"Edit profile",MB_YESNOCANCEL|MB_ICONQUESTION);
					switch(c){
						case 6:{
							char STR[114514];
							strcpy(STR,GetString4ThisLang(33));
							strcat(STR,VP);
							strcat(STR,GetString4ThisLang(34));
							if(MessageBox(hwnd,STR,GetString4ThisLang(35),MB_YESNO|MB_ICONQUESTION)==6){
								if(OpenFileDlg(hwnd,GetString4ThisLang(7),VP))
									MessageBox(hwnd,GetString4ThisLang(36),"Information",MB_ICONINFORMATION);
								else MessageBox(hwnd,GetString4ThisLang(37),"Information",MB_ICONINFORMATION);
							}
							break;
						}
						case 7:{
							char STR[114514];
							strcpy(STR,GetString4ThisLang(38));
							strcat(STR,(sound=='t')?GetString4ThisLang(39):GetString4ThisLang(40));
							strcat(STR,GetString4ThisLang(41));
							sound=(MessageBox(hwnd,STR,"Edit",MB_YESNO|MB_ICONQUESTION)==6)?'t':'f';
							break;
						}
						case 2:{
							goto ExitChoose;
							break;
						}
					}
					goto DefChooseChangeObject;
					ExitChoose://保存配置信息 
					if(MessageBox(hwnd,GetString4ThisLang(42),"Edit",MB_YESNO|MB_ICONQUESTION)==6){
						freopen(SP,"w",stdout);
						printf("%s",(sound?"t":"f"));
						printf("%s",VP);
						fclose(stdout);
						if(MessageBox(hwnd,GetString4ThisLang(43),"Edit",MB_YESNO|MB_ICONQUESTION)==6){
							StartDwp(SP,false);
							ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//提示启动完成 
							Sleep(1000);
						}
					}*/
					break;
				}
				case 9:{//启动默认的配置文件 
					char SP[1145];
					if(GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",SP)!=ERROR_SUCCESS) break;
					StartDwp(SP,false);
					ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//提示启动完成 
					Sleep(1000);
					break;
				}
				case 10:{//切换是否开机自启动的状态 
		            UINT st=GetMenuState(FileMenu, 10, MF_BYCOMMAND);//获取是否被选中 
					HKEY hKey; 
					DWORD disp;
					RegCreateKeyEx(//创建项 
				        HKEY_CURRENT_USER,      // 根键
				        "Software\\DWPT",        // 子键路径
				        0,                       // 保留，必须为0
						NULL,                    // 注册表项类型（我们不需要指定类型）
					    REG_OPTION_NON_VOLATILE, // 注册表项的类型
				        KEY_WRITE,               // 访问权限
				        NULL,                    // 如果类型和权限未指定，使用默认的安全描述符
				        &hKey,                   // 返回新创建或打开的注册表项的句柄
				        &disp                    // 返回值，指示注册表项是新创建还是已存在
				    );
		            if (st == MF_CHECKED) {//当是开机自启动时 
		            	char str[]="false";
		            	if(DelRegValue(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Run","DWPT")!=ERROR_SUCCESS){
		            		MessageBox(hwnd,GetString4ThisLang(18),"ERROR",MB_ICONERROR);
		            		break;
						}
						if(SetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","BLAS",str)!=ERROR_SUCCESS){
		            		MessageBox(hwnd,GetString4ThisLang(18),"ERROR",MB_ICONERROR);
		            		break;

						}
		                CheckMenuItem(FileMenu, 10, MF_UNCHECKED);
		                CheckDlgButton(hSet,10,BST_UNCHECKED);
		            }
		            else {//当非开机自启动时 
		            	char str[]="true",ExePath[MAX_PATH+10];
		            	GetModuleFileName(NULL,ExePath,MAX_PATH);
		            	strcat(ExePath," -q");
		            	if(SetRegValue(HKEY_CURRENT_USER,"Software\\Microsoft\\Windows\\CurrentVersion\\Run","DWPT",ExePath)!=ERROR_SUCCESS){
		            		MessageBox(hwnd,GetString4ThisLang(18),"ERROR",MB_ICONERROR);
		            		break;
						}
						if(SetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","BLAS",str)!=ERROR_SUCCESS){
		            		MessageBox(hwnd,GetString4ThisLang(18),"ERROR",MB_ICONERROR);
		            		break;
						}
		                CheckMenuItem(FileMenu, 10, MF_CHECKED);
		                CheckDlgButton(hSet,10,BST_CHECKED);
		            }
					break;
				}
				case 11: {//隐藏窗口 
					ShowWindow(hwnd,SW_HIDE);
					return 0;
				}
				case 12:{//打开帮助窗口（HelpDWPT.dll） 
					HelpWindow(hwnd);
					break;
				}
				case 13:{//查找窗口（必须启用Developer Options） 
					CreateThread(NULL,NULL,FindWindowProcess,NULL,NULL,NULL);
					break;
				}
				case 14:{//设定 
					if(ChooseWindow==0||ChooseWindow==HWND_||(!IsWindowVisible(HWND_))||IsIconic(HWND_)) MessageBox(hwnd,"未选择一个正确的窗口，无法设置为背景！","Error",MB_ICONWARNING);//失败提示 
					else{
						char Text[1145];
						GetClassName(ChooseWindow,Text,sizeof(Text));//获取窗口类名 
						if(strcmp(Text,"WorkerW")==0||strcmp(Text,"Progman")==0||strcmp(Text,"Shell_TrayWnd")==0) MessageBox(hwnd,"未选择一个正确的窗口，无法设置为背景！","Error",MB_ICONWARNING);
						else if(MessageBox(hwnd,GetString4ThisLang(6),"Warning",MB_ICONWARNING|MB_YESNO)==6){
							HWND PROGMAN=FindWindow("Progman", 0);
							if(PROGMAN) EnumChildWindows(PROGMAN,StopDWPProc,NULL);//
							PutToDesktop(ChooseWindow);
						}
					}
					break;
				}
				case 15:{//打开WinWatcher工具（HelpDWPT.dll） 
					WinWatcher();
					break;
				}
				case 16:
				case 17:
				case 18:
				case 19:
				case 20:
				case 21:
				case 22:
				case 23:
				case 24:
				case 25:{//打开历史项 
					char str[1145];
					GetMenuString(HistroyMenu,LOWORD(wParam),str,MAX_PATH+2,MF_STRING);
					if(access(str,F_OK)==0){
						StartDwp(str,false);
						ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//提示启动完成 
					}
					else MessageBox(hwnd,GetString4ThisLang(55),"Error",MB_ICONWARNING);
					break;
				}
				case 26:{//未完成 
					MessageBox(hwnd,"This feature has not been developed yet.","ERROR",MB_ICONWARNING);
					break;
				}
				case 27:{//创建GUID/UUID 
					char str[1145],guid_str[1145];
					GUID guid;
					CoCreateGuid(&guid);
					sprintf(str,"Guid \\ Uuid: %08x-%04x-%04x-%02x%02x%02x%02x%02x%02x%02x%02x, Click Cancel to Copy that.",guid.Data1,guid.Data2,guid.Data3,guid.Data4[0],guid.Data4[1],guid.Data4[2],guid.Data4[3],guid.Data4[4],guid.Data4[5],guid.Data4[6],guid.Data4[7]);
					sprintf(guid_str,"%08x-%04x-%04x-%02x%02x%02x%02x%02x%02x%02x%02x",guid.Data1,guid.Data2,guid.Data3,guid.Data4[0],guid.Data4[1],guid.Data4[2],guid.Data4[3],guid.Data4[4],guid.Data4[5],guid.Data4[6],guid.Data4[7]);
					if(MessageBox(HWND_,str,"Guid \\ Uuid Generater",MB_ICONINFORMATION|MB_OKCANCEL)==2){
						if (OpenClipboard(NULL)) {
							// 清空剪切板
							EmptyClipboard();
							// 分配内存用于存储字符串
							HGLOBAL hglbCopy = GlobalAlloc(GMEM_MOVEABLE, (strlen(guid_str) + 1) * sizeof(char));
							if (hglbCopy == NULL) {
							    CloseClipboard();
							    break;
							}
							// 锁定内存
							char *lptstrCopy = (char*)GlobalLock(hglbCopy);
							memcpy(lptstrCopy, guid_str, strlen(guid_str) + 1);
							// 解锁内存
							GlobalUnlock(hglbCopy);
							// 设置剪切板数据
							SetClipboardData(CF_TEXT, hglbCopy);
							// 关闭剪切板
							CloseClipboard();
						}
					}
					break;
				}
				case 29:{
					if(TabCtrl_GetCurSel(hTab)==4){
						switch(HIWORD(wParam)){
							case EN_CHANGE:{
								isEditing=TRUE;
								break;
							}
						}
					}
					break;
				}
				case 30:{//快速启动 
					char Command[1145],VPath[1145],ProP[1145];
					GetModuleFileName(NULL,ProP,1140);
					bool SpacePro=false,SpaceVideo=false;
					for(int i=0;i<strlen(ProP);i++) if(ProP[i]==' ') SpacePro=true;
					if(SpacePro){//程序文件名有空格 
						GetDlgItemText(hFB,29,VPath,1140);
						if((GetFileAttributes(VPath)==INVALID_FILE_ATTRIBUTES)){
							MessageBox(HWND_,GetString4ThisLang(59),NULL,MB_ICONWARNING|MB_OK);
							break;
						}
						for(int i=0;i<strlen(VPath);i++) if(VPath[i]==' ') SpaceVideo=true;
						if(SpaceVideo) sprintf(Command,"\"%s\" -f false \"%s\"",ProP,VPath);//视频文件名有空格 
						else sprintf(Command,"\"%s\" -f false %s",ProP,VPath);//视频文件名无空格 
					}
					else{//程序文件名无空格 
						GetDlgItemText(hFB,29,VPath,1140);
						if((GetFileAttributes(VPath)==INVALID_FILE_ATTRIBUTES)){
							MessageBox(HWND_,GetString4ThisLang(59),NULL,MB_ICONWARNING|MB_OK);
							break;
						}
						for(int i=0;i<strlen(VPath);i++) if(VPath[i]==' ') SpaceVideo=true;
						if(SpaceVideo) sprintf(Command,"%s -f false \"%s\"",ProP,VPath);//视频文件名有空格 
						else sprintf(Command,"%s -f false %s",ProP,VPath);//视频文件名无空格 
					}
					WinExec(Command,SW_HIDE);//启动 
					ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//提示启动完成 
					break;
				}
				case 31:{//和上面一样的道理，不同之处：一个静音一个不静音 
					char Command[1145],VPath[1145],ProP[1145];
					GetModuleFileName(NULL,ProP,1140);
					bool SpacePro=false,SpaceVideo=false;
					for(int i=0;i<strlen(ProP);i++) if(ProP[i]==' ') SpacePro=true;
					if(SpacePro){
						GetDlgItemText(hFB,29,VPath,1140);
						if((GetFileAttributes(VPath)==INVALID_FILE_ATTRIBUTES)){
							MessageBox(HWND_,GetString4ThisLang(59),NULL,MB_ICONWARNING|MB_OK);
							break;
						}
						for(int i=0;i<strlen(VPath);i++) if(VPath[i]==' ') SpaceVideo=true;
						if(SpaceVideo) sprintf(Command,"\"%s\" -f true \"%s\"",ProP,VPath);
						else sprintf(Command,"\"%s\" -f true %s",ProP,VPath);
					}
					else{
						GetDlgItemText(hFB,29,VPath,1140);
						if((GetFileAttributes(VPath)==INVALID_FILE_ATTRIBUTES)){
							MessageBox(HWND_,GetString4ThisLang(59),NULL,MB_ICONWARNING|MB_OK);
							break;
						}
						for(int i=0;i<strlen(VPath);i++) if(VPath[i]==' ') SpaceVideo=true;
						if(SpaceVideo) sprintf(Command,"%s -f true \"%s\"",ProP,VPath);
						else sprintf(Command,"%s -f true %s",ProP,VPath);
					}
					WinExec(Command,SW_HIDE);
					ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//提示启动完成 
					break;
				}
				case 32:{//打开快速启动菜单 
					HMENU FastBoot=CreatePopupMenu();
					AppendMenu(FastBoot,MF_STRING,(UINT_PTR)30,GetString4ThisLang(60));
					AppendMenu(FastBoot,MF_STRING,(UINT_PTR)31,GetString4ThisLang(61));
					POINT p;
					GetCursorPos(&p);
		            TrackPopupMenu(FastBoot, TPM_LEFTALIGN | TPM_RIGHTBUTTON, p.x, p.y, NULL, HWND_, NULL);
					break;
				}
				case 33:{
					char str_path[1145];
					if(!OpenFileDlg(HWND_,GetString4ThisLang(7),str_path)) break;
					if(SendMessage(hTab,TCM_GETCURSEL,NULL,NULL)==4) SetDlgItemText(hEditor,29,str_path);
					else SetDlgItemText(hFB,29,str_path);
					break;
				}
				case 34:{
					LOGFONTA lf;
					if(SetDefFont(&lf)==TRUE){
						char TempStr[1145];
						sprintf(TempStr,"%s%s%s",GetString4ThisLang(70),lf.lfFaceName,GetString4ThisLang(71));
						MessageBox(HWND_,TempStr,"Information",MB_ICONINFORMATION|MB_OK);
					}
					break;
				}
				case 35:{
					if(IsDlgButtonChecked(hSet,35)==TRUE){
						CheckDlgButton(hSet,35,BST_UNCHECKED);
						WritePrivateProfileString("Main","DevMode","0",ConfigFile);
						EnableMenuItem(FuncMenu,15,MF_DISABLED);
						EnableMenuItem(FuncMenu,27,MF_DISABLED);
					}
					else{
						if(MessageBox(hwnd,"Warning! You are performing a critical operation, please carefully decide whether to activate developer mode!","Warning",MB_ICONWARNING|MB_YESNO)==6){
							CheckDlgButton(hSet,35,BST_CHECKED);
							WritePrivateProfileString("Main","DevMode","1",ConfigFile);
							EnableMenuItem(FuncMenu,15,MF_ENABLED);
							EnableMenuItem(FuncMenu,27,MF_ENABLED);
						}
					}
					break;
				}
				case 36:{
					MessageBox(hwnd,GetString4ThisLang(77),"Information",MB_ICONINFORMATION);
					WritePrivateProfileString("Main","Lang","0",ConfigFile);
					CheckMenuItem(LangMenu,36,MF_CHECKED);
					CheckMenuItem(LangMenu,37,MF_UNCHECKED);
					CheckMenuItem(LangMenu,38,MF_UNCHECKED);
					SGetLangId(TRUE,0); 
					break;
				} 
				case 37:{
					MessageBox(hwnd,GetString4ThisLang(77),"Information",MB_ICONINFORMATION);
					WritePrivateProfileString("Main","Lang","1",ConfigFile);
					CheckMenuItem(LangMenu,36,MF_UNCHECKED);
					CheckMenuItem(LangMenu,37,MF_CHECKED);
					CheckMenuItem(LangMenu,38,MF_UNCHECKED);
					SGetLangId(TRUE,1); 
					break;
				}
				case 38:{
					MessageBox(hwnd,GetString4ThisLang(77),"Information",MB_ICONINFORMATION);
					WritePrivateProfileString("Main","Lang","2",ConfigFile);
					CheckMenuItem(LangMenu,36,MF_UNCHECKED);
					CheckMenuItem(LangMenu,37,MF_UNCHECKED);
					CheckMenuItem(LangMenu,38,MF_CHECKED);
					SGetLangId(TRUE,2); 
					break;
				}
				case 39:{
					WinExec("start https://github.com/BOffice-Excel/Excel-s-Dynamic-Wallpaper-Tools",SW_HIDE);
					break;
				}
				case 40:{
					if(IsDlgButtonChecked(hwnd,40)){
						WritePrivateProfileString("Main","BootDp","0",ConfigFile);
						CheckDlgButton(hwnd,40,BST_UNCHECKED);
					}
					else{
						WritePrivateProfileString("Main","BootDp","1",ConfigFile);
						CheckDlgButton(hwnd,40,BST_CHECKED);
					}
					break;
				}
				case 41:{
					MessageBox(HWND_,GetString4ThisLang(102),"Information",MB_ICONINFORMATION);
					break;
				}
				case 42:{//打开保存菜单 
					HMENU FastBoot=CreatePopupMenu();
					AppendMenu(FastBoot,MF_STRING,(UINT_PTR)43,GetString4ThisLang(96));
					AppendMenu(FastBoot,MF_STRING,(UINT_PTR)44,GetString4ThisLang(97));
					POINT p;
					GetCursorPos(&p);
		            TrackPopupMenu(FastBoot, TPM_LEFTALIGN | TPM_RIGHTBUTTON, p.x, p.y, NULL, HWND_, NULL);
					break;
				}
				case 43:{
					if(strcmp(Editing,"")==0) if(!SaveFileDlg(HWND_,GetString4ThisLang(8),Editing,"dp")) return FALSE;
					DWORD dw=0;
					HANDLE hFile=CreateFile(Editing, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL); 
					char sound,Path[114514];
					sound=((IsDlgButtonChecked(hwnd,45))?'t':'f');
					WriteFile(hFile,&sound,1,&dw,NULL);
					GetDlgItemText(hwnd,29,Path,114510);
					WriteFile(hFile,Path,strlen(Path)-1,&dw,NULL);
					CloseHandle(hFile);
					isEditing=FALSE;
					return TRUE;
					break;
				}
				case 44:{
					if(SendMessage(hwnd,WM_COMMAND,(WPARAM)43,NULL)==FALSE) break;
					StartDwp(Editing,FALSE);
					break;
				}
				case 45:{
					isEditing=TRUE;
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
		case WM_SYSCOMMAND:{
			if(LOWORD(wParam)==11||LOWORD(wParam)==4) return WndProc(hwnd,WM_COMMAND,wParam,lParam);
			return DefWindowProc(hwnd, Message, wParam, lParam);
			break;
		}
		case WM_NOTIFY:{
			switch((reinterpret_cast<LPNMHDR>(lParam))->code){
				case TCN_SELCHANGE:{
					LRESULT result=SendMessage(hTab,TCM_GETCURSEL,NULL,NULL); 
					if(result==0){
						ShowWindow(hFB,SW_HIDE);
						ShowWindow(hSet,SW_HIDE);
						ShowWindow(hAnyWindow,SW_HIDE);
						ShowWindow(hConfig,SW_SHOW);
						ShowWindow(hEditor,SW_HIDE);
					}
					else if(result==1){
						ShowWindow(hFB,SW_HIDE);
						ShowWindow(hConfig,SW_HIDE);
						ShowWindow(hAnyWindow,SW_HIDE);
						ShowWindow(hSet,SW_SHOW);
						ShowWindow(hEditor,SW_HIDE);
					}
					else if(result==2){
						ShowWindow(hFB,SW_HIDE);
						ShowWindow(hConfig,SW_HIDE);
						ShowWindow(hAnyWindow,((GetPrivateProfileInt("Main","DevMode",0,ConfigFile)==0)?SW_HIDE:SW_SHOW));
						ShowWindow(hSet,SW_HIDE);
						ShowWindow(hEditor,SW_HIDE);
					}
					else if(result==3){
						ShowWindow(hFB,SW_SHOW);
						ShowWindow(hConfig,SW_HIDE);
						ShowWindow(hAnyWindow,SW_HIDE);
						ShowWindow(hSet,SW_HIDE);
						ShowWindow(hEditor,SW_HIDE);
					}
					else if(result==4){
						ShowWindow(hFB,SW_HIDE);
						ShowWindow(hConfig,SW_HIDE);
						ShowWindow(hAnyWindow,SW_HIDE);
						ShowWindow(hSet,SW_HIDE);
						ShowWindow(hEditor,SW_SHOW);
					}
					break;
				}
				case BCN_DROPDOWN:{
					PostMessage(hwnd,WM_COMMAND,wParam,NULL);
					break;
				}
				case NM_CLICK:
			    case NM_RETURN:{
			        PNMLINK pNMLink=(PNMLINK)lParam;
			        LITEM item=pNMLink->item;
			        if(pNMLink->hdr.idFrom==39) ShellExecuteW(NULL, L"open", item.szUrl, NULL, NULL, SW_SHOW);
			        break;
			    }
			}
			break;
		}
		case WM_TIMER:{
			HDC hdc=GetDC(hwnd);
			if(GetPixel(hdc,10,10)==RGB(0,0,0)) break;
			RECT rect;GetWindowRect(hwnd,&rect);rect.bottom-=rect.top;rect.right-=rect.left;rect.left=rect.top=0;
			InvertRect(hdc,&rect);
			break;
		}
		case WM_KEYUP:{
			if(wParam==VK_TAB&&key_press(VK_CONTROL)){
				int index=SendMessage(hTab,TCM_GETCURSEL,NULL,NULL);
				index++;
				if(index==5) index=0;
				TabCtrl_SetCurFocus(hTab,index);
			}
			break;
		}
		case WM_DROPFILES:{
			char File[114514],cmd[114514];
			DragQueryFileA((HDROP)wParam,0,File,114510);
			if((File[strlen(File)-1]=='p'||File[strlen(File)-1]=='P')&&(File[strlen(File)-2]=='d'||File[strlen(File)-2]=='D')&&File[strlen(File)-3]=='.'){
				sprintf(cmd,"\"%s\" -o \"%s\"",NameOfPro,File);
				WinExec(cmd,SW_HIDE);
			}
			DragFinish((HDROP)wParam);
			break;
		}
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);//默认窗口过程 
	}
	return 0;
}

LRESULT CALLBACK TrayNotificationCallback(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {//系统托盘图标窗口进程 
    switch (uMsg) {
    	case WM_CLOSE:{
        	PostQuitMessage(0);
			break;
		}
		case WM_USER:{
			switch(lParam){
				case WM_RBUTTONDOWN:{
					POINT p;
					GetCursorPos(&p);
		            TrackPopupMenu(FileMenu, TPM_LEFTALIGN | TPM_RIGHTBUTTON, p.x, p.y, NULL, HWND_, NULL);  //展示FileMenu 
					break;
				}
				case WM_LBUTTONDOWN:{
					ShowWindow(HWND_,SW_SHOW);
					SwitchToThisWindow(HWND_,TRUE);
					break;
				}
			}
			break;
		}
		case WM_COMMAND:{
			WndProc(HWND_,WM_COMMAND,wParam,lParam);
			break;
		}
    }
    return DefWindowProc(hWnd, uMsg, wParam, lParam);
}
/*
DWORD WINAPI nidThread(LPVOID lparam){//系统托盘图标主进程 
	MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    Shell_NotifyIcon(NIM_DELETE, &nid);
	return 0;
}*/

int main(int argc,char *argv[]) {//main函数 
	NameOfPro=(char*)malloc(114514);
	GetModuleFileName(NULL,NameOfPro,114510);
	//NameOfPro = argv[0];//当前程序目录+名称 
	//if(hasCmd==false) runAsAdmin();
	programName=(char*)malloc(114514);
	GetModuleFileName(NULL,programName,114510);
	for(int i=strlen(programName)-1;i>=0;i--){//获取当前位置 
		if(programName[i]!='\\') programName[i]=NULL;
		else break;
	}
	sprintf(ConfigFile,"%s\\Config.ini",programName);
	HMODULE hModule = LoadLibrary("user32.dll");
	if(hModule){
		SetProcessDPIAwarev = (SPDA)GetProcAddress(hModule,"SetProcessDPIAware");
		if(SetProcessDPIAwarev) SetProcessDPIAwarev();//清晰！！！ 
	} 
	hModule = LoadLibrary("WallpaperCore.dll");
	if(hModule){
		InitStringSystem = (ISS_FT)GetProcAddress(hModule,"InitStringSystem");
		GetString4ThisLang = (GS4TL)GetProcAddress(hModule,"GetString4ThisLang");
		if(!GetString4ThisLang){
			MessageBox(NULL,"Load function \"GetString4ThisLang\" failed!","System error.",MB_ICONERROR|MB_OK);
			return -1;
		}
		if(!InitStringSystem){
			MessageBox(NULL,"Load function \"InitStringSystem\" failed!","System error.",MB_ICONERROR|MB_OK);
			return -1;
		}
	} 
	else{
		MessageBox(NULL,"Load library \"WallpaperCore.dll\" failed!","System error.",MB_ICONERROR|MB_OK);
		return -1;
	}
	InitStringSystem();
	bool hasCmd=false;
	//处理命令行 
	if(argc>1) for(int i=0;i<strlen(argv[1]);i++) if(argv[1][i]>='A'&&argv[1][i]<='Z') argv[1][i]+='a'-'A';
	if(argc==2){
		if(strcmp(argv[1],"-q")==0){
			if(GetPrivateProfileInt("Main","BootDp",0,ConfigFile)==TRUE){
				GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",RETURN);
				SGetQuietMode(true,true);
				SGetVidPath(true,RETURN);
				DwpThread(NULL);
			}
			hasCmd=true;
		}
		strcpy(CmdLine,argv[1]);
	}
	else if(argc==3){
		if(strcmp(argv[1],"-o")==0){
			if(argv[2][0]=='"') argv[2]++;
			if(argv[2][strlen(argv[2])-1]=='"') argv[2][strlen(argv[2])-1]=NULL;
			SGetQuietMode(true,true);
			SGetVidPath(true,argv[2]);
			DwpThread(NULL);
			hasCmd=true;
		}
		else if(strcmp(argv[1],"-i")==0){
			char downloadStr[1145];
			//strcpy(downloadStr,"https://");//https://s-53.lanzog.com:446/05061900151857485bb/2023/12/10/6cbb705319ab14754c1efb17176847da.zip?st=M5OWXJmJvhkDLRV5WP5e1Q&e=1714998274&b=AbVbwAG1UbEE9ADrVuECnAnYWeMHtAO2Ve5a5gabBehVuwiABuBXx1m8B7cA3QSuVuYM3AeDCiwFsA2dAJdVvwHnW_aMB5FHYBNQAuVa6Ao8Jcll_aB28DdQ_c_c&fi=151857485&pid=121-33-146-147&up=2&mp=0&co=0
			for(int i=0;i<7;i++) argv[2]++;
			strcat(downloadStr,argv[2]);
			MessageBox(NULL,downloadStr,NULL,NULL);
			mkdir("C:\\Dwpt_Video");
			URLDownloadToFile(NULL,downloadStr,"C:\\Dwpt_Video\\1.zip",NULL,NULL);
			MessageBox(NULL,"Complete","!!!",NULL);
			return 0;
		}
	}
	else if(argc==4){
		if(strcmp(argv[1],"-f")==0){
			if((strcmp(argv[2],"true")==0||strcmp(argv[2],"false")==0)){
				char tPath[1145];
				GetTempPath(1140,tPath);
				strcat(tPath,"FastLaunch.dp");
				freopen(tPath,"w",stdout);
				printf("%c%s",(strcmp(argv[2],"true")==0?'t':'f'),argv[3]);
				fclose(stdout);
				SGetQuietMode(true,true);
				SGetVidPath(true,tPath);
				DwpThread(NULL);
				return 0;
			}
		}
	} 
	SGetLangId(true,GetPrivateProfileInt("Main","Lang",-1,ConfigFile));
	if(GetPrivateProfileInt("Main","FirstSetup",false,ConfigFile)==false){
		LOGFONT lf;
		if(SetDefFont(&lf)!=TRUE){
			MessageBox(NULL,GetString4ThisLang(72),"Error",MB_ICONWARNING|MB_OK);
			return 0;
		}
		else WritePrivateProfileString("Main","FirstSetup","1",ConfigFile);
	}
	else{
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
	}
	if(hasCmd==true){
		if(FindWindow("DWPT_PRIVATECLASS",0)!=NULL) return 0;
		else{
			return winMain(
				GetModuleHandle(NULL),//获取本程序的句柄
				NULL,//这个参数为什么需要我也不知道
				CmdLine,//命令行
				SW_HIDE//定义窗口展示方式，参数传给ShowWindow函数，这里为SW_SHOW
			);
		}
	}
	if(FindWindow("DWPT_PRIVATECLASS",0)!=NULL){
		//SetWindowPos(FindWindow("DWPT_PRIVATECLASS",0),0,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE|SWP_SHOWWINDOW);
		MessageBox(NULL,GetString4ThisLang(32),"ERROR",MB_ICONWARNING|MB_OK); 
		ShowWindow(FindWindow("DWPT_PRIVATECLASS",0),SW_SHOW);
		SwitchToThisWindow(FindWindow("DWPT_PRIVATECLASS",0),TRUE);
		return 0;
	}
	return winMain(
		GetModuleHandle(NULL),//获取本程序的句柄
		NULL,//这个参数为什么需要我也不知道
		CmdLine,//命令行
		SW_SHOW//定义窗口展示方式，参数传给ShowWindow函数，这里为SW_SHOW
	);
}
/*
DWORD WINAPI TimeThread(LPVOID lparam){
	char str[200]="Dynamic Wallpaper Tools";
	while(true){
		SYSTEMTIME st;
		GetLocalTime(&st);
		strcpy(str,"Dynamic Wallpaper Tools Date: ");
		strcat(str,NumToString(st.wYear));
		strcat(str,"/");
		strcat(str,NumToString(st.wMonth));
		strcat(str,"/");
		strcat(str,NumToString(st.wDay));
		strcat(str," Time: ");
		strcat(str,NumToString(st.wHour));
		strcat(str,":");
		strcat(str,NumToString(st.wMinute));
		strcat(str,":");
		strcat(str,NumToString(st.wSecond));
		strcat(str,((LangID==0)?" Language: English":((LangID==1)?" 语言: 中文简体":" 語言：中文繁體"))); 
		SetWindowText(HWND_,str);
	}
}*/

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI winMain(_In_ HINSTANCE hINstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nShowCmd) {
	//LoadUI();
	
	HInstance = GetModuleHandle(NULL);
	WNDCLASS wc1 = {};
    wc1.lpfnWndProc = TrayNotificationCallback;
    wc1.hInstance = GetModuleHandle(NULL);
    wc1.lpszClassName = "TrayIconWindowClass";
    if(!RegisterClass(&wc1)){//注册系统托盘图标窗口类 
    	MessageBox(NULL,"Tray Icon Registration Failed!","Error",MB_ICONWARNING|MB_OK);
    	return 0;
	}
    HWND hWnd = CreateWindowEx(0, wc1.lpszClassName, "TrayIconWindow", 0, 0, 0, 0, 0, HWND_MESSAGE, 0, wc1.hInstance, 0);//窗口托盘图标处理窗口 
	//创建 
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hWnd;
    nid.uID = 10000;
    nid.uVersion = NIM_SETVERSION;
    nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE | NIF_INFO;//托盘图标标记 
    nid.uCallbackMessage = WM_USER;
    nid.hIcon = LoadIcon(hINstance,"A"); // 从资源加载图标
    Shell_NotifyIcon(NIM_ADD,&nid);
    ToastMessage("Dynamic Wallpaper Tools","^_^",GetString4ThisLang(78));//打开ToastMessage 
    //Shell_NotifyIcon(NIM_SETVERSION, &nid);
	
    //CreateThread(NULL,NULL,nidThread,NULL,NULL,NULL);//启动线程 
    //Sleep(200);
    
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc, 0, sizeof(wc));//注册主窗口类 
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WndProc; /* This is where we will send messages to */
	wc.hInstance = HInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.style=CS_DBLCLKS|CS_SAVEBITS|CS_GLOBALCLASS;

	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = CreateSolidBrush(RGB(25,25,25));//(HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszClassName = "DWPT_PRIVATECLASS";
	wc.hIcon = LoadIcon(hINstance,"IDI_SELECTUNUSE"); /* Load a standard icon */
	wc.hIconSm = LoadIcon(hINstance,"A"); /* use the name "A" to use the project icon */

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);//判断是否成功 
		return 0;
	}
	
	//添加历史到HistroyMenu
	char str[10],path[1145];
	for(int i=0;i<=9;i++){
		sprintf(str,"File[%d]",i);
		GetPrivateProfileString("Histroy",str,NULL,path,MAX_PATH+2,ConfigFile);
		AppendMenu(HistroyMenu,MF_STRING,16+i,path); 
	}
	
	HMENU menu=CreateMenu(),OPEN=CreatePopupMenu(),AboutMenu=CreatePopupMenu(),DefMenu=CreatePopupMenu();//添加菜单项 
	GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","BLAS",RETURN);//获取注册表项 
	AppendMenu(FileMenu,((strcmp(RETURN,"true")==0)?MF_CHECKED:MF_UNCHECKED),10,GetString4ThisLang(15));//开机自启动项 
	AppendMenu(OPEN,MF_STRING,2,GetString4ThisLang(17));//编辑配置文件 
	AppendMenu(OPEN,MF_STRING,3,GetString4ThisLang(24));//启动配置文件 
	AppendMenu(OPEN,MF_STRING,7,GetString4ThisLang(25));//设置为默认项 
	AppendMenu(DefMenu,MF_STRING,8,GetString4ThisLang(17));//编辑默认配置文件 
	AppendMenu(DefMenu,MF_STRING,9,GetString4ThisLang(24));//启动默认配置文件 
	AppendMenu(FileMenu,MF_STRING,1,StringCat(GetString4ThisLang(0)," (&N)"));//新建配置文件项 
	AppendMenu(FileMenu,MF_HILITE,0,NULL);//分割线 
	AppendMenu(FileMenu,MF_POPUP,(UINT_PTR)DefMenu,GetString4ThisLang(31));//打开默认项并。。。 
	AppendMenu(FileMenu,MF_POPUP,(UINT_PTR)OPEN,GetString4ThisLang(30));//打开并。。。 
	AppendMenu(FileMenu,MF_POPUP,(UINT_PTR)HistroyMenu,GetString4ThisLang(52));//历史 
	AppendMenu(FileMenu,MF_HILITE,0,NULL);//分割线 
	AppendMenu(FileMenu,MF_STRING,5,GetString4ThisLang(29));//结束动态壁纸 
	AppendMenu(FileMenu,MF_STRING,4,GetString4ThisLang(20));//退出 
	AppendMenu(menu,MF_POPUP,(UINT_PTR)FileMenu,GetString4ThisLang(27));//文件 
	AppendMenu(FuncMenu,MF_STRING|((GetPrivateProfileInt("Main","DevMode",0,ConfigFile)==true)?MF_ENABLED:MF_DISABLED),15,GetString4ThisLang(54));//打开WinWatcher工具 
	AppendMenu(FuncMenu,MF_STRING|((GetPrivateProfileInt("Main","DevMode",0,ConfigFile)==true)?MF_ENABLED:MF_DISABLED),27,GetString4ThisLang(56));//生成 GUID \ UUID
	AppendMenu(FuncMenu,MF_STRING,34,GetString4ThisLang(69));//设置默认字体
	AppendMenu(menu,MF_POPUP,(UINT_PTR)FuncMenu,GetString4ThisLang(53));//功能
	AppendMenu(LangMenu,MF_STRING|((SGetLangId(false,false)==0)?MF_CHECKED:MF_UNCHECKED),36,GetString4ThisLang(74));//英语 
	AppendMenu(LangMenu,MF_STRING|((SGetLangId(false,false)==1)?MF_CHECKED:MF_UNCHECKED),37,GetString4ThisLang(75));//简体中文 
	AppendMenu(LangMenu,MF_STRING|((SGetLangId(false,false)==2)?MF_CHECKED:MF_UNCHECKED),38,GetString4ThisLang(76));//繁体中文 
	AppendMenu(menu,MF_POPUP,(UINT_PTR)LangMenu,GetString4ThisLang(73));//语言 
	AppendMenu(AboutMenu,MF_STRING,12,GetString4ThisLang(45));//如何使用 
	AppendMenu(AboutMenu,MF_STRING,6,GetString4ThisLang(28));//弹出关于信息框 
	AppendMenu(menu,MF_POPUP,(UINT_PTR)AboutMenu,GetString4ThisLang(26));//关于 
	//创建各种菜单 
	
	HWND_ = CreateWindowEx(WS_EX_ACCEPTFILES,"DWPT_PRIVATECLASS", "Dynamic Wallpaper Tools", WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | DS_FIXEDSYS | DS_3DLOOK | DS_SETFONT | DS_MODALFRAME | DS_NOIDLEMSG,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		800, /* width */
		400/*60*/, /* height */
		NULL, menu, HInstance, NULL);//创建窗口 

	if (HWND_ == NULL) {//判断是否成功 
		MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	/*
	MENUINFO menuInfo={0};
	menuInfo.cbSize=sizeof(MENUINFO);
	menuInfo.fMask=MIM_BACKGROUND;
	menuInfo.hbrBack=CreateSolidBrush(RGB(44,44,44));
	SetMenuInfo(FileMenu,&menuInfo);
	DrawMenuBar(HWND_);*/
	//SendMessage(HWND_, WM_MENUSELECT, (WPARAM)menu, MAKELPARAM(0, MF_BYPOSITION));
	//DeleteObject(menuInfo.hbrBack);
	
	//CreateWindow("Button","BUTTON",WS_CHILD|WS_VISIBLE,20,200,100,100,HWND_,NULL,NULL,NULL); 
	TCITEM tie;
    LRESULT count, id;
    
    hTab = CreateWindow("SysTabControl32", NULL, WS_CHILD | WS_VISIBLE,
        0, 0, 800, 400, HWND_,(HMENU) 13, NULL, NULL);//创建Tab Control
    SendMessage(hTab,WM_SETFONT,(WPARAM)hFont,NULL);
    for(int i=0;i<5;i++){//创建两个窗口和控件 
		tie.mask = TCIF_TEXT;
	    if(i<2) tie.pszText = GetString4ThisLang(13+i);//获取语言文本 
	    else if(i==2) tie.pszText=GetString4ThisLang(46);
	    else if(i==3) tie.pszText=GetString4ThisLang(58);
	    else if(i==4) tie.pszText=(char*)"Profile Editor";
		if(i==0){
			hConfig=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);
			for(int j=0;j<5;j++){//记住：Dev C++编译时要在 项目[P] -> 项目属性[O] 里面选中"支持 Windows XP 主题"，否则难看到去世！！！ 
				HWND hwnd=CreateWindow(BUTTON_CLASS,GetString4ThisLang(j)/*BtnName[i]*/,WS_CHILD|WS_VISIBLE|BS_COMMANDLINK,BtnPos[j].left,BtnPos[j].top,BtnPos[j].right-BtnPos[j].left,BtnPos[j].bottom-BtnPos[j].top,hConfig,(HMENU)BtnWparam[j],NULL,NULL);
				//CreateButton(BtnName[i],BtnPos[i].left,BtnPos[i].top,BtnPos[i].right-BtnPos[i].left,BtnPos[i].bottom-BtnPos[i].top,HWND_,(HMENU)BtnWparam[i],NULL,NULL);
				SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,NULL);
				//SendMessage(hwnd,BCM_SETNOTE,NULL,(LPARAM)GetString4ThisLang(64+j));
				//SendMessage(hwnd,BCM_SETNOTE,NULL,(LPARAM)NoteText[j][0]);
			}
			CreateWindowEx(0,"SysLink","<A HREF=\"https://github.com/BOffice-Excel/Excel-s-Dynamic-Wallpaper-Tools\">Github</A>  <A HREF=\"https://boffice-excel.github.io/Website/DWPT/\">Homepage</A>",WS_VISIBLE|WS_CHILD,20,270,500,30,hConfig, (HMENU)39, NULL, NULL);
			SendDlgItemMessage(hConfig,39,WM_SETFONT,(WPARAM)hFont,NULL);
			ShowWindow(hConfig,SW_SHOW);
		}
		else if(i==1){
			hSet=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);
			HWND hwnd=CreateWindow(BUTTON_CLASS,0,WS_CHILD|WS_VISIBLE|BS_CHECKBOX,20,20,25,25,hSet,(HMENU)10,NULL,NULL);//开机自启动 
			SendMessage(CreateWindow("STATIC",GetString4ThisLang(15),WS_CHILD|WS_VISIBLE,45,20,225,25,hSet,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			CreateWindow(BUTTON_CLASS,0,WS_CHILD|WS_VISIBLE|BS_CHECKBOX,300,20,25,25,hSet,(HMENU)40,NULL,NULL);//是否在启动时启动动态壁纸 
			SendMessage(CreateWindow("STATIC",GetString4ThisLang(82),WS_CHILD|WS_VISIBLE,325,20,735,25,hSet,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendDlgItemMessageA(hSet,40,WM_SETFONT,(WPARAM)hFont,NULL);
			CreateWindow(BUTTON_CLASS,0,WS_CHILD|WS_VISIBLE|BS_CHECKBOX,20,140,25,25,hSet,(HMENU)35,NULL,NULL);
			SendMessage(CreateWindow("STATIC","Developer Options",WS_CHILD|WS_VISIBLE,45,140,735,25,hSet,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendDlgItemMessageA(hSet,35,WM_SETFONT,(WPARAM)hFont,NULL);
			CheckDlgButton(hSet,35,((GetPrivateProfileInt("Main","DevMode",0,ConfigFile)==1)?BST_CHECKED:BST_UNCHECKED));//设置CheckBox是否被确认 
			SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,NULL);
			GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","BLAS",RETURN);
			CheckDlgButton(hSet,10,((strcmp(RETURN,"true")==0)?BST_CHECKED:BST_UNCHECKED));//设置CheckBox是否被确认 
			GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",RETURN);
			char str[1145];
			sprintf(str,"%s%s",GetString4ThisLang(16),RETURN);
			hStaticDef=CreateWindow(STATIC_CLASS,str,WS_CHILD|WS_VISIBLE,20,60,660,25,hSet,(HMENU)100,NULL,NULL);
			SendMessage(hStaticDef,WM_SETFONT,(WPARAM)hFont,NULL);
			hBossKey=CreateWindowEx(0,"msctls_hotkey32",NULL,WS_CHILD|WS_VISIBLE,160,100,500,30,hSet,NULL,NULL,NULL);
			SendMessage(hBossKey,WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,STATIC_CLASS,GetString4ThisLang(51),WS_CHILD|WS_VISIBLE,20,100,120,30,hSet,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,BUTTON_CLASS,GetString4ThisLang(47),WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,680,100,100,30,hSet,(HMENU)26,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			hwnd=CreateWindow(BUTTON_CLASS,GetString4ThisLang(17),WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,680,60,100,30,hSet,(HMENU)7,NULL,NULL);
			SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,NULL);
			ShowWindow(hSet,SW_HIDE);//隐藏hSet窗口 
		}
		else if(i==2){
			hAnyWindow=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);	
			ShowWindow(hAnyWindow,SW_HIDE);
			SendMessage(CreateWindowEx(0,BUTTON_CLASS,0,WS_CHILD|WS_VISIBLE|BS_GROUPBOX,50,10,700,280,hAnyWindow,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindow("STATIC",GetString4ThisLang(48),WS_CHILD|WS_VISIBLE,70,10,300,25,hAnyWindow,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			hsti=CreateWindowEx(0,BUTTON_CLASS,NULL,WS_CHILD|WS_VISIBLE|BS_ICON,100,50,50,50,hAnyWindow,(HMENU)13,NULL,NULL);
			SendMessage(hsti, BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(hINstance,"IDI_SELECTUNUSE"));
			SendMessage(CreateWindowEx(0,STATIC_CLASS,GetString4ThisLang(49),WS_CHILD|WS_VISIBLE,100,120,600,120,hAnyWindow,(HMENU)1,NULL,NULL),WM_SETFONT,
				(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,STATIC_CLASS,GetString4ThisLang(50),WS_CHILD|WS_VISIBLE,100,250,650,25,hAnyWindow,(HMENU)2,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,BUTTON_CLASS,GetString4ThisLang(47),WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,685,200,60,40,hAnyWindow,(HMENU)14,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,BUTTON_CLASS,GetString4ThisLang(79),WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,625,200,60,40,hAnyWindow,(HMENU)39,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
		}
		else if(i==3){
			hFB=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);
			ShowWindow(hFB,SW_HIDE);
			//SendMessage(CreateWindowEx(0,"BUTTON","",BS_ICON|WS_VISIBLE|WS_CHILD,760,10,32,32,hFB,(HMENU)33,NULL,NULL), BM_SETIMAGE, IMAGE_BITMAP,(LPARAM)LoadBitmap(hINstance,"IDB_OPEN"));
			SendMessage(CreateWindowEx(0,BUTTON_CLASS,"...",WS_VISIBLE|WS_CHILD,760,10,32,32,hFB,(HMENU)33,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,BUTTON_CLASS,GetString4ThisLang(63),BS_SPLITBUTTON|WS_VISIBLE|WS_CHILD,160,220,200,80,hFB,(HMENU)32,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,STATIC_CLASS,GetString4ThisLang(62),WS_VISIBLE|WS_CHILD,10,10,150,125,hFB,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,BUTTON_CLASS,GetString4ThisLang(100),WS_VISIBLE|WS_CHILD,20,220,100,32,hFB,(HMENU)41,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,EDIT_CLASS,"",WS_VISIBLE|WS_CHILD|WS_VSCROLL|ES_MULTILINE|ES_AUTOVSCROLL|WS_BORDER,160,10,600,200,hFB,(HMENU)29,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
		}
		else if(i==4){
			hEditor=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);
			ShowWindow(hEditor,SW_HIDE);
			SendMessage(CreateWindowEx(0,BUTTON_CLASS,"...",WS_VISIBLE|WS_CHILD,760,10,32,32,hEditor,(HMENU)33,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,BUTTON_CLASS,GetString4ThisLang(95),BS_SPLITBUTTON|WS_VISIBLE|WS_CHILD,160,220,200,80,hEditor,(HMENU)42,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,STATIC_CLASS,GetString4ThisLang(99),WS_VISIBLE|WS_CHILD,10,10,150,200,hEditor,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,BUTTON_CLASS,GetString4ThisLang(100),WS_VISIBLE|WS_CHILD,20,220,100,32,hEditor,(HMENU)41,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,EDIT_CLASS,"",WS_VISIBLE|WS_CHILD|WS_VSCROLL|ES_MULTILINE|ES_AUTOVSCROLL|WS_BORDER,160,10,600,200,hEditor,(HMENU)29,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindow(BUTTON_CLASS,0,WS_CHILD|WS_VISIBLE|BS_AUTOCHECKBOX,400,250,25,25,hEditor,(HMENU)45,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindow("STATIC",GetString4ThisLang(98),WS_CHILD|WS_VISIBLE,425,250,735,25,hEditor,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
		}
	    //count=SendMessage(hTab, TCM_GETITEMCOUNT, 0, 0);
	    SendMessage(hTab, TCM_INSERTITEM, i, (LPARAM) (LPTCITEM) &tie);//添加
	}
	HMODULE hModule=NULL;
	hModule=LoadLibrary("uxtheme.dll");
	if(hModule){
		typedef VOID (*SWT)(HWND,LPCWSTR,LPCWSTR);
		SWT SetWindowTheme=(SWT)GetProcAddress(hModule,"SetWindowTheme");
		if(SetWindowTheme){
			for(int i=0;i<=50;i++){
				HWND hTmp;
				hTmp=GetDlgItem(hConfig,i);
				if(hTmp) SetWindowTheme(hTmp,L"DarkMode_Explorer",NULL);
				hTmp=GetDlgItem(hSet,i);
				if(hTmp) SetWindowTheme(hTmp,L"DarkMode_Explorer",NULL);
				hTmp=GetDlgItem(hAnyWindow,i);
				if(hTmp) SetWindowTheme(hTmp,L"DarkMode_Explorer",NULL);
				hTmp=GetDlgItem(hFB,i);
				if(hTmp) SetWindowTheme(hTmp,L"DarkMode_Explorer",NULL);
				hTmp=GetDlgItem(hEditor,i);
				if(hTmp) SetWindowTheme(hTmp,L"DarkMode_Explorer",NULL);
			};
			SetWindowTheme(hTab,L"DarkMode_Explorer",NULL);
			SetWindowTheme(HWND_,L"DarkMode_Explorer",NULL);
		}
	}
	
	HMENU hMenu=GetSystemMenu(HWND_,FALSE);
	AppendMenu(hMenu,MF_HILITE,0,NULL);//分割线 
	AppendMenu(hMenu,MF_STRING,11,GetString4ThisLang(44));//缩小到系统托盘 
	AppendMenu(hMenu,MF_STRING,4,GetString4ThisLang(20));//退出 
	//修改窗口的默认系统菜单

	/*
		This is the heart of our program where all input is processed and
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	
	ShowWindow(HWND_, nShowCmd);//展示窗口（也可以是在静态启动时隐藏窗口） 
	UpdateWindow(HWND_);//更新窗口 
	
	//CreateThread(NULL,NULL,TimeThread,NULL,NULL,NULL);
	
	while (GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}//主循环 
	
    Shell_NotifyIcon(NIM_DELETE, &nid);//删除图标 
	return (int)msg.wParam;//返回值 
}
