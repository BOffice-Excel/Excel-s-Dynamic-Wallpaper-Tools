/* Replace "dll.h" with the name of your header */
#include "dll.h"
char MUIText[][3][260]={//������֧�ֹ����ı���ȫ�������� 
	{"Create profile","�½������ļ�","�½��O���n"},//0
	{"Edit profile","�༭�����ļ�","��݋�O���n"},
	{"Apply profile","Ӧ�������ļ�","�����O���n"},
	{"Stop Wallpaper","ֹͣ��̬��ֽ","ֹͣ�ӑB����"},
	{"About Dynamic Wallpaper Tools","����Dynamic Wallpaper Tools","�P�Dynamic Wallpaper Tools"},
	{"Unable to open the video display program \"mshta.exe\" (playing videos using a browser), please check if the program exists in the system directory","�޷�����Ƶ��ʾ����\"mshta.exe\"��ʹ�������������Ƶ��������ϵͳĿ¼�³����Ƿ����","�o�����_ҕ�l�@ʾ��ʽ\"mshta.exe\"��ʹ�Þg�[������ҕ�l����Ո�z��ϵ�yĿ��³�ʽ�Ƿ����"},
	{"Warning! This operation will close all windows under the class name \"Progman\"!","���棡�˲�����ر�����������Ϊ��Progman���Ĵ����µ����д��ڣ�","���棡 �˲������P�]����������顰Progman����ҕ���µ�����ҕ��"},
	{"Video files (*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv)\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0All files (*.*) \0*.*\0","��Ƶ�ļ���*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv��\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0�����ļ���*.*��\0*.*\0","ҕ�l�n����*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv��\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0���Йn����*.*��\0*.*\0"},
	{"Dynamic Wallpaper Configuration Files (.dp)\0*.dp\0","Dynamic Wallpaper�����ļ���.dp��\0*.dp\0","Dynamic Wallpaper�O���n��.dp��\0*.dp\0"},
	{"Do you need to play sound?","�Ƿ���Ҫ����������","�Ƿ���Ҫ��������"},//9
	{
		"Programming: Office Excel\nReference video by ż���е�С�Ժ�, video id: BV1HZ4y1978a (press to cancel to view original video)\nTools used: Dev-C++, Code language: C++\nProject start date: April 21, 2024\nVersion: 0.0.7.2\nTranslator: Baidu Translate",
		"����������Office-Excel\n�ο���Ƶ by ż���е�С�Ժ�����Ƶid��BV1HZ4y1978a������ȡ���鿴ԭ��Ƶ��\nʹ�ù��ߣ�Dev-C++���������ԣ�C++\n��Ŀ��ʼ���ڣ�2024/04/21\n�汾��0.0.7.2\n���������ٶȷ���",
		"��ʽ�u����Office-Excel\n����ҕ�l by ż���е�С�Ժ���ҕ�lid:BV1HZ4y1978a������ȡ���鿴ԭҕ�l��\nʹ�ù��ߣ�Dev-C++����ʽ�a�Z�ԣ�C++\n�Ŀ�_ʼ���ڣ�2024/04/21\n�汾��0.0.7.2\n���g�����ٶȷ��g"
	},//10
	{"The configuration file operation is complete. Do you want to start it now?","�����ļ�������ɣ��Ƿ�Ҫ����������","�O���n������ɣ��Ƿ�Ҫ�R�φ��ӣ�"},
	{"Please select the object you want to modify:\nYes -> Modify video file path\nNo -> Modify whether there is sound\nCancel -> Do nothing","��ѡ��Ҫ�޸ĵĶ���\n ��->�޸���Ƶ�ļ�·��\n ��->�޸��Ƿ�������\n ȡ��->ʲôҲ����","Ո�x��Ҫ�޸ĵČ���\n��->�޸�ҕ�l�n��·��\n��->�޸��Ƿ�����\nȡ��->ʲ�NҲ����"},
	{"Wallplaper Config","��ֽ����","�����䌅"},
	{"Global settings","ȫ������","ȫ���O��"},
	{"Self start upon startup","����������","�_�C�Ԇ���"},//15
	{"Current default item:","��ǰĬ���","��ǰĬ�J헣�"},
	{"Edit","�༭","��݋"},
	{"Registry modification failed!","ע����޸�ʧ�ܣ�","�]�Ա��޸�ʧ����"},//18
	{"Do you want to restart explorer.exe? This may result in a black screen for a while. If Win11 users set a right angle, it will turn back into a rounded corner. Please make a careful decision!","�Ƿ���Ҫ����explorer.exe������ܻ����һ�����Win11�û����������ֱ�ǻ���Բ�ǣ������ؾ�����","�Ƿ���Ҫ�؆�explorer.exe�� �@���ܕ�����һ������Win11�Ñ�����O����ֱ�Ǖ�׃�؈A�ǣ�Ո���ؾ�����"},
	{"Quit(&Q)","�˳���&Q��","�˳���&Q��"},//20
	{"Registry modification completed!","ע����޸���ɣ�","�]�Ա��޸���ɣ�"},
	{"Do you need to set this configuration item as the default (including startup default)��","�Ƿ���Ҫ���������������ΪĬ�����������Ĭ�����","�Ƿ���Ҫ���@���䌅��O����Ĭ�J헣���������Ĭ�J헣���"},
	{"explorer.exe has been restarted and completed, you can continue your work now!","explorer.exe��������ɣ������Լ������Ĺ����ˣ�","explorer.exe���؆���ɣ��������^�m���Ĺ����ˣ�"},
	{"Apply","Ӧ��","����"},
	{"Set as default configuration","����ΪĬ������","�O����Ĭ�J�䌅"},
	{"Help(&H)","������&H��","������&H��"},
	{"Operation(&O)","������&O��","������&O��"},//27
	{"About(&A)","���ڣ�&A��","�P춣�&A��"},
	{"End dynamic wallpaper(&E)","������̬��ֽ��&E��","�Y���ӑB���棨&E��"},
	{"Open and...(&C)","�򿪲�...��&C��","���_�K...��&C��"},//30
	{"Open the default item and...(&D)","��Ĭ���...��&D��","���_Ĭ�J헁K...��&D��"},
	{"The program has already started, please do not execute it again!","�����Ѿ������ˣ��벻Ҫ�ٴ�ִ�У�","��ʽ�ѽ������ˣ�Ո��Ҫ�ٴΈ��У�"},
	{"The original value was: ","ԭ����ֵΪ��","ԭ���ֵ�飺"},
	{"\nDo you want to modify it?","\n�Ƿ�Ҫ�޸ģ�","\n�Ƿ�Ҫ�޸ģ�"},
	{"Please select: ","��ѡ��","Ո�x��"},//35
	{"The video path has been modified!","��Ƶ·�����޸���ɣ�","ҕ�l·�����޸���ɣ�"},//36
	{"The modification of the video path has been canceled...","��ȡ���޸���Ƶ·��������","��ȡ���޸�ҕ�l·��������"},
	{"The original value for playing sound when using dynamic wallpapers is:","ԭ���Ƿ���ʹ�ö�̬��ֽʱ����������ֵΪ��","ԭ���Ƿ���ʹ�ÄӑB����r��������ֵ�飺"},
	{"Yes","��","��"},
	{"No","��","��"},//40
	{"\nPlease select: ","\n��ѡ��","\nՈ�x��"},
	{"Do you want to save this modification?","�Ƿ�Ҫ������ε��޸ģ�","�Ƿ�Ҫ�����@�ε��޸ģ�"},
	{"Do you want to apply it now?","�Ƿ�Ҫ����Ӧ�ã� ","�Ƿ�Ҫ�������ã�"},
	{"Shrink to system tray","��С��ϵͳ����","�sС��ϵ�yӚ�P"},
	{"How to use it?","���ʹ�ã�","���ʹ�ã�"},//45
	{"Advanced Options","�߼�ѡ��","�߼��x�"},
	{"Set","����","�O��"},
	{"Set any window as wallpaper (Unsafe)","�����ⴰ������Ϊ��ֽ������ȫ��","������ҕ���O�������棨����ȫ��"},
	{"Title of Window: ","���ڱ��⣺","ҕ�����}��"},
	{"Class Name of Window: ","����������","ҕ�������"},//50
	{"Boss key:","�ϰ����","����I��"},
	{"Histroy","��ʷ","�vʷ"},
	{"Tools (&T)","���ߣ�&T��","���ߣ�&T��"},
	{"Open the WinWatcher tool","��WinWatcher����","���_WinWatcher����"},//54
	{"The path is invalid \\ The file does not exist, unable to start the dp configuration file","·�����Ϸ�\\�ļ������ڣ��޷�����dp�����ļ�","·�����Ϸ�\\�n�������ڣ��o������dp�O���n"},
	{"Generate GUID","���� GUID","���� GUID"},
	{"Generate UUID","���� UUID","���� UUID"},//�ѷϳ�//57
	{"Fast Boot","��������","���ن���"},//58
	{"Error: The target video does not exist","����Ŀ����Ƶ������","�e�`��Ŀ��ҕ�l������"},//59
	{"Mute and start","����������","�o��K����"},
	{"Do not mute and start","������������","���o��K����"},//61
	{"Video Path: \r\n\r\nSupports: \r\nLocal Video","��Ƶ·����\r\n\r\n֧���\r\n������Ƶ","ҕ�l·����\r\n\r\n֧��헣�\r\n����ҕ�l"},//62
	{"Launch","����","����"},//63
	{"Save a configuration file to save wallpaper settings.","����һ�������ļ��Ա����ֽ���á�","����һ���O���n�Ա��������O����"},//64
	{"Modify a configuration file to change wallpaper settings.","�޸�һ�������ļ��Ը��ı�ֽ���á�","�޸�һ���O���n�Ը��������O����"},//65
	{"Open a configuration file to start dynamic wallpaper.","��һ�������ļ���������̬��ֽ��","���_һ���O���n�Ԇ��ӄӑB���档"},
	{"Close all windows created by mshta.exe to stop dynamic wallpapers.","�ر�����mshta.exe�����Ĵ�����ֹͣ��̬��ֽ��","�P�]����mshta.exe������ҕ����ֹͣ�ӑB���档"},
	{"Open 'About'","�򿪡����ڡ�","���_���P춡�"},//68
	{"Set Default Font","����Ĭ������","�O���A�O���w"},//69
	{"Font setting completed, font name: ","������������ɣ��������ƣ�","���w���O����ɣ����w���Q��"},//70
	{". After restarting the program, the font will take effect!","������������������彫��Ч��","�������ӳ�ʽ�����w����Ч��"},//71
	{"Please select a font to continue initialization. If you want to try again, please restart this program.","��ѡ��һ�������Լ�����ʼ���������Ҫ���ԣ�����������������","Ո�x��һ�����w���^�m��ʼ���������Ҫ��ԇ��Ո�����ӱ���ʽ��"},//72
	{"Language","����","�Z��"},//73
	{"English","Ӣ��","Ӣ�Z"},//74
	{"Chinese Simplified","��������","���w����"},//75
	{"Chinese Traditional","��������","���w����"},//76
	{"The language has been updated and will take effect after restarting the program!","�����Ѹ��£������������Ч��","�Z���Ѹ��£��؆���ʽ�ጢ��Ч��"},//77
	{"The program has been started. Please don't run again!","������������ɣ��벻Ҫ�������У�","��ʽ�ц�����ɣ�Ո��Ҫ���Ά��ӣ�"},//78
	{"Close","�ر�","�P�]"},//79
	{"The dynamic wallpaper has been launched and completed!","��̬��ֽ��������ɣ�","�ӑB�����ц�����ɣ�"},//80
	{"Explorer.exe has been restarted and completed!","Explorer.exe��������ɣ�","Explorer.exe���؆���ɣ�"},//81
};

