/* Replace "dll.h" with the name of your header */
#include "dll.h"
/*char MUIText[][3][3100]={//多语言支持功能文本，全在这里了 
	{"Create profile","新建配置文件","新建設定檔"},//0
	{"Edit profile","编辑配置文件","編輯設定檔"},
	{"Apply profile","应用配置文件","應用設定檔"},
	{"Stop Wallpaper","停止动态壁纸","停止動態桌面"},
	{"About Dynamic Wallpaper Tools","关于Dynamic Wallpaper Tools","關於Dynamic Wallpaper Tools"},
	{"Unable to open the video display program \"mshta.exe\" (playing videos using a browser), please check if the program exists in the system directory","无法打开视频显示程序\"mshta.exe\"（使用浏览器播放视频），请检查系统目录下程序是否存在","無法打開視頻顯示程式\"mshta.exe\"（使用瀏覽器播放視頻），請檢查系統目錄下程式是否存在"},
	{"Warning! This operation will close all windows under the class name \"Progman\"!","警告！此操作会关闭所有在类名为“Progman的窗口下的所有窗口！","警告！ 此操作會關閉所有在類名為“Progman的視窗下的所有視窗"},
	{"Video files (*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv)\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0All files (*.*) \0*.*\0","视频文件（*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv）\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0所有文件（*.*）\0*.*\0","視頻檔案（*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv）\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0所有檔案（*.*）\0*.*\0"},
	{"Dynamic Wallpaper Configuration Files (.dp)\0*.dp\0","Dynamic Wallpaper配置文件（.dp）\0*.dp\0","Dynamic Wallpaper設定檔（.dp）\0*.dp\0"},
	{"Do you need to play sound?","是否需要播放声音？","是否需要播放聲音？"},//9
	{
		"Programming: Office Excel\nReference video by 偶尔有点小迷糊, video id: BV1HZ4y1978a (press to cancel to view original video)\nTools used: Dev-C++, Code language: C++\nProject start date: April 21, 2024\nVersion: 0.0.7.3\nTranslator: Baidu Translate",
		"程序制作：Office-Excel\n参考视频 by 偶尔有点小迷糊，视频id：BV1HZ4y1978a（按下取消查看原视频）\n使用工具：Dev-C++，代码语言：C++\n项目开始日期：2024/04/21\n版本：0.0.7.3\n翻译器：百度翻译",
		"程式製作：Office-Excel\n參攷視頻 by 偶尔有点小迷糊，視頻id:BV1HZ4y1978a（按下取消查看原視頻）\n使用工具：Dev-C++，程式碼語言：C++\n項目開始日期：2024/04/21\n版本：0.0.7.3\n翻譯器：百度翻譯"
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
	{"Open 'About'","打开“关于","打開“關於"},//68
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
	{"Start dynamic wallpaper at startup.","启动时启动动态壁纸。","啟動時啟動動態桌面。"},//82
	{"Advantages of DWPT:\r\n\
1. Lightweight\r\n\
In versions of Windows 7 and above, DWPT does not require any other miscellaneous libraries except for the WinAPI library and HelpDWPT.dll (DWPT Help Library), WallpaperCore.dll (Wallpaper Core Library), and the DWPT main program is less than 1Mib (excluding installation and uninstallation programs), which is smaller than the program compiled by writing a Hello World program using the iostream library, and does not rely on the Visual C++runtime library\r\n\
2. Concise interface\r\n\
The user interface of DWPT has no advertisements and will not slow down or slow down your computer. When not needed, you can also hide program icons in the system tray, which is very user-friendly\
\r\n3. Better support\r\n\
The video playback tool for DWPT is mshta.exe (Microsoft HTML application). Don't question why I use this (because I don't know how to write a player) instead of ffplay.exe. The reason is that ffplay.exe is indeed too large, over 100 MiB, larger than the main program, and I chose 32-bit compilation, so 32-bit Windows can also be used\r\n\
So, if you want to choose a lightweight, simple, ad free dynamic wallpaper software, choose DWPT\r\n\
","DWPT的优点：\n\r1.轻便\r\n\
    DWPT在Windows7及上的版本中除了WinAPI的库和HelpDWPT.dll（DWPT帮助库）、WallpaperCore.dll（壁纸核心库），不需要其他杂七杂八的库，且DWPT主程序不到1Mib（不包括安装程序和卸载程序），比你用iostream库写一个Hello World编译出来的程序还小，并且不依赖Visual C++运行库\r\n\
2.界面简洁\r\n\
    DWPT的用户界面没有任何的广告，也不会让你的电脑变慢变卡，不需要时还可以将程序图标隐藏到系统托盘中，十分人性化\r\n\
\r\n3.更好的支持性\r\n\
    DWPT的视频播放工具是mshta.exe（Microsoft HTML应用程序），不要质疑为什么我要用这个（因为我不会写播放器），而不用ffplay.exe的原因是ffplay.exe确实是太大了，100多MiB，比主程序还要大，并且我选的是32位编译，所以32位的Windows也能用\r\n\
\r\n所以，如果你要选择一款轻便、简单、无广告的动态壁纸软件，就选DWPT吧！ \
","DWPT的優點：\r\n\
1.輕便\r\n\
    DWPT在Windows7及上的版本中除了WinAPI的庫和HelpDWPT.dll（DWPT幫助庫）、WallpaperCore.dll（桌面覈心庫），不需要其他雜七雜八的庫，且DWPT主程序不到1Mib（不包括安裝程式和卸載程式），比你用iostream庫寫一個Hello World編譯出來的程式還小，並且不依賴Visual C++庫\r\n\
2.介面簡潔\r\n\
    DWPT的使用者介面沒有任何的廣告，也不會讓你的電腦變慢變卡，不需要時還可以將程式圖標隱藏到系統託盤中，十分人性化\r\n\
\r\n\
3.更好的支持性\r\n\
    DWPT的視頻播放工具是mshta.exe（Microsoft HTML應用程序），不要質疑為什麼我要用這個（因為我不會寫播放機），而不用ffplay.exe的原因是ffplay.exe確實是太大了，100多MiB，比主程序還要大，並且我選的是32比特編譯，所以32比特的Windows也能用\r\n\
\r\n\
所以，如果你要選擇一款輕便、簡單、無廣告的動態桌面軟件，就選DWPT吧！\r\n\
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
	"DWPT的打开方法很简单，第一步：打开程序，不需要允许管理员权限，本程序自0.0.7.2及以后就移除了管理员身份的需要\r\n\
一.如何启动动态壁纸：\r\n\
 1.点击\"创建配置文件\"按钮\r\n\
 2.选择一个保存位置（记得输入保存的文件名称）\r\n\
 3.选择你的一个视频，记得点击那个视频一下让它处于被选中状态\r\n\
 4.询问你是否需要声音，你可以点击\"是\"或者\"否\"来禁用或启用声音\r\n\
 5.到这里，配置文件就创建完成了，你可以在接下来的点击\"是\"来立即使用这个配置文件，或者点击\"否\"把这个文件先放着\r\n\r\n\
二.我上次创建了配置文件了，如何使用上次的配置：\r\n\
 1.点击\"打开配置文件\"按钮\r\n\
 2.选择你上次创建的配置文件\r\n\
 3.在弹出的问你是否继续，这个时候请确定你是否有其它的和DWPT无关的mshta.exe进程在运行，如果没有就点\"是\"，有的话就去看看重不重要，不重要的就关了，如果有重要的就先别开\r\n\r\n\
三.我想修改配置文件的内容怎么办：\r\n\
 1.点击\"修改配置文件\"按钮\r\n\
 2.选择你的配置文件\r\n\
 3.进入到编辑页面，这个时候你就可以开始修改了，可以点击\"是\"或\"否\"来修改，\"取消\"则是停止修改\r\n\
 4.继续第三步直到修改完成\r\n\
 5.选择是否保存\r\n\
 6.完成！\r\n\r\n\
四.我不想用了要停下怎么办：\r\n\
 1.确认你的电脑上没有与DWPT不相干的mshta.exe在运行\r\n\
 2.点击\"停止动态壁纸\"\r\n\
 3.点击确认并在弹出的框框选\"是\"，即可停止动态壁纸\r\n\r\n\
五.如何 设置\\修改 默认项的位置：\r\n\
 1.点击\"全局设置\"\r\n\
 2.点击\"编辑\"，选择你要设置为默认项的配置文件，点击确定即可\r\n\r\n\
六.我想要开机自启动动态壁纸怎么办：\r\n\
 1.请确保您已经设置了默认项，如果没有请看\"五\"\r\n\
 2.点击\"全局设置\"\r\n\
 3.选中\"开机自启动\"检查框即可\r\n\
","DWPT的打開方法很簡單，第一步：打開程式，不需要允許管理員許可權，本程式自0.0.7.2及以後就移除了管理員身份的需要\r\n\
一. 如何啟動動態桌面：\r\n\
1.點擊“創建設定檔按鈕\r\n\
2.選擇一個保存位置（記得輸入保存的檔案名稱）\r\n\
3.選擇你的一個視頻，記得點擊那個視頻一下讓它處於被選中狀態\r\n\
4.詢問你是否需要聲音，你可以點擊“是或者“否來禁用或啟用聲音\r\n\
5.到這裡，設定檔就創建完成了，你可以在接下來的點擊“是來立即使用這個設定檔，或者點擊“否把這個檔先放著\r\n\r\n\
二. 我上次創建了設定檔了，如何使用上次的配寘：\r\n\
1.點擊“打開設定檔按鈕\r\n\
2.選擇你上次創建的設定檔\r\n\
3.在彈出的問你是否繼續，這個時候請確定你是否有其它的和DWPT無關的mshta.exe行程正在使用，如果沒有就點“是，有的話就去看看重不重要，不重要的就關了，如果有重要的就先別開\r\n\r\n\
三. 我想修改設定檔的內容怎麼辦：\r\n\
1.點擊修改設定檔按鈕\r\n\
2.選擇你的設定檔\r\n\
3.進入到編輯頁面，這個時候你就可以開始修改了，可以點擊“是或“否來修改，“取消則是停止修改\r\n\
4.繼續第三步直到修改完成\r\n\
5.選擇是否保存\r\n\
6.完成！ \r\n\r\n\
四. 我不想用了要停下怎麼辦：\r\n\
1.確認你的電腦上沒有與DWPT不相干的mshta.exe正在使用\r\n\
2.點擊停止動態桌面\r\n\
3.點擊確認並在彈出的框框選是，即可停止動態桌面\r\n\r\n\
五. 如何設定\\修改默認項的位置：\r\n\
1.點擊全域設定\r\n\
2.點擊編輯，選擇你要設定為默認項的設定檔，點擊確定即可\r\n\r\n\
六. 我想要開機自啟動動態桌面怎麼辦：\r\n\
1.請確保您已經設定了默認項，如果沒有請看五\r\n\
2.點擊全域設定\r\n\
3.選中開機自啟動檢查框即可\r\n\
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
	"问题 & 回答：\n\r\
问：为什么你不用CLR创建窗口？\r\n\
答：因为要照顾一些装不上Visual C++运行库的特殊人群，就像She_Fa21（我朋友），如果不装VC会提示少dll，并且gcc编译的更小\r\n\r\n\
问：你创建出来的窗口和控件为什么都是Win11样式的且DPI不会有问题而我不行？\r\n\
答：这个问题我也想过，我从网上大量搜集资料且实践了很久才琢磨出这种方法，对于您的问题，我有以下解决方法：\r\n\
    对于控件是旧版的问题：\r\n\
        Visual Studio:请在前面加上以下代码：\r\n\
            #ifdef _UNICODE\r\n\
            #if defined _M_IX86\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #elif defined _M_X64\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #else\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #endif\r\n\
            #endif\r\n\
        Dev-C++:相对于Visual Studio来说，Dev的操作更简单，在 项目[P]->项目属性[O] 里面勾选上\"支持 Windows XP 主题\"即可\r\n\
    对于DPI显示不正确的问题：\r\n\
        微软相关文档：https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setprocessdpiaware/\r\n\
        Visual Studio:直接在程序起始的地方加上代码：SetProcessDPIAware();\r\n\
        Dev-C++:请在程序起始的地方加入以下代码：\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID);\r\n\
            SPDA SetProcessDPIAware;\r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\");\r\n\
            if(hModule){//异常处理\
                SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");//提示：SetProcessDPIAware函数是Windows Vista加入的\r\n\
                if(SetProcessDPIAware) SetProcessDPIAware();//非异常状态\r\n\
			}\r\n\
            //Dev-C++使用的GCC版本是4.9.2，新版的GCC已经添加了这个API\r\n\
    这样就解决啦！\r\n\
问：如果出现创建窗口失败、窗口类注册失败之类的该怎么办？\r\n\
答：请尝试重新下载本程序，如果还是不行，那我就没办法了\r\n\
问：为什么字体那么丑？\r\n\
答：我写代码时使用的字体为用户定义的字体，难看可能是因为某些字体并不支持中文，我是用CreateFontA来加载字体的，所以可以去看看微软开发文档里面的CreateFontA函数",
	"問題&回答：\n\r\
問：為什麼你不用CLR創建視窗？ \r\n\
答：因為要照顧一些裝不上Visual C++庫的特殊人群，就像She_Fa21（我朋友），如果不裝VC會提示少dll，並且gcc編譯的更小\r\n\r\n\
問：你創建出來的視窗和控制項為什麼都是Win11樣式的且DPI不會有問題而我不行？ \r\n\
答：這個問題我也想過，我從網上大量蒐集資料且實踐了很久才琢磨出這種方法，對於您的問題，我有以下解決方法：\r\n\
    對於控制項是舊版的問題：\r\n\
        Visual Studio:請在前面加上以下程式碼：\r\n\
            #ifdef _UNICODE\r\n\
            #if defined _M_IX86\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #elif defined _M_X64\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #else\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #endif\r\n\
            #endif\r\n\
        Dev-C++：相對於Visual Studio來說，Dev的操作更簡單，在項目[P]->項目内容[O]裡面勾選上支持Windows XP主題即可\r\n\
    對於DPI顯示不正確的問題：\r\n\
        微軟相關文檔： https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setprocessdpiaware/ \r\n\
        Visual Studio:直接在程式起始的地方加上程式碼：SetProcessDPIAware（）； \r\n\
        Dev-C++：請在程式起始的地方加入以下程式碼：\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID); \r\n\
            SPDA SetProcessDPIAware; \r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\"); \r\n\
            if（hModule）{//異常處理\r\n\
                SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");// 提示：SetProcessDPIAware函數是Windows Vista加入的\r\n\
                if(SetProcessDPIAware) SetProcessDPIAware();// 非异常狀態\r\n\
            }\r\n\
            //Dev-C++使用的GCC版本是4.9.2，新版的GCC已經添加了這個API\r\n\
        這樣就解决啦！ \r\n\
問：如果出現創建視窗失敗、視窗類注册失敗之類的該怎麼辦？ \r\n\
答：請嘗試重新下載本程式，如果還是不行，那我就沒辦法了\r\n\
問：為什麼字體那麼醜？ \r\n\
答：我寫程式碼時使用的字體為用戶定義的字體，難看可能是因為某些字體並不支援中文，我是用CreateFontA來加載字體的，所以可以去看看微軟開發檔案裡面的CreateFontA函數"},//85
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
	"关于DWPT：\r\n\
作者：Office-Excel\r\n\
参考视频（哔哩哔哩视频编号）：BV1HZ4y1978a，地址：https://www.bilibili.com/video/BV1HZ4y1978a/\r\n\
使用的代码编辑工具：Dev-C++ 使用的代码语言：C++ 用得最多的库：windows.h\r\n\
窗口创建：Windows API（不是资源文件里的对话框，因为我不会用）\r\n\
DWPT项目属性：\r\n\
    名称：DWPT（全称Dynamic Wallpaper Tools，翻译：动态壁纸工具）\r\n\
    项目开始日期：2024/04/21\r\n\
    项目目标：做一个纯净简单的动态壁纸工具\r\n\
    作者为什么要做这个破玩意：只是为了好玩随便写了几百多行的代码\r\n\
    dp文件结构：\r\n\
        如果你用记事本打开dp文件\r\n\
            你会发现第一个字符总是't'或者'f'，这代表了是否启用声音，f=不启用，t=启用\r\n\
            后面的则是视频的绝对路径，文本按理说应该是使用GBK编码存储的，所以支持中文\r\n\
\r\n\
    DWPT启动动态壁纸的原理：\r\n\
        1.读入文件\r\n\
        2.查看是否启用声音\r\n\
        3.将视频绝对路径存入VP（char数组）\r\n\
        4.拼接预设的文本并写入%temp%\\Temporary.hta文件\r\n\
        5.启动进程mshta.exe\r\n\
        6.向类名为Progman的窗口发送0x52C信号\r\n\
        7.找到第二个WorkerW窗口并隐藏它\r\n\
        8.将类名为Progman的窗口设置为mshta.exe窗口的父窗口\r\n\
        9.完成！\r\n\r\n\
作者的哔哩哔哩账号：Office-Excel（地址：https://space.bilibili.com/1439352366/）\r\n\
",
	"關於DWPT:\n\r\
作者：Office-Excel\r\n\
參攷視頻（嗶哩嗶哩視頻編號）：BV1HZ4y1978a，地址： https://www.bilibili.com/video/BV1HZ4y1978a/ \r\n\
使用的程式碼編輯工具：Dev-C++使用的程式碼語言：C++用得最多的庫：windows.h\r\n\
視窗創建：Windows API（不是資源檔裏的對話方塊，因為我不會用）\r\n\
DWPT項目内容：\r\n\
    名稱：DWPT（全稱Dynamic Wallpaper Tools，翻譯：動態桌面工具）\r\n\
    項目開始日期：2024/04/21\r\n\
    項目目標：做一個純淨簡單的動態桌面工具\r\n\
    作者為什麼要做這個破玩意：只是為了好玩隨便寫了幾百多行的程式碼\r\n\
    dp檔案結構：\r\n\
    如果你用記事本打開dp檔案\r\n\
    你會發現第一個字元總是't'或者'f'，這代表了是否啟用聲音，f=不啟用，t=啟用\r\n\
    後面的則是視頻的絕對路徑，文字按理說應該是使用GBK編碼存儲的，所以支援中文\r\n\
\r\n\
    DWPT啟動動態桌面的原理：\r\n\
        1.讀入檔案\r\n\
        2.查看是否啟用聲音\r\n\
        3.將視頻絕對路徑存入VP（char數組）\r\n\
        4.拼接預設的文字並寫入%temp%\\Temporary.hta檔案\r\n\
        5.啟動行程mshta.exe\r\n\
        6.向類名為Progman的視窗發送0x52C訊號\r\n\
        7.找到第二個WorkerW視窗並隱藏它\r\n\
        8.將類名為Progman的視窗設定為mshta.exe視窗的父視窗\r\n\
        9.完成！ \r\n\r\n\
作者的嗶哩嗶哩帳號：Office-Excel（地址： https://space.bilibili.com/1439352366/ ）\r\n\
"},//86
};*/
LPSTR MUIText[120][3];

