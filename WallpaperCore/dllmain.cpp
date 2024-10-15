/* Replace "dll.h" with the name of your header */
#include "dll.h"
char MUIText[][3][260]={//多语言支持功能文本，全在这里了 
	{"Create profile","新建配置文件","新建設定檔"},//0
	{"Edit profile","编辑配置文件","編輯設定檔"},
	{"Apply profile","应用配置文件","應用設定檔"},
	{"Stop Wallpaper","停止动态壁纸","停止動態桌面"},
	{"About Dynamic Wallpaper Tools","关于Dynamic Wallpaper Tools","關於Dynamic Wallpaper Tools"},
	{"Unable to open the video display program \"mshta.exe\" (playing videos using a browser), please check if the program exists in the system directory","无法打开视频显示程序\"mshta.exe\"（使用浏览器播放视频），请检查系统目录下程序是否存在","無法打開視頻顯示程式\"mshta.exe\"（使用瀏覽器播放視頻），請檢查系統目錄下程式是否存在"},
	{"Warning! This operation will close all windows under the class name \"Progman\"!","警告！此操作会关闭所有在类名为“Progman”的窗口下的所有窗口！","警告！ 此操作會關閉所有在類名為“Progman”的視窗下的所有視窗"},
	{"Video files (*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv)\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0All files (*.*) \0*.*\0","视频文件（*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv）\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0所有文件（*.*）\0*.*\0","視頻檔案（*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv）\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0所有檔案（*.*）\0*.*\0"},
	{"Dynamic Wallpaper Configuration Files (.dp)\0*.dp\0","Dynamic Wallpaper配置文件（.dp）\0*.dp\0","Dynamic Wallpaper設定檔（.dp）\0*.dp\0"},
	{"Do you need to play sound?","是否需要播放声音？","是否需要播放聲音？"},//9
	{
		"Programming: Office Excel\nReference video by 偶尔有点小迷糊, video id: BV1HZ4y1978a (press to cancel to view original video)\nTools used: Dev-C++, Code language: C++\nProject start date: April 21, 2024\nVersion: 0.0.7.2\nTranslator: Baidu Translate",
		"程序制作：Office-Excel\n参考视频 by 偶尔有点小迷糊，视频id：BV1HZ4y1978a（按下取消查看原视频）\n使用工具：Dev-C++，代码语言：C++\n项目开始日期：2024/04/21\n版本：0.0.7.2\n翻译器：百度翻译",
		"程式製作：Office-Excel\n參攷視頻 by 偶尔有点小迷糊，視頻id:BV1HZ4y1978a（按下取消查看原視頻）\n使用工具：Dev-C++，程式碼語言：C++\n項目開始日期：2024/04/21\n版本：0.0.7.2\n翻譯器：百度翻譯"
	},//10
	{"The configuration file operation is complete. Do you want to start it now?","配置文件操作完成，是否要马上启动？","設定檔操作完成，是否要馬上啟動？"},
	{"Please select the object you want to modify:\nYes -> Modify video file path\nNo -> Modify whether there is sound\nCancel -> Do nothing","请选择要修改的对象：\n 是->修改视频文件路径\n 否->修改是否有声音\n 取消->什么也不做","請選擇要修改的對象：\n是->修改視頻檔案路徑\n否->修改是否有聲音\n取消->什麼也不做"},
	{"Wallplaper Config","壁纸配置","桌面配寘"},
	{"Global settings","全局设置","全域設定"},
	{"Self start upon startup","开机自启动","開機自啟動"},//15
	{"Current default item:","当前默认项：","當前默認項："},
	{"Edit","编辑","編輯"},
	{"Registry modification failed!","注册表修改失败！","註冊表修改失敗！"},//18
	{"Do you want to restart explorer.exe? This may result in a black screen for a while. If Win11 users set a right angle, it will turn back into a rounded corner. Please make a careful decision!","是否需要重启explorer.exe？这可能会黑屏一会儿，Win11用户如果设置了直角会变回圆角，请慎重决定！","是否需要重啓explorer.exe？ 這可能會黑屏一會兒，Win11用戶如果設定了直角會變回圓角，請慎重决定！"},
	{"Quit(&Q)","退出（&Q）","退出（&Q）"},//20
	{"Registry modification completed!","注册表修改完成！","註冊表修改完成！"},
	{"Do you need to set this configuration item as the default (including startup default)：","是否需要将这个配置项设置为默认项（包括启动默认项）：","是否需要將這個配寘項設定為默認項（包括啟動默認項）："},
	{"explorer.exe has been restarted and completed, you can continue your work now!","explorer.exe已重启完成，您可以继续您的工作了！","explorer.exe已重啓完成，您可以繼續您的工作了！"},
	{"Apply","应用","應用"},
	{"Set as default configuration","设置为默认配置","設定為默認配寘"},
	{"Help(&H)","帮助（&H）","幫助（&H）"},
	{"Operation(&O)","操作（&O）","操作（&O）"},//27
	{"About(&A)","关于（&A）","關於（&A）"},
	{"End dynamic wallpaper(&E)","结束动态壁纸（&E）","結束動態桌面（&E）"},
	{"Open and...(&C)","打开并...（&C）","打開並...（&C）"},//30
	{"Open the default item and...(&D)","打开默认项并...（&D）","打開默認項並...（&D）"},
	{"The program has already started, please do not execute it again!","程序已经启动了，请不要再次执行！","程式已經啟動了，請不要再次執行！"},
	{"The original value was: ","原来的值为：","原來的值為："},
	{"\nDo you want to modify it?","\n是否要修改？","\n是否要修改？"},
	{"Please select: ","请选择：","請選擇："},//35
	{"The video path has been modified!","视频路径已修改完成！","視頻路徑已修改完成！"},//36
	{"The modification of the video path has been canceled...","已取消修改视频路径。。。","已取消修改視頻路徑。。。"},
	{"The original value for playing sound when using dynamic wallpapers is:","原来是否在使用动态壁纸时播放声音的值为：","原來是否在使用動態桌面時播放聲音的值為："},
	{"Yes","是","否"},
	{"No","否","否"},//40
	{"\nPlease select: ","\n请选择：","\n請選擇："},
	{"Do you want to save this modification?","是否要保存这次的修改？","是否要保存這次的修改？"},
	{"Do you want to apply it now?","是否要立即应用： ","是否要立即應用？"},
	{"Shrink to system tray","缩小到系统托盘","縮小到系統託盤"},
	{"How to use it?","如何使用？","如何使用？"},//45
	{"Advanced Options","高级选项","高級選項"},
	{"Set","设置","設置"},
	{"Set any window as wallpaper (Unsafe)","将任意窗口设置为壁纸（不安全）","將任意視窗設定為桌面（不安全）"},
	{"Title of Window: ","窗口标题：","視窗標題："},
	{"Class Name of Window: ","窗口类名：","視窗類名："},//50
	{"Boss key:","老板键：","老闆鍵："},
	{"Histroy","历史","歷史"},
	{"Tools (&T)","工具（&T）","工具（&T）"},
	{"Open the WinWatcher tool","打开WinWatcher工具","打開WinWatcher工具"},//54
	{"The path is invalid \\ The file does not exist, unable to start the dp configuration file","路径不合法\\文件不存在，无法启动dp配置文件","路徑不合法\\檔案不存在，無法啟動dp設定檔"},
	{"Generate GUID","生成 GUID","生成 GUID"},
	{"Generate UUID","生成 UUID","生成 UUID"},//已废除//57
	{"Fast Boot","快速启动","快速啟動"},//58
	{"Error: The target video does not exist","错误：目标视频不存在","錯誤：目標視頻不存在"},//59
	{"Mute and start","静音并启动","靜音並啟動"},
	{"Do not mute and start","不静音并启动","不靜音並啟動"},//61
	{"Video Path: \r\n\r\nSupports: \r\nLocal Video","视频路径：\r\n\r\n支持项：\r\n本地视频","視頻路徑：\r\n\r\n支持項：\r\n本地視頻"},//62
	{"Launch","启动","啟動"},//63
	{"Save a configuration file to save wallpaper settings.","保存一个配置文件以保存壁纸设置。","保存一個設定檔以保存桌面設定。"},//64
	{"Modify a configuration file to change wallpaper settings.","修改一个配置文件以更改壁纸设置。","修改一個設定檔以更改桌面設定。"},//65
	{"Open a configuration file to start dynamic wallpaper.","打开一个配置文件以启动动态壁纸。","打開一個設定檔以啟動動態桌面。"},
	{"Close all windows created by mshta.exe to stop dynamic wallpapers.","关闭所有mshta.exe创建的窗口以停止动态壁纸。","關閉所有mshta.exe創建的視窗以停止動態桌面。"},
	{"Open 'About'","打开“关于”","打開“關於”"},//68
	{"Set Default Font","设置默认字体","設定預設字體"},//69
	{"Font setting completed, font name: ","字体已设置完成，字体名称：","字體已設定完成，字體名稱："},//70
	{". After restarting the program, the font will take effect!","，重新启动程序后字体将生效！","，重新啟動程式後字體將生效！"},//71
	{"Please select a font to continue initialization. If you want to try again, please restart this program.","请选择一个字体以继续初始化，如果您要重试，请重新启动本程序。","請選擇一個字體以繼續初始化，如果您要重試，請重新啟動本程式。"},//72
	{"Language","语言","語言"},//73
	{"English","英语","英語"},//74
	{"Chinese Simplified","简体中文","簡體中文"},//75
	{"Chinese Traditional","繁体中文","繁體中文"},//76
	{"The language has been updated and will take effect after restarting the program!","语言已更新，重启程序后将生效！","語言已更新，重啓程式後將生效！"},//77
	{"The program has been started. Please don't run again!","程序已启动完成，请不要二次运行！","程式已啟動完成，請不要二次啟動！"},//78
	{"Close","关闭","關閉"},//79
	{"The dynamic wallpaper has been launched and completed!","动态壁纸已启动完成！","動態桌面已啟動完成！"},//80
	{"Explorer.exe has been restarted and completed!","Explorer.exe已重启完成！","Explorer.exe已重啓完成！"},//81
};

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
