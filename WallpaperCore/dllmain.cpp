/* Replace "dll.h" with the name of your header */
#include "dll.h"
/*char MUIText[][3][3100]={//������֧�ֹ����ı���ȫ�������� 
	{"Create profile","�½������ļ�","�½��O���n"},//0
	{"Edit profile","�༭�����ļ�","��݋�O���n"},
	{"Apply profile","Ӧ�������ļ�","�����O���n"},
	{"Stop Wallpaper","ֹͣ��̬��ֽ","ֹͣ�ӑB����"},
	{"About Dynamic Wallpaper Tools","����Dynamic Wallpaper Tools","�P�Dynamic Wallpaper Tools"},
	{"Unable to open the video display program \"mshta.exe\" (playing videos using a browser), please check if the program exists in the system directory","�޷�����Ƶ��ʾ����\"mshta.exe\"��ʹ�������������Ƶ��������ϵͳĿ¼�³����Ƿ����","�o�����_ҕ�l�@ʾ��ʽ\"mshta.exe\"��ʹ�Þg�[������ҕ�l����Ո�z��ϵ�yĿ��³�ʽ�Ƿ����"},
	{"Warning! This operation will close all windows under the class name \"Progman\"!","���棡�˲�����ر�����������Ϊ��Progman�Ĵ����µ����д��ڣ�","���棡 �˲������P�]����������顰Progman��ҕ���µ�����ҕ��"},
	{"Video files (*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv)\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0All files (*.*) \0*.*\0","��Ƶ�ļ���*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv��\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0�����ļ���*.*��\0*.*\0","ҕ�l�n����*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv��\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0���Йn����*.*��\0*.*\0"},
	{"Dynamic Wallpaper Configuration Files (.dp)\0*.dp\0","Dynamic Wallpaper�����ļ���.dp��\0*.dp\0","Dynamic Wallpaper�O���n��.dp��\0*.dp\0"},
	{"Do you need to play sound?","�Ƿ���Ҫ����������","�Ƿ���Ҫ��������"},//9
	{
		"Programming: Office Excel\nReference video by ż���е�С�Ժ�, video id: BV1HZ4y1978a (press to cancel to view original video)\nTools used: Dev-C++, Code language: C++\nProject start date: April 21, 2024\nVersion: 0.0.7.3\nTranslator: Baidu Translate",
		"����������Office-Excel\n�ο���Ƶ by ż���е�С�Ժ�����Ƶid��BV1HZ4y1978a������ȡ���鿴ԭ��Ƶ��\nʹ�ù��ߣ�Dev-C++���������ԣ�C++\n��Ŀ��ʼ���ڣ�2024/04/21\n�汾��0.0.7.3\n���������ٶȷ���",
		"��ʽ�u����Office-Excel\n����ҕ�l by ż���е�С�Ժ���ҕ�lid:BV1HZ4y1978a������ȡ���鿴ԭҕ�l��\nʹ�ù��ߣ�Dev-C++����ʽ�a�Z�ԣ�C++\n�Ŀ�_ʼ���ڣ�2024/04/21\n�汾��0.0.7.3\n���g�����ٶȷ��g"
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
	{"Open 'About'","�򿪡�����","���_���P�"},//68
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
	{"Start dynamic wallpaper at startup.","����ʱ������̬��ֽ��","���ӕr���ӄӑB���档"},//82
	{"Advantages of DWPT:\r\n\
1. Lightweight\r\n\
In versions of Windows 7 and above, DWPT does not require any other miscellaneous libraries except for the WinAPI library and HelpDWPT.dll (DWPT Help Library), WallpaperCore.dll (Wallpaper Core Library), and the DWPT main program is less than 1Mib (excluding installation and uninstallation programs), which is smaller than the program compiled by writing a Hello World program using the iostream library, and does not rely on the Visual C++runtime library\r\n\
2. Concise interface\r\n\
The user interface of DWPT has no advertisements and will not slow down or slow down your computer. When not needed, you can also hide program icons in the system tray, which is very user-friendly\
\r\n3. Better support\r\n\
The video playback tool for DWPT is mshta.exe (Microsoft HTML application). Don't question why I use this (because I don't know how to write a player) instead of ffplay.exe. The reason is that ffplay.exe is indeed too large, over 100 MiB, larger than the main program, and I chose 32-bit compilation, so 32-bit Windows can also be used\r\n\
So, if you want to choose a lightweight, simple, ad free dynamic wallpaper software, choose DWPT\r\n\
","DWPT���ŵ㣺\n\r1.���\r\n\
    DWPT��Windows7���ϵİ汾�г���WinAPI�Ŀ��HelpDWPT.dll��DWPT�����⣩��WallpaperCore.dll����ֽ���Ŀ⣩������Ҫ���������Ӱ˵Ŀ⣬��DWPT�����򲻵�1Mib����������װ�����ж�س��򣩣�������iostream��дһ��Hello World��������ĳ���С�����Ҳ�����Visual C++���п�\r\n\
2.������\r\n\
    DWPT���û�����û���κεĹ�棬Ҳ��������ĵ��Ա����俨������Ҫʱ�����Խ�����ͼ�����ص�ϵͳ�����У�ʮ�����Ի�\r\n\
\r\n3.���õ�֧����\r\n\
    DWPT����Ƶ���Ź�����mshta.exe��Microsoft HTMLӦ�ó��򣩣���Ҫ����Ϊʲô��Ҫ���������Ϊ�Ҳ���д����������������ffplay.exe��ԭ����ffplay.exeȷʵ��̫���ˣ�100��MiB����������Ҫ�󣬲�����ѡ����32λ���룬����32λ��WindowsҲ����\r\n\
\r\n���ԣ������Ҫѡ��һ����㡢�򵥡��޹��Ķ�̬��ֽ�������ѡDWPT�ɣ� \
","DWPT�ă��c��\r\n\
1.�p��\r\n\
    DWPT��Windows7���ϵİ汾�г���WinAPI�Ď��HelpDWPT.dll��DWPT�����죩��WallpaperCore.dll������҇�Ď죩������Ҫ�����s���s�˵Ď죬��DWPT�����򲻵�1Mib�����������b��ʽ��ж�d��ʽ����������iostream�쌑һ��Hello World���g����ĳ�ʽ߀С���K�Ҳ���هVisual C++��\r\n\
2.���溆��\r\n\
    DWPT��ʹ���߽���]���κεďV�棬Ҳ����׌�����X׃��׃��������Ҫ�r߀���Ԍ���ʽ�D���[�ص�ϵ�yӚ�P�У�ʮ�����Ի�\r\n\
\r\n\
3.���õ�֧����\r\n\
    DWPT��ҕ�l���Ź�����mshta.exe��Microsoft HTML���ó��򣩣���Ҫ�|�ɞ�ʲ�N��Ҫ���@��������Ҳ��������řC����������ffplay.exe��ԭ����ffplay.exe�_����̫���ˣ�100��MiB����������߀Ҫ�󣬁K�����x����32���ؾ��g������32���ص�WindowsҲ����\r\n\
\r\n\
���ԣ������Ҫ�x��һ���p�㡢���Ρ��o�V��ĄӑB����ܛ�������xDWPT�ɣ�\r\n\
"},//83
	{"The opening method of DWPT is very simple. The first step is to open the program without allowing administrator privileges. This program has removed the need for administrator identity since 0.0.7.2 and later\r\n\
First - How to start dynamic wallpaper:\r\n\
1. Click on the 'Create Profile' button\r\n\
2. Choose a save location (remember to enter the name of the saved file)\r\n\
3. Choose one of your videos and remember to click on it to make it selected\r\n\
4. When asked if you need sound, you can click \"Yes\" or \"No\" to disable or enable the sound\r\n\
5. At this point, the configuration file has been created. You can click \"Yes\" to immediately use this configuration file, or click \"No\" to put this file aside for now\r\n\
Second - If I created a configuration file last time, how to use the previous configuration:\r\n\
1. Click on the 'Open Profile' button\r\n\
2. Select the configuration file you created last time\r\n\
3. When the pop-up asks if you want to continue, please make sure if there are any other mshta.exe processes that are not related to DWPT running. If not, click \"Yes\". If there are, go check if they are important. If they are not important, close them. If they are important, don't open them yet\r\n\
Third -  What should I do if I want to modify the content of the configuration file:\r\n\
1. Click on the 'Modify Configuration File' button\r\n\
2. Select your configuration file\r\n\
3. When you enter the editing page, you can start modifying. You can click \"Yes\" or \"No\" to modify, or \"Cancel\" to stop modifying\r\n\
4. Continue with the third step until the modifications are completed\r\n\
5. Choose whether to save\r\n\
6. Done! \r\n\r\n\
Fourth - I don't want to use it anymore. What should I do if I stop using it\r\n\
1. Confirm that there is no mshta.exe running on your computer that is unrelated to DWPT.\r\n\
2. Click on \"Stop Dynamic Wallpaper\"\r\n\
3. Click confirm and select 'Yes' in the pop-up box to stop the dynamic wallpaper\r\n\
Fifth - How to set \\ modify the position of default items:\r\n\
1. Click on \"Global Settings\"\r\n\
2. Click on \"Edit\", select the configuration file you want to set as the default option, and click OK\r\n\
Sixth -  What should I do if I want to boot up a dynamic wallpaper: \r\n\
1. Please ensure that you have set the default settings. If not, please refer to \"Five\"\r\n\
2. Click on \"Global Settings\"\r\n\
3. Select the \"Power on Self Start\" checkbox to check\r\n\
",
	"DWPT�Ĵ򿪷����ܼ򵥣���һ�����򿪳��򣬲���Ҫ�������ԱȨ�ޣ���������0.0.7.2���Ժ���Ƴ��˹���Ա��ݵ���Ҫ\r\n\
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
","DWPT�Ĵ��_�����ܺ��Σ���һ�������_��ʽ������Ҫ���S����T�S�ə࣬����ʽ��0.0.7.2��������Ƴ��˹���T��ݵ���Ҫ\r\n\
һ. ��Ά��ӄӑB���棺\r\n\
1.�c���������O���n���o\r\n\
2.�x��һ������λ�ã�ӛ��ݔ�뱣��ęn�����Q��\r\n\
3.�x�����һ��ҕ�l��ӛ���c���ǂ�ҕ�lһ��׌��̎춱��x�Р�B\r\n\
4.ԃ�����Ƿ���Ҫ����������c�����ǻ��ߡ������û�����\r\n\
5.���@�e���O���n�̈́�������ˣ�������ڽ�����c�����ǁ�����ʹ���@���O���n�������c��������@���n�ȷ���\r\n\r\n\
��. ���ϴ΄������O���n�ˣ����ʹ���ϴε��䌅��\r\n\
1.�c�������_�O���n���o\r\n\
2.�x�����ϴ΄������O���n\r\n\
3.�ڏ����Ć����Ƿ��^�m���@���r��Ո�_�����Ƿ��������ĺ�DWPT�o�P��mshta.exe�г�����ʹ�ã�����]�о��c���ǣ��е�Ԓ��ȥ�����ز���Ҫ������Ҫ�ľ��P�ˣ��������Ҫ�ľ��Ȅe�_\r\n\r\n\
��. �����޸��O���n�ă������N�k��\r\n\
1.�c���޸��O���n���o\r\n\
2.�x������O���n\r\n\
3.�M�뵽��݋��棬�@���r����Ϳ����_ʼ�޸��ˣ������c�����ǻ򡰷���޸ģ���ȡ���t��ֹͣ�޸�\r\n\
4.�^�m������ֱ���޸����\r\n\
5.�x���Ƿ񱣴�\r\n\
6.��ɣ� \r\n\r\n\
��. �Ҳ�������Ҫͣ�����N�k��\r\n\
1.�_�J�����X�ϛ]���cDWPT����ɵ�mshta.exe����ʹ��\r\n\
2.�c��ֹͣ�ӑB����\r\n\
3.�c���_�J�K�ڏ����Ŀ���x�ǣ�����ֹͣ�ӑB����\r\n\r\n\
��. ����O��\\�޸�Ĭ�J헵�λ�ã�\r\n\
1.�c��ȫ���O��\r\n\
2.�c����݋���x����Ҫ�O����Ĭ�J헵��O���n���c���_������\r\n\r\n\
��. ����Ҫ�_�C�Ԇ��ӄӑB�������N�k��\r\n\
1.Ո�_�����ѽ��O����Ĭ�J헣�����]��Ո����\r\n\
2.�c��ȫ���O��\r\n\
3.�x���_�C�Ԇ��әz��򼴿�\r\n\
"},//84
	{"Question&Answer:\n\r\
Q: Why don't you use CLR to create windows? \r\n\
Answer: Because we need to take care of some special groups of people who cannot install the Visual C++runtime library, such as She_Fa21 (my friend). If we don't install VC, it will prompt that the DLL is missing, and gcc compiles smaller\r\n\
Q: Why are the windows and controls you create in Win11 style and DPI not an issue while I am not? \r\n\
Answer: I have also thought about this question. I collected a lot of information online and practiced for a long time before figuring out this method. For your question, I have the following solutions:\r\n\
For the issue of controls being outdated:\r\n\
	Visual Studio: Please add the following code before:\r\n\
            #ifdef _UNICODE\r\n\
            #if defined _M_IX86\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #elif defined _M_X64\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #else\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #endif\r\n\
            #endif\r\n\
	Dev-C++: Compared to Visual Studio, the operation of Dev is simpler. Simply check \"Supports Windows XP themes\" in the project [P] ->project properties [O]\
	For the issue of incorrect DPI display:\r\n\
		Microsoft related documents: https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setprocessdpiaware/\r\n\
		Visual Studio: Add code directly at the beginning of the program: Set ProcessDPIAware();\r\n\
		Dev-C++: Please add the following code at the beginning of the program:\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID);\r\n\
            SPDA SetProcessDPIAware;\r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\");\r\n\
            if(hModule){//Exception handling\r\n\
                SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");// Tip: The SetProcessDPIAware function was added to Windows Vista\r\n\
                if(SetProcessDPIAware) SetProcessDPIAware();//Non abnormal state\r\n\
			}\r\n\
            //The GCC version used by Dev-C++ is 4.9.2, and this API has been added to the new version of GCC\r\n\
	That's it! \r\n\
Q: What should I do if there is a failure to create a window or register a window class?\r\n\
Answer: Please try downloading this program again. If it still doesn't work, then I have no choice\r\n\
Q: Why is the font so ugly? \r\n\
Answer: The font I use when writing code is user-defined, which may not look good because some fonts do not support Chinese. I use CreateFontA to load fonts, so you can take a look at the CreateFontA function in Microsoft's development documentation",
	"���� & �ش�\n\r\
�ʣ�Ϊʲô�㲻��CLR�������ڣ�\r\n\
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
        ΢������ĵ���https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setprocessdpiaware/\r\n\
        Visual Studio:ֱ���ڳ�����ʼ�ĵط����ϴ��룺SetProcessDPIAware();\r\n\
        Dev-C++:���ڳ�����ʼ�ĵط��������´��룺\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID);\r\n\
            SPDA SetProcessDPIAware;\r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\");\r\n\
            if(hModule){//�쳣����\
                SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");//��ʾ��SetProcessDPIAware������Windows Vista�����\r\n\
                if(SetProcessDPIAware) SetProcessDPIAware();//���쳣״̬\r\n\
			}\r\n\
            //Dev-C++ʹ�õ�GCC�汾��4.9.2���°��GCC�Ѿ���������API\r\n\
    �����ͽ������\r\n\
�ʣ�������ִ�������ʧ�ܡ�������ע��ʧ��֮��ĸ���ô�죿\r\n\
���볢���������ر�����������ǲ��У����Ҿ�û�취��\r\n\
�ʣ�Ϊʲô������ô��\r\n\
����д����ʱʹ�õ�����Ϊ�û���������壬�ѿ���������ΪĳЩ���岢��֧�����ģ�������CreateFontA����������ģ����Կ���ȥ����΢�����ĵ������CreateFontA����",
	"���}&�ش�\n\r\
������ʲ�N�㲻��CLR����ҕ���� \r\n\
�����Ҫ���һЩ�b����Visual C++���������Ⱥ������She_Fa21�������ѣ���������bVC����ʾ��dll���K��gcc���g�ĸ�С\r\n\r\n\
�����ㄓ�������ҕ���Ϳ���헞�ʲ�N����Win11��ʽ����DPI�����І��}���Ҳ��У� \r\n\
���@�����}��Ҳ���^���ҏľW�ϴ����L���Y���Ҍ��`�˺ܾò���ĥ���@�N������������Ć��}���������½�Q������\r\n\
    ��춿�������f��Ć��}��\r\n\
        Visual Studio:Ո��ǰ��������³�ʽ�a��\r\n\
            #ifdef _UNICODE\r\n\
            #if defined _M_IX86\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #elif defined _M_X64\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #else\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #endif\r\n\
            #endif\r\n\
        Dev-C++�������Visual Studio���f��Dev�Ĳ��������Σ����Ŀ[P]->�Ŀ����[O]�e�湴�x��֧��Windows XP���}����\r\n\
    ���DPI�@ʾ�����_�Ć��}��\r\n\
        ΢ܛ���P�ęn�� https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setprocessdpiaware/ \r\n\
        Visual Studio:ֱ���ڳ�ʽ��ʼ�ĵط����ϳ�ʽ�a��SetProcessDPIAware������ \r\n\
        Dev-C++��Ո�ڳ�ʽ��ʼ�ĵط��������³�ʽ�a��\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID); \r\n\
            SPDA SetProcessDPIAware; \r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\"); \r\n\
            if��hModule��{//����̎��\r\n\
                SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");// ��ʾ��SetProcessDPIAware������Windows Vista�����\r\n\
                if(SetProcessDPIAware) SetProcessDPIAware();// ���쳣��B\r\n\
            }\r\n\
            //Dev-C++ʹ�õ�GCC�汾��4.9.2���°��GCC�ѽ�������@��API\r\n\
        �@�Ӿͽ������ \r\n\
����������F����ҕ��ʧ����ҕ���ע��ʧ��֮�ԓ���N�k�� \r\n\
��Ո�Lԇ�������d����ʽ�����߀�ǲ��У����Ҿ͛]�k����\r\n\
������ʲ�N���w���N�h�� \r\n\
���Ҍ���ʽ�a�rʹ�õ����w���Ñ����x�����w���y�����������ĳЩ���w�K��֧Ԯ���ģ�������CreateFontA����d���w�ģ����Կ���ȥ����΢ܛ�_�l�n���e���CreateFontA����"},//85
	{"About DWPT:\r\n\
Author: Office-Excel\r\n\
Reference video (Bilibili video number): BV1HZ4y1978a, address: https://www.bilibili.com/video/BV1HZ4y1978a/\r\n\
Code editing tool used: Dev-C++Code language used: C++. Most commonly used libraries: windows.h\r\n\
Window creation: Windows API (not a dialog box in the resource file, as I don't know how to use it)\r\n\
DWPT project properties:\r\n\
    Name: DWPT (Dynamic Wallpaper Tools)\
    Project start date: 2024/04/21\r\n\
    Project objective: To create a pure and simple dynamic wallpaper tool\r\n\
    Why did the author do this stupid thing: just for fun, he wrote a few hundred lines of code casually\r\n\
    Dp file structure:\r\n\
        If you open the dp file with Notepad\r\n\
            You will find that the first character is always 't' or 'f', which represents whether the sound is enabled or not. f=disabled, t=enabled\r\n\
            The following is the absolute path of the video, and the text should theoretically be stored using GBK encoding, so it supports Chinese\r\n\
\r\n\
    The principle of starting dynamic wallpaper in DWPT:\r\n\
        1. Read in file\r\n\
        2. Check if sound is enabled\r\n\
        3. Store the absolute path of the video in VP (char array)\r\n\
        4. Splice the preset text and write it to the %temp%\\Temporary.hta file\r\n\
        5. Start the process mshta.exe\r\n\
        6. Send 0x52C signal to window with class name Progman\r\n\
        7. Find the second WorkerW window and hide it\r\n\
        8. Set the window with the class name Progman as the parent window of the mshta.exe window\r\n\
        9. Done! \r\n\r\n\
Author's Bilibili account: Office-Excel (Address: https://space.bilibili.com/1439352366/)\r\n\
",
	"����DWPT��\r\n\
���ߣ�Office-Excel\r\n\
�ο���Ƶ������������Ƶ��ţ���BV1HZ4y1978a����ַ��https://www.bilibili.com/video/BV1HZ4y1978a/\r\n\
ʹ�õĴ���༭���ߣ�Dev-C++ ʹ�õĴ������ԣ�C++ �õ����Ŀ⣺windows.h\r\n\
���ڴ�����Windows API��������Դ�ļ���ĶԻ�����Ϊ�Ҳ����ã�\r\n\
DWPT��Ŀ���ԣ�\r\n\
    ���ƣ�DWPT��ȫ��Dynamic Wallpaper Tools�����룺��̬��ֽ���ߣ�\r\n\
    ��Ŀ��ʼ���ڣ�2024/04/21\r\n\
    ��ĿĿ�꣺��һ�������򵥵Ķ�̬��ֽ����\r\n\
    ����ΪʲôҪ����������⣺ֻ��Ϊ�˺������д�˼��ٶ��еĴ���\r\n\
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
",
	"�P�DWPT:\n\r\
���ߣ�Office-Excel\r\n\
����ҕ�l����������ҕ�l��̖����BV1HZ4y1978a����ַ�� https://www.bilibili.com/video/BV1HZ4y1978a/ \r\n\
ʹ�õĳ�ʽ�a��݋���ߣ�Dev-C++ʹ�õĳ�ʽ�a�Z�ԣ�C++�õ����Ď죺windows.h\r\n\
ҕ��������Windows API�������YԴ�n�Y�Č�Ԓ���K������Ҳ����ã�\r\n\
DWPT�Ŀ���ݣ�\r\n\
    ���Q��DWPT��ȫ�QDynamic Wallpaper Tools�����g���ӑB���湤�ߣ�\r\n\
    �Ŀ�_ʼ���ڣ�2024/04/21\r\n\
    �ĿĿ�ˣ���һ�����Q���εĄӑB���湤��\r\n\
    ���ߞ�ʲ�NҪ���@�������⣺ֻ�Ǟ��˺����S�㌑�ˎװٶ��еĳ�ʽ�a\r\n\
    dp�n���Y����\r\n\
    �������ӛ�±����_dp�n��\r\n\
    ����l�F��һ����Ԫ����'t'����'f'���@�������Ƿ�������f=�����ã�t=����\r\n\
    ����Ąt��ҕ�l�Ľ^��·�������ְ����f��ԓ��ʹ��GBK���a�惦�ģ�����֧Ԯ����\r\n\
\r\n\
    DWPT���ӄӑB�����ԭ��\r\n\
        1.�x��n��\r\n\
        2.�鿴�Ƿ�����\r\n\
        3.��ҕ�l�^��·������VP��char���M��\r\n\
        4.ƴ���A�O�����ցK����%temp%\\Temporary.hta�n��\r\n\
        5.�����г�mshta.exe\r\n\
        6.�������Progman��ҕ���l��0x52CӍ̖\r\n\
        7.�ҵ��ڶ���WorkerWҕ���K�[����\r\n\
        8.�������Progman��ҕ���O����mshta.exeҕ���ĸ�ҕ��\r\n\
        9.��ɣ� \r\n\r\n\
���ߵĆ���������̖��Office-Excel����ַ�� https://space.bilibili.com/1439352366/ ��\r\n\
"},//86
};*/
LPSTR MUIText[120][3];

