#include "WallpaperCore\dll.h" //WallpaperCore.dll�Ŀ��ļ� 
#include "HelpDWPT\dll.h" //HelpDWPT.dll�Ŀ��ļ� 
#include <commctrl.h> 
#undef BS_OWNERDRAW
#define BS_OWNERDRAW 0 
//#pragma comment (lib,"HelpDWPT\libHelpDWPT.a") 
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
#define IL_UNSET -1 //δ���� 
#define IL_ENGLISH 0 //Ӣ�� 
#define IL_Simplified_Chinese 1 //�������� 
#define IL_Traditional_Chinese 2 //�������� 

HINSTANCE HInstance; //����ľ����ʹ��GetModuleHandle�������ɻ�� 
WNDCLASSEX wc; //�����࣬��������ʱ��Ҫע��һ����ſ��Դ������ڣ����򱨴� 
char RETURN[1145],*programName,*NameOfPro,CmdLine[1145],ConfigFile[MAX_PATH+1];//һ�ѵ��ַ�������඼����ʱ�ġ���StartDwp������ʹ�� 
DWORD dw/*���ļ�ʱ�ı��*//*,BtnType[5]={BT_MOUSEMOVE,BT_MOUSEMOVE,BT_MOUSEMOVE,BT_MOUSEMOVE,BT_MOUSEMOVE}/*��ס���а�ť״̬*/;
HANDLE hFile;//�ļ���� 
HDC hdc=GetDC(0);//��ȡ�����HDC�������㴰��ѡ������ 
int W /*������*/,H /*����߶�*/,BtnWparam[5]={1,2,3,5,6}/*���ð�ť�¼�ID���*/;
HWND /*hWnd,*/HWND_,hTab,hSet,hConfig,hAnyWindow,hStaticDef,hBossKey,hsti,ChooseWindow,hFB;//hWnd=����ͼ�괰�ھ����HWND_=�����ھ�� 
NOTIFYICONDATAA nid;//����ͼ������ 
HMENU FileMenu=CreatePopupMenu(),HistroyMenu=CreatePopupMenu(),FuncMenu=CreatePopupMenu(),LangMenu=CreatePopupMenu();//�ļ��˵���ȫ������Ϊ�����Ҽ�Ҫ����� 
int WINAPI winMain(_In_ HINSTANCE,_In_opt_ HINSTANCE,_In_ LPSTR,_In_ int);
typedef BOOL WINAPI (*SPDA)(VOID);
SPDA SetProcessDPIAwarev;//���øý��̵�DPI�������ܳ��ұ�����̫�� 
HFONT hFont = CreateFont(25, NULL, NULL, NULL, NULL, NULL, NULL, NULL, GB2312_CHARSET, NULL, NULL, NULL, NULL, TEXT("˼Դ"));//Ĭ������ 
//char BtnName[5][30]={"�½������ļ�","�༭�����ļ�","Ӧ�������ļ�","ֹͣ��̬��ֽ","����Dynamic Wallpaper Tools"};//��ť�ı� 

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
};//���а�ť��λ��

char* StringCat(char *Str1,const char *Str2){//û�õĶ��� 
	char* a;//�����ַ��� 
	strcpy(a,Str1);
	strcat(a,Str2);
	return a;
}

void ToastMessage(const char Title[],const char Info[],const char InfoTitle[],int time=0){
	nid.uTimeout=time;
	strcpy(nid.szInfo,Info);//������Ϣ 
	strcpy(nid.szTip,Title);
	strcpy(nid.szInfoTitle,InfoTitle);
    Shell_NotifyIcon(NIM_MODIFY, &nid);//�޸�ͼ��  
    Shell_NotifyIcon(NIM_SETVERSION, &nid);//���� 
}

