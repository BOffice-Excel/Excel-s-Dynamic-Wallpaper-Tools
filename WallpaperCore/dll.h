#ifndef _DLL_H_
#define _DLL_H_
#ifndef DLLIMPORT
#if BUILDING_DLL
#define DLLIMPORT __declspec(dllexport)
#else
#define DLLIMPORT __declspec(dllimport)
#endif
#endif
#include <windows.h>//�ǳ���Ҫ������������ 
#include <stdio.h>
#include <io.h>
#define IL_UNSET -1 //δ���� 
#define IL_ENGLISH 0 //Ӣ�� 
#define IL_Simplified_Chinese 1 //�������� 
#define IL_Traditional_Chinese 2 //�������� 
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
		"Programming: Office Excel\nReference video by ż���е�С�Ժ�, video id: BV1HZ4y1978a (press to cancel to view original video)\nTools used: Dev-C++, Code language: C++\nProject start date: April 21, 2024\nVersion: 0.0.7.0\nTranslator: Baidu Translate",
		"����������Office-Excel\n�ο���Ƶ by ż���е�С�Ժ�����Ƶid��BV1HZ4y1978a������ȡ���鿴ԭ��Ƶ��\nʹ�ù��ߣ�Dev-C++���������ԣ�C++\n��Ŀ��ʼ���ڣ�2024/04/21\n�汾��0.0.7.0\n���������ٶȷ���",
		"��ʽ�u����Office-Excel\n����ҕ�l by ż���е�С�Ժ���ҕ�lid:BV1HZ4y1978a������ȡ���鿴ԭҕ�l��\nʹ�ù��ߣ�Dev-C++����ʽ�a�Z�ԣ�C++\n�Ŀ�_ʼ���ڣ�2024/04/21\n�汾��0.0.7.0\n���g�����ٶȷ��g"
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
};

extern "C"{
	DLLIMPORT BOOL CALLBACK EnumWindowProc(_In_ HWND hwnd, _In_ LPARAM Lparam);
	DLLIMPORT WINBOOL PutToDesktop(HWND Wallpaper);
	DLLIMPORT DWORD WINAPI DwpThread(LPVOID lparam);
	DLLIMPORT void StartDwp(const char PathA[],BOOL Quiet);
	DLLIMPORT BOOL CALLBACK StopDWPProc(_In_ HWND hWnd,_In_ LPARAM lparam);
	DLLIMPORT char* GetString4ThisLang(UINT index);
	DLLIMPORT bool SGetQuietMode(bool Set,bool beQuiet);
	DLLIMPORT int SGetLangId(bool Set,int LangId);
	DLLIMPORT char* SGetVidPath(bool Set,char Source[]);
}
#endif
