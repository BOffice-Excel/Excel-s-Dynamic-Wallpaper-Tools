#pragma once
#define DLLIMPORT __declspec(dllexport)
enum GETPERM{
	GP_FILEREAD=0,//�����ȡ�ļ� 
	GP_FILEWRITE,//����д���ļ� 
	GP_DLG,//�������Ի��� 
	GP_READREGISTRY,//�����ȡע��� 
	GP_WRITEREGISTRY,//����дע��� 
	GP_REGWNDCLS,//����ע�ᴰ���� 
	GP_CRTWND,//���������� 
	GP_CRTPROCS,//���������� 
	GP_ADMIN,//��������������ԱȨ�� 
	GP_CRTMENU,//�������˵� 
	GP_WRITEPROFILE,//����д�����ļ� 
	GP_READPROFILE,//�����ȡ�����ļ� 
	GP_GETFONT,//�������û�ѡ������ 
	GP_LOADRES,//���������Դ 
	GP_NOTEHIS,//������ʷ��¼ 
};
extern "C" DLLIMPORT void WINAPI HelpWindow(/*HINSTANCE,*/HWND);
extern "C" DLLIMPORT void WinWatcher();
extern "C" DLLIMPORT bool GetPerm(short Type);