char Path[114514],res[114514];
int LangID=IL_UNSET/*����ID*/;
bool quietMode=false;//�Ƿ����ð���ģʽ��������dp�ļ��У� 
struct Version{
	int Main;
	int Sub;
	int Release;
	int Make; 
};
typedef Version *LPVERSION; 
extern "C"{
	DLLIMPORT void InitStringSystem(){MUIText[0][0]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[0][0],"Create profile");
MUIText[0][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[0][1],"�½������ļ�");
MUIText[0][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[0][2],"�½��O���n");
MUIText[1][0]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[1][0],"Edit profile");
MUIText[1][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[1][1],"�༭�����ļ�");
MUIText[1][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[1][2],"��݋�O���n");
MUIText[2][0]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[2][0],"Apply profile");
MUIText[2][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[2][1],"Ӧ�������ļ�");
MUIText[2][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[2][2],"�����O���n");
MUIText[3][0]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[3][0],"Stop Wallpaper");
MUIText[3][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[3][1],"ֹͣ��̬��ֽ");
MUIText[3][2]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[3][2],"ֹͣ�ӑB����");
MUIText[4][0]=(char*)calloc(129,sizeof(char));
strcpy(MUIText[4][0],"About Dynamic Wallpaper Tools");
MUIText[4][1]=(char*)calloc(127,sizeof(char));
strcpy(MUIText[4][1],"����Dynamic Wallpaper Tools");
MUIText[4][2]=(char*)calloc(127,sizeof(char));
strcpy(MUIText[4][2],"�P�Dynamic Wallpaper Tools");
MUIText[5][0]=(char*)calloc(245,sizeof(char));
strcpy(MUIText[5][0],"Unable to open the video display program \"mshta.exe\" (playing videos using a browser), please check if the program exists in the system directory");
MUIText[5][1]=(char*)calloc(183,sizeof(char));
strcpy(MUIText[5][1],"�޷�����Ƶ��ʾ����\"mshta.exe\"��ʹ�������������Ƶ��������ϵͳĿ¼�³����Ƿ����");
MUIText[5][2]=(char*)calloc(183,sizeof(char));
strcpy(MUIText[5][2],"�o�����_ҕ�l�@ʾ��ʽ\"mshta.exe\"��ʹ�Þg�[������ҕ�l����Ո�z��ϵ�yĿ��³�ʽ�Ƿ����");
MUIText[6][0]=(char*)calloc(178,sizeof(char));
strcpy(MUIText[6][0],"Warning! This operation will close all windows under the class name \"Progman\"!");
MUIText[6][1]=(char*)calloc(159,sizeof(char));
strcpy(MUIText[6][1],"���棡�˲�����ر�����������Ϊ��Progman���Ĵ����µ����д��ڣ�");
MUIText[6][2]=(char*)calloc(158,sizeof(char));
strcpy(MUIText[6][2],"���棡 �˲������P�]����������顰Progman����ҕ���µ�����ҕ��");
MUIText[7][0]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[7][0],"Video files (*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv)\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0All files (*.*) \0*.*\0\0",sizeof("Video files (*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv)\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0All files (*.*) \0*.*\0\0"));
MUIText[7][1]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[7][1],"��Ƶ�ļ���*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv��\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0�����ļ���*.*��\0*.*\0\0",sizeof("��Ƶ�ļ���*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv��\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0�����ļ���*.*��\0*.*\0\0"));
MUIText[7][2]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[7][2],"ҕ�l�n����*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv��\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0���Йn����*.*��\0*.*\0\0",sizeof("ҕ�l�n����*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv��\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0���Йn����*.*��\0*.*\0\0"));
MUIText[8][0]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[8][0],"Dynamic Wallpaper Configuration Files (.dp)\0*.dp\0\0",sizeof("Dynamic Wallpaper Configuration Files (.dp)\0*.dp\0\0"));
MUIText[8][1]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[8][1],"Dynamic Wallpaper�����ļ���.dp��\0*.dp\0\0",sizeof("Dynamic Wallpaper�����ļ���.dp��\0*.dp\0\0"));
MUIText[8][2]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[8][2],"Dynamic Wallpaper�O���n��.dp��\0*.dp\0\0",sizeof("Dynamic Wallpaper�O���n��.dp��\0*.dp\0\0"));
MUIText[9][0]=(char*)calloc(126,sizeof(char));
strcpy(MUIText[9][0],"Do you need to play sound?");
MUIText[9][1]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[9][1],"�Ƿ���Ҫ����������");
MUIText[9][2]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[9][2],"�Ƿ���Ҫ��������");
MUIText[10][0]=(char*)calloc(344,sizeof(char));
strcpy(MUIText[10][0],"Programming: Office-Excel\r\nReference video by ż���е�С�Ժ�, video id: BV1HZ4y1978a (press to cancel to view original video)\r\nTools used: Dev-C++, Code language: C++\r\nProject start date: April 21, 2024\r\nVersion: 0.0.9.1\nTranslator: Baidu Translate");
MUIText[10][1]=(char*)calloc(282,sizeof(char));
strcpy(MUIText[10][1],"����������Office-Excel\r\n�ο���Ƶ by ż���е�С�Ժ�����Ƶid��BV1HZ4y1978a������ȡ���鿴ԭ��Ƶ��\r\nʹ�ù��ߣ�Dev-C++���������ԣ�C++\r\n��Ŀ��ʼ���ڣ�2024/04/21\r\n�汾��0.0.9.1\r\n���������ٶȷ���");
MUIText[10][2]=(char*)calloc(283,sizeof(char));
strcpy(MUIText[10][2],"��ʽ�u����Office-Excel\r\n����ҕ�l by ż���е�С�Ժ���ҕ�lid:BV1HZ4y1978a������ȡ���鿴ԭҕ�l��\r\nʹ�ù��ߣ�Dev-C++����ʽ�a�Z�ԣ�C++\r\n�Ŀ�_ʼ���ڣ�2024/04/21\r\n�汾��0.0.9.1\r\n���g�����ٶȷ��g");
MUIText[11][0]=(char*)calloc(174,sizeof(char));
strcpy(MUIText[11][0],"The configuration file operation is complete. Do you want to start it now?");
MUIText[11][1]=(char*)calloc(134,sizeof(char));
strcpy(MUIText[11][1],"�����ļ�������ɣ��Ƿ�Ҫ����������");
MUIText[11][2]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[11][2],"�O���n������ɣ��Ƿ�Ҫ�R�φ��ӣ�");
MUIText[12][0]=(char*)calloc(231,sizeof(char));
strcpy(MUIText[12][0],"Please select the object you want to modify:Yes -> Modify video file pathNo -> Modify whether there is soundCancel -> Do nothing");
MUIText[12][1]=(char*)calloc(180,sizeof(char));
strcpy(MUIText[12][1],"��ѡ��Ҫ�޸ĵĶ��� ��->�޸���Ƶ�ļ�·�� ��->�޸��Ƿ������� ȡ��->ʲôҲ����");
MUIText[12][2]=(char*)calloc(177,sizeof(char));
strcpy(MUIText[12][2],"Ո�x��Ҫ�޸ĵČ�����->�޸�ҕ�l�n��·����->�޸��Ƿ�����ȡ��->ʲ�NҲ����");
MUIText[13][0]=(char*)calloc(117,sizeof(char));
strcpy(MUIText[13][0],"Wallplaper Config");
MUIText[13][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[13][1],"��ֽ����");
MUIText[13][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[13][2],"�����䌅");
MUIText[14][0]=(char*)calloc(115,sizeof(char));
strcpy(MUIText[14][0],"Global settings");
MUIText[14][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[14][1],"ȫ������");
MUIText[14][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[14][2],"ȫ���O��");
MUIText[15][0]=(char*)calloc(123,sizeof(char));
strcpy(MUIText[15][0],"Self start upon startup");
MUIText[15][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[15][1],"����������");
MUIText[15][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[15][2],"�_�C�Ԇ���");
MUIText[16][0]=(char*)calloc(121,sizeof(char));
strcpy(MUIText[16][0],"Current default item:");
MUIText[16][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[16][1],"��ǰĬ���");
MUIText[16][2]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[16][2],"��ǰĬ�J헣�");
MUIText[17][0]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[17][0],"Edit");
MUIText[17][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[17][1],"�༭");
MUIText[17][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[17][2],"��݋");
MUIText[18][0]=(char*)calloc(129,sizeof(char));
strcpy(MUIText[18][0],"Registry modification failed!");
MUIText[18][1]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[18][1],"ע����޸�ʧ�ܣ�");
MUIText[18][2]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[18][2],"�]�Ա��޸�ʧ����");
MUIText[19][0]=(char*)calloc(290,sizeof(char));
strcpy(MUIText[19][0],"Do you want to restart explorer.exe? This may result in a black screen for a while. If Win11 users set a right angle, it will turn back into a rounded corner. Please make a careful decision!");
MUIText[19][1]=(char*)calloc(193,sizeof(char));
strcpy(MUIText[19][1],"�Ƿ���Ҫ����explorer.exe������ܻ����һ�����Win11�û����������ֱ�ǻ���Բ�ǣ������ؾ�����");
MUIText[19][2]=(char*)calloc(194,sizeof(char));
strcpy(MUIText[19][2],"�Ƿ���Ҫ�؆�explorer.exe�� �@���ܕ�����һ������Win11�Ñ�����O����ֱ�Ǖ�׃�؈A�ǣ�Ո���ؾ�����");
MUIText[20][0]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[20][0],"Quit(&Q)");
MUIText[20][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[20][1],"�˳���&Q��");
MUIText[20][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[20][2],"�˳���&Q��");
MUIText[21][0]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[21][0],"Registry modification completed!");
MUIText[21][1]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[21][1],"ע����޸���ɣ�");
MUIText[21][2]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[21][2],"�]�Ա��޸���ɣ�");
MUIText[22][0]=(char*)calloc(187,sizeof(char));
strcpy(MUIText[22][0],"Do you need to set this configuration item as the default (including startup default)��");
MUIText[22][1]=(char*)calloc(152,sizeof(char));
strcpy(MUIText[22][1],"�Ƿ���Ҫ���������������ΪĬ�����������Ĭ�����");
MUIText[22][2]=(char*)calloc(152,sizeof(char));
strcpy(MUIText[22][2],"�Ƿ���Ҫ���@���䌅��O����Ĭ�J헣���������Ĭ�J헣���");
MUIText[23][0]=(char*)calloc(178,sizeof(char));
strcpy(MUIText[23][0],"explorer.exe has been restarted and completed, you can continue your work now!");
MUIText[23][1]=(char*)calloc(146,sizeof(char));
strcpy(MUIText[23][1],"explorer.exe��������ɣ������Լ������Ĺ����ˣ�");
MUIText[23][2]=(char*)calloc(146,sizeof(char));
strcpy(MUIText[23][2],"explorer.exe���؆���ɣ��������^�m���Ĺ����ˣ�");
MUIText[24][0]=(char*)calloc(105,sizeof(char));
strcpy(MUIText[24][0],"Apply");
MUIText[24][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[24][1],"Ӧ��");
MUIText[24][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[24][2],"����");
MUIText[25][0]=(char*)calloc(128,sizeof(char));
strcpy(MUIText[25][0],"Set as default configuration");
MUIText[25][1]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[25][1],"����ΪĬ������");
MUIText[25][2]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[25][2],"�O����Ĭ�J�䌅");
MUIText[26][0]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[26][0],"Help(&H)");
MUIText[26][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[26][1],"������&H��");
MUIText[26][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[26][2],"������&H��");
MUIText[27][0]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[27][0],"Operation(&O)");
MUIText[27][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[27][1],"������&O��");
MUIText[27][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[27][2],"������&O��");
MUIText[28][0]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[28][0],"About(&A)");
MUIText[28][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[28][1],"���ڣ�&A��");
MUIText[28][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[28][2],"�P춣�&A��");
MUIText[29][0]=(char*)calloc(125,sizeof(char));
strcpy(MUIText[29][0],"End dynamic wallpaper(&E)");
MUIText[29][1]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[29][1],"������̬��ֽ��&E��");
MUIText[29][2]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[29][2],"�Y���ӑB���棨&E��");
MUIText[30][0]=(char*)calloc(115,sizeof(char));
strcpy(MUIText[30][0],"Open and...(&C)");
MUIText[30][1]=(char*)calloc(115,sizeof(char));
strcpy(MUIText[30][1],"�򿪲�...��&C��");
MUIText[30][2]=(char*)calloc(115,sizeof(char));
strcpy(MUIText[30][2],"���_�K...��&C��");
MUIText[31][0]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[31][0],"Open the default item and...(&D)");
MUIText[31][1]=(char*)calloc(121,sizeof(char));
strcpy(MUIText[31][1],"��Ĭ���...��&D��");
MUIText[31][2]=(char*)calloc(121,sizeof(char));
strcpy(MUIText[31][2],"���_Ĭ�J헁K...��&D��");
MUIText[32][0]=(char*)calloc(164,sizeof(char));
strcpy(MUIText[32][0],"The program has already started, please do not execute it again!");
MUIText[32][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[32][1],"�����Ѿ������ˣ��벻Ҫ�ٴ�ִ�У�");
MUIText[32][2]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[32][2],"��ʽ�ѽ������ˣ�Ո��Ҫ�ٴΈ��У�");
MUIText[33][0]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[33][0],"The original value was: ");
MUIText[33][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[33][1],"ԭ����ֵΪ��");
MUIText[33][2]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[33][2],"ԭ���ֵ�飺");
MUIText[34][0]=(char*)calloc(126,sizeof(char));
strcpy(MUIText[34][0],"Do you want to modify it?");
MUIText[34][1]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[34][1],"�Ƿ�Ҫ�޸ģ�");
MUIText[34][2]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[34][2],"�Ƿ�Ҫ�޸ģ�");
MUIText[35][0]=(char*)calloc(115,sizeof(char));
strcpy(MUIText[35][0],"Please select: ");
MUIText[35][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[35][1],"��ѡ��");
MUIText[35][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[35][2],"Ո�x��");
MUIText[36][0]=(char*)calloc(133,sizeof(char));
strcpy(MUIText[36][0],"The video path has been modified!");
MUIText[36][1]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[36][1],"��Ƶ·�����޸���ɣ�");
MUIText[36][2]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[36][2],"ҕ�l·�����޸���ɣ�");
MUIText[37][0]=(char*)calloc(155,sizeof(char));
strcpy(MUIText[37][0],"The modification of the video path has been canceled...");
MUIText[37][1]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[37][1],"��ȡ���޸���Ƶ·��������");
MUIText[37][2]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[37][2],"��ȡ���޸�ҕ�l·��������");
MUIText[38][0]=(char*)calloc(170,sizeof(char));
strcpy(MUIText[38][0],"The original value for playing sound when using dynamic wallpapers is:");
MUIText[38][1]=(char*)calloc(140,sizeof(char));
strcpy(MUIText[38][1],"ԭ���Ƿ���ʹ�ö�̬��ֽʱ����������ֵΪ��");
MUIText[38][2]=(char*)calloc(140,sizeof(char));
strcpy(MUIText[38][2],"ԭ���Ƿ���ʹ�ÄӑB����r��������ֵ�飺");
MUIText[39][0]=(char*)calloc(103,sizeof(char));
strcpy(MUIText[39][0],"Yes");
MUIText[39][1]=(char*)calloc(102,sizeof(char));
strcpy(MUIText[39][1],"��");
MUIText[39][2]=(char*)calloc(102,sizeof(char));
strcpy(MUIText[39][2],"��");
MUIText[40][0]=(char*)calloc(102,sizeof(char));
strcpy(MUIText[40][0],"No");
MUIText[40][1]=(char*)calloc(102,sizeof(char));
strcpy(MUIText[40][1],"��");
MUIText[40][2]=(char*)calloc(102,sizeof(char));
strcpy(MUIText[40][2],"��");
MUIText[41][0]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[41][0],"Please select: ");
MUIText[41][1]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[41][1],"��ѡ��");
MUIText[41][2]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[41][2],"Ո�x��");
MUIText[42][0]=(char*)calloc(138,sizeof(char));
strcpy(MUIText[42][0],"Do you want to save this modification?");
MUIText[42][1]=(char*)calloc(122,sizeof(char));
strcpy(MUIText[42][1],"�Ƿ�Ҫ������ε��޸ģ�");
MUIText[42][2]=(char*)calloc(122,sizeof(char));
strcpy(MUIText[42][2],"�Ƿ�Ҫ�����@�ε��޸ģ�");
MUIText[43][0]=(char*)calloc(128,sizeof(char));
strcpy(MUIText[43][0],"Do you want to apply it now?");
MUIText[43][1]=(char*)calloc(117,sizeof(char));
strcpy(MUIText[43][1],"�Ƿ�Ҫ����Ӧ�ã� ");
MUIText[43][2]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[43][2],"�Ƿ�Ҫ�������ã�");
MUIText[44][0]=(char*)calloc(121,sizeof(char));
strcpy(MUIText[44][0],"Shrink to system tray");
MUIText[44][1]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[44][1],"��С��ϵͳ����");
MUIText[44][2]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[44][2],"�sС��ϵ�yӚ�P");
MUIText[45][0]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[45][0],"How to use it?");
MUIText[45][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[45][1],"���ʹ�ã�");
MUIText[45][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[45][2],"���ʹ�ã�");
MUIText[46][0]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[46][0],"Advanced Options");
MUIText[46][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[46][1],"�߼�ѡ��");
MUIText[46][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[46][2],"�߼��x�");
MUIText[47][0]=(char*)calloc(103,sizeof(char));
strcpy(MUIText[47][0],"Set");
MUIText[47][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[47][1],"����");
MUIText[47][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[47][2],"�O��");
MUIText[48][0]=(char*)calloc(136,sizeof(char));
strcpy(MUIText[48][0],"Set any window as wallpaper (Unsafe)");
MUIText[48][1]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[48][1],"�����ⴰ������Ϊ��ֽ������ȫ��");
MUIText[48][2]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[48][2],"������ҕ���O�������棨����ȫ��");
MUIText[49][0]=(char*)calloc(117,sizeof(char));
strcpy(MUIText[49][0],"Title of Window: ");
MUIText[49][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[49][1],"���ڱ��⣺");
MUIText[49][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[49][2],"ҕ�����}��");
MUIText[50][0]=(char*)calloc(122,sizeof(char));
strcpy(MUIText[50][0],"Class Name of Window: ");
MUIText[50][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[50][1],"����������");
MUIText[50][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[50][2],"ҕ�������");
MUIText[51][0]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[51][0],"Boss key:");
MUIText[51][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[51][1],"�ϰ����");
MUIText[51][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[51][2],"����I��");
MUIText[52][0]=(char*)calloc(107,sizeof(char));
strcpy(MUIText[52][0],"Histroy");
MUIText[52][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[52][1],"��ʷ");
MUIText[52][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[52][2],"�vʷ");
MUIText[53][0]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[53][0],"Tools (&T)");
MUIText[53][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[53][1],"���ߣ�&T��");
MUIText[53][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[53][2],"���ߣ�&T��");
MUIText[54][0]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[54][0],"Open the WinWatcher tool");
MUIText[54][1]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[54][1],"��WinWatcher����");
MUIText[54][2]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[54][2],"���_WinWatcher����");
MUIText[55][0]=(char*)calloc(188,sizeof(char));
strcpy(MUIText[55][0],"The path is invalid \\ The file does not exist, unable to start the dp configuration file");
MUIText[55][1]=(char*)calloc(141,sizeof(char));
strcpy(MUIText[55][1],"·�����Ϸ�\\�ļ������ڣ��޷�����dp�����ļ�");
MUIText[55][2]=(char*)calloc(139,sizeof(char));
strcpy(MUIText[55][2],"·�����Ϸ�\\�n�������ڣ��o������dp�O���n");
MUIText[56][0]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[56][0],"Generate GUID");
MUIText[56][1]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[56][1],"���� GUID");
MUIText[56][2]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[56][2],"���� GUID");
MUIText[57][0]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[57][0],"Generate UUID");
MUIText[57][1]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[57][1],"���� UUID");
MUIText[57][2]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[57][2],"���� UUID");
MUIText[58][0]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[58][0],"Fast Boot");
MUIText[58][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[58][1],"��������");
MUIText[58][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[58][2],"���ن���");
MUIText[59][0]=(char*)calloc(138,sizeof(char));
strcpy(MUIText[59][0],"Error: The target video does not exist");
MUIText[59][1]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[59][1],"����Ŀ����Ƶ������");
MUIText[59][2]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[59][2],"�e�`��Ŀ��ҕ�l������");
MUIText[60][0]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[60][0],"Mute and start");
MUIText[60][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[60][1],"����������");
MUIText[60][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[60][2],"�o��K����");
MUIText[61][0]=(char*)calloc(121,sizeof(char));
strcpy(MUIText[61][0],"Do not mute and start");
MUIText[61][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[61][1],"������������");
MUIText[61][2]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[61][2],"���o��K����");
MUIText[62][0]=(char*)calloc(139,sizeof(char));
strcpy(MUIText[62][0],"Video Path: \r\n\
\r\n\
Supports: \r\n\
Local Video");
MUIText[62][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[62][1],"��Ƶ·����\r\n\
\r\n\
֧���\r\n\
������Ƶ");
MUIText[62][2]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[62][2],"ҕ�l·����\r\n\
\r\n\
֧��헣�\r\n\
����ҕ�l");
MUIText[63][0]=(char*)calloc(106,sizeof(char));
strcpy(MUIText[63][0],"Launch");
MUIText[63][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[63][1],"����");
MUIText[63][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[63][2],"����");
MUIText[64][0]=(char*)calloc(153,sizeof(char));
strcpy(MUIText[64][0],"Save a configuration file to save wallpaper settings.");
MUIText[64][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[64][1],"����һ�������ļ��Ա����ֽ���á�");
MUIText[64][2]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[64][2],"����һ���O���n�Ա��������O����");
MUIText[65][0]=(char*)calloc(157,sizeof(char));
strcpy(MUIText[65][0],"Modify a configuration file to change wallpaper settings.");
MUIText[65][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[65][1],"�޸�һ�������ļ��Ը��ı�ֽ���á�");
MUIText[65][2]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[65][2],"�޸�һ���O���n�Ը��������O����");
MUIText[66][0]=(char*)calloc(153,sizeof(char));
strcpy(MUIText[66][0],"Open a configuration file to start dynamic wallpaper.");
MUIText[66][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[66][1],"��һ�������ļ���������̬��ֽ��");
MUIText[66][2]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[66][2],"���_һ���O���n�Ԇ��ӄӑB���档");
MUIText[67][0]=(char*)calloc(166,sizeof(char));
strcpy(MUIText[67][0],"Close all windows created by mshta.exe to stop dynamic wallpapers.");
MUIText[67][1]=(char*)calloc(143,sizeof(char));
strcpy(MUIText[67][1],"�ر�����mshta.exe�����Ĵ�����ֹͣ��̬��ֽ��");
MUIText[67][2]=(char*)calloc(143,sizeof(char));
strcpy(MUIText[67][2],"�P�]����mshta.exe������ҕ����ֹͣ�ӑB���档");
MUIText[68][0]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[68][0],"Open 'About'");
MUIText[68][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[68][1],"�򿪡�����");
MUIText[68][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[68][2],"���_���P�");
MUIText[69][0]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[69][0],"Set Default Font");
MUIText[69][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[69][1],"����Ĭ������");
MUIText[69][2]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[69][2],"�O���A�O���w");
MUIText[70][0]=(char*)calloc(135,sizeof(char));
strcpy(MUIText[70][0],"Font setting completed, font name: ");
MUIText[70][1]=(char*)calloc(126,sizeof(char));
strcpy(MUIText[70][1],"������������ɣ��������ƣ�");
MUIText[70][2]=(char*)calloc(126,sizeof(char));
strcpy(MUIText[70][2],"���w���O����ɣ����w���Q��");
MUIText[71][0]=(char*)calloc(158,sizeof(char));
strcpy(MUIText[71][0],". After restarting the program, the font will take effect!");
MUIText[71][1]=(char*)calloc(128,sizeof(char));
strcpy(MUIText[71][1],"������������������彫��Ч��");
MUIText[71][2]=(char*)calloc(128,sizeof(char));
strcpy(MUIText[71][2],"�������ӳ�ʽ�����w����Ч��");
MUIText[72][0]=(char*)calloc(203,sizeof(char));
strcpy(MUIText[72][0],"Please select a font to continue initialization. If you want to try again, please restart this program.");
MUIText[72][1]=(char*)calloc(160,sizeof(char));
strcpy(MUIText[72][1],"��ѡ��һ�������Լ�����ʼ���������Ҫ���ԣ�����������������");
MUIText[72][2]=(char*)calloc(160,sizeof(char));
strcpy(MUIText[72][2],"Ո�x��һ�����w���^�m��ʼ���������Ҫ��ԇ��Ո�����ӱ���ʽ��");
MUIText[73][0]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[73][0],"Language");
MUIText[73][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[73][1],"����");
MUIText[73][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[73][2],"�Z��");
MUIText[74][0]=(char*)calloc(107,sizeof(char));
strcpy(MUIText[74][0],"English");
MUIText[74][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[74][1],"Ӣ��");
MUIText[74][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[74][2],"Ӣ�Z");
MUIText[75][0]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[75][0],"Chinese Simplified");
MUIText[75][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[75][1],"��������");
MUIText[75][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[75][2],"���w����");
MUIText[76][0]=(char*)calloc(119,sizeof(char));
strcpy(MUIText[76][0],"Chinese Traditional");
MUIText[76][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[76][1],"��������");
MUIText[76][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[76][2],"���w����");
MUIText[77][0]=(char*)calloc(180,sizeof(char));
strcpy(MUIText[77][0],"The language has been updated and will take effect after restarting the program!");
MUIText[77][1]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[77][1],"�����Ѹ��£������������Ч��");
MUIText[77][2]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[77][2],"�Z���Ѹ��£��؆���ʽ�ጢ��Ч��");
MUIText[78][0]=(char*)calloc(153,sizeof(char));
strcpy(MUIText[78][0],"The program has been started. Please don't run again!");
MUIText[78][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[78][1],"������������ɣ��벻Ҫ�������У�");
MUIText[78][2]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[78][2],"��ʽ�ц�����ɣ�Ո��Ҫ���Ά��ӣ�");
MUIText[79][0]=(char*)calloc(105,sizeof(char));
strcpy(MUIText[79][0],"Close");
MUIText[79][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[79][1],"�ر�");
MUIText[79][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[79][2],"�P�]");
MUIText[80][0]=(char*)calloc(154,sizeof(char));
strcpy(MUIText[80][0],"The dynamic wallpaper has been launched and completed!");
MUIText[80][1]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[80][1],"��̬��ֽ��������ɣ�");
MUIText[80][2]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[80][2],"�ӑB�����ц�����ɣ�");
MUIText[81][0]=(char*)calloc(146,sizeof(char));
strcpy(MUIText[81][0],"Explorer.exe has been restarted and completed!");
MUIText[81][1]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[81][1],"Explorer.exe��������ɣ�");
MUIText[81][2]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[81][2],"Explorer.exe���؆���ɣ�");
MUIText[82][0]=(char*)calloc(135,sizeof(char));
strcpy(MUIText[82][0],"Start dynamic wallpaper at startup.");
MUIText[82][1]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[82][1],"����ʱ������̬��ֽ��");
MUIText[82][2]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[82][2],"���ӕr���ӄӑB���档");
MUIText[83][0]=(char*)calloc(1269,sizeof(char));
strcpy(MUIText[83][0],"Advantages of DWPT:\r\n\
1. Lightweight\r\n\
In versions of Windows 7 and above, DWPT does not require any other miscellaneous libraries except for the WinAPI library and HelpDWPT.dll (DWPT Help Library), WallpaperCore.dll (Wallpaper Core Library), and the DWPT main program is less than 1Mib (excluding installation and uninstallation programs), which is smaller than the program compiled by writing a Hello World program using the iostream library, and does not rely on the Visual C++runtime library\r\n\
2. Concise interface\r\n\
The user interface of DWPT has no advertisements and will not slow down or slow down your computer. When not needed, you can also hide program icons in the system tray, which is very user-friendly\r\n\
3. Better support\r\n\
The video playback tool for DWPT is mshta.exe (Microsoft HTML application). Don't question why I use this (because I don't know how to write a player) instead of ffplay.exe. The reason is that ffplay.exe is indeed too large, over 100 MiB, larger than the main program, and I chose 32-bit compilation, so 32-bit Windows can also be used\r\n\
So, if you want to choose a lightweight, simple, ad free dynamic wallpaper software, choose DWPT\r\n\
");
MUIText[83][1]=(char*)calloc(829,sizeof(char));
strcpy(MUIText[83][1],"DWPT���ŵ㣺\r\n\
1.���\r\n\
    DWPT��Windows7���ϵİ汾�г���WinAPI�Ŀ��HelpDWPT.dll��DWPT�����⣩��WallpaperCore.dll����ֽ���Ŀ⣩������Ҫ������ ���Ӱ˵Ŀ⣬��DWPT�����򲻵�1Mib����������װ�����ж�س��򣩣�������iostream��дһ��Hello World��������ĳ���С������ ������Visual C++���п�\r\n\
2.������\r\n\
    DWPT���û�����û���κεĹ�棬Ҳ��������ĵ��Ա����俨������Ҫʱ�����Խ�����ͼ�����ص�ϵͳ�����У�ʮ�����Ի�\r\n\
\r\n\
3.���õ�֧����\r\n\
    DWPT����Ƶ���Ź�����mshta.exe��Microsoft HTMLӦ�ó��򣩣���Ҫ����Ϊʲô��Ҫ���������Ϊ�Ҳ���д����������������ffplay.exe��ԭ����ffplay.exeȷʵ��̫���ˣ�100��MiB����������Ҫ�󣬲�����ѡ����32λ���룬����32λ��WindowsҲ����\r\n\
\r\n\
���ԣ������Ҫѡ��һ����㡢�򵥡��޹��Ķ�̬��ֽ�������ѡDWPT�ɣ� ");
MUIText[83][2]=(char*)calloc(832,sizeof(char));
strcpy(MUIText[83][2],"DWPT�ă��c��\r\n\
1.�p��\r\n\
    DWPT��Windows7���ϵİ汾�г���WinAPI�Ď��HelpDWPT.dll��DWPT�����죩��WallpaperCore.dll������҇�Ď죩������Ҫ�����s ���s�˵Ď죬��DWPT�����򲻵�1Mib�����������b��ʽ��ж�d��ʽ����������iostream�쌑һ��Hello World���g����ĳ�ʽ߀С���K�� ����هVisual C++��\r\n\
2.���溆��\r\n\
    DWPT��ʹ���߽���]���κεďV�棬Ҳ����׌�����X׃��׃��������Ҫ�r߀���Ԍ���ʽ�D���[�ص�ϵ�yӚ�P�У�ʮ�����Ի�\r\n\
\r\n\
3.���õ�֧����\r\n\
    DWPT��ҕ�l���Ź�����mshta.exe��Microsoft HTML���ó��򣩣���Ҫ�|�ɞ�ʲ�N��Ҫ���@��������Ҳ��������řC����������ffplay.exe��ԭ����ffplay.exe�_����̫���ˣ�100��MiB����������߀Ҫ�󣬁K�����x����32���ؾ��g������32���ص�WindowsҲ����\r\n\
\r\n\
���ԣ������Ҫ�x��һ���p�㡢���Ρ��o�V��ĄӑB����ܛ�������xDWPT�ɣ�\r\n\
");
MUIText[84][0]=(char*)calloc(2436,sizeof(char));
strcpy(MUIText[84][0],"The opening method of DWPT is very simple. The first step is to open the program without allowing administrator privileges. This program has removed the need for administrator identity since 0.0.7.2 and later\r\n\
First - How to start dynamic wallpaper:\r\n\
1. Click on the 'Create Profile' button\r\n\
2. Choose a save location (remember to enter the name of the saved file)\r\n\
3. Choose one of your videos and remember to click on it to make it selected\r\n\
4. When asked if you need sound, you can click \"Yes\" or \"No\" to disable or enable the sound\r\n\
5. At this point, the configuration file has been created. You can click \"Yes\" to immediately use this configuration file, or click \"No\" to put this file aside for now\r\n\
Second - If I created a configuration file last time, how to use the previous configuration:\r\n\
1. Click on the 'Open Profile' button\r\n\
2. Select the configuration file you created last time\r\n\
3. When the pop-up asks if you want to continue, please make sure if there are any other mshta.exe processes that are not related to DWPT running. If not, click \"Yes\". If there are, go check if they are important. If they are not important, close them. If they are important, don't open them yet\r\n\
Third -  What should I do if I want to modify the content of the configuration file:\r\n\
1. Click on the 'Modify Configuration File' button\r\n\
2. Select your configuration file\r\n\
3. When you enter the editing page, you can start modifying. You can click \"Yes\" or \"No\" to modify, or \"Cancel\" to stop modifying\r\n\
4. Continue with the third step until the modifications are completed\r\n\
5. Choose whether to save\r\n\
6. Done! \r\n\
\r\n\
Fourth - I don't want to use it anymore. What should I do if I stop using it\r\n\
1. Confirm that there is no mshta.exe running on your computer that is unrelated to DWPT.\r\n\
2. Click on \"Stop Dynamic Wallpaper\"\r\n\
3. Click confirm and select 'Yes' in the pop-up box to stop the dynamic wallpaper\r\n\
Fifth - How to set \\ modify the position of default items:\r\n\
1. Click on \"Global Settings\"\r\n\
2. Click on \"Edit\", select the configuration file you want to set as the default option, and click OK\r\n\
Sixth -  What should I do if I want to boot up a dynamic wallpaper: \r\n\
1. Please ensure that you have set the default settings. If not, please refer to \"Five\"\r\n\
2. Click on \"Global Settings\"\r\n\
3. Select the \"Power on Self Start\" checkbox to check\r\n\
");
MUIText[84][1]=(char*)calloc(1456,sizeof(char));
strcpy(MUIText[84][1],"DWPT�Ĵ򿪷����ܼ򵥣���һ�����򿪳��򣬲���Ҫ�������ԱȨ�ޣ���������0.0.7.2���Ժ���Ƴ��˹���Ա��ݵ���Ҫ\r\n\
һ.���������̬��ֽ��\r\n\
 1.���\"���������ļ�\"��ť\r\n\
 2.ѡ��һ������λ�ã��ǵ����뱣����ļ����ƣ�\r\n\
 3.ѡ�����һ����Ƶ���ǵõ���Ǹ���Ƶһ���������ڱ�ѡ��״̬\r\n\
 4.ѯ�����Ƿ���Ҫ����������Ե��\"��\"����\"��\"�����û���������\r\n\
 5.����������ļ��ʹ�������ˣ�������ڽ������ĵ��\"��\"������ʹ����������ļ������ߵ��\"��\"������ļ��ȷ���\r\n\
\r\n\
��.���ϴδ����������ļ��ˣ����ʹ���ϴε����ã�\r\n\
 1.���\"�������ļ�\"��ť\r\n\
 2.ѡ�����ϴδ����������ļ�\r\n\
 3.�ڵ����������Ƿ���������ʱ����ȷ�����Ƿ��������ĺ�DWPT�޹ص�mshta.exe���������У����û�о͵�\"��\"���еĻ���ȥ�����ز���Ҫ������Ҫ�ľ͹��ˣ��������Ҫ�ľ��ȱ�\r\n\
\r\n\
��.�����޸������ļ���������ô�죺\r\n\
 1.���\"�޸������ļ�\"��ť\r\n\
 2.ѡ����������ļ�\r\n\
 3.���뵽�༭ҳ�棬���ʱ����Ϳ��Կ�ʼ�޸��ˣ����Ե��\"��\"��\"��\"���޸ģ�\"ȡ��\"����ֹͣ�޸�\r\n\
 4.����������ֱ���޸����\r\n\
 5.ѡ���Ƿ񱣴�\r\n\
 6.��ɣ�\r\n\
\r\n\
��.�Ҳ�������Ҫͣ����ô�죺\r\n\
 1.ȷ����ĵ�����û����DWPT����ɵ�mshta.exe������\r\n\
 2.���\"ֹͣ��̬��ֽ\"\r\n\
 3.���ȷ�ϲ��ڵ����Ŀ��ѡ\"��\"������ֹͣ��̬��ֽ\r\n\
\r\n\
��.��� ����\\�޸� Ĭ�����λ�ã�\r\n\
 1.���\"ȫ������\"\r\n\
 2.���\"�༭\"��ѡ����Ҫ����ΪĬ����������ļ������ȷ������\r\n\
\r\n\
��.����Ҫ������������̬��ֽ��ô�죺\r\n\
 1.��ȷ�����Ѿ�������Ĭ������û���뿴\"��\"\r\n\
 2.���\"ȫ������\"\r\n\
 3.ѡ��\"����������\"���򼴿�\r\n\
");
MUIText[84][2]=(char*)calloc(1407,sizeof(char));
strcpy(MUIText[84][2],"DWPT�Ĵ��_�����ܺ��Σ���һ�������_��ʽ������Ҫ���S����T�S�ə࣬����ʽ��0.0.7.2��������Ƴ��˹���T��ݵ���Ҫ\r\n\
һ. ��Ά��ӄӑB���棺\r\n\
1.�c���������O���n���o\r\n\
2.�x��һ������λ�ã�ӛ��ݔ�뱣��ęn�����Q��\r\n\
3.�x�����һ��ҕ�l��ӛ���c���ǂ�ҕ�lһ��׌��̎춱��x�Р�B\r\n\
4.ԃ�����Ƿ���Ҫ����������c�����ǻ��ߡ������û�����\r\n\
5.���@�e���O���n�̈́�������ˣ�������ڽ�����c�����ǁ�����ʹ���@���O���n�������c��������@���n�ȷ���\r\n\
\r\n\
��. ���ϴ΄������O���n�ˣ����ʹ���ϴε��䌅��\r\n\
1.�c�������_�O���n���o\r\n\
2.�x�����ϴ΄������O���n\r\n\
3.�ڏ����Ć����Ƿ��^�m���@���r��Ո�_�����Ƿ��������ĺ�DWPT�o�P��mshta.exe�г�����ʹ�ã�����]�о��c���ǣ��е�Ԓ��ȥ���� �ز���Ҫ������Ҫ�ľ��P�ˣ��������Ҫ�ľ��Ȅe�_\r\n\
\r\n\
��. �����޸��O���n�ă������N�k��\r\n\
1.�c���޸��O���n���o\r\n\
2.�x������O���n\r\n\
3.�M�뵽��݋��棬�@���r����Ϳ����_ʼ�޸��ˣ������c�����ǻ򡰷���޸ģ���ȡ���t��ֹͣ�޸�\r\n\
4.�^�m������ֱ���޸����\r\n\
5.�x���Ƿ񱣴�\r\n\
6.��ɣ� \r\n\
\r\n\
��. �Ҳ�������Ҫͣ�����N�k��\r\n\
1.�_�J�����X�ϛ]���cDWPT����ɵ�mshta.exe����ʹ��\r\n\
2.�c��ֹͣ�ӑB����\r\n\
3.�c���_�J�K�ڏ����Ŀ���x�ǣ�����ֹͣ�ӑB����\r\n\
\r\n\
��. ����O��\\�޸�Ĭ�J헵�λ�ã�\r\n\
1.�c��ȫ���O��\r\n\
2.�c����݋���x����Ҫ�O����Ĭ�J헵��O���n���c���_������\r\n\
\r\n\
��. ����Ҫ�_�C�Ԇ��ӄӑB�������N�k��\r\n\
1.Ո�_�����ѽ��O����Ĭ�J헣�����]��Ո����\r\n\
2.�c��ȫ���O��\r\n\
3.�x���_�C�Ԇ��әz��򼴿�\r\n\
");
MUIText[85][0]=(char*)calloc(3107,sizeof(char));
strcpy(MUIText[85][0],"Question&Answer:\r\n\
Q: Why don't you use CLR to create windows? \r\n\
Answer: Because we need to take care of some special groups of people who cannot install the Visual C++runtime library, such as She_Fa21 (my friend). If we don't install VC, it will prompt that the DLL is missing, and gcc compiles smaller\r\n\
Q: Why are the windows and controls you create in Win11 style and DPI not an issue while I am not? \r\n\
Answer: I have also thought about this question. I collected a lot of information online and practiced for a long time before figuring out this method. For your question, I have the following solutions:\r\n\
For the issue of controls being outdated:\r\n\
        Visual Studio: Please add the following code before:\r\n\
            #ifdef _UNICODE\r\n\
            #if defined _M_IX86\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #elif defined _M_X64\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #else\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #endif\r\n\
            #endif\r\n\
        Dev-C++: Compared to Visual Studio, the operation of Dev is simpler. Simply check \"Supports Windows XP themes\" in the project [P] ->project properties [O]    For the issue of incorrect DPI display:\r\n\
                Microsoft related documents: https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setprocessdpiaware/\r\n\
                Visual Studio: Add code directly at the beginning of the program: Set ProcessDPIAware();\r\n\
                Dev-C++: Please add the following code at the beginning of the program:\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID);\r\n\
            SPDA SetProcessDPIAware;\r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\");\r\n\
            if(hModule){//Exception handling\r\n\
                SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");// Tip: The SetProcessDPIAware function was added to Windows Vista\r\n\
                if(SetProcessDPIAware) SetProcessDPIAware();//Non abnormal state\r\n\
                        }\r\n\
            //The GCC version used by Dev-C++ is 4.9.2, and this API has been added to the new version of GCC\r\n\
        That's it! \r\n\
Q: What should I do if there is a failure to create a window or register a window class?\r\n\
Answer: Please try downloading this program again. If it still doesn't work, then I have no choice\r\n\
Q: Why is the font so ugly? \r\n\
Answer: The font I use when writing code is user-defined, which may not look good because some fonts do not support Chinese. I use CreateFontA to load fonts, so you can take a look at the CreateFontA function in Microsoft's development documentation");
MUIText[85][1]=(char*)calloc(2479,sizeof(char));
strcpy(MUIText[85][1],"���� & �ش�\r\n\
�ʣ�Ϊʲô�㲻��CLR�������ڣ�\r\n\
����ΪҪ�չ�һЩװ����Visual C++���п��������Ⱥ������She_Fa21�������ѣ��������װVC����ʾ��dll������gcc����ĸ�С\r\n\
\r\n\
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
        ΢������ĵ���https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setprocessdpiaware/\r\n\
        Visual Studio:ֱ���ڳ�����ʼ�ĵط����ϴ��룺SetProcessDPIAware();\r\n\
        Dev-C++:���ڳ�����ʼ�ĵط��������´��룺\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID);\r\n\
            SPDA SetProcessDPIAware;\r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\");\r\n\
            if(hModule){//�쳣����                SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");//��ʾ��SetProcessDPIAware������Windows Vista�����\r\n\
                if(SetProcessDPIAware) SetProcessDPIAware();//���쳣״̬\r\n\
                        }\r\n\
            //Dev-C++ʹ�õ�GCC�汾��4.9.2���°��GCC�Ѿ���������API\r\n\
    �����ͽ������\r\n\