char Path[114514],res[114514];
int LangID=IL_UNSET/*����ID*/;
bool quietMode=false;//�Ƿ����ð���ģʽ��������dp�ļ��У� 
extern "C"{
	DLLIMPORT char* GetString4ThisLang(UINT index){
		if(LangID==IL_UNSET){
			switch(PRIMARYLANGID(GetUserDefaultLangID())){//��ȡ����ID�����õ�ǰ���� 
				case LANG_CHINESE_SIMPLIFIED:LangID=IL_Simplified_Chinese;break;
				case LANG_CHINESE_TRADITIONAL:LangID=IL_Traditional_Chinese;break;
				default:LangID=IL_ENGLISH;break;
			}
		}
		return MUIText[index][LangID];
	}
	
	DLLIMPORT BOOL CALLBACK StopDWPProc(_In_ HWND hWnd,_In_ LPARAM lparam){//ֹͣ��̬��ֽ�Ļص�������Enum������ 
		char Text[1145];
		GetClassName(hWnd,Text,sizeof(Text));
		//GetWindowText(hWnd,Text,GetWindowTextLength(hWnd)+1);
		if(strcmp(Text,"HTML Application Host Window Class")==0) PostMessage(hWnd,WM_CLOSE,0,0);
		return FALSE;
	}
	
	DLLIMPORT BOOL CALLBACK EnumWindowProc(_In_ HWND hwnd, _In_ LPARAM Lparam)//���ģ�������̬��ֽ��Ƕ�봰�ڹ��� 
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
	
	DLLIMPORT WINBOOL PutToDesktop(HWND Wallpaper){//��Wallpaper���ڷŽ������� 
		if(!Wallpaper){//...
			MessageBox(Wallpaper,"������Ž������������������","Error",MB_ICONINFORMATION|MB_OK);
			return FALSE;
		}
		int width=GetDeviceCaps(GetDC(0), DESKTOPHORZRES),height=GetDeviceCaps(GetDC(0), DESKTOPVERTRES);//��ȡ��Ļ�豸�ֱ��� 
		HWND hProgman = FindWindow("Progman", 0), hFfplay = Wallpaper;
		SendMessageTimeout(hProgman, 0x52C, 0, 0, 0, 100, 0);//��ʱ������Ϣ 
		SetWindowPos(hFfplay, NULL, 0, 0, width, height, SWP_NOZORDER);//���ô��ڴ�С��λ�� 
		SetParent(hFfplay, hProgman);//���ø����� 
		EnumWindows(EnumWindowProc, 0);//��������ڷŵ�����ĺ�� 
	    //Shell_NotifyIcon(NIM_SETVERSION, &nid);//Toast Message Box
		return TRUE;
	}
	
	DLLIMPORT DWORD WINAPI DwpThread(LPVOID lparam){//�����߳� 
		if((!quietMode)&&MessageBox(NULL,GetString4ThisLang(6),"Warning",MB_YESNO|MB_ICONWARNING)!=6) return 0; //���� 
		char cmd[1145]=" \"",sound,VP[1145],TmpPath[MAX_PATH+20],str1[MAX_PATH*4];//��ʼ��һ���ı� 
		STARTUPINFO si = {0};
		PROCESS_INFORMATION pi = {0};//�����������̵Ľṹ�� 
		HWND PROGMAN=FindWindow("Progman", 0);
		if(PROGMAN) EnumChildWindows(PROGMAN,StopDWPProc,NULL);
		
		/*SHELLEXECUTEINFO sei = {0};
	    sei.cbSize = sizeof(SHELLEXECUTEINFO);
	    sei.fMask = SEE_MASK_NOCLOSEPROCESS;
	    sei.lpFile = "taskkill.exe";
	    sei.nShow = SW_HIDE;
	    sei.lpParameters = "/F /IM mshta.exe";
	    if (ShellExecuteEx(&sei)) CloseHandle(sei.hProcess);//����������mshta.exe */
	    
		strcpy(str1,"<html>\
	<META http-equiv=\"content-type\" content=\"text/html; charset=GBK\">\
	<meta http-equiv=\"x-ua-compatible\" content=\"IE=9\"/>\
	<head><title>VideoPlayer</title><HTA:APPLICATION APPLICATIONNAME=\"VideoPlayer\"ID=\"VideoPlayer\" BORDER=\"none\" SHOWINTASKBAR=\"no\" VERSION=\"0.0\"/></head>\
	<body><video style=\"width:100%;height:100%;left:0px;top:0px;position:fixed\" autoplay loop");//�����ı� 
		Sleep(500);
		
		DWORD dw=0;
		HANDLE hFile=CreateFile(Path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);//���ļ���� 
		ReadFile(hFile,&sound,1,&dw,NULL);
		ReadFile(hFile,VP,GetFileSize(hFile,NULL)-1,&dw,NULL);
		int i=strlen(VP);
		while(!(VP[i]<='Z'&&VP[i]>='A'||VP[i]<='z'&&VP[i]>='a'||VP[i]<='9'&&VP[i]>='0')) VP[i]=NULL,i--;//�����ļ������� 
		
		//ʹ��mshta.exe����
		GetTempPath(MAX_PATH,TmpPath);//��ȡ��ʱĿ¼������Temporary.hta��ʱ�ļ� 
		strcat(TmpPath,"Temporary.hta");
		if(TmpPath[strlen(TmpPath)-1]=='\r') TmpPath[strlen(TmpPath)-1]=NULL;
		freopen(TmpPath,"w",stdout);
		while(_access(VP,0)==-1) VP[strlen(VP)-1]=NULL;
		printf("%s%s><source src=\"%s",str1,(sound=='t'?"":" muted"),VP);
		strcpy(str1,"\" type=\"video/mp4\">ERROR</video></body></html>");
		printf("%s",str1);
		fclose(stdout);//�˳�д�� 
		
		memset(&si,NULL,sizeof si);
		memset(&pi,NULL,sizeof pi);
	    strcat(cmd,TmpPath);
	    strcat(cmd,"\"");
	    GetSystemDirectory(str1,MAX_PATH);//��ȡϵͳ��Ŀ¼��System32�� 
	    strcat(str1,"\\mshta.exe");
		if(!CreateProcess(str1,cmd,NULL,NULL,NULL,NULL,NULL,NULL,&si,&pi)){//�������� 
			if(!quietMode) MessageBox(NULL,GetString4ThisLang(5),NULL,MB_ICONERROR);
			if(quietMode) ExitProcess(0);
			else return 0;
		}
		
		while(FindWindow("HTML Application Host Window Class", 0)==NULL) Sleep(500);//��mshta�Ĵ��� 
		PutToDesktop(FindWindow("HTML Application Host Window Class", 0));
		return 0;
	}
	
	DLLIMPORT void StartDwp(const char PathA[],BOOL Quiet){//��������Dwp���� 
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
