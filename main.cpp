#include <Windows.h>
#include <stdio.h>
#include <io.h>
#include <commctrl.h>
//#include <dwmapi.h>
#define DLLIMPORT __declspec(dllexport)
#include "HelpDWPT\dll.h"
#pragma comment (lib,"HelpDWPT\libHelpDWPT.a") 
#define key_press(key) ((GetAsyncKeyState(key)&0x8000)?1:0)//���尴����⺯�� 
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
/*�궨�壬BT=Button Type=��ť״̬����WndProc�����б�ʹ�ã��ѷϳ���*//*
#define BT_NORMAL 0 //���δ�Ƶ��Ϸ� 
#define BT_MOUSEMOVE 1 //����Ƶ��Ϸ� 
#define BT_CLICK 2 //����������� 
*/
/*�궨�壬IL=Integer Language=���������Ա�ʶ*/
#define IL_ENGLISH 0 //Ӣ�� 
#define IL_Simplified_Chinese 1 //�������� 
#define IL_Traditional_Chinese 2 //�������� 

HINSTANCE HInstance; //����ľ����ʹ��GetModuleHandle�������ɻ�� 
WNDCLASSEX wc; //�����࣬��������ʱ��Ҫע��һ����ſ��Դ������ڣ����򱨴� 
char RETURN[1145],*programName,Path[1145],*NameOfPro,CmdLine[1145];//һ�ѵ��ַ�������඼����ʱ�ġ���StartDwp������ʹ�� 
DWORD dw/*���ļ�ʱ�ı��*//*,BtnType[5]={BT_MOUSEMOVE,BT_MOUSEMOVE,BT_MOUSEMOVE,BT_MOUSEMOVE,BT_MOUSEMOVE}/*��ס���а�ť״̬*/;
HANDLE hFile;//�ļ���� 
HDC hdc=GetDC(0);
int W /*������*/,H /*����߶�*/,BtnWparam[5]={1,2,3,5,6}/*���ð�ť�¼�ID���*/,LangID=-1;
bool quietMode=false;//�Ƿ����ð���ģʽ��������dwp�ļ��У� 
HWND /*hWnd,*/HWND_,hTab,hSet,hConfig,hAnyWindow,hStaticDef,hBossKey,hsti,ChooseWindow;//hWnd=����ͼ�괰�ھ����HWND_=�����ھ�� 
NOTIFYICONDATA nid;//����ͼ������ 
HMENU FileMenu=CreatePopupMenu();//�ļ��˵���ȫ������Ϊ�����Ҽ�Ҫ����� 
int WINAPI winMain(_In_ HINSTANCE,_In_opt_ HINSTANCE,_In_ LPSTR,_In_ int);
typedef BOOL WINAPI (*SPDA)(VOID);
SPDA SetProcessDPIAwarev;//���øý��̵�DPI�������ܳ��ұ�����̫�� 
HFONT hFont = CreateFont(25, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("˼Դ"));//Ĭ������ 
//char BtnName[5][30]={"�½������ļ�","�༭�����ļ�","Ӧ�������ļ�","ֹͣ��̬��ֽ","����Dynamic Wallpaper Tools"};//��ť�ı� 
char MUIText[][3][250]={//������֧�ֹ��� 
	{"Create profile","�½������ļ�","�½��O���n"},
	{"Edit profile","�༭�����ļ�","��݋�O���n"},
	{"Apply profile","Ӧ�������ļ�","�����O���n"},
	{"Stop Wallpaper","ֹͣ��̬��ֽ","ֹͣ�ӑB����"},
	{"About Dynamic Wallpaper Tools","����Dynamic Wallpaper Tools","�P�Dynamic Wallpaper Tools"},
	{"Unable to open the video display program \"mshta.exe\" (playing videos using a browser), please check if the program exists in the system directory","�޷�����Ƶ��ʾ����\"mshta.exe\"��ʹ�������������Ƶ��������ϵͳĿ¼�³����Ƿ����","�o�����_ҕ�l�@ʾ��ʽ\"mshta.exe\"��ʹ�Þg�[������ҕ�l����Ո�z��ϵ�yĿ��³�ʽ�Ƿ����"},
	{"Warning! This operation will close all windows under the class name \"Program\"!","���棡�˲�����ر�����������Ϊ��Progman���Ĵ����µ����д��ڣ�","���棡 �˲������P�]����������顰Progman����ҕ���µ�����ҕ��"},
	{"Video files (.mp4)\0*.mp4\0Video files (.mov)\0*.mov\0Video files (.m4v)\0*.m4v\0Video files (.mpg)\0*.mpg\0Video files (.mpeg)\0*.mpeg\0Video files (.wmv)\0*.wmv\0All files (*.*) \0 *.* \0","��Ƶ�ļ���.mp4��\0*.mp4\0��Ƶ�ļ���.mov��\0*.mov\0��Ƶ�ļ���.m4v��\0*.m4v\0��Ƶ�ļ���.mpg��\0*.mpg\0��Ƶ�ļ���.mpeg��\0*.mpeg\0��Ƶ�ļ���.wmv��\0*.wmv\0�����ļ���*.*��\0*.*\0","ҕ�l�n����.mp4��\0*.mp4\0ҕ�l�n����.mov��\0*.mov\0ҕ�l�n����.m4v��\0*.m4v\0ҕ�l�n����.mpg��\0*.mpg\0ҕ�l�n����.mpeg��\0*.mpeg\0ҕ�l�n����.wmv��\0*.wmv\0���Йn����*.*��\0*.*\0"},
	{"Dynamic Wallpaper Configuration Files (.dwp)\0*.dwp\0","Dynamic Wallpaper�����ļ���.dwp��\0*.dwp\0","Dynamic Wallpaper�O���n��.dwp��\0*.dwp\0"},
	{"Do you need to play sound?","�Ƿ���Ҫ����������","�Ƿ���Ҫ��������"},
	{"Programming: Office Excel\nReference video by occasionally a bit confused, video id: BV1HZ4y1978a (press to cancel to view original video)\nTools used: Dev-C++, Code language: C++\nProject start date: April 21, 2024\nVersion: 0.0.4.1","����������Office-Excel\n�ο���Ƶ by ż���е�С�Ժ�����Ƶid��BV1HZ4y1978a������ȡ���鿴ԭ��Ƶ��\nʹ�ù��ߣ�Dev-C++���������ԣ�C++\n��Ŀ��ʼ���ڣ�2024/04/21\n�汾��0.0.4.1","��ʽ�u����Office-Excel\n����ҕ�lbyż�����cС�Ժ���ҕ�lid:BV1HZ4y1978a������ȡ���鿴ԭҕ�l��\nʹ�ù��ߣ�Dev-C++����ʽ�a�Z�ԣ�C++\n�Ŀ�_ʼ���ڣ�2024/04/21\n�汾��0.0.4.1"},
	{"The configuration file operation is complete. Do you want to start it now?","�����ļ�������ɣ��Ƿ�Ҫ����������","�O���n������ɣ��Ƿ�Ҫ�R�φ��ӣ�"},
	{"Please select the object you want to modify:\nYes -> Modify video file path\nNo -> Modify whether there is sound\nCancel -> Do nothing","��ѡ��Ҫ�޸ĵĶ���\n ��->�޸���Ƶ�ļ�·��\n ��->�޸��Ƿ�������\n ȡ��->ʲôҲ����","Ո�x��Ҫ�޸ĵČ���\n��->�޸�ҕ�l�n��·��\n��->�޸��Ƿ�����\nȡ��->ʲ�NҲ����"},
	{"Wallplaper Config","��ֽ����","�����䌅"},
	{"Global settings","ȫ������","ȫ���O��"},
	{"Self start upon startup","����������","�_�C�Ԇ���"},
	{"Current default item:","��ǰĬ���","��ǰĬ�J헣�"},
	{"Edit","�༭","��݋"},
	{"Registry modification failed!","ע����޸�ʧ�ܣ�","�]�Ա��޸�ʧ����"},
	{"Do you want to restart explorer.exe? This may result in a black screen for a while. If Win11 users set a right angle, it will turn back into a rounded corner. Please make a careful decision!","�Ƿ���Ҫ����explorer.exe������ܻ����һ�����Win11�û����������ֱ�ǻ���Բ�ǣ������ؾ�����","�Ƿ���Ҫ�؆�explorer.exe�� �@���ܕ�����һ������Win11�Ñ�����O����ֱ�Ǖ�׃�؈A�ǣ�Ո���ؾ�����"},
	{"Quit(&Q)","�˳���&Q��","�˳���&Q��"},
	{"Registry modification completed!","ע����޸���ɣ�","�]�Ա��޸���ɣ�"},
	{"Do you need to set this configuration item as the default (including startup default)��","�Ƿ���Ҫ���������������ΪĬ�����������Ĭ�����","�Ƿ���Ҫ���@���䌅��O����Ĭ�J헣���������Ĭ�J헣���"},
	{"explorer.exe has been restarted and completed, you can continue your work now!","explorer.exe��������ɣ������Լ������Ĺ����ˣ�","explorer.exe���؆���ɣ��������^�m���Ĺ����ˣ�"},
	{"Apply","Ӧ��","����"},
	{"Set as default configuration","����ΪĬ������","�O����Ĭ�J�䌅"},
	{"Help(&H)","������&H��","������&H��"},
	{"Operation(&O)","������&O��","������&O��"},
	{"About(&A)","���ڣ�&A��","�P춣�&A��"},
	{"End dynamic wallpaper(&E)","������̬��ֽ��&E��","�Y���ӑB���棨&E��"},
	{"Open and...(&C)","�򿪲�...��&C��","���_�K...��&C��"},
	{"Open the default item and...(&D)","��Ĭ���...��&D��","���_Ĭ�J헁K...��&D��"},
	{"The program has already started, please do not execute it again!","�����Ѿ������ˣ��벻Ҫ�ٴ�ִ�У�","��ʽ�ѽ������ˣ�Ո��Ҫ�ٴΈ��У�"},
	{"The original value was: ","ԭ����ֵΪ��","ԭ���ֵ�飺"},
	{"\nDo you want to modify it?","\n�Ƿ�Ҫ�޸ģ�","\n�Ƿ�Ҫ�޸ģ�"},
	{"Please select: ","��ѡ��","Ո�x��"},
	{"The video path has been modified!","��Ƶ·�����޸���ɣ�","ҕ�l·�����޸���ɣ�"},
	{"The modification of the video path has been canceled...","��ȡ���޸���Ƶ·��������","��ȡ���޸�ҕ�l·��������"},
	{"The original value for playing sound when using dynamic wallpapers is:","ԭ���Ƿ���ʹ�ö�̬��ֽʱ����������ֵΪ��","ԭ���Ƿ���ʹ�ÄӑB����r��������ֵ�飺"},
	{"Yes","��","��"},
	{"No","��","��"},
	{"\nPlease select: ","\n��ѡ��","\nՈ�x��"},
	{"Do you want to save this modification?","�Ƿ�Ҫ������ε��޸ģ�","�Ƿ�Ҫ�����@�ε��޸ģ�"},
	{"Do you want to apply it now?","�Ƿ�Ҫ����Ӧ�ã� ","�Ƿ�Ҫ�������ã�"},
	{"Shrink to system tray","��С��ϵͳ����","�sС��ϵ�yӚ�P"},
	{"How to use it?","���ʹ�ã�","���ʹ�ã�"},
	{"Advanced Options","�߼�ѡ��","�߼��x�"},
	{"Set","����","�O��"},
	{"Set any window as wallpaper","�����ⴰ������Ϊ��ֽ","������ҕ���O��������"},
	{"Title of Window: ","���ڱ��⣺","ҕ�����}��"},
	{"Class Name of Window: ","����������","ҕ�������"},
	{"Boss key:","�ϰ����","����I��"}
};