�ʣ�������ִ�������ʧ�ܡ�������ע��ʧ��֮��ĸ���ô�죿\r\n\
���볢���������ر�����������ǲ��У����Ҿ�û�취��\r\n\
�ʣ�Ϊʲô������ô��\r\n\
����д����ʱʹ�õ�����Ϊ�û���������壬�ѿ���������ΪĳЩ���岢��֧�����ģ�������CreateFontA����������ģ����Կ���ȥ ����΢�����ĵ������CreateFontA����");
MUIText[85][2]=(char*)calloc(2514,sizeof(char));
strcpy(MUIText[85][2],"���}&�ش�\r\n\
������ʲ�N�㲻��CLR����ҕ���� \r\n\
�����Ҫ���һЩ�b����Visual C++���������Ⱥ������She_Fa21�������ѣ���������bVC����ʾ��dll���K��gcc���g�ĸ�С\r\n\
\r\n\
�����ㄓ�������ҕ���Ϳ���헞�ʲ�N����Win11��ʽ����DPI�����І��}���Ҳ��У� \r\n\
���@�����}��Ҳ���^���ҏľW�ϴ����L���Y���Ҍ��`�˺ܾò���ĥ���@�N������������Ć��}���������½�Q������\r\n\
    ��춿�������f��Ć��}��\r\n\
        Visual Studio:Ո��ǰ��������³�ʽ�a��\r\n\
            #ifdef _UNICODE\r\n\
            #if defined _M_IX86\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #elif defined _M_X64\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #else\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #endif\r\n\
            #endif\r\n\
        Dev-C++�������Visual Studio���f��Dev�Ĳ��������Σ����Ŀ[P]->�Ŀ����[O]�e�湴�x��֧��Windows XP���}����\r\n\
    ���DPI�@ʾ�����_�Ć��}��\r\n\
        ΢ܛ���P�ęn�� https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setprocessdpiaware/ \r\n\
        Visual Studio:ֱ���ڳ�ʽ��ʼ�ĵط����ϳ�ʽ�a��SetProcessDPIAware������ \r\n\
        Dev-C++��Ո�ڳ�ʽ��ʼ�ĵط��������³�ʽ�a��\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID); \r\n\
            SPDA SetProcessDPIAware; \r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\"); \r\n\
            if��hModule��{//����̎��\r\n\
                SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");// ��ʾ��SetProcessDPIAware�� ����Windows Vista�����\r\n\
                if(SetProcessDPIAware) SetProcessDPIAware();// ���쳣��B\r\n\
            }\r\n\
            //Dev-C++ʹ�õ�GCC�汾��4.9.2���°��GCC�ѽ�������@��API\r\n\
        �@�Ӿͽ������ \r\n\