char Path[114514],res[114514];
int LangID=IL_UNSET/*语言ID*/;
bool quietMode=false;//是否启用安静模式（在启动dp文件中） 
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
strcpy(MUIText[0][1],"新建配置文件");
MUIText[0][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[0][2],"新建設定檔");
MUIText[1][0]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[1][0],"Edit profile");
MUIText[1][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[1][1],"编辑配置文件");
MUIText[1][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[1][2],"編輯設定檔");
MUIText[2][0]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[2][0],"Apply profile");
MUIText[2][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[2][1],"应用配置文件");
MUIText[2][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[2][2],"應用設定檔");
MUIText[3][0]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[3][0],"Stop Wallpaper");
MUIText[3][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[3][1],"停止动态壁纸");
MUIText[3][2]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[3][2],"停止動態桌面");
MUIText[4][0]=(char*)calloc(129,sizeof(char));
strcpy(MUIText[4][0],"About Dynamic Wallpaper Tools");
MUIText[4][1]=(char*)calloc(127,sizeof(char));
strcpy(MUIText[4][1],"关于Dynamic Wallpaper Tools");
MUIText[4][2]=(char*)calloc(127,sizeof(char));
strcpy(MUIText[4][2],"關於Dynamic Wallpaper Tools");
MUIText[5][0]=(char*)calloc(245,sizeof(char));
strcpy(MUIText[5][0],"Unable to open the video display program \"mshta.exe\" (playing videos using a browser), please check if the program exists in the system directory");
MUIText[5][1]=(char*)calloc(183,sizeof(char));
strcpy(MUIText[5][1],"无法打开视频显示程序\"mshta.exe\"（使用浏览器播放视频），请检查系统目录下程序是否存在");
MUIText[5][2]=(char*)calloc(183,sizeof(char));
strcpy(MUIText[5][2],"無法打開視頻顯示程式\"mshta.exe\"（使用瀏覽器播放視頻），請檢查系統目錄下程式是否存在");
MUIText[6][0]=(char*)calloc(178,sizeof(char));
strcpy(MUIText[6][0],"Warning! This operation will close all windows under the class name \"Progman\"!");
MUIText[6][1]=(char*)calloc(159,sizeof(char));
strcpy(MUIText[6][1],"警告！此操作会关闭所有在类名为“Progman”的窗口下的所有窗口！");
MUIText[6][2]=(char*)calloc(158,sizeof(char));
strcpy(MUIText[6][2],"警告！ 此操作會關閉所有在類名為“Progman”的視窗下的所有視窗");
MUIText[7][0]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[7][0],"Video files (*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv)\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0All files (*.*) \0*.*\0\0",sizeof("Video files (*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv)\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0All files (*.*) \0*.*\0\0"));
MUIText[7][1]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[7][1],"视频文件（*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv）\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0所有文件（*.*）\0*.*\0\0",sizeof("视频文件（*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv）\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0所有文件（*.*）\0*.*\0\0"));
MUIText[7][2]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[7][2],"視頻檔案（*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv）\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0所有檔案（*.*）\0*.*\0\0",sizeof("視頻檔案（*.mp4 ,*.mov, *.m4v, *.mpg, *.mpeg, *.wmv）\0*.mp4;*.mov;*.m4v;*.mpg;*.mpeg;*.wmv\0所有檔案（*.*）\0*.*\0\0"));
MUIText[8][0]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[8][0],"Dynamic Wallpaper Configuration Files (.dp)\0*.dp\0\0",sizeof("Dynamic Wallpaper Configuration Files (.dp)\0*.dp\0\0"));
MUIText[8][1]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[8][1],"Dynamic Wallpaper配置文件（.dp）\0*.dp\0\0",sizeof("Dynamic Wallpaper配置文件（.dp）\0*.dp\0\0"));
MUIText[8][2]=(char*)calloc(1000,sizeof(char));
memcpy(MUIText[8][2],"Dynamic Wallpaper設定檔（.dp）\0*.dp\0\0",sizeof("Dynamic Wallpaper設定檔（.dp）\0*.dp\0\0"));
MUIText[9][0]=(char*)calloc(126,sizeof(char));
strcpy(MUIText[9][0],"Do you need to play sound?");
MUIText[9][1]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[9][1],"是否需要播放声音？");
MUIText[9][2]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[9][2],"是否需要播放聲音？");
MUIText[10][0]=(char*)calloc(344,sizeof(char));
strcpy(MUIText[10][0],"Programming: Office-Excel\r\nReference video by 偶尔有点小迷糊, video id: BV1HZ4y1978a (press to cancel to view original video)\r\nTools used: Dev-C++, Code language: C++\r\nProject start date: April 21, 2024\r\nVersion: 0.0.9.1\nTranslator: Baidu Translate");
MUIText[10][1]=(char*)calloc(282,sizeof(char));
strcpy(MUIText[10][1],"程序制作：Office-Excel\r\n参考视频 by 偶尔有点小迷糊，视频id：BV1HZ4y1978a（按下取消查看原视频）\r\n使用工具：Dev-C++，代码语言：C++\r\n项目开始日期：2024/04/21\r\n版本：0.0.9.1\r\n翻译器：百度翻译");
MUIText[10][2]=(char*)calloc(283,sizeof(char));
strcpy(MUIText[10][2],"程式製作：Office-Excel\r\n參攷視頻 by 偶尔有点小迷糊，視頻id:BV1HZ4y1978a（按下取消查看原視頻）\r\n使用工具：Dev-C++，程式碼語言：C++\r\n項目開始日期：2024/04/21\r\n版本：0.0.9.1\r\n翻譯器：百度翻譯");
MUIText[11][0]=(char*)calloc(174,sizeof(char));
strcpy(MUIText[11][0],"The configuration file operation is complete. Do you want to start it now?");
MUIText[11][1]=(char*)calloc(134,sizeof(char));
strcpy(MUIText[11][1],"配置文件操作完成，是否要马上启动？");
MUIText[11][2]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[11][2],"設定檔操作完成，是否要馬上啟動？");
MUIText[12][0]=(char*)calloc(231,sizeof(char));
strcpy(MUIText[12][0],"Please select the object you want to modify:Yes -> Modify video file pathNo -> Modify whether there is soundCancel -> Do nothing");
MUIText[12][1]=(char*)calloc(180,sizeof(char));
strcpy(MUIText[12][1],"请选择要修改的对象： 是->修改视频文件路径 否->修改是否有声音 取消->什么也不做");
MUIText[12][2]=(char*)calloc(177,sizeof(char));
strcpy(MUIText[12][2],"請選擇要修改的對象：是->修改視頻檔案路徑否->修改是否有聲音取消->什麼也不做");
MUIText[13][0]=(char*)calloc(117,sizeof(char));
strcpy(MUIText[13][0],"Wallplaper Config");
MUIText[13][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[13][1],"壁纸配置");
MUIText[13][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[13][2],"桌面配寘");
MUIText[14][0]=(char*)calloc(115,sizeof(char));
strcpy(MUIText[14][0],"Global settings");
MUIText[14][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[14][1],"全局设置");
MUIText[14][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[14][2],"全域設定");
MUIText[15][0]=(char*)calloc(123,sizeof(char));
strcpy(MUIText[15][0],"Self start upon startup");
MUIText[15][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[15][1],"开机自启动");
MUIText[15][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[15][2],"開機自啟動");
MUIText[16][0]=(char*)calloc(121,sizeof(char));
strcpy(MUIText[16][0],"Current default item:");
MUIText[16][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[16][1],"当前默认项：");
MUIText[16][2]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[16][2],"當前默認項：");
MUIText[17][0]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[17][0],"Edit");
MUIText[17][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[17][1],"编辑");
MUIText[17][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[17][2],"編輯");
MUIText[18][0]=(char*)calloc(129,sizeof(char));
strcpy(MUIText[18][0],"Registry modification failed!");
MUIText[18][1]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[18][1],"注册表修改失败！");
MUIText[18][2]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[18][2],"註冊表修改失敗！");
MUIText[19][0]=(char*)calloc(290,sizeof(char));
strcpy(MUIText[19][0],"Do you want to restart explorer.exe? This may result in a black screen for a while. If Win11 users set a right angle, it will turn back into a rounded corner. Please make a careful decision!");
MUIText[19][1]=(char*)calloc(193,sizeof(char));
strcpy(MUIText[19][1],"是否需要重启explorer.exe？这可能会黑屏一会儿，Win11用户如果设置了直角会变回圆角，请慎重决定！");
MUIText[19][2]=(char*)calloc(194,sizeof(char));
strcpy(MUIText[19][2],"是否需要重啓explorer.exe？ 這可能會黑屏一會兒，Win11用戶如果設定了直角會變回圓角，請慎重决定！");
MUIText[20][0]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[20][0],"Quit(&Q)");
MUIText[20][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[20][1],"退出（&Q）");
MUIText[20][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[20][2],"退出（&Q）");
MUIText[21][0]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[21][0],"Registry modification completed!");
MUIText[21][1]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[21][1],"注册表修改完成！");
MUIText[21][2]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[21][2],"註冊表修改完成！");
MUIText[22][0]=(char*)calloc(187,sizeof(char));
strcpy(MUIText[22][0],"Do you need to set this configuration item as the default (including startup default)：");
MUIText[22][1]=(char*)calloc(152,sizeof(char));
strcpy(MUIText[22][1],"是否需要将这个配置项设置为默认项（包括启动默认项）：");
MUIText[22][2]=(char*)calloc(152,sizeof(char));
strcpy(MUIText[22][2],"是否需要將這個配寘項設定為默認項（包括啟動默認項）：");
MUIText[23][0]=(char*)calloc(178,sizeof(char));
strcpy(MUIText[23][0],"explorer.exe has been restarted and completed, you can continue your work now!");
MUIText[23][1]=(char*)calloc(146,sizeof(char));
strcpy(MUIText[23][1],"explorer.exe已重启完成，您可以继续您的工作了！");
MUIText[23][2]=(char*)calloc(146,sizeof(char));
strcpy(MUIText[23][2],"explorer.exe已重啓完成，您可以繼續您的工作了！");
MUIText[24][0]=(char*)calloc(105,sizeof(char));
strcpy(MUIText[24][0],"Apply");
MUIText[24][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[24][1],"应用");
MUIText[24][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[24][2],"應用");
MUIText[25][0]=(char*)calloc(128,sizeof(char));
strcpy(MUIText[25][0],"Set as default configuration");
MUIText[25][1]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[25][1],"设置为默认配置");
MUIText[25][2]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[25][2],"設定為默認配寘");
MUIText[26][0]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[26][0],"Help(&H)");
MUIText[26][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[26][1],"帮助（&H）");
MUIText[26][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[26][2],"幫助（&H）");
MUIText[27][0]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[27][0],"Operation(&O)");
MUIText[27][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[27][1],"操作（&O）");
MUIText[27][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[27][2],"操作（&O）");
MUIText[28][0]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[28][0],"About(&A)");
MUIText[28][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[28][1],"关于（&A）");
MUIText[28][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[28][2],"關於（&A）");
MUIText[29][0]=(char*)calloc(125,sizeof(char));
strcpy(MUIText[29][0],"End dynamic wallpaper(&E)");
MUIText[29][1]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[29][1],"结束动态壁纸（&E）");
MUIText[29][2]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[29][2],"結束動態桌面（&E）");
MUIText[30][0]=(char*)calloc(115,sizeof(char));
strcpy(MUIText[30][0],"Open and...(&C)");
MUIText[30][1]=(char*)calloc(115,sizeof(char));
strcpy(MUIText[30][1],"打开并...（&C）");
MUIText[30][2]=(char*)calloc(115,sizeof(char));
strcpy(MUIText[30][2],"打開並...（&C）");
MUIText[31][0]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[31][0],"Open the default item and...(&D)");
MUIText[31][1]=(char*)calloc(121,sizeof(char));
strcpy(MUIText[31][1],"打开默认项并...（&D）");
MUIText[31][2]=(char*)calloc(121,sizeof(char));
strcpy(MUIText[31][2],"打開默認項並...（&D）");
MUIText[32][0]=(char*)calloc(164,sizeof(char));
strcpy(MUIText[32][0],"The program has already started, please do not execute it again!");
MUIText[32][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[32][1],"程序已经启动了，请不要再次执行！");
MUIText[32][2]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[32][2],"程式已經啟動了，請不要再次執行！");
MUIText[33][0]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[33][0],"The original value was: ");
MUIText[33][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[33][1],"原来的值为：");
MUIText[33][2]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[33][2],"原來的值為：");
MUIText[34][0]=(char*)calloc(126,sizeof(char));
strcpy(MUIText[34][0],"Do you want to modify it?");
MUIText[34][1]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[34][1],"是否要修改？");
MUIText[34][2]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[34][2],"是否要修改？");
MUIText[35][0]=(char*)calloc(115,sizeof(char));
strcpy(MUIText[35][0],"Please select: ");
MUIText[35][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[35][1],"请选择：");
MUIText[35][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[35][2],"請選擇：");
MUIText[36][0]=(char*)calloc(133,sizeof(char));
strcpy(MUIText[36][0],"The video path has been modified!");
MUIText[36][1]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[36][1],"视频路径已修改完成！");
MUIText[36][2]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[36][2],"視頻路徑已修改完成！");
MUIText[37][0]=(char*)calloc(155,sizeof(char));
strcpy(MUIText[37][0],"The modification of the video path has been canceled...");
MUIText[37][1]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[37][1],"已取消修改视频路径。。。");
MUIText[37][2]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[37][2],"已取消修改視頻路徑。。。");
MUIText[38][0]=(char*)calloc(170,sizeof(char));
strcpy(MUIText[38][0],"The original value for playing sound when using dynamic wallpapers is:");
MUIText[38][1]=(char*)calloc(140,sizeof(char));
strcpy(MUIText[38][1],"原来是否在使用动态壁纸时播放声音的值为：");
MUIText[38][2]=(char*)calloc(140,sizeof(char));
strcpy(MUIText[38][2],"原來是否在使用動態桌面時播放聲音的值為：");
MUIText[39][0]=(char*)calloc(103,sizeof(char));
strcpy(MUIText[39][0],"Yes");
MUIText[39][1]=(char*)calloc(102,sizeof(char));
strcpy(MUIText[39][1],"是");
MUIText[39][2]=(char*)calloc(102,sizeof(char));
strcpy(MUIText[39][2],"否");
MUIText[40][0]=(char*)calloc(102,sizeof(char));
strcpy(MUIText[40][0],"No");
MUIText[40][1]=(char*)calloc(102,sizeof(char));
strcpy(MUIText[40][1],"否");
MUIText[40][2]=(char*)calloc(102,sizeof(char));
strcpy(MUIText[40][2],"否");
MUIText[41][0]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[41][0],"Please select: ");
MUIText[41][1]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[41][1],"请选择：");
MUIText[41][2]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[41][2],"請選擇：");
MUIText[42][0]=(char*)calloc(138,sizeof(char));
strcpy(MUIText[42][0],"Do you want to save this modification?");
MUIText[42][1]=(char*)calloc(122,sizeof(char));
strcpy(MUIText[42][1],"是否要保存这次的修改？");
MUIText[42][2]=(char*)calloc(122,sizeof(char));
strcpy(MUIText[42][2],"是否要保存這次的修改？");
MUIText[43][0]=(char*)calloc(128,sizeof(char));
strcpy(MUIText[43][0],"Do you want to apply it now?");
MUIText[43][1]=(char*)calloc(117,sizeof(char));
strcpy(MUIText[43][1],"是否要立即应用： ");
MUIText[43][2]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[43][2],"是否要立即應用？");
MUIText[44][0]=(char*)calloc(121,sizeof(char));
strcpy(MUIText[44][0],"Shrink to system tray");
MUIText[44][1]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[44][1],"缩小到系统托盘");
MUIText[44][2]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[44][2],"縮小到系統託盤");
MUIText[45][0]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[45][0],"How to use it?");
MUIText[45][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[45][1],"如何使用？");
MUIText[45][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[45][2],"如何使用？");
MUIText[46][0]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[46][0],"Advanced Options");
MUIText[46][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[46][1],"高级选项");
MUIText[46][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[46][2],"高級選項");
MUIText[47][0]=(char*)calloc(103,sizeof(char));
strcpy(MUIText[47][0],"Set");
MUIText[47][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[47][1],"设置");
MUIText[47][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[47][2],"設置");
MUIText[48][0]=(char*)calloc(136,sizeof(char));
strcpy(MUIText[48][0],"Set any window as wallpaper (Unsafe)");
MUIText[48][1]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[48][1],"将任意窗口设置为壁纸（不安全）");
MUIText[48][2]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[48][2],"將任意視窗設定為桌面（不安全）");
MUIText[49][0]=(char*)calloc(117,sizeof(char));
strcpy(MUIText[49][0],"Title of Window: ");
MUIText[49][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[49][1],"窗口标题：");
MUIText[49][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[49][2],"視窗標題：");
MUIText[50][0]=(char*)calloc(122,sizeof(char));
strcpy(MUIText[50][0],"Class Name of Window: ");
MUIText[50][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[50][1],"窗口类名：");
MUIText[50][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[50][2],"視窗類名：");
MUIText[51][0]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[51][0],"Boss key:");
MUIText[51][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[51][1],"老板键：");
MUIText[51][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[51][2],"老闆鍵：");
MUIText[52][0]=(char*)calloc(107,sizeof(char));
strcpy(MUIText[52][0],"Histroy");
MUIText[52][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[52][1],"历史");
MUIText[52][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[52][2],"歷史");
MUIText[53][0]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[53][0],"Tools (&T)");
MUIText[53][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[53][1],"工具（&T）");
MUIText[53][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[53][2],"工具（&T）");
MUIText[54][0]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[54][0],"Open the WinWatcher tool");
MUIText[54][1]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[54][1],"打开WinWatcher工具");
MUIText[54][2]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[54][2],"打開WinWatcher工具");
MUIText[55][0]=(char*)calloc(188,sizeof(char));
strcpy(MUIText[55][0],"The path is invalid \\ The file does not exist, unable to start the dp configuration file");
MUIText[55][1]=(char*)calloc(141,sizeof(char));
strcpy(MUIText[55][1],"路径不合法\\文件不存在，无法启动dp配置文件");
MUIText[55][2]=(char*)calloc(139,sizeof(char));
strcpy(MUIText[55][2],"路徑不合法\\檔案不存在，無法啟動dp設定檔");
MUIText[56][0]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[56][0],"Generate GUID");
MUIText[56][1]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[56][1],"生成 GUID");
MUIText[56][2]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[56][2],"生成 GUID");
MUIText[57][0]=(char*)calloc(113,sizeof(char));
strcpy(MUIText[57][0],"Generate UUID");
MUIText[57][1]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[57][1],"生成 UUID");
MUIText[57][2]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[57][2],"生成 UUID");
MUIText[58][0]=(char*)calloc(109,sizeof(char));
strcpy(MUIText[58][0],"Fast Boot");
MUIText[58][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[58][1],"快速启动");
MUIText[58][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[58][2],"快速啟動");
MUIText[59][0]=(char*)calloc(138,sizeof(char));
strcpy(MUIText[59][0],"Error: The target video does not exist");
MUIText[59][1]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[59][1],"错误：目标视频不存在");
MUIText[59][2]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[59][2],"錯誤：目標視頻不存在");
MUIText[60][0]=(char*)calloc(114,sizeof(char));
strcpy(MUIText[60][0],"Mute and start");
MUIText[60][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[60][1],"静音并启动");
MUIText[60][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[60][2],"靜音並啟動");
MUIText[61][0]=(char*)calloc(121,sizeof(char));
strcpy(MUIText[61][0],"Do not mute and start");
MUIText[61][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[61][1],"不静音并启动");
MUIText[61][2]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[61][2],"不靜音並啟動");
MUIText[62][0]=(char*)calloc(139,sizeof(char));
strcpy(MUIText[62][0],"Video Path: \r\n\
\r\n\
Supports: \r\n\
Local Video");
MUIText[62][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[62][1],"视频路径：\r\n\
\r\n\
支持项：\r\n\
本地视频");
MUIText[62][2]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[62][2],"視頻路徑：\r\n\
\r\n\
支持項：\r\n\
本地視頻");
MUIText[63][0]=(char*)calloc(106,sizeof(char));
strcpy(MUIText[63][0],"Launch");
MUIText[63][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[63][1],"启动");
MUIText[63][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[63][2],"啟動");
MUIText[64][0]=(char*)calloc(153,sizeof(char));
strcpy(MUIText[64][0],"Save a configuration file to save wallpaper settings.");
MUIText[64][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[64][1],"保存一个配置文件以保存壁纸设置。");
MUIText[64][2]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[64][2],"保存一個設定檔以保存桌面設定。");
MUIText[65][0]=(char*)calloc(157,sizeof(char));
strcpy(MUIText[65][0],"Modify a configuration file to change wallpaper settings.");
MUIText[65][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[65][1],"修改一个配置文件以更改壁纸设置。");
MUIText[65][2]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[65][2],"修改一個設定檔以更改桌面設定。");
MUIText[66][0]=(char*)calloc(153,sizeof(char));
strcpy(MUIText[66][0],"Open a configuration file to start dynamic wallpaper.");
MUIText[66][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[66][1],"打开一个配置文件以启动动态壁纸。");
MUIText[66][2]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[66][2],"打開一個設定檔以啟動動態桌面。");
MUIText[67][0]=(char*)calloc(166,sizeof(char));
strcpy(MUIText[67][0],"Close all windows created by mshta.exe to stop dynamic wallpapers.");
MUIText[67][1]=(char*)calloc(143,sizeof(char));
strcpy(MUIText[67][1],"关闭所有mshta.exe创建的窗口以停止动态壁纸。");
MUIText[67][2]=(char*)calloc(143,sizeof(char));
strcpy(MUIText[67][2],"關閉所有mshta.exe創建的視窗以停止動態桌面。");
MUIText[68][0]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[68][0],"Open 'About'");
MUIText[68][1]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[68][1],"打开“关于");
MUIText[68][2]=(char*)calloc(110,sizeof(char));
strcpy(MUIText[68][2],"打開“關於");
MUIText[69][0]=(char*)calloc(116,sizeof(char));
strcpy(MUIText[69][0],"Set Default Font");
MUIText[69][1]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[69][1],"设置默认字体");
MUIText[69][2]=(char*)calloc(112,sizeof(char));
strcpy(MUIText[69][2],"設定預設字體");
MUIText[70][0]=(char*)calloc(135,sizeof(char));
strcpy(MUIText[70][0],"Font setting completed, font name: ");
MUIText[70][1]=(char*)calloc(126,sizeof(char));
strcpy(MUIText[70][1],"字体已设置完成，字体名称：");
MUIText[70][2]=(char*)calloc(126,sizeof(char));
strcpy(MUIText[70][2],"字體已設定完成，字體名稱：");
MUIText[71][0]=(char*)calloc(158,sizeof(char));
strcpy(MUIText[71][0],". After restarting the program, the font will take effect!");
MUIText[71][1]=(char*)calloc(128,sizeof(char));
strcpy(MUIText[71][1],"，重新启动程序后字体将生效！");
MUIText[71][2]=(char*)calloc(128,sizeof(char));
strcpy(MUIText[71][2],"，重新啟動程式後字體將生效！");
MUIText[72][0]=(char*)calloc(203,sizeof(char));
strcpy(MUIText[72][0],"Please select a font to continue initialization. If you want to try again, please restart this program.");
MUIText[72][1]=(char*)calloc(160,sizeof(char));
strcpy(MUIText[72][1],"请选择一个字体以继续初始化，如果您要重试，请重新启动本程序。");
MUIText[72][2]=(char*)calloc(160,sizeof(char));
strcpy(MUIText[72][2],"請選擇一個字體以繼續初始化，如果您要重試，請重新啟動本程式。");
MUIText[73][0]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[73][0],"Language");
MUIText[73][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[73][1],"语言");
MUIText[73][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[73][2],"語言");
MUIText[74][0]=(char*)calloc(107,sizeof(char));
strcpy(MUIText[74][0],"English");
MUIText[74][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[74][1],"英语");
MUIText[74][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[74][2],"英語");
MUIText[75][0]=(char*)calloc(118,sizeof(char));
strcpy(MUIText[75][0],"Chinese Simplified");
MUIText[75][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[75][1],"简体中文");
MUIText[75][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[75][2],"簡體中文");
MUIText[76][0]=(char*)calloc(119,sizeof(char));
strcpy(MUIText[76][0],"Chinese Traditional");
MUIText[76][1]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[76][1],"繁体中文");
MUIText[76][2]=(char*)calloc(108,sizeof(char));
strcpy(MUIText[76][2],"繁體中文");
MUIText[77][0]=(char*)calloc(180,sizeof(char));
strcpy(MUIText[77][0],"The language has been updated and will take effect after restarting the program!");
MUIText[77][1]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[77][1],"语言已更新，重启程序后将生效！");
MUIText[77][2]=(char*)calloc(130,sizeof(char));
strcpy(MUIText[77][2],"語言已更新，重啓程式後將生效！");
MUIText[78][0]=(char*)calloc(153,sizeof(char));
strcpy(MUIText[78][0],"The program has been started. Please don't run again!");
MUIText[78][1]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[78][1],"程序已启动完成，请不要二次运行！");
MUIText[78][2]=(char*)calloc(132,sizeof(char));
strcpy(MUIText[78][2],"程式已啟動完成，請不要二次啟動！");
MUIText[79][0]=(char*)calloc(105,sizeof(char));
strcpy(MUIText[79][0],"Close");
MUIText[79][1]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[79][1],"关闭");
MUIText[79][2]=(char*)calloc(104,sizeof(char));
strcpy(MUIText[79][2],"關閉");
MUIText[80][0]=(char*)calloc(154,sizeof(char));
strcpy(MUIText[80][0],"The dynamic wallpaper has been launched and completed!");
MUIText[80][1]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[80][1],"动态壁纸已启动完成！");
MUIText[80][2]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[80][2],"動態桌面已啟動完成！");
MUIText[81][0]=(char*)calloc(146,sizeof(char));
strcpy(MUIText[81][0],"Explorer.exe has been restarted and completed!");
MUIText[81][1]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[81][1],"Explorer.exe已重启完成！");
MUIText[81][2]=(char*)calloc(124,sizeof(char));
strcpy(MUIText[81][2],"Explorer.exe已重啓完成！");
MUIText[82][0]=(char*)calloc(135,sizeof(char));
strcpy(MUIText[82][0],"Start dynamic wallpaper at startup.");
MUIText[82][1]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[82][1],"启动时启动动态壁纸。");
MUIText[82][2]=(char*)calloc(120,sizeof(char));
strcpy(MUIText[82][2],"啟動時啟動動態桌面。");
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
strcpy(MUIText[83][1],"DWPT的优点：\r\n\
1.轻便\r\n\
    DWPT在Windows7及上的版本中除了WinAPI的库和HelpDWPT.dll（DWPT帮助库）、WallpaperCore.dll（壁纸核心库），不需要其他杂 七杂八的库，且DWPT主程序不到1Mib（不包括安装程序和卸载程序），比你用iostream库写一个Hello World编译出来的程序还小，并且 不依赖Visual C++运行库\r\n\
2.界面简洁\r\n\
    DWPT的用户界面没有任何的广告，也不会让你的电脑变慢变卡，不需要时还可以将程序图标隐藏到系统托盘中，十分人性化\r\n\
\r\n\
3.更好的支持性\r\n\
    DWPT的视频播放工具是mshta.exe（Microsoft HTML应用程序），不要质疑为什么我要用这个（因为我不会写播放器），而不用ffplay.exe的原因是ffplay.exe确实是太大了，100多MiB，比主程序还要大，并且我选的是32位编译，所以32位的Windows也能用\r\n\
\r\n\
所以，如果你要选择一款轻便、简单、无广告的动态壁纸软件，就选DWPT吧！ ");
MUIText[83][2]=(char*)calloc(832,sizeof(char));
strcpy(MUIText[83][2],"DWPT的優點：\r\n\
1.輕便\r\n\
    DWPT在Windows7及上的版本中除了WinAPI的庫和HelpDWPT.dll（DWPT幫助庫）、WallpaperCore.dll（桌面覈心庫），不需要其他雜 七雜八的庫，且DWPT主程序不到1Mib（不包括安裝程式和卸載程式），比你用iostream庫寫一個Hello World編譯出來的程式還小，並且 不依賴Visual C++庫\r\n\
2.介面簡潔\r\n\
    DWPT的使用者介面沒有任何的廣告，也不會讓你的電腦變慢變卡，不需要時還可以將程式圖標隱藏到系統託盤中，十分人性化\r\n\
\r\n\
3.更好的支持性\r\n\
    DWPT的視頻播放工具是mshta.exe（Microsoft HTML應用程序），不要質疑為什麼我要用這個（因為我不會寫播放機），而不用ffplay.exe的原因是ffplay.exe確實是太大了，100多MiB，比主程序還要大，並且我選的是32比特編譯，所以32比特的Windows也能用\r\n\
\r\n\
所以，如果你要選擇一款輕便、簡單、無廣告的動態桌面軟件，就選DWPT吧！\r\n\
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
strcpy(MUIText[84][1],"DWPT的打开方法很简单，第一步：打开程序，不需要允许管理员权限，本程序自0.0.7.2及以后就移除了管理员身份的需要\r\n\
一.如何启动动态壁纸：\r\n\
 1.点击\"创建配置文件\"按钮\r\n\
 2.选择一个保存位置（记得输入保存的文件名称）\r\n\
 3.选择你的一个视频，记得点击那个视频一下让它处于被选中状态\r\n\
 4.询问你是否需要声音，你可以点击\"是\"或者\"否\"来禁用或启用声音\r\n\
 5.到这里，配置文件就创建完成了，你可以在接下来的点击\"是\"来立即使用这个配置文件，或者点击\"否\"把这个文件先放着\r\n\
\r\n\
二.我上次创建了配置文件了，如何使用上次的配置：\r\n\
 1.点击\"打开配置文件\"按钮\r\n\
 2.选择你上次创建的配置文件\r\n\
 3.在弹出的问你是否继续，这个时候请确定你是否有其它的和DWPT无关的mshta.exe进程在运行，如果没有就点\"是\"，有的话就去看看重不重要，不重要的就关了，如果有重要的就先别开\r\n\
\r\n\
三.我想修改配置文件的内容怎么办：\r\n\
 1.点击\"修改配置文件\"按钮\r\n\
 2.选择你的配置文件\r\n\
 3.进入到编辑页面，这个时候你就可以开始修改了，可以点击\"是\"或\"否\"来修改，\"取消\"则是停止修改\r\n\
 4.继续第三步直到修改完成\r\n\
 5.选择是否保存\r\n\
 6.完成！\r\n\
\r\n\
四.我不想用了要停下怎么办：\r\n\
 1.确认你的电脑上没有与DWPT不相干的mshta.exe在运行\r\n\
 2.点击\"停止动态壁纸\"\r\n\
 3.点击确认并在弹出的框框选\"是\"，即可停止动态壁纸\r\n\
\r\n\
五.如何 设置\\修改 默认项的位置：\r\n\
 1.点击\"全局设置\"\r\n\
 2.点击\"编辑\"，选择你要设置为默认项的配置文件，点击确定即可\r\n\
\r\n\
六.我想要开机自启动动态壁纸怎么办：\r\n\
 1.请确保您已经设置了默认项，如果没有请看\"五\"\r\n\
 2.点击\"全局设置\"\r\n\
 3.选中\"开机自启动\"检查框即可\r\n\
");
MUIText[84][2]=(char*)calloc(1407,sizeof(char));
strcpy(MUIText[84][2],"DWPT的打開方法很簡單，第一步：打開程式，不需要允許管理員許可權，本程式自0.0.7.2及以後就移除了管理員身份的需要\r\n\
一. 如何啟動動態桌面：\r\n\
1.點擊“創建設定檔按鈕\r\n\
2.選擇一個保存位置（記得輸入保存的檔案名稱）\r\n\
3.選擇你的一個視頻，記得點擊那個視頻一下讓它處於被選中狀態\r\n\
4.詢問你是否需要聲音，你可以點擊“是或者“否來禁用或啟用聲音\r\n\
5.到這裡，設定檔就創建完成了，你可以在接下來的點擊“是來立即使用這個設定檔，或者點擊“否把這個檔先放著\r\n\
\r\n\
二. 我上次創建了設定檔了，如何使用上次的配寘：\r\n\
1.點擊“打開設定檔按鈕\r\n\
2.選擇你上次創建的設定檔\r\n\
3.在彈出的問你是否繼續，這個時候請確定你是否有其它的和DWPT無關的mshta.exe行程正在使用，如果沒有就點“是，有的話就去看看 重不重要，不重要的就關了，如果有重要的就先別開\r\n\
\r\n\
三. 我想修改設定檔的內容怎麼辦：\r\n\
1.點擊修改設定檔按鈕\r\n\
2.選擇你的設定檔\r\n\
3.進入到編輯頁面，這個時候你就可以開始修改了，可以點擊“是或“否來修改，“取消則是停止修改\r\n\
4.繼續第三步直到修改完成\r\n\
5.選擇是否保存\r\n\
6.完成！ \r\n\
\r\n\
四. 我不想用了要停下怎麼辦：\r\n\
1.確認你的電腦上沒有與DWPT不相干的mshta.exe正在使用\r\n\
2.點擊停止動態桌面\r\n\
3.點擊確認並在彈出的框框選是，即可停止動態桌面\r\n\
\r\n\
五. 如何設定\\修改默認項的位置：\r\n\
1.點擊全域設定\r\n\
2.點擊編輯，選擇你要設定為默認項的設定檔，點擊確定即可\r\n\
\r\n\
六. 我想要開機自啟動動態桌面怎麼辦：\r\n\
1.請確保您已經設定了默認項，如果沒有請看五\r\n\
2.點擊全域設定\r\n\
3.選中開機自啟動檢查框即可\r\n\
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
strcpy(MUIText[85][1],"问题 & 回答：\r\n\
问：为什么你不用CLR创建窗口？\r\n\
答：因为要照顾一些装不上Visual C++运行库的特殊人群，就像She_Fa21（我朋友），如果不装VC会提示少dll，并且gcc编译的更小\r\n\
\r\n\
问：你创建出来的窗口和控件为什么都是Win11样式的且DPI不会有问题而我不行？\r\n\
答：这个问题我也想过，我从网上大量搜集资料且实践了很久才琢磨出这种方法，对于您的问题，我有以下解决方法：\r\n\
    对于控件是旧版的问题：\r\n\
        Visual Studio:请在前面加上以下代码：\r\n\
            #ifdef _UNICODE\r\n\
            #if defined _M_IX86\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #elif defined _M_X64\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #else\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #endif\r\n\
            #endif\r\n\
        Dev-C++:相对于Visual Studio来说，Dev的操作更简单，在 项目[P]->项目属性[O] 里面勾选上\"支持 Windows XP 主题\"即可\r\n\
    对于DPI显示不正确的问题：\r\n\
        微软相关文档：https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setprocessdpiaware/\r\n\
        Visual Studio:直接在程序起始的地方加上代码：SetProcessDPIAware();\r\n\
        Dev-C++:请在程序起始的地方加入以下代码：\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID);\r\n\
            SPDA SetProcessDPIAware;\r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\");\r\n\
            if(hModule){//异常处理                SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");//提示：SetProcessDPIAware函数是Windows Vista加入的\r\n\
                if(SetProcessDPIAware) SetProcessDPIAware();//非异常状态\r\n\
                        }\r\n\
            //Dev-C++使用的GCC版本是4.9.2，新版的GCC已经添加了这个API\r\n\
    这样就解决啦！\r\n\
问：如果出现创建窗口失败、窗口类注册失败之类的该怎么办？\r\n\
答：请尝试重新下载本程序，如果还是不行，那我就没办法了\r\n\
问：为什么字体那么丑？\r\n\
答：我写代码时使用的字体为用户定义的字体，难看可能是因为某些字体并不支持中文，我是用CreateFontA来加载字体的，所以可以去 看看微软开发文档里面的CreateFontA函数");
MUIText[85][2]=(char*)calloc(2514,sizeof(char));
strcpy(MUIText[85][2],"問題&回答：\r\n\
問：為什麼你不用CLR創建視窗？ \r\n\
答：因為要照顧一些裝不上Visual C++庫的特殊人群，就像She_Fa21（我朋友），如果不裝VC會提示少dll，並且gcc編譯的更小\r\n\
\r\n\
問：你創建出來的視窗和控制項為什麼都是Win11樣式的且DPI不會有問題而我不行？ \r\n\
答：這個問題我也想過，我從網上大量蒐集資料且實踐了很久才琢磨出這種方法，對於您的問題，我有以下解決方法：\r\n\
    對於控制項是舊版的問題：\r\n\
        Visual Studio:請在前面加上以下程式碼：\r\n\
            #ifdef _UNICODE\r\n\
            #if defined _M_IX86\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='x86' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #elif defined _M_X64\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='amd64' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #else\r\n\
            #pragma comment(linker,\"/manifestdependency:\\\"type='win32' name='Microsoft.Windows.Common-Controls' version='6.0.0.0' processorArchitecture='*' publicKeyToken='6595b64144ccf1df' language='*'\\\"\")\r\n\
            #endif\r\n\
            #endif\r\n\
        Dev-C++：相對於Visual Studio來說，Dev的操作更簡單，在項目[P]->項目内容[O]裡面勾選上支持Windows XP主題即可\r\n\
    對於DPI顯示不正確的問題：\r\n\
        微軟相關文檔： https://learn.microsoft.com/zh-cn/windows/win32/api/winuser/nf-winuser-setprocessdpiaware/ \r\n\
        Visual Studio:直接在程式起始的地方加上程式碼：SetProcessDPIAware（）； \r\n\
        Dev-C++：請在程式起始的地方加入以下程式碼：\r\n\
            typedef BOOL WINAPI (*SPDA)(VOID); \r\n\
            SPDA SetProcessDPIAware; \r\n\
            HMODULE hModule = LoadLibrary(\"user32.dll\"); \r\n\
            if（hModule）{//異常處理\r\n\
                SetProcessDPIAware = (SPDA)GetProcAddress(hModule,\"SetProcessDPIAware\");// 提示：SetProcessDPIAware函 數是Windows Vista加入的\r\n\
                if(SetProcessDPIAware) SetProcessDPIAware();// 非异常狀態\r\n\
            }\r\n\
            //Dev-C++使用的GCC版本是4.9.2，新版的GCC已經添加了這個API\r\n\
        這樣就解决啦！ \r\n\
問：如果出現創建視窗失敗、視窗類注册失敗之類的該怎麼辦？ \r\n\
答：請嘗試重新下載本程式，如果還是不行，那我就沒辦法了\r\n\
問：為什麼字體那麼醜？ \r\n\
答：我寫程式碼時使用的字體為用戶定義的字體，難看可能是因為某些字體並不支援中文，我是用CreateFontA來加載字體的，所以可以 去看看微軟開發檔案裡面的CreateFontA函數");
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
strcpy(MUIText[86][1],"关于DWPT：\r\n\
作者：Office-Excel\r\n\
参考视频（哔哩哔哩视频编号）：BV1HZ4y1978a，地址：https://www.bilibili.com/video/BV1HZ4y1978a/\r\n\
使用的代码编辑工具：Dev-C++ 使用的代码语言：C++ 用得最多的库：windows.h\r\n\
窗口创建：Windows API（不是资源文件里的对话框，因为我不会用）\r\n\
DWPT项目属性：\r\n\
    名称：DWPT（全称Dynamic Wallpaper Tools，翻译：动态壁纸工具）\r\n\
    项目开始日期：2024/04/21\r\n\
    项目目标：做一个纯净简单的动态壁纸工具\r\n\
    作者为什么要做这个破玩意：只是为了好玩随便写了几百多行的代码\r\n\
    dp文件结构：\r\n\
        如果你用记事本打开dp文件\r\n\
            你会发现第一个字符总是't'或者'f'，这代表了是否启用声音，f=不启用，t=启用\r\n\
            后面的则是视频的绝对路径，文本按理说应该是使用GBK编码存储的，所以支持中文\r\n\
\r\n\
    DWPT启动动态壁纸的原理：\r\n\
        1.读入文件\r\n\
        2.查看是否启用声音\r\n\
        3.将视频绝对路径存入VP（char数组）\r\n\
        4.拼接预设的文本并写入%temp%\\Temporary.hta文件\r\n\
        5.启动进程mshta.exe\r\n\
        6.向类名为Progman的窗口发送0x52C信号\r\n\
        7.找到第二个WorkerW窗口并隐藏它\r\n\
        8.将类名为Progman的窗口设置为mshta.exe窗口的父窗口\r\n\
        9.完成！\r\n\
\r\n\
作者的哔哩哔哩账号：Office-Excel（地址：https://space.bilibili.com/1439352366/）\r\n\
");
MUIText[86][2]=(char*)calloc(1258,sizeof(char));
strcpy(MUIText[86][2],"關於DWPT:\r\n\
作者：Office-Excel\r\n\
參攷視頻（嗶哩嗶哩視頻編號）：BV1HZ4y1978a，地址： https://www.bilibili.com/video/BV1HZ4y1978a/ \r\n\
使用的程式碼編輯工具：Dev-C++使用的程式碼語言：C++用得最多的庫：windows.h\r\n\
視窗創建：Windows API（不是資源檔裏的對話方塊，因為我不會用）\r\n\
DWPT項目内容：\r\n\
    名稱：DWPT（全稱Dynamic Wallpaper Tools，翻譯：動態桌面工具）\r\n\
    項目開始日期：2024/04/21\r\n\
    項目目標：做一個純淨簡單的動態桌面工具\r\n\
    作者為什麼要做這個破玩意：只是為了好玩隨便寫了幾百多行的程式碼\r\n\
    dp檔案結構：\r\n\
    如果你用記事本打開dp檔案\r\n\
    你會發現第一個字元總是't'或者'f'，這代表了是否啟用聲音，f=不啟用，t=啟用\r\n\
    後面的則是視頻的絕對路徑，文字按理說應該是使用GBK編碼存儲的，所以支援中文\r\n\
\r\n\
    DWPT啟動動態桌面的原理：\r\n\
        1.讀入檔案\r\n\
        2.查看是否啟用聲音\r\n\
        3.將視頻絕對路徑存入VP（char數組）\r\n\
        4.拼接預設的文字並寫入%temp%\\Temporary.hta檔案\r\n\
        5.啟動行程mshta.exe\r\n\
        6.向類名為Progman的視窗發送0x52C訊號\r\n\
        7.找到第二個WorkerW視窗並隱藏它\r\n\
        8.將類名為Progman的視窗設定為mshta.exe視窗的父視窗\r\n\
        9.完成！ \r\n\
\r\n\
作者的嗶哩嗶哩帳號：Office-Excel（地址： https://space.bilibili.com/1439352366/ ）\r\n\
");
		MUIText[88][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[88][0],"WHY CHOOSE US");
		MUIText[88][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[88][1],"为什么选择我们");
		MUIText[88][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[88][2],"為什麼選擇我們");
		
		MUIText[89][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[89][0],"HOW TO USE");
		MUIText[89][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[89][1],"如何使用");
		MUIText[89][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[89][2],"如何使用");
		
		MUIText[90][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[90][0],"Q && A");
		MUIText[90][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[90][1],"问题 && 回答");
		MUIText[90][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[90][2],"問題 && 回答");
		
		MUIText[91][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[91][0],"ABOUT DWPT");
		MUIText[91][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[91][1],"关于 DWPT");
		MUIText[91][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[91][2],"關於 DWPT");
		
		MUIText[92][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[92][0],"AUTHOR's HOMEPAGE");
		MUIText[92][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[92][1],"作者主页");
		MUIText[92][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[92][2],"作者主頁");
		
		MUIText[93][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[93][0],"REFERENCE VIDEO");
		MUIText[93][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[93][1],"参考视频");
		MUIText[93][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[93][2],"參攷視頻");
		
		MUIText[94][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[94][0],"CLOSE");
		MUIText[94][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[94][1],"关闭");
		MUIText[94][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[94][2],"關閉");
		
		MUIText[95][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[95][0],"Save");
		MUIText[95][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[95][1],"保存");
		MUIText[95][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[95][2],"保存");
		
		MUIText[96][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[96][0],"Only save");
		MUIText[96][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[96][1],"仅保存");
		MUIText[96][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[96][2],"僅保存");
		
		MUIText[97][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[97][0],"Save and start.");
		MUIText[97][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[97][1],"保存并启动");
		MUIText[97][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[97][2],"保存並啟動");
		
		MUIText[98][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[98][0],"Play sound.");
		MUIText[98][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[98][1],"播放音乐。");
		MUIText[98][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[98][2],"播放音樂。");
		
		MUIText[99][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[99][0],"Video Path:\r\n\r\nThere are some environment variable you can use: ");
		MUIText[99][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[99][1],"视频路径：\r\n\r\n您可以使用以下环境变量：");
		MUIText[99][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[99][2],"視頻路徑：\r\n\r\n您可以使用以下環境變數：");
		
		MUIText[100][0]=(char*)calloc(105,sizeof(char));
		strcpy(MUIText[100][0],"View all");
		MUIText[100][1]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[100][1],"查看所有");
		MUIText[100][2]=(char*)calloc(104,sizeof(char));
		strcpy(MUIText[100][2],"查看所有");
		
		MUIText[101][0]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[101][0],"The last edited configuration file has not been saved yet! Do you need to save the last edited configuration file or continue editing the unsaved configuration file?");
		MUIText[101][1]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[101][1],"上一次编辑的配置文件还未保存！是否需要保存上一次编辑的配置文件或继续编辑未保存的配置文件？");
		MUIText[101][2]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[101][2],"上一次編輯的設定檔還未保存！ 是否需要保存上一次編輯的設定檔或繼續編輯未保存的設定檔？");
		
		MUIText[102][0]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[102][0],"Video location variable:\r\n - ${dp} = Directory where the profile is located.\r\n - ${pp} = The path of this program.\r\n - .. = The last directory.\r\n - ${System environment variable name} = The variable from system.\r\n\r\nExample:\r\n${SystemRoot}\\1.mp4\r\nAfter parsing is completed, it is: C:\\WINDOWS\\1.mp4");
		MUIText[102][1]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[102][1],"视频位置环境变量：\r\n - ${dp} = 配置文件所在的目录。\r\n - ${pp} = 此程序的路径。\r\n - …=上一个目录。\r\n - ${系统环境变量名} = 系统中的环境变量。\r\n\r\n例如：\r\n${SystemRoot}\\1.mp4\r\n解析完成后是：C:\\WINDOWS\\1.mp4");
		MUIText[102][2]=(char*)calloc(1000,sizeof(char));
		strcpy(MUIText[102][2],"視頻位置環境變數：\r\n - ${dp} = 設定檔所在的目錄。 \r\n - ${pp} = 此程式的路徑。 \r\n - …=上一個目錄。 \r\n - ${系統環境變數名} = 系統中的環境變數。 \r\n\r\n例如：\r\n${SystemRoot}\\1.mp4\r\n解析完成後是：C:\\WINDOWS\\1.mp4");
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
			switch(PRIMARYLANGID(GetUserDefaultLangID())){//获取语言ID并设置当前语言 
				case LANG_CHINESE_SIMPLIFIED:LangID=IL_Simplified_Chinese;break;
				case LANG_CHINESE_TRADITIONAL:LangID=IL_Traditional_Chinese;break;
				default:LangID=IL_ENGLISH;break;
			}
		}
		return (char*)MUIText[index][LangID];
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
			MessageBox(Wallpaper,"SetParent function run failed!","Error",MB_ICONINFORMATION|MB_OK);
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
		char cmd[1145]=" \"",/*sound,*/VP[1145],TmpPath[MAX_PATH+20],str1[MAX_PATH*4];//初始化一堆文本 
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
		/*
		DWORD dw=0;
		HANDLE hFile=CreateFile(Path, GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);//打开文件句柄 
		ReadFile(hFile,&sound,1,&dw,NULL);
		ReadFile(hFile,VP,GetFileSize(hFile,NULL)-1,&dw,NULL);*/
		bool sound;
		SolvePath(Path,VP,&sound);
		int i=strlen(VP);
		while(!(VP[i]<='Z'&&VP[i]>='A'||VP[i]<='z'&&VP[i]>='a'||VP[i]<='9'&&VP[i]>='0')) VP[i]=NULL,i--;//读入文件的数据 
		//MessageBox(NULL,VP,NULL,NULL);
		
		//使用mshta.exe播放
		GetTempPath(MAX_PATH,TmpPath);//获取临时目录并创建Temporary.hta临时文件 
		strcat(TmpPath,"Temporary.hta");
		if(TmpPath[strlen(TmpPath)-1]=='\r') TmpPath[strlen(TmpPath)-1]=NULL;
		freopen(TmpPath,"w",stdout);
		while(_access(VP,0)==-1) VP[strlen(VP)-1]=NULL;
		printf("%s%s><source src=\"%s",str1,(sound?"":" muted"),VP);
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