//left->top->right->bottom
RECT BtnPos[5]={
	{20,20,220,70},{240,20,440,70},{460,20,660,70},{20,90,220,140},{240,90,660,140}
};//���а�ť��λ��

char* StringCat(char *Str1,const char *Str2){
	char* a;
	strcpy(a,Str1);
	strcat(a,Str2);
	return a;
}

char* GetString4ThisLang(UINT index){
	if(LangID==-1){
		switch(PRIMARYLANGID(GetUserDefaultLangID())){//��ȡ����ID�����õ�ǰ���� 
			case LANG_CHINESE_SIMPLIFIED:LangID=IL_Simplified_Chinese;break;
			case LANG_CHINESE_TRADITIONAL:LangID=IL_Traditional_Chinese;break;
			default:LangID=IL_ENGLISH;break;
		}
	}
	return MUIText[index][LangID];
}

LONG GetRegValue(HKEY key,const char path[],const char keyname[],char value[]){//��ȡע����ĳ��ֵ ���������Ա�� 
    HKEY hKey;
    BYTE byData[255];
    LONG status = RegOpenKeyExA(key, path, 0, KEY_READ, &hKey);
    if (status != ERROR_SUCCESS) return status;
    DWORD dwSize = sizeof(byData),dwType;
    status = RegQueryValueExA(hKey, keyname, NULL, &dwType, byData, &dwSize);
    if (status != ERROR_SUCCESS) {
        RegCloseKey(hKey);
        return status;
    }
    strcpy(value,(char*)byData);
    RegCloseKey(hKey);
    return 0;
	/*ʹ��ԭʼ������Ҫ����ԱȨ�� 
	LONG result;
    DWORD dwType,dwSize;
    HKEY hKey;
	result = RegOpenKeyEx(key, path, 0, KEY_READ, &hKey);
	if(result!=ERROR_SUCCESS) return result;
    result = RegGetValue(hKey,NULL,keyname,RRF_RT_REG_SZ,&dwType,value,&dwSize);
    RegCloseKey(hKey);
	return result;*/
}

LONG SetRegValue(HKEY key,const char path[],const char keyname[],char value[]){//����ע����ĳ��ֵ����Ҫ����Ա�� 
 
    // ��ע�����
    HKEY hKey;
    LONG result = RegOpenKeyExA(
        key, // ����
        path, // �Ӽ�·��
        0, // ������������0
        KEY_SET_VALUE, // ����Ȩ��
        &hKey // ���ش򿪵�ע�������
    );
 
    if (result == ERROR_SUCCESS) {
        // ����ע������ֵ
        result = RegSetValueExA(
            hKey, // ע�������
            keyname, // ֵ������
            0, // ������������0
            REG_SZ, // ֵ������
            (BYTE*)value, // ֵ������
            strlen(value)+1 // ���ݵĴ�С��������������
        );
 
        // �ر�ע�����
        RegCloseKey(hKey);
    }
    return result;
}