����������F����ҕ��ʧ����ҕ���ע��ʧ��֮�ԓ���N�k�� \r\n\
��Ո�Lԇ�������d����ʽ�����߀�ǲ��У����Ҿ͛]�k����\r\n\
������ʲ�N���w���N�h�� \r\n\
���Ҍ���ʽ�a�rʹ�õ����w���Ñ����x�����w���y�����������ĳЩ���w�K��֧Ԯ���ģ�������CreateFontA����d���w�ģ����Կ��� ȥ����΢ܛ�_�l�n���e���CreateFontA����");
MUIText[86][0]=(char*)calloc(1738,sizeof(char));
strcpy(MUIText[86][0],"About DWPT:\r\n\
Author: Office-Excel\r\n\
Reference video (Bilibili video number): BV1HZ4y1978a, address: https://www.bilibili.com/video/BV1HZ4y1978a/\r\n\
Code editing tool used: Dev-C++Code language used: C++. Most commonly used libraries: windows.h\r\n\
Window creation: Windows API (not a dialog box in the resource file, as I don't know how to use it)\r\n\
DWPT project properties:\r\n\
    Name: DWPT (Dynamic Wallpaper Tools)    Project start date: 2024/04/21\r\n\
    Project objective: To create a pure and simple dynamic wallpaper tool\r\n\
    Why did the author do this stupid thing: just for fun, he wrote a few hundred lines of code casually\r\n\
    Dp file structure:\r\n\
        If you open the dp file with Notepad\r\n\
            You will find that the first character is always 't' or 'f', which represents whether the sound is enabled or not. f=disabled, t=enabled\r\n\
            The following is the absolute path of the video, and the text should theoretically be stored using GBK encoding, so it supports Chinese\r\n\
\r\n\
    The principle of starting dynamic wallpaper in DWPT:\r\n\
        1. Read in file\r\n\
        2. Check if sound is enabled\r\n\
        3. Store the absolute path of the video in VP (char array)\r\n\
        4. Splice the preset text and write it to the %temp%\\Temporary.hta file\r\n\
        5. Start the process mshta.exe\r\n\
        6. Send 0x52C signal to window with class name Progman\r\n\
        7. Find the second WorkerW window and hide it\r\n\
        8. Set the window with the class name Progman as the parent window of the mshta.exe window\r\n\
        9. Done! \r\n\
\r\n\
Author's Bilibili account: Office-Excel (Address: https://space.bilibili.com/1439352366/)\r\n\
");
MUIText[86][1]=(char*)calloc(1270,sizeof(char));
strcpy(MUIText[86][1],"����DWPT��\r\n\
���ߣ�Office-Excel\r\n\
�ο���Ƶ������������Ƶ��ţ���BV1HZ4y1978a����ַ��https://www.bilibili.com/video/BV1HZ4y1978a/\r\n\
ʹ�õĴ���༭���ߣ�Dev-C++ ʹ�õĴ������ԣ�C++ �õ����Ŀ⣺windows.h\r\n\
���ڴ�����Windows API��������Դ�ļ���ĶԻ�����Ϊ�Ҳ����ã�\r\n\
DWPT��Ŀ���ԣ�\r\n\
    ���ƣ�DWPT��ȫ��Dynamic Wallpaper Tools�����룺��̬��ֽ���ߣ�\r\n\
    ��Ŀ��ʼ���ڣ�2024/04/21\r\n\
    ��ĿĿ�꣺��һ�������򵥵Ķ�̬��ֽ����\r\n\
    ����ΪʲôҪ����������⣺ֻ��Ϊ�˺������д�˼��ٶ��еĴ���\r\n\
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
        9.��ɣ�\r\n\
\r\n\
���ߵ����������˺ţ�Office-Excel����ַ��https://space.bilibili.com/1439352366/��\r\n\
");
MUIText[86][2]=(char*)calloc(1258,sizeof(char));
strcpy(MUIText[86][2],"�P�DWPT:\r\n\
���ߣ�Office-Excel\r\n\
����ҕ�l����������ҕ�l��̖����BV1HZ4y1978a����ַ�� https://www.bilibili.com/video/BV1HZ4y1978a/ \r\n\
ʹ�õĳ�ʽ�a��݋���ߣ�Dev-C++ʹ�õĳ�ʽ�a�Z�ԣ�C++�õ����Ď죺windows.h\r\n\
ҕ��������Windows API�������YԴ�n�Y�Č�Ԓ���K������Ҳ����ã�\r\n\
DWPT�Ŀ���ݣ�\r\n\
    ���Q��DWPT��ȫ�QDynamic Wallpaper Tools�����g���ӑB���湤�ߣ�\r\n\
    �Ŀ�_ʼ���ڣ�2024/04/21\r\n\
    �ĿĿ�ˣ���һ�����Q���εĄӑB���湤��\r\n\
    ���ߞ�ʲ�NҪ���@�������⣺ֻ�Ǟ��˺����S�㌑�ˎװٶ��еĳ�ʽ�a\r\n\
    dp�n���Y����\r\n\
    �������ӛ�±����_dp�n��\r\n\
    ����l�F��һ����Ԫ����'t'����'f'���@�������Ƿ�������f=�����ã�t=����\r\n\
    ����Ąt��ҕ�l�Ľ^��·�������ְ����f��ԓ��ʹ��GBK���a�惦�ģ�����֧Ԯ����\r\n\
\r\n\
    DWPT���ӄӑB�����ԭ��\r\n\
        1.�x��n��\r\n\
        2.�鿴�Ƿ�����\r\n\
        3.��ҕ�l�^��·������VP��char���M��\r\n\
        4.ƴ���A�O�����ցK����%temp%\\Temporary.hta�n��\r\n\
        5.�����г�mshta.exe\r\n\
        6.�������Progman��ҕ���l��0x52CӍ̖\r\n\
        7.�ҵ��ڶ���WorkerWҕ���K�[����\r\n\
        8.�������Progman��ҕ���O����mshta.exeҕ���ĸ�ҕ��\r\n\
        9.��ɣ� \r\n\
\r\n\
���ߵĆ���������̖��Office-Excel����ַ�� https://space.bilibili.com/1439352366/ ��\r\n\
");
		MUIText[88][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[88][0],"WHY CHOOSE US");
		MUIText[88][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[88][1],"Ϊʲôѡ������");
		MUIText[88][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[88][2],"��ʲ�N�x���҂�");
		
		MUIText[89][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[89][0],"HOW TO USE");
		MUIText[89][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[89][1],"���ʹ��");
		MUIText[89][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[89][2],"���ʹ��");
		
		MUIText[90][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[90][0],"Q && A");
		MUIText[90][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[90][1],"���� && �ش�");
		MUIText[90][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[90][2],"���} && �ش�");
		
		MUIText[91][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[91][0],"ABOUT DWPT");
		MUIText[91][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[91][1],"���� DWPT");
		MUIText[91][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[91][2],"�P� DWPT");
		
		MUIText[92][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[92][0],"AUTHOR's HOMEPAGE");
		MUIText[92][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[92][1],"������ҳ");
		MUIText[92][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[92][2],"�������");
		
		MUIText[93][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[93][0],"REFERENCE VIDEO");
		MUIText[93][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[93][1],"�ο���Ƶ");
		MUIText[93][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[93][2],"����ҕ�l");
		
		MUIText[94][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[94][0],"CLOSE");
		MUIText[94][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[94][1],"�ر�");
		MUIText[94][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[94][2],"�P�]");
		
		MUIText[95][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[95][0],"Save");
		MUIText[95][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[95][1],"����");
		MUIText[95][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[95][2],"����");
		
		MUIText[96][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[96][0],"Only save");
		MUIText[96][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[96][1],"������");
		MUIText[96][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[96][2],"�H����");
		
		MUIText[97][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[97][0],"Save and start.");
		MUIText[97][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[97][1],"���沢����");
		MUIText[97][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[97][2],"����K����");
		
		MUIText[98][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[98][0],"Play sound.");
		MUIText[98][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[98][1],"�������֡�");
		MUIText[98][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[98][2],"����������");
		
		MUIText[99][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[99][0],"Video Path:\r\n\r\nThere are some environment variable you can use: ");
		MUIText[99][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[99][1],"��Ƶ·����\r\n\r\n������ʹ�����»���������");
		MUIText[99][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[99][2],"ҕ�l·����\r\n\r\n������ʹ�����­h��׃����");
		
		MUIText[100][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[100][0],"View all");
		MUIText[100][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[100][1],"�鿴����");
		MUIText[100][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[100][2],"�鿴����");
		
		MUIText[101][0]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[101][0],"The last edited configuration file has not been saved yet! Do you need to save the last edited configuration file or continue editing the unsaved configuration file?");
		MUIText[101][1]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[101][1],"��һ�α༭�������ļ���δ���棡�Ƿ���Ҫ������һ�α༭�������ļ�������༭δ����������ļ���");
		MUIText[101][2]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[101][2],"��һ�ξ�݋���O���n߀δ���棡 �Ƿ���Ҫ������һ�ξ�݋���O���n���^�m��݋δ������O���n��");
		
		MUIText[102][0]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[102][0],"Video location variable:\r\n - ${dp} = Directory where the profile is located.\r\n - ${pp} = The path of this program.\r\n - .. = The last directory.\r\n - ${System environment variable name} = The variable from system.\r\n\r\nExample:\r\n${SystemRoot}\\1.mp4\r\nAfter parsing is completed, it is: C:\\WINDOWS\\1.mp4");
		MUIText[102][1]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[102][1],"��Ƶλ�û���������\r\n - ${dp} = �����ļ����ڵ�Ŀ¼��\r\n - ${pp} = �˳����·����\r\n - ��=��һ��Ŀ¼��\r\n - ${ϵͳ����������} = ϵͳ�еĻ���������\r\n\r\n���磺\r\n${SystemRoot}\\1.mp4\r\n������ɺ��ǣ�C:\\WINDOWS\\1.mp4");
		MUIText[102][2]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[102][2],"ҕ�lλ�íh��׃����\r\n - ${dp} = �O���n���ڵ�Ŀ䛡� \r\n - ${pp} = �˳�ʽ��·���� \r\n - ��=��һ��Ŀ䛡� \r\n - ${ϵ�y�h��׃����} = ϵ�y�еĭh��׃���� \r\n\r\n���磺\r\n${SystemRoot}\\1.mp4\r\n����������ǣ�C:\\WINDOWS\\1.mp4");
	}
	char TS[114514],Result[114514],SysVarName[11451],SysVar[11451];
	DLLIMPORT void SolvePath(char ProfilePath[],char SolvedPath[],bool *Sound){
		char in;DWORD dw=0;
		HANDLE hFile=CreateFile(ProfilePath, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
		ReadFile(hFile,&in,1,&dw,NULL);
		*Sound=(in=='t'||in=='T');
		ReadFile(hFile,TS,GetFileSize(hFile,NULL)-1,&dw,NULL);
		CloseHandle(hFile);
		int pointer=0,SysVarPointer;
		memset(Result,false,sizeof(Result));
		for(int i=0;i<strlen(TS);i++){
			if(TS[i]=='$'&&TS[i+1]=='{'){
				i+=2;
				SysVarPointer=0;
				while(TS[i]!='}') SysVarName[SysVarPointer++]=TS[i++];
				SysVarName[SysVarPointer]='\0';
				if(strcmp(SysVarName,"pp")==0||strcmp(SysVarName,"Pp")==0||strcmp(SysVarName,"PP")==0||strcmp(SysVarName,"pP")==0){
					GetModuleFileName(NULL,SysVar,11445);
					for(int j=strlen(SysVar)-1;SysVar[j]!='\\';j--) SysVar[j]='\0';
					SysVar[strlen(SysVar)-1]='\0';
				}
				else if(strcmp(SysVarName,"dp")==0||strcmp(SysVarName,"Dp")==0||strcmp(SysVarName,"DP")==0||strcmp(SysVarName,"dP")==0){
					strcpy(SysVar,ProfilePath);
					for(int j=strlen(SysVar)-1;SysVar[j]!='\\';j--) SysVar[j]='\0';
					SysVar[strlen(SysVar)-1]='\0';
				}
				else{
					GetEnvironmentVariableA(SysVarName,SysVar,11451);
				}
				strcat(Result,SysVar);
				pointer=strlen(Result);
			}
			else if(Result[pointer-1]=='\\'&&TS[i]=='.'&&TS[i+1]=='.'&&TS[i+2]=='\\'){
				i++;
				Result[pointer-1]='\0';
				for(int j=pointer-2;Result[j]!='\\';j--) Result[j]='\0';
				Result[strlen(Result)-1]='\0';
				pointer=strlen(Result);
			}
			else{
				Result[pointer++]=TS[i];
			}
		}
		Result[pointer]='\0';
		strcpy(SolvedPath,Result);
		return;
	}
	DLLIMPORT void GetVer(LPVERSION lpVersion){
		lpVersion->Main=0;
		lpVersion->Sub=0;
		lpVersion->Release=9;
		lpVersion->Make=1;
		return ;
	}
	DLLIMPORT char* GetString4ThisLang(UINT index){
		if(LangID==IL_UNSET){
			switch(PRIMARYLANGID(GetUserDefaultLangID())){//��ȡ����ID�����õ�ǰ���� 
				case LANG_CHINESE_SIMPLIFIED:LangID=IL_Simplified_Chinese;break;
				case LANG_CHINESE_TRADITIONAL:LangID=IL_Traditional_Chinese;break;
				default:LangID=IL_ENGLISH;break;
			}
		}
		return (char*)MUIText[index][LangID];
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
			MessageBox(Wallpaper,"SetParent function run failed!","Error",MB_ICONINFORMATION|MB_OK);
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
		char cmd[1145]=" \"",/*sound,*/VP[1145],TmpPath[MAX_PATH+20],str1[MAX_PATH*4];//��ʼ��һ���ı� 
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
		/*
		DWORD dw=0;
		HANDLE hFile=CreateFile(Path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);//���ļ���� 
		ReadFile(hFile,&sound,1,&dw,NULL);
		ReadFile(hFile,VP,GetFileSize(hFile,NULL)-1,&dw,NULL);*/
		bool sound;
		SolvePath(Path,VP,&sound);
		int i=strlen(VP);
		while(!(VP[i]<='Z'&&VP[i]>='A'||VP[i]<='z'&&VP[i]>='a'||VP[i]<='9'&&VP[i]>='0')) VP[i]=NULL,i--;//�����ļ������� 
		//MessageBox(NULL,VP,NULL,NULL);
		
		//ʹ��mshta.exe����
		GetTempPath(MAX_PATH,TmpPath);//��ȡ��ʱĿ¼������Temporary.hta��ʱ�ļ� 
		strcat(TmpPath,"Temporary.hta");
		if(TmpPath[strlen(TmpPath)-1]=='\r') TmpPath[strlen(TmpPath)-1]=NULL;
		freopen(TmpPath,"w",stdout);
		while(_access(VP,0)==-1) VP[strlen(VP)-1]=NULL;
		printf("%s%s><source src=\"%s",str1,(sound?"":" muted"),VP);
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