LONG GetRegValue(HKEY key,const char path[],const char keyname[],char value[]){//��ȡע����ĳ��ֵ ���������Ա�� 
    HKEY hKey;
    BYTE byData[255];//���������� 
    LONG status = RegOpenKeyExA(key, path, 0, KEY_READ, &hKey);//�򿪼� 
    if (status != ERROR_SUCCESS) return status;
    DWORD dwSize = sizeof(byData),dwType;
    status = RegQueryValueExA(hKey, keyname, NULL, &dwType, byData, &dwSize);//��ȡ���� 
    if (status != ERROR_SUCCESS) {//�����ж� 
        RegCloseKey(hKey);
        return status;
    }
    strcpy(value,(char*)byData);//���� 
    RegCloseKey(hKey);//�رռ� 
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

char* NumToString(int n){//������ת��Ϊ�ı�������ֵ��RETURN�����У�
	sprintf(RETURN,"%d",n);
	return RETURN;
}
bool OpenFileDlg(HWND ParentWindow, LPCSTR FileType, char Output_Path[]) {//���ļ��Ի��� 
	OPENFILENAME ofn;//���ļ��ṹ�� 
	TCHAR szFile[MAX_PATH] = {};

	ZeroMemory(&ofn, sizeof(ofn));//��ʼ�����ļ��Ľṹ�� 
	ofn.lStructSize = sizeof(ofn);
	ofn.lpstrFile = szFile;//����������Ҫ�� 
	ofn.lpstrFile[0] = '\0';//�ļ���������Ϊ�� 
	ofn.hwndOwner = ParentWindow;//�����ڣ����� 
	ofn.nMaxFile = sizeof(szFile);
	ofn.lpstrFilter = FileType;//����ɸѡ�� 
	ofn.nFilterIndex = 1;
	ofn.lpstrInitialDir = NULL;
	ofn.lpstrFileTitle = NULL;
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;//���ñ�־ 
	if (!GetOpenFileName(&ofn)) return false;//ʧ�� ���� �û������ȡ�� 
	else strcpy(Output_Path,ofn.lpstrFile);
	if(strcmp(FileType,GetString4ThisLang(8))==0){
		char str[1145];
		for(int i=9;i>=1;i--){//��¼��ʷ 
			sprintf(RETURN,"File[%d]",i-1);
			GetPrivateProfileString("Histroy",RETURN,NULL,str,MAX_PATH,ConfigFile);
			sprintf(RETURN,"File[%d]",i);
			WritePrivateProfileString("Histroy",RETURN,str,ConfigFile);
		}
		WritePrivateProfileString("Histroy","File[0]",Output_Path,ConfigFile);//д�������ļ� 
	}
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
	ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_OVERWRITEPROMPT;

	if (!GetSaveFileNameA(&ofn)) return false;//ʧ�� \ �û������ȡ�� 
	else strcpy(Output_Path,ofn.lpstrFile);//�����ı� 
	int i = strlen(ofn.lpstrFile);
	while (i>0&&((Output_Path)[i]) != '.' && ((Output_Path)[i]) != '\\') i--;
	if (((Output_Path)[i]) == '\\') strcat((Output_Path),(char*)"."), strcat((Output_Path), (char*)typestr);//�ж��Ƿ��к�׺����û�оͼ�һ��Ĭ�ϵ� 
	char str[1145];
	for(int i=1;i<=9;i++){
		sprintf(RETURN,"File[%d]",i-1);
		GetPrivateProfileString("Histroy",RETURN,NULL,str,MAX_PATH,ConfigFile);
		sprintf(RETURN,"File[%d]",i);
		WritePrivateProfileString("Histroy",RETURN,str,ConfigFile);
	}
	WritePrivateProfileString("Histroy","File[0]",Output_Path,ConfigFile);
	return true;//�ɹ��� 
}

/*BOOL CALLBACK OutDWPProc(_In_ HWND hWnd,_In_ LPARAM lparam){
	char Text[1145];
	GetClassName(hWnd,Text,sizeof(Text));
	//GetWindowText(hWnd,Text,GetWindowTextLength(hWnd)+1);
	if(strcmp(Text,"SHELLDLL_DefView")!=0) PostMessage(hWnd,WM_CLOSE,NULL,NULL);
	return TRUE;
}*/
int SetDefFont(LOGFONTA *lpLogFont){//����Ĭ������ 
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
		WritePrivateProfileString("Font","lflfHeight",TempStr,ConfigFile);
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
DWORD WINAPI FindWindowProcess(LPVOID lparam){//���Ҵ��ڵ��߳� //��ȡ�û�ѡ��Ĵ��� 
	SendMessage(hsti, BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(HInstance,"IDI_SELECTUSING"));//����ͼ�� 
	ChooseWindow=0;//Ĭ������Ϊ�� 
	POINT cur;//���ָ��λ�� 
	//HCURSOR hCursor=LoadCursor(HInstance,"IDC_SELECTCURSOR");
	HWND Find;//��ǰѡ��Ĵ��ھ�� 
	RECT rect,DRect;
	char str[1145];
	HBRUSH GBrush=CreateSolidBrush(RGB(0,255,0));//Ԥ���ˢ 
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
			strcat(str,Text);//ƴ����ʾ�ı� 
			SetDlgItemText(hAnyWindow,1,str);
			strcpy(str,GetString4ThisLang(50));
			GetClassName(ChooseWindow,Text,sizeof(Text));
			strcat(str,Text);//ƴ����ʾ�ı� 
			SetDlgItemText(hAnyWindow,2,str);//���ô�����Ϣ+���� 
		}
	}
	SendMessage(hsti, BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(HInstance,"IDI_SELECTUNUSE"));//����ͼ�� 
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

BOOL CALLBACK SetDPI(_In_ HWND hwnd, _In_ LPARAM Lparam){
	return SetProcessDPIAwarev();
}

/* This is where all the input to the window goes to */

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
		
		case WM_CREATE:{//Dark Mode Menu+Titlebar
			//SetTimer(hwnd,1,100,NULL);
			HMODULE hModule=LoadLibrary("dwmapi.dll");
			if(hModule){
				bool Dark=true;
				typedef VOID (*DSWA)(HWND,DWORD,LPCVOID,DWORD);
				DSWA DwmSetWindowAttribute=(DSWA)GetProcAddress(hModule,"DwmSetWindowAttribute");
				if(DwmSetWindowAttribute) DwmSetWindowAttribute(hwnd, 20,  &Dark, 4);
			}
			hModule=GetModuleHandle("uxtheme.dll");
			if(hModule){
				typedef VOID (*SPAM)(int);
				SPAM SetPreferredAppMode=(SPAM)GetProcAddress(hModule,MAKEINTRESOURCE(135));
				if(SetPreferredAppMode) SetPreferredAppMode(2);
				typedef VOID (*FMT)();
				FMT FlushMenuThemes=(FMT)GetProcAddress(hModule,MAKEINTRESOURCE(136));
				if(FlushMenuThemes) FlushMenuThemes();
				typedef VOID (*ADMW)(HWND,BOOLEAN);
				ADMW AllowDarkModeForWindow=(ADMW)GetProcAddress(hModule,MAKEINTRESOURCE(133));
				if(AllowDarkModeForWindow) AllowDarkModeForWindow(hwnd,TRUE);
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
					if(!SaveFileDlg(hwnd,GetString4ThisLang(8),SP,"dp")) break;//���Ϊĳ��dp�ļ� 
					if(!OpenFileDlg(hwnd,GetString4ThisLang(7),Video)) break;//��ȡ��Ƶ 
					isSound=(MessageBox(hwnd,GetString4ThisLang(9),"Question",MB_YESNO|MB_ICONQUESTION)==6);
					freopen(SP,"w",stdout);
					printf("%s",(isSound?"t":"f"));//д����Ϣ 
					printf("%s",Video);
					fclose(stdout);
					if(MessageBox(hwnd,GetString4ThisLang(11),"Information",MB_YESNO|MB_ICONQUESTION)==6){
						StartDwp(SP,false);//������ 
						ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//��ʾ������� 
					}
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
							ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//��ʾ������� 
							Sleep(1000);
						}
					}
					break;
				}
				case 3:{//���������� 
					char SP[1145];
					if(!OpenFileDlg(hwnd,GetString4ThisLang(8),SP)) break;
					StartDwp(SP,false);//������ 
					ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//��ʾ������� 
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
							STARTUPINFOA StartupInfo;memset(&StartupInfo,0,sizeof(StartupInfo));
							PROCESS_INFORMATION ProcessInformation;memset(&ProcessInformation,0,sizeof(ProcessInformation));
							char buf[MAX_PATH+5],buf2[MAX_PATH+5];
							GetSystemDirectory(buf,MAX_PATH+1);
							sprintf(buf2,"%c:\\Windows\\explorer.exe",buf[0]);
							CreateProcess(buf2,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&StartupInfo,&ProcessInformation);
							Sleep(2000); 
							MessageBox(hwnd,GetString4ThisLang(23),"Restart explorer.exe complete",MB_ICONINFORMATION); 
							Shell_NotifyIcon(NIM_ADD,&nid);
							ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(81));//��ʾ������� 
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
					ExitChoose://����������Ϣ 
					if(MessageBox(hwnd,GetString4ThisLang(42),"Edit",MB_YESNO|MB_ICONQUESTION)==6){
						freopen(SP,"w",stdout);
						printf("%s",(sound?"t":"f"));
						printf("%s",VP);
						fclose(stdout);
						if(MessageBox(hwnd,GetString4ThisLang(43),"Edit",MB_YESNO|MB_ICONQUESTION)==6){
							StartDwp(SP,false);
							ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//��ʾ������� 
							Sleep(1000);
						}
					}
					break;
				}
				case 9:{//����Ĭ�ϵ������ļ� 
					char SP[1145];
					if(GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",SP)!=ERROR_SUCCESS) break;
					StartDwp(SP,false);
					ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//��ʾ������� 
					Sleep(1000);
					break;
				}
				case 10:{//�л��Ƿ񿪻���������״̬ 
		            UINT st=GetMenuState(FileMenu, 10, MF_BYCOMMAND);//��ȡ�Ƿ�ѡ�� 
					HKEY hKey; 
					DWORD disp;
					RegCreateKeyEx(//������ 
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
		            if (st == MF_CHECKED) {//���ǿ���������ʱ 
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
		            else {//���ǿ���������ʱ 
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
				case 12:{//�򿪰������ڣ�HelpDWPT.dll�� 
					HelpWindow(hwnd);
					break;
				}
				case 13:{//���Ҵ��ڣ���������Developer Options�� 
					CreateThread(NULL,NULL,FindWindowProcess,NULL,NULL,NULL);
					break;
				}
				case 14:{//�趨 
					if(ChooseWindow==0||ChooseWindow==HWND_||(!IsWindowVisible(HWND_))||IsIconic(HWND_)) MessageBox(hwnd,"δѡ��һ����ȷ�Ĵ��ڣ��޷�����Ϊ������","Error",MB_ICONWARNING);//ʧ����ʾ 
					else{
						char Text[1145];
						GetClassName(ChooseWindow,Text,sizeof(Text));//��ȡ�������� 
						if(strcmp(Text,"WorkerW")==0||strcmp(Text,"Progman")==0||strcmp(Text,"Shell_TrayWnd")==0) MessageBox(hwnd,"δѡ��һ����ȷ�Ĵ��ڣ��޷�����Ϊ������","Error",MB_ICONWARNING);
						else if(MessageBox(hwnd,GetString4ThisLang(6),"Warning",MB_ICONWARNING|MB_YESNO)==6){
							HWND PROGMAN=FindWindow("Progman", 0);
							if(PROGMAN) EnumChildWindows(PROGMAN,StopDWPProc,NULL);//
							PutToDesktop(ChooseWindow);
						}
					}
					break;
				}
				case 15:{//��WinWatcher���ߣ�HelpDWPT.dll�� 
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
				case 25:{//����ʷ�� 
					char str[1145];
					GetMenuString(HistroyMenu,LOWORD(wParam),str,MAX_PATH+2,MF_STRING);
					if(access(str,F_OK)==0){
						StartDwp(str,false);
						ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//��ʾ������� 
					}
					else MessageBox(hwnd,GetString4ThisLang(55),"Error",MB_ICONWARNING);
					break;
				}
				case 26:{//δ��� 
					MessageBox(hwnd,"This feature has not been developed yet.","ERROR",MB_ICONWARNING);
					break;
				}
				case 27:{//����GUID/UUID 
					char str[1145],guid_str[1145];
					GUID guid;
					CoCreateGuid(&guid);
					sprintf(str,"Guid \\ Uuid: %08x-%04x-%04x-%02x%02x%02x%02x%02x%02x%02x%02x, Click Cancel to Copy that.",guid.Data1,guid.Data2,guid.Data3,guid.Data4[0],guid.Data4[1],guid.Data4[2],guid.Data4[3],guid.Data4[4],guid.Data4[5],guid.Data4[6],guid.Data4[7]);
					sprintf(guid_str,"%08x-%04x-%04x-%02x%02x%02x%02x%02x%02x%02x%02x",guid.Data1,guid.Data2,guid.Data3,guid.Data4[0],guid.Data4[1],guid.Data4[2],guid.Data4[3],guid.Data4[4],guid.Data4[5],guid.Data4[6],guid.Data4[7]);
					if(MessageBox(HWND_,str,"Guid \\ Uuid Generater",MB_ICONINFORMATION|MB_OKCANCEL)==2){
						if (OpenClipboard(NULL)) {
							// ��ռ��а�
							EmptyClipboard();
							// �����ڴ����ڴ洢�ַ���
							HGLOBAL hglbCopy = GlobalAlloc(GMEM_MOVEABLE, (strlen(guid_str) + 1) * sizeof(char));
							if (hglbCopy == NULL) {
							    CloseClipboard();
							    break;
							}
							// �����ڴ�
							char *lptstrCopy = (char*)GlobalLock(hglbCopy);
							memcpy(lptstrCopy, guid_str, strlen(guid_str) + 1);
							// �����ڴ�
							GlobalUnlock(hglbCopy);
							// ���ü��а�����
							SetClipboardData(CF_TEXT, hglbCopy);
							// �رռ��а�
							CloseClipboard();
						}
					}
					break;
				}
				case 30:{//�������� 
					char Command[1145],VPath[1145],ProP[1145];
					GetModuleFileName(NULL,ProP,1140);
					bool SpacePro=false,SpaceVideo=false;
					for(int i=0;i<strlen(ProP);i++) if(ProP[i]==' ') SpacePro=true;
					if(SpacePro){//�����ļ����пո� 
						GetDlgItemText(hFB,29,VPath,1140);
						if((GetFileAttributes(VPath)==INVALID_FILE_ATTRIBUTES)){
							MessageBox(HWND_,GetString4ThisLang(59),NULL,MB_ICONWARNING|MB_OK);
							break;
						}
						for(int i=0;i<strlen(VPath);i++) if(VPath[i]==' ') SpaceVideo=true;
						if(SpaceVideo) sprintf(Command,"\"%s\" -f false \"%s\"",ProP,VPath);//��Ƶ�ļ����пո� 
						else sprintf(Command,"\"%s\" -f false %s",ProP,VPath);//��Ƶ�ļ����޿ո� 
					}
					else{//�����ļ����޿ո� 
						GetDlgItemText(hFB,29,VPath,1140);
						if((GetFileAttributes(VPath)==INVALID_FILE_ATTRIBUTES)){
							MessageBox(HWND_,GetString4ThisLang(59),NULL,MB_ICONWARNING|MB_OK);
							break;
						}
						for(int i=0;i<strlen(VPath);i++) if(VPath[i]==' ') SpaceVideo=true;
						if(SpaceVideo) sprintf(Command,"%s -f false \"%s\"",ProP,VPath);//��Ƶ�ļ����пո� 
						else sprintf(Command,"%s -f false %s",ProP,VPath);//��Ƶ�ļ����޿ո� 
					}
					WinExec(Command,SW_HIDE);//���� 
					ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//��ʾ������� 
					break;
				}
				case 31:{//������һ���ĵ�����֮ͬ����һ������һ�������� 
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
					ToastMessage("Dynamic Wallpaper Tools","~(^-^)~",GetString4ThisLang(80));//��ʾ������� 
					break;
				}
				case 32:{//�򿪿��������˵� 
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
					SetDlgItemText(hFB,29,str_path);
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
					break;
				} 
				case 37:{
					MessageBox(hwnd,GetString4ThisLang(77),"Information",MB_ICONINFORMATION);
					WritePrivateProfileString("Main","Lang","1",ConfigFile);
					CheckMenuItem(LangMenu,36,MF_UNCHECKED);
					CheckMenuItem(LangMenu,37,MF_CHECKED);
					CheckMenuItem(LangMenu,38,MF_UNCHECKED);
					break;
				}
				case 38:{
					MessageBox(hwnd,GetString4ThisLang(77),"Information",MB_ICONINFORMATION);
					WritePrivateProfileString("Main","Lang","2",ConfigFile);
					CheckMenuItem(LangMenu,36,MF_UNCHECKED);
					CheckMenuItem(LangMenu,37,MF_UNCHECKED);
					CheckMenuItem(LangMenu,38,MF_CHECKED);
					break;
				}
				case 39:{
					WinExec("start https://github.com/BOffice-Excel/Excel-s-Dynamic-Wallpaper-Tools",SW_HIDE);
					break;
				}
			}
			break;
		}
		case WM_CTLCOLORBTN: 
		case WM_CTLCOLORSTATIC:{
			HBRUSH hbrBkgnd=NULL;
	        HDC hdcStatic = (HDC) wParam;
	        SetTextColor(hdcStatic, RGB(0,0,0));
	        SetBkColor(hdcStatic, RGB(255,255,255));
	        if (hbrBkgnd == NULL){
	            hbrBkgnd = CreateSolidBrush(RGB(255,255,255));
	        }
	        return (INT_PTR)hbrBkgnd;
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
					}
					else if(result==1){
						ShowWindow(hFB,SW_HIDE);
						ShowWindow(hConfig,SW_HIDE);
						ShowWindow(hAnyWindow,SW_HIDE);
						ShowWindow(hSet,SW_SHOW);
					}
					else if(result==2){
						ShowWindow(hFB,SW_HIDE);
						ShowWindow(hConfig,SW_HIDE);
						ShowWindow(hAnyWindow,((GetPrivateProfileInt("Main","DevMode",0,ConfigFile)==0)?SW_HIDE:SW_SHOW));
						ShowWindow(hSet,SW_HIDE);
					}
					else if(result==3){
						ShowWindow(hFB,SW_SHOW);
						ShowWindow(hConfig,SW_HIDE);
						ShowWindow(hAnyWindow,SW_HIDE);
						ShowWindow(hSet,SW_HIDE);
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
			        if ((((LPNMHDR)lParam)->idFrom == 39) && (item.iLink == 0)){
			            ShellExecuteW(NULL, L"open", item.szUrl, NULL, NULL, SW_SHOW);
			        }
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
	if(hModule){
		SetProcessDPIAwarev = (SPDA)GetProcAddress(hModule,"SetProcessDPIAware");
		if(SetProcessDPIAwarev) SetProcessDPIAwarev();//���������� 
	} 
	bool hasCmd=false;
	//���������� 
	if(argc>1) for(int i=0;i<strlen(argv[1]);i++) if(argv[1][i]>='A'&&argv[1][i]<='Z') argv[1][i]+='a'-'A';
	if(argc==2){
		if(strcmp(argv[1],"-q")==0){
			GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",RETURN);
			SGetQuietMode(true,true);
			SGetVidPath(true,RETURN);
			DwpThread(NULL);
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
			if((GetFileAttributes(argv[3])!=INVALID_FILE_ATTRIBUTES)&&(strcmp(argv[2],"true")==0||strcmp(argv[2],"false")==0)){
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
	NameOfPro = argv[0];//��ǰ����Ŀ¼+���� 
	//if(hasCmd==false) runAsAdmin();
	programName = argv[0];
	for(int i=strlen(programName)-1;i>=0;i--){//��ȡ��ǰλ�� 
		if(programName[i]!='\\') programName[i]=NULL;
		else break;
	}
	sprintf(ConfigFile,"%s\\Config.ini",programName);
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
		ShowWindow(FindWindow("DWPT_PRIVATECLASS",0),SW_SHOW);
		SwitchToThisWindow(FindWindow("DWPT_PRIVATECLASS",0),TRUE);
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
    nid.uVersion = NIM_SETVERSION;
    nid.uFlags = NIF_ICON | NIF_TIP | NIF_MESSAGE | NIF_INFO;//����ͼ���� 
    nid.uCallbackMessage = WM_USER;
    nid.hIcon = LoadIcon(hINstance,"A"); // ����Դ����ͼ��
    Shell_NotifyIcon(NIM_ADD,&nid);
    ToastMessage("Dynamic Wallpaper Tools","^_^",GetString4ThisLang(78));//��ToastMessage 
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
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wc.lpszClassName = "DWPT_PRIVATECLASS";
	wc.hIcon = LoadIcon(hINstance,"IDI_SELECTUNUSE"); /* Load a standard icon */
	wc.hIconSm = LoadIcon(hINstance,"A"); /* use the name "A" to use the project icon */

	if (!RegisterClassEx(&wc)) {
		MessageBox(NULL, "Window Registration Failed!", "Error!", MB_ICONEXCLAMATION | MB_OK);//�ж��Ƿ�ɹ� 
		return 0;
	}
	
	//�����ʷ��HistroyMenu
	char str[]="File[114]",path[1145];
	for(int i=0;i<=9;i++){
		sprintf(str,"File[%d]",i);
		GetPrivateProfileString("Histroy",str,NULL,path,MAX_PATH+2,ConfigFile);
		AppendMenu(HistroyMenu,MF_STRING,16+i,path); 
	}
	
	HMENU menu=CreateMenu(),OPEN=CreatePopupMenu(),AboutMenu=CreatePopupMenu(),DefMenu=CreatePopupMenu();//��Ӳ˵��� 
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
	AppendMenu(FileMenu,MF_POPUP,(UINT_PTR)HistroyMenu,GetString4ThisLang(52));//��ʷ 
	AppendMenu(FileMenu,MF_HILITE,0,NULL);//�ָ��� 
	AppendMenu(FileMenu,MF_STRING,5,GetString4ThisLang(29));//������̬��ֽ 
	AppendMenu(FileMenu,MF_STRING,4,GetString4ThisLang(20));//�˳� 
	AppendMenu(menu,MF_POPUP,(UINT_PTR)FileMenu,GetString4ThisLang(27));//�ļ� 
	AppendMenu(FuncMenu,MF_STRING|((GetPrivateProfileInt("Main","DevMode",0,ConfigFile)==true)?MF_ENABLED:MF_DISABLED),15,GetString4ThisLang(54));//��WinWatcher���� 
	AppendMenu(FuncMenu,MF_STRING|((GetPrivateProfileInt("Main","DevMode",0,ConfigFile)==true)?MF_ENABLED:MF_DISABLED),27,GetString4ThisLang(56));//���� GUID \ UUID
	AppendMenu(FuncMenu,MF_STRING,34,GetString4ThisLang(69));//����Ĭ������
	AppendMenu(menu,MF_POPUP,(UINT_PTR)FuncMenu,GetString4ThisLang(53));//����
	AppendMenu(LangMenu,MF_STRING|((SGetLangId(false,false)==0)?MF_CHECKED:MF_UNCHECKED),36,GetString4ThisLang(74));//Ӣ�� 
	AppendMenu(LangMenu,MF_STRING|((SGetLangId(false,false)==1)?MF_CHECKED:MF_UNCHECKED),37,GetString4ThisLang(75));//�������� 
	AppendMenu(LangMenu,MF_STRING|((SGetLangId(false,false)==2)?MF_CHECKED:MF_UNCHECKED),38,GetString4ThisLang(76));//�������� 
	AppendMenu(menu,MF_POPUP,(UINT_PTR)LangMenu,GetString4ThisLang(73));//���� 
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
        0, 0, 800, 400, HWND_,(HMENU) 13, NULL, NULL);//����Tab Control
    SendMessage(hTab,WM_SETFONT,(WPARAM)hFont,NULL);
	
	HMODULE hModule=GetModuleHandle("uxtheme.dll");
	typedef VOID (*ADMW)(HWND,BOOLEAN);
	ADMW AllowDarkModeForWindow=(ADMW)GetProcAddress(hModule,MAKEINTRESOURCE(133));
    for(int i=0;i<4;i++){//�����������ںͿؼ� 
		tie.mask = TCIF_TEXT;
	    if(i<2) tie.pszText = GetString4ThisLang(13+i);//��ȡ�����ı� 
	    else if(i==2) tie.pszText=GetString4ThisLang(46);
	    else tie.pszText=GetString4ThisLang(58);
		if(i==0){
			hConfig=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);
			for(int j=0;j<5;j++){//��ס��Dev C++����ʱҪ�� ��Ŀ[P] -> ��Ŀ����[O] ����ѡ��"֧�� Windows XP ����"�������ѿ���ȥ�������� 
				HWND hwnd=CreateWindow("Button",GetString4ThisLang(j)/*BtnName[i]*/,WS_CHILD|WS_VISIBLE|BS_COMMANDLINK,BtnPos[j].left,BtnPos[j].top,BtnPos[j].right-BtnPos[j].left,BtnPos[j].bottom-BtnPos[j].top,hConfig,(HMENU)BtnWparam[j],NULL,NULL);
				//CreateButton(BtnName[i],BtnPos[i].left,BtnPos[i].top,BtnPos[i].right-BtnPos[i].left,BtnPos[i].bottom-BtnPos[i].top,HWND_,(HMENU)BtnWparam[i],NULL,NULL);
				SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,NULL);
				//SendMessage(hwnd,BCM_SETNOTE,NULL,(LPARAM)GetString4ThisLang(64+j));
				//SendMessage(hwnd,BCM_SETNOTE,NULL,(LPARAM)NoteText[j][0]);
			}
			CreateWindowEx(0,"SysLink","<A HREF=\"https://github.com/BOffice-Excel/Excel-s-Dynamic-Wallpaper-Tools\">Github</A>",WS_VISIBLE|WS_CHILD,20,270,500,30,hConfig, (HMENU)39, NULL, NULL);
			SendDlgItemMessage(hConfig,39,WM_SETFONT,(WPARAM)hFont,NULL);
			ShowWindow(hConfig,SW_SHOW);
		}
		else if(i==1){
			hSet=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);
			HWND hwnd=CreateWindow("button",GetString4ThisLang(15),WS_CHILD|WS_VISIBLE|BS_CHECKBOX,20,20,760,25,hSet,(HMENU)10,NULL,NULL);
			CreateWindow("button","Developer Options",WS_CHILD|WS_VISIBLE|BS_CHECKBOX,20,140,760,25,hSet,(HMENU)35,NULL,NULL);
			SendDlgItemMessageA(hSet,35,WM_SETFONT,(WPARAM)hFont,NULL);
			CheckDlgButton(hSet,35,((GetPrivateProfileInt("Main","DevMode",0,ConfigFile)==1)?BST_CHECKED:BST_UNCHECKED));//����CheckBox�Ƿ�ȷ�� 
			SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,NULL);
			GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","BLAS",RETURN);
			CheckDlgButton(hSet,10,((strcmp(RETURN,"true")==0)?BST_CHECKED:BST_UNCHECKED));//����CheckBox�Ƿ�ȷ�� 
			GetRegValue(HKEY_CURRENT_USER,"Software\\DWPT","SrtDefCfgPath",RETURN);
			char str[1145];
			sprintf(str,"%s%s",GetString4ThisLang(16),RETURN);
			hStaticDef=CreateWindow("STATIC",str,WS_CHILD|WS_VISIBLE,20,60,660,25,hSet,(HMENU)100,NULL,NULL);
			SendMessage(hStaticDef,WM_SETFONT,(WPARAM)hFont,NULL);
			hBossKey=CreateWindowEx(0,"msctls_hotkey32",NULL,WS_CHILD|WS_VISIBLE,160,100,500,30,hSet,NULL,NULL,NULL);
			SendMessage(hBossKey,WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"STATIC",GetString4ThisLang(51),WS_CHILD|WS_VISIBLE,20,100,120,30,hSet,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON",GetString4ThisLang(47),WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,680,100,100,30,hSet,(HMENU)26,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			hwnd=CreateWindow("button",GetString4ThisLang(17),WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,680,60,100,30,hSet,(HMENU)7,NULL,NULL);
			SendMessage(hwnd,WM_SETFONT,(WPARAM)hFont,NULL);
			ShowWindow(hSet,SW_HIDE);//����hSet���� 
		}
		else if(i==2){
			hAnyWindow=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);	
			ShowWindow(hAnyWindow,SW_HIDE);
			SendMessage(CreateWindowEx(0,"BUTTON",GetString4ThisLang(48),WS_CHILD|WS_VISIBLE|BS_GROUPBOX,50,10,700,280,hAnyWindow,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			hsti=CreateWindowEx(0,"BUTTON",NULL,WS_CHILD|WS_VISIBLE|BS_ICON,100,50,50,50,hAnyWindow,(HMENU)13,NULL,NULL);
			SendMessage(hsti, BM_SETIMAGE, IMAGE_ICON,(LPARAM)LoadIcon(hINstance,"IDI_SELECTUNUSE"));
			SendMessage(CreateWindowEx(0,"STATIC",GetString4ThisLang(49),WS_CHILD|WS_VISIBLE,100,120,600,120,hAnyWindow,(HMENU)1,NULL,NULL),WM_SETFONT,
				(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"STATIC",GetString4ThisLang(50),WS_CHILD|WS_VISIBLE,100,250,650,25,hAnyWindow,(HMENU)2,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON",GetString4ThisLang(47),WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,685,200,60,40,hAnyWindow,(HMENU)14,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON",GetString4ThisLang(79),WS_CHILD|WS_VISIBLE|BS_OWNERDRAW,625,200,60,40,hAnyWindow,(HMENU)39,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
		}
		else if(i==3){
			hFB=CreateWindow("DWPT_PRIVATECLASS",NULL,WS_CHILD|WS_VISIBLE,0,30,800,360,hTab,NULL,NULL,NULL);
			ShowWindow(hFB,SW_HIDE);
			//SendMessage(CreateWindowEx(0,"BUTTON","",BS_ICON|WS_VISIBLE|WS_CHILD,760,10,32,32,hFB,(HMENU)33,NULL,NULL), BM_SETIMAGE, IMAGE_BITMAP,(LPARAM)LoadBitmap(hINstance,"IDB_OPEN"));
			SendMessage(CreateWindowEx(0,"BUTTON","...",WS_VISIBLE|WS_CHILD,760,10,32,32,hFB,(HMENU)33,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"BUTTON",GetString4ThisLang(63),BS_SPLITBUTTON|WS_VISIBLE|WS_CHILD,160,220,200,80,hFB,(HMENU)32,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"STATIC",GetString4ThisLang(62),WS_VISIBLE|WS_CHILD,10,10,150,125,hFB,NULL,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
			SendMessage(CreateWindowEx(0,"EDIT","",WS_VISIBLE|WS_CHILD|WS_VSCROLL|ES_MULTILINE|ES_AUTOVSCROLL|WS_BORDER,160,10,600,200,hFB,(HMENU)29,NULL,NULL),WM_SETFONT,(WPARAM)hFont,NULL);
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