LONG DelRegValue(HKEY key,const char path[],const char keyname[]){//ɾ��ע����е�ĳһ��ֵ 
    // ��ע�����
    HKEY hKey;
    LONG result = RegOpenKeyExA(
        key, // ����
        path, // �Ӽ�·��
        0, // ������������0
        KEY_SET_VALUE, // ����Ȩ��
        &hKey // ���ش򿪵�ע�������
    );
 
    if (result == ERROR_SUCCESS) {
        result = RegDeleteValue(hKey,keyname);
        RegCloseKey(hKey);
    }
    return result;
}

BOOL CALLBACK EnumWindowProc(_In_ HWND hwnd, _In_ LPARAM Lparam)//���ģ�������̬��ֽ��Ƕ�봰�ڹ��� 
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

int GetNumberLength(int num){//��ȡ���ֳ��ȣ��ж���λ�� 
	int cnt=0;
	while(num){
		cnt++;
		num/=10;
	}
	return cnt;
}
char* NumToString(int n){//������ת��Ϊ�ı�������ֵ��RETURN�����У� 
	memset(RETURN,0,sizeof RETURN);
	if(n==0){
		RETURN[0]='0';
		return RETURN;
	}
	if(n<0){
		RETURN[0]='-';
		int i=GetNumberLength(n);
		while(n){
			RETURN[i]=n%10+'0';
			n/=10;
			i--;
		}
		return RETURN;
	}
	int i=GetNumberLength(n)-1;
	while(n){
		RETURN[i]=n%10+'0';
		n/=10;
		i--;
	}
	return RETURN;
}
bool OpenFileDlg(HWND ParentWindow, LPCSTR FileType, char Output_Path[]) {//���ļ��Ի��� 
	OPENFILENAME ofn;
	TCHAR szFile[MAX_PATH] = {};

	ZeroMemory(&ofn, sizeof(ofn));//��ʼ�����ļ��Ľṹ�� 
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.hwndOwner = ParentWindow;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = FileType;
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFileTitle = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
	if (!GetOpenFileName(&ofn)) return false;//ʧ�� ���� �û������ȡ�� 
	else strcpy(Output_Path,ofn.lpstrFile);
	return true;//�ɹ� 
}
bool SaveFileDlg(HWND ParentWindow, LPCSTR FileType, char Output_Path[],const char typestr[]) {//�����ļ��Ի��� 
	OPENFILENAMEA ofn;
	char szFile[MAX_PATH] = {};

	ZeroMemory(&ofn, sizeof(ofn));//��ʼ�������ļ��Ľṹ�� 
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;
	ofn.lpstrFile[0] = '\0';
	ofn.hwndOwner = ParentWindow;
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = FileType;
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFileTitle = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;

	if (!GetSaveFileNameA(&ofn)) return false;//ʧ�� \ �û������ȡ�� 
	else strcpy(Output_Path,ofn.lpstrFile);//�����ı� 
	int i = strlen(ofn.lpstrFile);
	while (i>0&&((Output_Path)[i]) != '.' && ((Output_Path)[i]) != '\\') i--;
	if (((Output_Path)[i]) == '\\') strcat((Output_Path),(char*)"."), strcat((Output_Path), (char*)typestr);//�ж��Ƿ��к�׺����û�оͼ�һ��Ĭ�ϵ� 
	return true;//�ɹ��� 
}

BOOL CALLBACK StopDWPProc(_In_ HWND hWnd,_In_ LPARAM lparam){
	char Text[1145];
	GetClassName(hWnd,Text,sizeof(Text));
	//GetWindowText(hWnd,Text,GetWindowTextLength(hWnd)+1);
	if(strcmp(Text,"SHELLDLL_DefView")!=0) PostMessage(hWnd,WM_CLOSE,NULL,NULL);
	return FALSE;
}

/*BOOL CALLBACK OutDWPProc(_In_ HWND hWnd,_In_ LPARAM lparam){
	char Text[1145];
	GetClassName(hWnd,Text,sizeof(Text));
	//GetWindowText(hWnd,Text,GetWindowTextLength(hWnd)+1);
	if(strcmp(Text,"SHELLDLL_DefView")!=0) PostMessage(hWnd,WM_CLOSE,NULL,NULL);
	return TRUE;
}*/

void PutToDesktop(HWND Wallpaper){
	if(!Wallpaper){
		MessageBox(Wallpaper,"������Ž������������������","Error",MB_ICONINFORMATION|MB_OK);
		return ;
	}
	int width=GetDeviceCaps(GetDC(0), DESKTOPHORZRES),height=GetDeviceCaps(GetDC(0), DESKTOPVERTRES);//��ȡ��Ļ�豸�ֱ��� 
	HWND hProgman = FindWindow("Progman", 0), hFfplay = Wallpaper;
	SendMessageTimeout(hProgman, 0x52C, 0, 0, 0, 100, 0);//��ʱ������Ϣ 
	SetWindowPos(hFfplay, NULL, 0, 0, width, height, SWP_NOZORDER);//���ô��ڴ�С��λ�� 
	SetParent(hFfplay, hProgman);//���ø����� 
	EnumWindows(EnumWindowProc, 0);//��������ڷŵ�����ĺ�� 
    //Shell_NotifyIcon(NIM_SETVERSION, &nid);//Toast Message Box
	return ;
}

DWORD WINAPI DwpThread(LPVOID lparam){//�����߳� 
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
	
	dw=0;
	hFile=CreateFile(Path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);//���ļ���� 
	ReadFile(hFile,&sound,1,&dw,NULL);
	ReadFile(hFile,VP,GetFileSize(hFile,NULL)-1,&dw,NULL);
	for(int i=strlen(VP);!(VP[i]<='Z'&&VP[i]>='A'||VP[i]<='z'&&VP[i]>='a'||VP[i]<='9'&&VP[i]>='0');i--) VP[i]=NULL;//�����ļ������� 
	
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
bool isRunningAsAdmin() {//�ж��Ƿ��ڹ���Ա��������� 
    HANDLE hToken;
    if (!OpenProcessToken(GetCurrentProcess(), TOKEN_QUERY, &hToken)) return false;//��ȡ���� 
    TOKEN_ELEVATION elevation;
    DWORD size;
    if (GetTokenInformation(hToken, TokenElevation, &elevation, sizeof(elevation), &size)) {
        CloseHandle(hToken);
        return elevation.TokenIsElevated > 0;
    }
 
    CloseHandle(hToken);
    return false;
}
bool runAsAdmin() {//�ڹ���Ա��������� 
	if(isRunningAsAdmin()) return true;
    SHELLEXECUTEINFO sei = {0};
    sei.cbSize = sizeof(SHELLEXECUTEINFO);
    sei.fMask = SEE_MASK_NOCLOSEPROCESS;
    sei.lpFile = NameOfPro; // ��ǰӦ�ó��������·��
    sei.lpVerb = "runas"; // �������ԱȨ��
    sei.nShow = SW_SHOWNORMAL;
    sei.lpParameters = CmdLine;

    if (ShellExecuteEx(&sei)) {//������ 
        CloseHandle(sei.hProcess);
        ExitProcess(0);
        return true;
    }
 	ExitProcess(0);
 	return false;
}
DWORD WINAPI FindWindowProcess(LPVOID lparam){
	SendMessage(hsti, BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(HInstance,"IDI_SELECTUSING"));
	ChooseWindow=0;
	POINT cur;
	HCURSOR hCursor=LoadCursor(HInstance,"IDC_SELECTCURSOR");
	HWND Find;
	RECT rect,DRect;
	char str[1145];
	HBRUSH GBrush=CreateSolidBrush(RGB(0,255,0));
	while(!key_press(VK_LBUTTON)){
        SetCursor(hCursor);
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
			strcat(str,Text);
			SetDlgItemText(hAnyWindow,1,str);
			strcpy(str,GetString4ThisLang(50));
			GetClassName(ChooseWindow,Text,sizeof(Text));
			strcat(str,Text);
			SetDlgItemText(hAnyWindow,2,str);
		}
	}
	SendMessage(hsti, BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(HInstance,"IDI_SELECTUNUSE"));
	//RedrawWindow(0,NULL,NULL,RDW_ERASE);
} 
void StartDwp(const char PathA[],bool Quiet){//��������Dwp���� 
	quietMode=Quiet;
	strcpy(Path,PathA);
	CreateThread(NULL,NULL,DwpThread,NULL,NULL,NULL);
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
		char set[114514]="��ǰ��Ƶ·����";
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
	memset(&wc_dlg, 0, sizeof(wc_dlg));//ע���������� 
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
	SendMessage(CreateWindow("STATIC","��ǰ��Ƶ·����",WS_CHILD|WS_VISIBLE,20,20,650,30,Dlg,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","�޸�",WS_CHILD|WS_VISIBLE,700,20,70,30,Dlg,(HMENU)1,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("STATIC","�Ƿ�����������",WS_CHILD|WS_VISIBLE,20,70,190,30,Dlg,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","��",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON,200,70,100,30,Dlg,(HMENU)2,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	SendMessage(CreateWindow("BUTTON","��",WS_CHILD|WS_VISIBLE|BS_RADIOBUTTON,310,70,650,30,Dlg,(HMENU)3,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
	ShowWindow(Dlg,SW_SHOW);
	UpdateWindow(Dlg);
	MSG msg={0};
	while(GetMessage(&msg,NULL,0,0)>0){
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return TRUE;
}*/

/* This is where all the input to the window goes to */

BOOL CALLBACK SetDPI(_In_ HWND hwnd, _In_ LPARAM Lparam){
	return SetProcessDPIAwarev();
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT Message, WPARAM wParam, LPARAM lParam) {//���ڹ��� 
	switch (Message) {
		/* Upon destruction, tell the main thread to stop */
		case WM_DESTROY: {//���ٴ��� 
			PostQuitMessage(0);
			break;
		}
		
		case WM_CLOSE: {//���ش��� 
			ShowWindow(hwnd,SW_HIDE);
			break;
		}
		
		/*case WM_MOUSEMOVE: {//������ƶ�ʱ 
			HDC DC=GetDC(hwnd);//��ȡHDC 
			SelectObject(DC,hFont);
			RECT WindowRect;//��ȡ��ǰ����λ�� 
			GetWindowRect(hwnd,&WindowRect);
			POINT mousePoint;
			GetCursorPos(&mousePoint);//��ȡ��ǰ���λ�� 
			mousePoint.x-=WindowRect.left+10;
			mousePoint.y-=WindowRect.top;//����ʹ�����Ͻ�Ϊ0,0 
			mousePoint.y-=50;//������� 
			for(int i=0;i<5;i++){
				RECT Pos=BtnPos[i];
				if(mousePoint.x>=BtnPos[i].left&&mousePoint.y>=BtnPos[i].top&&mousePoint.x<=BtnPos[i].right&&mousePoint.y<=BtnPos[i].bottom){//Ѱ�ұ���������İ�ť 
					if(BtnType[i]!=BT_MOUSEMOVE){//�ж��Ƿ��Ѿ������״̬����Լ���� 
						RECT Pos1=Pos;
						Pos1.top+=18;
						FillRect(DC,&Pos,CreateSolidBrush(RGB(229,229,229)));//������ 
						SetBkColor(DC,RGB(229,229,229));
						DrawText(DC,BtnName[i],strlen(BtnName[i]),&Pos1,DT_CENTER|DT_VCENTER);//д���ı� 
						MoveToEx(DC,Pos.left+5,Pos.bottom+1,NULL);//���ߡ��������� 
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						MoveToEx(DC,Pos.right+1,Pos.top+5,NULL);
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						BtnType[i]=BT_MOUSEMOVE;//�޸�״̬ 
					}
				}
				else{
					if(BtnType[i]!=BT_NORMAL){//�ж��Ƿ��Ѿ������״̬����Լ���� 
						RECT Pos1=Pos;
						Pos1.top+=18;
						FillRect(DC,&Pos,CreateSolidBrush(RGB(239, 239, 239)));//������ 
						SetBkColor(DC,RGB(239,239,239));
						DrawText(DC,BtnName[i],strlen(BtnName[i]),&Pos1,DT_CENTER|DT_VCENTER);//д�ı� 
						MoveToEx(DC,Pos.left+5,Pos.bottom+1,NULL);//���ߣ����Ǹ������� 
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						MoveToEx(DC,Pos.right+1,Pos.top+5,NULL);
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						BtnType[i]=BT_NORMAL;//�޸ı��״̬ 
					}
				}
			}
			break;
		}
		
		case WM_LBUTTONUP: {//������������ʱ 
			HDC DC=GetDC(hwnd);//ȡHDC 
			SelectObject(DC,hFont);//�������� 
			RECT WindowRect;//��ȡ����λ�� 
			GetWindowRect(hwnd,&WindowRect);
			POINT mousePoint;//��ȡ���λ�� 
			GetCursorPos(&mousePoint);
			mousePoint.x-=WindowRect.left+10;
			mousePoint.y-=WindowRect.top;
			mousePoint.y-=50;//�����Դ������Ͻ�Ϊ0,0��x,y���� 
			for(int i=0;i<5;i++){
				RECT Pos=BtnPos[i];
				if(mousePoint.x>=BtnPos[i].left&&mousePoint.y>=BtnPos[i].top&&mousePoint.x<=BtnPos[i].right&&mousePoint.y<=BtnPos[i].bottom){//Ѱ�ұ����µİ�ť 
					if(BtnType[i]!=BT_MOUSEMOVE){//�ж��Ƿ��Ѿ������״̬����Լ���� 
						RECT Pos1=Pos;
						Pos1.top+=18;
						FillRect(DC,&Pos,CreateSolidBrush(RGB(239,239,239)));//������ 
						SetBkColor(DC,RGB(239,239,239));
						DrawText(DC,BtnName[i],strlen(BtnName[i]),&Pos1,DT_CENTER|DT_VCENTER);//���ı� 
						MoveToEx(DC,Pos.left+5,Pos.bottom+1,NULL);//���ߣ���Ȼ������� 
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						MoveToEx(DC,Pos.right+1,Pos.top+5,NULL);
						LineTo(DC,Pos.right+1,Pos.bottom+1); 
						BtnType[i]=BT_MOUSEMOVE;//����״̬ 
						SendMessage(hwnd,WM_COMMAND,BtnWparam[i],NULL);//���Ͱ�����Ϣ 
					}
					break;
				}
			}
			break;
		}
		
		case WM_LBUTTONDOWN: {//������������ 
			HDC DC=GetDC(hwnd);//��ȡHDC 
			SelectObject(DC,hFont);//�������� 
			RECT WindowRect;
			GetWindowRect(hwnd,&WindowRect);//��ȡ�������� 
			POINT mousePoint;//��ȡ������� 
			GetCursorPos(&mousePoint);
			mousePoint.x-=WindowRect.left+10;
			mousePoint.y-=WindowRect.top;
			mousePoint.y-=50;//�����������ڵ����Ͻ�Ϊ0,0ʱ��������� 
			for(int i=0;i<5;i++){
				RECT Pos=BtnPos[i];
				if(mousePoint.x>=BtnPos[i].left&&mousePoint.y>=BtnPos[i].top&&mousePoint.x<=BtnPos[i].right&&mousePoint.y<=BtnPos[i].bottom){//Ѱ�ұ����µİ�ť 
					if(BtnType[i]!=BT_CLICK){
						RECT Pos1=Pos;//����RECT 
						Pos1.bottom+=5;
						Pos1.right+=5; 
						FillRect(DC,&Pos1,CreateSolidBrush(RGB(255,255,255)));//������ǰ�� 
						Pos1.bottom-=5;
						Pos1.right-=5;//�ָ�ԭʼ 
						Pos1.top+=20;
						Pos1.left+=2;//�޸�λ�����廯 
						SetBkColor(DC,RGB(245,245,245));
						FillRect(DC,&Pos,CreateSolidBrush(RGB(239, 239, 239)));//���µľ��� 
						DrawText(DC,BtnName[i],strlen(BtnName[i]),&Pos1,DT_CENTER|DT_VCENTER);//���ı� 
						MoveToEx(DC,Pos.left+2,Pos.top+2,NULL);//�������ߣ����� 
						LineTo(DC,Pos.right-1,Pos.top+2); 
						MoveToEx(DC,Pos.left+2,Pos.top+2,NULL);
						LineTo(DC,Pos.left+2,Pos.bottom-2); 
						BtnType[i]=BT_CLICK;//�޸�״̬ 
						Sleep(100);
					}
					break;
				}
			}
			break;
		}*/
		case WM_COMMAND: {//��xxx������ 
			switch (LOWORD(wParam)) {
				case 1:{//�����µ������� 
					char Video[1145],SP[1145],chr;
					bool isSound=false;
					if(!SaveFileDlg(hwnd,GetString4ThisLang(8),SP,"dwp")) break;
					if(!OpenFileDlg(hwnd,GetString4ThisLang(7),Video)) break;
					isSound=(MessageBox(hwnd,GetString4ThisLang(9),"Question",MB_YESNO|MB_ICONQUESTION)==6);
					freopen(SP,"w",stdout);
					printf("%s",(isSound?"t":"f"));
					printf("%s",Video);
					fclose(stdout);
					if(MessageBox(hwnd,GetString4ThisLang(11),"Information",MB_YESNO|MB_ICONQUESTION)==6) StartDwp(SP,false);//������ 
					break;
				}
				case 2:{//�༭������ 
					char SP[1145];
					if(!OpenFileDlg(hwnd,GetString4ThisLang(8),SP)) break;
					char sound,VP[1145],put;
					dw=0;
					hFile=CreateFile(SP, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
					ReadFile(hFile,&sound,1,&dw,NULL);
					ReadFile(hFile,VP,GetFileSize(hFile,NULL)-1,&dw,NULL);
					if(VP[strlen(VP)-1]=='\r') VP[strlen(VP)-1]=NULL;
					ChooseChangeObject:
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
							StartDwp(SP,false);//������ 
							Sleep(1000);
						}
					}
					break;
				}
				case 3:{//���������� 
					char SP[1145];
					if(!OpenFileDlg(hwnd,GetString4ThisLang(8),SP)) break;
					StartDwp(SP,false);//������ 
					Sleep(1000);
					break;
				}
				case 4:{//�˳� 
					PostQuitMessage(0);
					break;
				}
				case 5:{//������̬��ֽ�������� 
					if(MessageBox(hwnd,GetString4ThisLang(6),"Warning",MB_ICONWARNING|MB_YESNO)==6){
						HWND PROGMAN=FindWindow("Progman", 0);
						if(PROGMAN) EnumChildWindows(PROGMAN,StopDWPProc,NULL);
						if(MessageBox(hwnd,GetString4ThisLang(19),"Stop Dynamic Wallpaper",MB_ICONQUESTION|MB_YESNO)==6){
							system("taskkill /F /IM explorer.exe");
							Sleep(1000);
							system("timeout /T 5&explorer.exe");
							MessageBox(hwnd,GetString4ThisLang(23),"Restart explorer.exe complete",MB_ICONINFORMATION); 
						}
					}
					break;
				}
				case 6:{//���� 
					if(MessageBox(hwnd,GetString4ThisLang(10),"About",MB_YESNO|MB_ICONINFORMATION)!=6) system("start https://www.bilibili.com/video/BV1HZ4y1978a/");
					break;
				}
				case 7:{//����Ĭ�������� 
					char SP[1145],outText[1145];
					strcpy(outText,GetString4ThisLang(22));
					if(!OpenFileDlg(hwnd,GetString4ThisLang(8),SP)) break;
					strcat(outText,SP);
					if(MessageBox(hwnd,outText,"Question",MB_ICONQUESTION|MB_YESNO)==6){
						HKEY hKey; 
						DWORD disp;
						RegCreateKeyEx(
					        HKEY_CURRENT_USER,      // ����
					        "Software\\DWPT",        // �Ӽ�·��
					        0,                       // ����������Ϊ0
					        NULL,                    // ע��������ͣ����ǲ���Ҫָ�����ͣ�
					        REG_OPTION_NON_VOLATILE, // ע����������
					        KEY_WRITE,               // ����Ȩ��
					        NULL,                    // ������ͺ�Ȩ��δָ����ʹ��Ĭ�ϵİ�ȫ������
					        &hKey,                   // �����´�����򿪵�ע�����ľ��
					        &disp                    // ����ֵ��ָʾע��������´��������Ѵ���
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
				case 8:{//�޸������������ļ� 
					char SP[1145];
					if(GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",SP)!=ERROR_SUCCESS) break;
					char sound,VP[1145],put;
					dw=0;
					hFile=CreateFile(SP, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
					ReadFile(hFile,&sound,1,&dw,NULL);
					ReadFile(hFile,VP,GetFileSize(hFile,NULL)-1,&dw,NULL);
					if(VP[strlen(VP)-1]=='\r') VP[strlen(VP)-1]=NULL;
					DefChooseChangeObject:
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
					ExitChoose:
					if(MessageBox(hwnd,GetString4ThisLang(42),"Edit",MB_YESNO|MB_ICONQUESTION)==6){
						freopen(SP,"w",stdout);
						printf("%s",(sound?"t":"f"));
						printf("%s",VP);
						fclose(stdout);
						if(MessageBox(hwnd,GetString4ThisLang(43),"Edit",MB_YESNO|MB_ICONQUESTION)==6){
							StartDwp(SP,false);
							Sleep(1000);
						}
					}
					break;
				}
				case 9:{//����Ĭ�ϵ������ļ� 
					char SP[1145];
					if(GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",SP)!=ERROR_SUCCESS) break;
					StartDwp(SP,false);
					Sleep(1000);
					break;
				}
				case 10:{//�л��Ƿ񿪻���������״̬ 
		            UINT st=GetMenuState(FileMenu, 10, MF_BYCOMMAND);
					HKEY hKey; 
					DWORD disp;
					RegCreateKeyEx(
				        HKEY_CURRENT_USER,      // ����
				        "Software\\DWPT",        // �Ӽ�·��
				        0,                       // ����������Ϊ0
						NULL,                    // ע��������ͣ����ǲ���Ҫָ�����ͣ�
					    REG_OPTION_NON_VOLATILE, // ע����������
				        KEY_WRITE,               // ����Ȩ��
				        NULL,                    // ������ͺ�Ȩ��δָ����ʹ��Ĭ�ϵİ�ȫ������
				        &hKey,                   // �����´�����򿪵�ע�����ľ��
				        &disp                    // ����ֵ��ָʾע��������´��������Ѵ���
				    );
		            if (st == MF_CHECKED) {
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
		            else {
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
				case 11: {//���ش��� 
					ShowWindow(hwnd,SW_HIDE);
					return 0;
				}
				case 12:{
					HelpWindow(hwnd);
					break;
				} 
				case 13:{
					CreateThread(NULL,NULL,FindWindowProcess,NULL,NULL,NULL);
					break;
				}
				case 14:{
					if(ChooseWindow==0||ChooseWindow==HWND_||(!IsWindowVisible(HWND_))||IsIconic(HWND_)) MessageBox(hwnd,"δѡ��һ����ȷ�Ĵ��ڣ��޷�����Ϊ������","Error",MB_ICONWARNING);
					else{
						char Text[1145];
						GetClassName(ChooseWindow,Text,sizeof(Text));
						if(strcmp(Text,"WorkerW")==0||strcmp(Text,"Progman")==0||strcmp(Text,"Shell_TrayWnd")==0) MessageBox(hwnd,"δѡ��һ����ȷ�Ĵ��ڣ��޷�����Ϊ������","Error",MB_ICONWARNING);
						else if(MessageBox(hwnd,GetString4ThisLang(6),"Warning",MB_ICONWARNING|MB_YESNO)==6){
							HWND PROGMAN=FindWindow("Progman", 0);
							if(PROGMAN) EnumChildWindows(PROGMAN,StopDWPProc,NULL);
							PutToDesktop(ChooseWindow);
						}
					}
					break;
				}
				case 15:{
					WinWatcher();
					break;
				}
			}
			break;
		}
		case WM_SYSCOMMAND:{
			if(LOWORD(wParam)==11||LOWORD(wParam)==4) return WndProc(hwnd,WM_COMMAND,wParam,lParam);
			else return DefWindowProc(hwnd, Message, wParam, lParam);
			break;
		}
		case WM_NOTIFY:{
			switch((reinterpret_cast<LPNMHDR>(lParam))->code){
				case TCN_SELCHANGE:{
					LRESULT result=SendMessage(hTab,TCM_GETCURSEL,NULL,NULL); 
					if(result==0){
						ShowWindow(hSet,SW_HIDE);
						ShowWindow(hAnyWindow,SW_HIDE);
						ShowWindow(hConfig,SW_SHOW);
					}
					else if(result==1){
						ShowWindow(hConfig,SW_HIDE);
						ShowWindow(hAnyWindow,SW_HIDE);
						ShowWindow(hSet,SW_SHOW);
					}
					else{
						ShowWindow(hConfig,SW_HIDE);
						ShowWindow(hAnyWindow,SW_SHOW);
						ShowWindow(hSet,SW_HIDE);
					}
					break;
				}
			}
			break;
		}
		default:
			return DefWindowProc(hwnd, Message, wParam, lParam);//Ĭ�ϴ��ڹ��� 
	}
	return 0;
}

LRESULT CALLBACK TrayNotificationCallback(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {//ϵͳ����ͼ�괰�ڽ��� 
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
		            TrackPopupMenu(FileMenu, TPM_LEFTALIGN | TPM_RIGHTBUTTON, p.x, p.y, NULL, HWND_, NULL);  //չʾFileMenu 
					break;
				}
				case WM_LBUTTONDOWN:{
					ShowWindow(HWND_,SW_SHOW);
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
DWORD WINAPI nidThread(LPVOID lparam){//ϵͳ����ͼ�������� 
	MSG msg = {};
    while (GetMessage(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessage(&msg);
    }
    Shell_NotifyIcon(NIM_DELETE, &nid);
	return 0;
}*/

int main(int argc,char *argv[]) {//main���� 
	HMODULE hModule = LoadLibrary("user32.dll");
	SetProcessDPIAwarev = (SPDA)GetProcAddress(hModule,"SetProcessDPIAware");
	SetProcessDPIAwarev();//���������� 
	bool hasCmd=false;
	//���������� 
	if(argc>1) for(int i=0;i<strlen(argv[1]);i++) if(argv[1][i]>='A'&&argv[1][i]<='Z') argv[1][i]+='a'-'A';
	if(argc==2){
		if(strcmp(argv[1],"-q")==0){
			GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",RETURN);
			quietMode=true;
			strcpy(Path,RETURN);
			DwpThread(NULL);
			hasCmd=true;
		}
		strcpy(CmdLine,argv[1]);
	}
	else if(argc==3){
		if(strcmp(argv[1],"-o")==0){
			if(argv[2][0]=='"') argv[2]++;
			if(argv[2][strlen(argv[2])-1]=='"') argv[2][strlen(argv[2])-1]=NULL;
			quietMode=true;
			strcpy(Path,argv[2]);
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
	NameOfPro = argv[0];//��ǰ����Ŀ¼+���� 
	if(hasCmd==false) runAsAdmin();
	programName = argv[0];
	for(int i=strlen(programName)-1;i>=0;i--){//��ȡ��ǰλ�� 
		if(programName[i]!='\\') programName[i]=NULL;
		else break;
	}
	if(hasCmd==true){
		if(FindWindow("DWPT_PRIVATECLASS",0)!=NULL) return 0;
		else{
			return winMain(
				GetModuleHandle(NULL),//��ȡ������ľ��
				NULL,//�������Ϊʲô��Ҫ��Ҳ��֪��
				CmdLine,//������
				SW_HIDE//���崰��չʾ��ʽ����������ShowWindow����������ΪSW_SHOW
			);		
		}
	}
	if(FindWindow("DWPT_PRIVATECLASS",0)!=NULL){
		//SetWindowPos(FindWindow("DWPT_PRIVATECLASS",0),0,0,0,0,0,SWP_NOSIZE|SWP_NOMOVE|SWP_SHOWWINDOW);
		MessageBox(NULL,GetString4ThisLang(32),"ERROR",MB_ICONWARNING|MB_OK); 
		return 0;
	}
	return winMain(
		GetModuleHandle(NULL),//��ȡ������ľ��
		NULL,//�������Ϊʲô��Ҫ��Ҳ��֪��
		CmdLine,//������
		SW_SHOW//���崰��չʾ��ʽ����������ShowWindow����������ΪSW_SHOW
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
		strcat(str,((LangID==0)?" Language: English":((LangID==1)?" ����: ���ļ���":" �Z�ԣ����ķ��w"))); 
		SetWindowText(HWND_,str);
	}
}*/

/* The 'main' function of Win32 GUI programs: this is where execution starts */
int WINAPI winMain(_In_ HINSTANCE hINstance,_In_opt_ HINSTANCE hPrevInstance,_In_ LPSTR lpCmdLine,_In_ int nShowCmd) {
	HMODULE hModule = LoadLibrary("user32.dll");
	SetProcessDPIAwarev = (SPDA)GetProcAddress(hModule,"SetProcessDPIAware");
	SetProcessDPIAwarev();//���������� 
	//LoadUI();
	
	HInstance = GetModuleHandle(NULL);
	WNDCLASS wc1 = {};
    wc1.lpfnWndProc = TrayNotificationCallback;
    wc1.hInstance = GetModuleHandle(NULL);
    wc1.lpszClassName = "TrayIconWindowClass";
    if(!RegisterClass(&wc1)){//ע��ϵͳ����ͼ�괰���� 
    	MessageBox(NULL,"Tray Icon Registration Failed!","Error",MB_ICONWARNING|MB_OK);
    	return 0;
	}
    HWND hWnd = CreateWindowEx(0, wc1.lpszClassName, "TrayIconWindow", 0, 0, 0, 0, 0, HWND_MESSAGE, 0, wc1.hInstance, 0);//��������ͼ�괦���� 
	//���� 
    nid.cbSize = sizeof(NOTIFYICONDATA);
    nid.hWnd = hWnd;
    nid.uID = 10000;
	nid.uTimeout = 0;
    nid.uVersion = NIM_SETVERSION;
    nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE | NIF_INFO;//����ͼ���� 
    nid.uCallbackMessage = WM_USER;
    nid.hIcon = LoadIcon(hINstance,"A"); // ����Դ����ͼ��
    strcpy(nid.szTip,"Dynamic Wallpaper Tools");
    strcpy(nid.szInfo, "^_^");
    strcpy(nid.szInfoTitle,"������������ɣ��벻Ҫ��������");//Toast Message Box
    Shell_NotifyIcon(NIM_ADD,&nid);
    //Shell_NotifyIcon(NIM_SETVERSION, &nid);
	
    //CreateThread(NULL,NULL,nidThread,NULL,NULL,NULL);//�����߳� 
    //Sleep(200);
    
	MSG msg; /* A temporary location for all messages */

	/* zero out the struct and set the stuff we want to modify */
	memset(&wc, 0, sizeof(wc));//ע���������� 
	wc.cbSize = sizeof(WNDCLASSEX);
	wc.lpfnWndProc = WndProc; /* This is where we will send messages to */
	wc.hInstance = HInstance;
	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
	wc.style=CS_DBLCLKS|CS_SAVEBITS|CS_GLOBALCLASS;

	/* White, COLOR_WINDOW is just a #define for a system color, try Ctrl+Clicking it */
	wc.hbrBackground = CreateSolidBrush(RGB(240,240,240))/*(HBRUSH)(COLOR_WINDOW + 1)*/;
	wc.lpszClassName = "DWPT_PRIVATECLASS";
	wc.hIcon = LoadIcon(hINstance,"IDI_SELECTUNUSE"); /* Load a standard icon */
	wc.hIconSm = LoadIcon(hINstance,"A"); /* use the name "A" to use the project icon */

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);//�ж��Ƿ�ɹ� 
		return 0;
	}
	
	HMENU menu=CreateMenu(),OPEN=CreatePopupMenu(),AboutMenu=CreatePopupMenu(),DefMenu=CreatePopupMenu(),FuncMenu=CreatePopupMenu();//��Ӳ˵��� 
	GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","BLAS",RETURN);//��ȡע����� 
	AppendMenu(FileMenu,((strcmp(RETURN,"true")==0)?MF_CHECKED:MF_UNCHECKED),10,GetString4ThisLang(15));//������������ 
	AppendMenu(OPEN,MF_STRING,2,GetString4ThisLang(17));//�༭�����ļ� 
	AppendMenu(OPEN,MF_STRING,3,GetString4ThisLang(24));//���������ļ� 
	AppendMenu(OPEN,MF_STRING,7,GetString4ThisLang(25));//����ΪĬ���� 
	AppendMenu(DefMenu,MF_STRING,8,GetString4ThisLang(17));//�༭Ĭ�������ļ� 
	AppendMenu(DefMenu,MF_STRING,9,GetString4ThisLang(24));//����Ĭ�������ļ� 
	AppendMenu(FileMenu,MF_STRING,1,StringCat(GetString4ThisLang(0)," (&N)"));//�½������ļ��� 
	AppendMenu(FileMenu,MF_HILITE,0,NULL);//�ָ��� 
	AppendMenu(FileMenu,MF_POPUP,(UINT_PTR)DefMenu,GetString4ThisLang(31));//��Ĭ��������� 
	AppendMenu(FileMenu,MF_POPUP,(UINT_PTR)OPEN,GetString4ThisLang(30));//�򿪲������� 
	AppendMenu(FileMenu,MF_HILITE,0,NULL);//�ָ��� 
	AppendMenu(FileMenu,MF_STRING,5,GetString4ThisLang(29));//������̬��ֽ 
	AppendMenu(FileMenu,MF_STRING,4,GetString4ThisLang(20));//�˳� 
	AppendMenu(menu,MF_POPUP,(UINT_PTR)FileMenu,GetString4ThisLang(27));//�ļ� 
	AppendMenu(FuncMenu,MF_STRING,15,"��WinWatcher����");//��WinWatcher���� 
	AppendMenu(menu,MF_POPUP,(UINT_PTR)FuncMenu,"���ܣ�&T��");//���� 
	AppendMenu(AboutMenu,MF_STRING,12,GetString4ThisLang(45));//���ʹ�� 
	AppendMenu(AboutMenu,MF_STRING,6,GetString4ThisLang(28));//����������Ϣ�� 
	AppendMenu(menu,MF_POPUP,(UINT_PTR)AboutMenu,GetString4ThisLang(26));//���� 
	//�������ֲ˵� 
	
	HWND_ = CreateWindowEx(WS_EX_ACCEPTFILES,"DWPT_PRIVATECLASS", "Dynamic Wallpaper Tools", WS_VISIBLE | WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX | WS_CLIPSIBLINGS | WS_CLIPCHILDREN | DS_FIXEDSYS | DS_3DLOOK | DS_SETFONT | DS_MODALFRAME | DS_NOIDLEMSG,
		CW_USEDEFAULT, /* x */
		CW_USEDEFAULT, /* y */
		800, /* width */
		400/*60*/, /* height */
		NULL, menu, HInstance, NULL);//�������� 

	if (HWND_ == NULL) {//�ж��Ƿ�ɹ� 
		MessageBox(NULL, "Window Creation Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}
	
	MENUINFO menuInfo={0};
	menuInfo.cbSize=sizeof(MENUINFO);
	menuInfo.fMask=MIM_BACKGROUND;
	menuInfo.hbrBack=CreateSolidBrush(RGB(44,44,44));
	SetMenuInfo(GetMenu(HWND_),&menuInfo);
	DrawMenuBar(HWND_);
	SendMessage(HWND_, WM_MENUSELECT, (WPARAM)menu, MAKELPARAM(0, MF_BYPOSITION));
	DeleteObject(menuInfo.hbrBack);
	
	//CreateWindow("Button","BUTTON",WS_CHILD|WS_VISIBLE,20,200,100,100,HWND_,NULL,NULL,NULL); 
	TCITEM tie;
    LRESULT count, id;
    
    hTab = CreateWindow("SysTabControl32", NULL, WS_CHILD | WS_VISIBLE,
        0, 0, 800, 400, HWND_,(HMENU) 13, NULL, NULL);//����Tab Control
    SendMessage(hTab,WM_SETFONT,(WPARAM)hFont,NULL);
	
	/*DWORD dwAttribute = 20;//DWMWA_USE_IMMERSIVE_DARK_MODE; // ���ð�ɫģʽ����
	BOOL bValue = TRUE; // ���ð�ɫģʽ
	DwmSetWindowAttribute(HWND_, dwAttribute, &bValue, sizeof(dwAttribute)); // ���ô�������*/
	
    for(int i=0;i<3;i++){//�����������ںͿؼ� 
		tie.mask = TCIF_TEXT;
	    if(i<2) tie.pszText = GetString4ThisLang(13+i);//��ȡ�����ı� 
	    else tie.pszText=GetString4ThisLang(46);
		if(i==0){
			hConfig=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);
			for(int i=0;i<5;i++){//��ס��Dev C++����ʱҪ�� ��Ŀ[P] -> ��Ŀ����[O] ����ѡ��"֧�� Windows XP ����"�������ѿ���ȥ�������� 
				HWND hwnd=CreateWindow("Button",GetString4ThisLang(i)/*BtnName[i]*/,WS_CHILD|WS_VISIBLE|BS_COMMANDLINK,BtnPos[i].left,BtnPos[i].top,BtnPos[i].right-BtnPos[i].left,BtnPos[i].bottom-BtnPos[i].top,hConfig,(HMENU)BtnWparam[i],NULL,NULL);
				//CreateButton(BtnName[i],BtnPos[i].left,BtnPos[i].top,BtnPos[i].right-BtnPos[i].left,BtnPos[i].bottom-BtnPos[i].top,HWND_,(HMENU)BtnWparam[i],NULL,NULL);
				SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,NULL);
			}
			ShowWindow(hConfig,SW_SHOW);
		}
		else if(i==1){
			hSet=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);
			HWND hwnd=CreateWindow("button",GetString4ThisLang(15),WS_CHILD|WS_VISIBLE|BS_CHECKBOX,20,20,760,25,hSet,(HMENU)10,NULL,NULL);
			SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,NULL);
			GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","BLAS",RETURN);
			CheckDlgButton(hSet,10,((strcmp(RETURN,"true")==0)?BST_CHECKED:BST_UNCHECKED));//����CheckBox�Ƿ�ȷ�� 
			GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",RETURN);
			char str[1145];
			strcpy(str,GetString4ThisLang(16));
			strcat(str,RETURN);
			hStaticDef=CreateWindow("STATIC",str,WS_CHILD|WS_VISIBLE,20,60,660,25,hSet,(HMENU)100,NULL,NULL);
			SendMessage(hStaticDef,WM_SETFONT,(WPARAM)hFont,NULL);
			hBossKey=CreateWindowEx(0,"msctls_hotkey32",NULL,WS_CHILD|WS_VISIBLE,160,100,500,30,hSet,NULL,NULL,NULL);
			SendMessage(hBossKey,WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"STATIC",GetString4ThisLang(51),WS_CHILD|WS_VISIBLE,20,100,120,30,hSet,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON",GetString4ThisLang(47),WS_CHILD|WS_VISIBLE,700,100,100,30,hSet,(HMENU)16,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			hwnd=CreateWindow("button",GetString4ThisLang(17),WS_CHILD|WS_VISIBLE|BS_PUSHBUTTON,680,60,100,30,hSet,(HMENU)7,NULL,NULL);
			SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,NULL);
			ShowWindow(hSet,SW_HIDE);//����hSet���� 
		}
		else{
			hAnyWindow=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);	
			ShowWindow(hAnyWindow,SW_HIDE);
			SendMessage(CreateWindowEx(0,"BUTTON",GetString4ThisLang(48),WS_CHILD|WS_VISIBLE|BS_GROUPBOX,50,10,700,280,hAnyWindow,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			hsti=CreateWindowEx(0,"BUTTON",NULL,WS_CHILD|WS_VISIBLE|BS_ICON,100,50,50,50,hAnyWindow,(HMENU)13,NULL,NULL);
			SendMessage(hsti, BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(hINstance,"IDI_SELECTUNUSE"));
			SendMessage(CreateWindowEx(0,"STATIC",GetString4ThisLang(49),WS_CHILD|WS_VISIBLE,100,120,600,120,hAnyWindow,(HMENU)1,NULL,NULL),WM_SETFONT,
				(WPARAM)CreateFont(20, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("˼Դ")),NULL);
			SendMessage(CreateWindowEx(0,"STATIC",GetString4ThisLang(50),WS_CHILD|WS_VISIBLE,100,250,650,25,hAnyWindow,(HMENU)2,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON",GetString4ThisLang(47),WS_CHILD|WS_VISIBLE,650,250,60,40,hAnyWindow,(HMENU)14,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
		}
	    //count=SendMessage(hTab, TCM_GETITEMCOUNT, 0, 0);
	    SendMessage(hTab, TCM_INSERTITEM, i, (LPARAM) (LPTCITEM) &tie);//��� 
	}
	
	HMENU hMenu=GetSystemMenu(HWND_,FALSE);
	AppendMenu(hMenu,MF_HILITE,0,NULL);//�ָ��� 
	AppendMenu(hMenu,MF_STRING,11,GetString4ThisLang(44));//��С��ϵͳ���� 
	AppendMenu(hMenu,MF_STRING,4,GetString4ThisLang(20));//�˳� 
	//�޸Ĵ��ڵ�Ĭ��ϵͳ�˵�

	/*
		This is the heart of our program where all input is processed and
		sent to WndProc. Note that GetMessage blocks code flow until it receives something, so
		this loop will not produce unreasonably high CPU usage
	*/
	
	ShowWindow(HWND_, nShowCmd);//չʾ���ڣ�Ҳ�������ھ�̬����ʱ���ش��ڣ� 
	UpdateWindow(HWND_);//���´��� 
	
	//CreateThread(NULL,NULL,TimeThread,NULL,NULL,NULL);
	
	while (GetMessage(&msg, NULL, 0, 0) > 0) { /* If no error is received... */
		TranslateMessage(&msg); /* Translate key codes to chars if present */
		DispatchMessage(&msg); /* Send it to WndProc */
	}//��ѭ�� 
	
    Shell_NotifyIcon(NIM_DELETE, &nid);//ɾ��ͼ�� 
	return (int)msg.wParam;//����ֵ 
}
