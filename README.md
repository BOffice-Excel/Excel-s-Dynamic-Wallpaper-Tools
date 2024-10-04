[Jump to English](https://github.com/BOffice-Excel/Excel-s-Dynamic-Wallpaper-Tools?tab=readme-ov-file#English)
# 中文
> 如有疑惑\建议，请转到[Issues](https://github.com/BOffice-Excel/Excel-s-Dynamic-Wallpaper-Tools/issues)提交
> 
> 如要下载，请打开[Release](https://github.com/BOffice-Excel/Excel-s-Dynamic-Wallpaper-Tools/releases)

# Office-Excel的动态壁纸工具
> 介绍：这是一个用C++写的动态壁纸工具，目前已经可以开始使用了
> 特别感谢 哔哩哔哩up主<a href="https://space.bilibili.com/39665558/">@偶尔有点小迷糊</a>（Uid39665558），参考项目：https://github.com/3150601355/VideoWallPaperDemo
> 
> 编译环境：Windows 11 IDE：Dev-C++ 编译器：TDM-GCC 4.9.2 32-bit Release 可以放到更高的版本中编译，但是没必要，4.9.2就够了，编译时不需要做任何事情，我已经配置好了链接库
>
> 现在有个非常好的一点，就是你可以通过包含WallpaperCore文件夹中的dll.h来制作你自己的动态壁纸工具了，记得链接库：libWallpaperCore.a
> 提示：打开代码时建议使用ANSI（GBK）来打开，不然那里面的注释基本都会乱码
>
> 注意事项：
> > 不建议使用Visual Studio编译，要改很多处地方，不然会报错，比如unsafe之类的  
> > 按理说能编译C++的都行，但是不建议，很可能会乱码或者报错  
> > 在旁边的Release中我已经有编译好的了，Windows 8 x86 ~ Windows 11 x64按理说都能用
> 
> 使用的头文件：stdio.h、io.h、windows.h、commctrl.h，就这些
> 可以自己去程序内的帮助看看

# 使用WallpaperCore.dll进行开发
> # 一、动态壁纸的原理（简略介绍）
> > # 1.动态壁纸的启动
> > > # 1-1.创建视频窗口
> > > > 在这里，我们使用[CreateProcessA函数](https://learn.microsoft.com/zh-cn/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa)创建进程，这里以mshta.exe作为视频播放工具示范（ffplay也可以）
> > > > 
> > > > 以下代码将会启动mshta.exe，不做其它的事情：
> > > > ```C++
> > > >   STARTUPINFOA sia,memset(&sia,0,sizeof(sia));//初始化信息结构体
> > > >   PROCESS_INFORMATIONA pia;memset(&pia,0,sizeof(pia));
> > > >   char mshtaPath[MAX_PATH+5];//在这里请尽量设大点
> > > >   GetSystemDirectory(mshtaPath,MAX_PATH);//获取系统（System32）目录，64位系统下32位程序会变成SysWOW64目录//MAX_PATH替换为你的数组长度-5（最好）
> > > >   if(mshtaPath[strlen(mshtaPath)-1]=='\\') strcat(mshtaPath,"mshta.exe");
> > > >   else strcat(mshtaPath,"\\mshta.exe");
> > > >   if(CreateProcess(mshtaPath,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&sia,&pia)!=0){
> > > >      //成功启动进程
> > > >   }
> > > >   else{
> > > >      //启动进程失败
> > > >   }
> > > > ```
> > > > 如果你成功编译了程序，你会发现什么也没有，这是因为我们没有为mshta.exe编写视频播放的HTA文件（HTML应用程序，与HTML的语法差不多），视频网页格式如下：
> > > > ```HTML
> > > >   <html>
> > > >     <META http-equiv="content-type" content="text/html; charset=GBK">
> > > >     <!--这里是设置让mshta.exe读取HTA文件时使用GBK编码（默认UTF-8），如果你是用的是Visual Studio，可以不写上面这一行（VS默认UTF-8）-->
> > > >     <meta http-equiv="x-ua-compatible" content="IE=9"/>
> > > >     <!--这里是设置mshta.exe的IE版本，IE=<版本号>，可填写"Edge"，mshta.exe默认的版本不支持Video标签-->
> > > >     <head>
> > > >       <title>VideoPlayer</title>
> > > >       <!--上面这一条实际用户也看不到，可以不写-->
> > > >       <HTA:APPLICATION APPLICATIONNAME="VideoPlayer"ID="VideoPlayer" BORDER="none" SHOWINTASKBAR="no" VERSION="0.0"/>
> > > >       <!--上面这一条设置无边框、不显示在任务栏、ID为VideoPlayer、版本为0.0、名称为VideoPlayer，版本、名称、ID可随意更改-->
> > > >     </head>
> > > >   	<body>
> > > >       <video style="width:100%;height:100%;left:0px;top:0px;position:fixed" autoplay loop[ muted]><source src="<这里填写视频的地址>" type="video/mp4">ERROR</video>
> > > >       <!--上面这一条播放视频，请合理替换内部信息，如果添加 muted则表示静音-->
> > > >     </body>
> > > >   </html>
> > > > ```
> > > > 现在可以打开你编辑好的hta文件，这样你就能看到一个无边框的视频窗口了（Alt+F4退出）
> > > > 接下来的代码为如何使用程序打开hta文件
> > > > ```C++
> > > >   STARTUPINFOA sia,memset(&sia,0,sizeof(sia));//初始化信息结构体
> > > >   PROCESS_INFORMATIONA pia;memset(&pia,0,sizeof(pia));
> > > >   char mshtaPath[MAX_PATH+5];//在这里请尽量设大点
> > > >   GetSystemDirectory(mshtaPath,MAX_PATH);//获取系统（System32）目录，64位系统下32位程序会变成SysWOW64目录//MAX_PATH替换为你的数组长度-5（最好）
> > > >   if(mshtaPath[strlen(mshtaPath)-1]=='\\') strcat(mshtaPath,"mshta.exe ");
> > > >   else strcat(mshtaPath,"\\mshta.exe ");
> > > >   if(CreateProcess(mshtaPath,<这里写你的hta文件路径，如果有特殊字符或符号要加引号>,NULL,NULL,NULL,NULL,NULL,NULL,&sia,&pia)!=0){
> > > >      //成功启动进程
> > > >   }
> > > >   else{
> > > >      //启动进程失败
> > > >   }
> > > > ```
> > > > 编译运行后你就可以看到程序打开了一个视频窗口了，这时你就已经成功了一半了，如果出现没有窗口创建的情况请检查视频文件路径
> > > # 1-2.设置背景
> > > > 现在有一个问题：如何获取mshta.exe创建的窗口句柄？
> > > > 
> > > > DWPT中使用的方法是FindWindow，当然，这种情况仅适用于只有一个mshta.exe窗口，通过Spy++工具我们可以得知：mshta.exe的窗口类名是HTML Application Host Window Class
> > > >
> > > > 所以我们就可以在创建进程代码的后面加上以下代码：
> > > > ```C++
> > > >   HWND hMshta=FindWindow("HTML Application Host Window Class", 0);
> > > >   while(hMshta==NULL){//一直到找到mshta的窗口为止
> > > >     Sleep(500);
> > > >     hMshta=FindWindow("HTML Application Host Window Class", 0);
> > > >   }
> > > >   //找到了
> > > > ```
> > > > mshta.exe的窗口句柄存放在hMshta中，好了，现在第一个问题解决了，第二个问题：如何放进去
> > > >
> > > > 这里我使用的方法来自 哔哩哔哩up主[@偶尔有点小迷糊](https://space.bilibili.com/39665558/)（Uid39665558）
> > > >
> > > > 首先向类名为Progman的窗口发送0x52C消息，使用SendMessageTimeout（SendMessage我不知道行不行）发送即可，然后调整mshta.exe窗口大小，再设置父窗口为Progman，最后隐藏类名为WorkerW的窗口即可，
> > > > 看得一头雾水的可以去[迷糊老师的这期视频](https://www.bilibili.com/video/BV1HZ4y1978a/)来看看，里面有详细的教程
> > > > 
> > > > 所以再后面的代码如下：
> > > > ```C++
> > > >   //这一部分放在main函数外
> > > >   DLLIMPORT BOOL CALLBACK EnumWindowProc(_In_ HWND hwnd, _In_ LPARAM Lparam)//核心！！！动态壁纸的嵌入窗口过程 
> > > >   {
> > > > 	    HWND hDefView = FindWindowEx(hwnd, 0, "SHELLDLL_DefView", 0);
> > > > 	    if (hDefView != 0) {
> > > > 	        HWND hWorkerw = FindWindowEx(0, hwnd, "WorkerW", 0);
> > > > 	        ShowWindow(hWorkerw, SW_HIDE);
> > > > 	        return FALSE;
> > > > 	    }
> > > > 	    return TRUE;
> > > > 	}
> > > >   //后面的部分请放在main函数中
> > > >   int width=GetDeviceCaps(GetDC(0), DESKTOPHORZRES),height=GetDeviceCaps(GetDC(0), DESKTOPVERTRES);//获取屏幕设备分辨率 
> > > >   HWND hProgman = FindWindow("Progman", 0);
> > > >   SendMessageTimeout(hProgman, 0x52C, 0, 0, 0, 100, 0);//延时发送消息 
> > > >   SetWindowPos(hMshta, NULL, 0, 0, width, height, SWP_NOZORDER);//设置窗口大小和位置 
> > > >   SetParent(hMshta, hProgman);//设置父窗口 
> > > >   EnumWindows(EnumWindowProc, 0);//将这个窗口放到桌面的后边 
> > > > ```
> > > > 编译运行程序后，动态壁纸就被启动了，还是比较简单的
> > # 2.动态壁纸的关闭
> > > 这个就更简单了，代码两种方法：
> > > # 2-1方法：使用EnumChildWindows遍历（推荐）
> > > ```C++
> > > //main函数外需要写的
> > > DLLIMPORT BOOL CALLBACK StopDWPProc(_In_ HWND hWnd,_In_ LPARAM lparam){//停止动态壁纸的回调函数（Enum遍历） 
> > >		char Text[1145];
> > >		GetClassName(hWnd,Text,sizeof(Text));
> > >		//GetWindowText(hWnd,Text,GetWindowTextLength(hWnd)+1);
> > >		if(strcmp(Text,"HTML Application Host Window Class")==0) PostMessage(hWnd,WM_CLOSE,0,0);
> > >		return FALSE;
> > >	}
> > > //关闭时需要写的
> > >	HWND PROGMAN=FindWindow("Progman", 0);
> > >	if(PROGMAN) EnumChildWindows(PROGMAN,StopDWPProc,NULL);
> > > ```
> > > # 2-2方法：taskkill强制结束进程
> > > ```C++
> > > WinExec("taskkill.exe /F /IM mshta.exe",SW_HIDE);
> > > ```
> # 二、使用WallpaperCore.dll编写动态壁纸程序
> > # 1.启动动态壁纸
> > > 目前WallpaperCore.dll仅支持启动dp文件，不支持直接启动，所以还需要写一个dp文件到%temp%目录
> > > # 1-1.创建dp文件
> > > > dp文件格式如下：<t/f表示是否需要声音><视频文件完整路径>
> > > >
> > > > 例：
> > > > ```Text
> > > > tC:\Video.mp4
> > > > ```
> > > > 这表示需要声音播放C:\Video.mp4视频
> > > > 这段文本需要写入至一个格式为dp的文件，推荐放在Temp目录中，必须是纯文本、GBK编码，否则可能会有问题
> > > # 1-2.启动dp文件
> > > > 在创建好dp文件后，你就可以使用WallpaperCore.dll的StartDwp函数来启动壁纸文件了，编译时请包含"WallpaperCore\dll.h"文件并链接库"WallpaperCore\libWallpaperCore.a"，否则GCC编译器会找不到符号
> > > >
> > > > 使用格式：
> > > > ```C++
> > > > StartDwp(<dp文件完整路径（char*）>,<是否为安静模式（不提示窗口，bool）>);
> > > > ```
> > > > 例：
> > > > ```C++
> > > > StartDwp("C:\\Users\\Admin\\Desktop\\1.dp",false);
> > > > ```
> > > > 这段代码会启动C:\Users\Admin\Desktop目录中的1.dp文件，不使用安静模式，这样就完成的动态壁纸的启动，非常的简单。StartDwp会启动一个线程，所以main函数一定要一直保持运行
> > # 2.关闭动态壁纸
> > > 这个是一样的，只不过我已经写了StopDWPProc回调函数，你只需要两行代码就可以终止：
> > > ```C++
> > > HWND PROGMAN=FindWindow("Progman", 0);
> > > if(PROGMAN) EnumChildWindows(PROGMAN,StopDWPProc,NULL);
> > > ```
> > > 还是比较简单的，好了，以上就是这篇文档的全部内容，DWPT还有待发展，如果感觉可以的话点个star吧
> # 结束
[中文](https://github.com/BOffice-Excel/Excel-s-Dynamic-Wallpaper-Tools?tab=readme-ov-file#%E4%B8%AD%E6%96%87)
# English
> if you have any doubts or suggestions, please go to [Issues](https://github.com/BOffice-Excel/Excel-s-Dynamic-Wallpaper-Tools/issues)Submit
> 
> To download, please open [Release](https://github.com/BOffice-Excel/Excel-s-Dynamic-Wallpaper-Tools/releases)
# Office Excel's dynamic wallpaper tool
> Introduction: This is a dynamic wallpaper tool written in C++, which can now be used
> Special thanks to the Bilibili user<a href="https://space.bilibili.com/39665558/">@偶尔有点小迷糊</a>(Uid39665558), reference project: https://github.com/3150601355/VideoWallPaperDemo
> 
> Compiling environment: Windows 11 IDE: Dev-C++Compiler: TDM-GCC 4.9.2 32-bit Release It can be compiled in a higher version, but it is not necessary.4.9.2 is enough and there is no need to do anything during compilation.I have already configured the link library
>
> Now there is a very good thing, which is that you can create your own dynamic wallpaper tool by including dll.h in the Wallpaper Core folder.Remember to link the library: libWallpaper Core.a
> Tip: It is recommended to use ANSI(GBK)to open the code, otherwise the comments inside will be mostly garbled
>
> Attention:
> It is not recommended to use Visual Studio for compilation.Many changes need to be made, otherwise errors may occur, such as unsafe
> In theory, anything that can compile C++is acceptable, but it is not recommended as it may result in garbled code or errors
> I have already compiled it in the nearby Release, and it should be compatible with both Windows 8 x86 and Windows 11 x64
> 
> The header files used are: std io.h io.h、windows.h、commctrl.h， That's all
> You can take a look at the help within the program yourself
# Developing with WallpaperCore.dll
> # 1.Principle of Dynamic Wallpaper(Brief Introduction)
> # 1.Startup of Dynamic Wallpaper
> > > # 1-1.Creating a Video Window
> Here, we use the [CreateProcessA Function](https://learn.microsoft.com/zh-cn/windows/win32/api/processthreadsapi/nf-processthreadsapi-createprocessa) to create a process, using mshta.exe as a video playback tool demonstration(ffplay can also be used)
> > > > 
>The following code will start mshta.exe without doing anything else:
> > > > ```C++
> > > >   STARTUPINFOA sia,memset(&sia,0,sizeof(sia));// Initialize information structure
> > > >   PROCESS_INFORMATIONA pia;memset(&pia,0,sizeof(pia));
> > > >   char mshtaPath[MAX_PATH+5];// Please try to make it bigger here
> > > > GetSystemDirectory(mshtaPath, MAX-PATH);//Get the System(System32)directory.On 64 bit systems, 32-bit programs will become SysWOW64 directory.//Replace MAX-PATH with your array length of -5(preferably)
> > > >   if(mshtaPath[strlen(mshtaPath)-1]=='\\')strcat(mshtaPath,"mshta.exe");
> > > >   else strcat(mshtaPath,"\\mshta.exe");
> > > >   if(CreateProcess(mshtaPath,NULL,NULL,NULL,NULL,NULL,NULL,NULL,&sia,&pia)!=0){
> > > > //Successfully started the process
> > > >   }
> > > >   else{
> > > > //Start process failed
> > > >   }
> > > > ```
> > > > if you successfully compile the program, you will find that there is nothing, because we did not write an HTA file(HTML application, similar to HTML syntax)for video playback for mshta.exe.The video webpage format is as follows:
> > > > ```HTML
> > > >   <html>
> > > >     <META http-equiv="content-type" content="text/html; charset=GBK">
> > > >     <!-- This is to set mshta.exe to use GBK encoding(default UTF-8)when reading HTA files.if you are using Visual Studio, you can skip the above line(VS default UTF-8)-->
> > > >     <meta http-equiv="x-ua-compatible" content="IE=9"/>
> > > >     <!-- This is the IE version for setting mshta.exe, IE=<version number>, you can fill in "Edge".The default version of mshta.exe does not support Video tags -->
> > > >     <head>
> > > >       <title>VideoPlayer</title>
> > > >       <!-- The above item cannot be seen by actual users, so it is not necessary to write -->
> > > >       <HTA:APPLICATION APPLICATIONNAME="VideoPlayer"ID="VideoPlayer" BORDER="none" SHOWINTASKBAR="no" VERSION="0.0"/>
> > > >       <!-- The above setting has no borders, does not display on the taskbar, ID is VideoPlayer, version is 0.0, name is VideoPlayer, version, name can be changed freely -->
> > > >     </head>
> > > >    <body>
> > > >       <video style="width: 100%; height: 100%; left: 0px; top: 0px; position: fixed" autoplay loop [mutated]><source src="<insert video address here>" type="video/mp4">ERROR</video>
> > > >       <!-- Please replace the internal information in a reasonable way when playing the video above.if muted is added, it means it is muted-->
> > > >     </body>
> > > >   </html>
> > > > ```
> > > > Now you can open your edited hta file, so you can see a borderless video window(Alt+F4 to exit)
> > > >The following code shows how to use the program to open an hta file
> > > > ```C++
> > > >   STARTUPINFOA sia;memset(&sia,0,sizeof(sia));// Initialize information structure
> > > >   PROCESS_INFORMATIONA pia;memset(&pia,0,sizeof(pia));
> > > >   char mshtaPath[MAX_PATH+5];// Please try to make it bigger here
> > > >   GetSystemDirectory(mshtaPath, MAX_PATH);//Get the System(System32)directory.On 64 bit systems, 32-bit programs will become SysWOW64 directory.//Replace MAX_PATH with your array length of -5(preferably)
> > > >   if(mshtaPath[strlen(mshtaPath)-1]=='\\')strcat(mshtaPath,"mshta.exe ");
> > > >   else strcat(mshtaPath,"\\mshta.exe ");
> > > >   if(CreateProcess(mshtaPath,<write your hta file path here, if there are special characters or symbols, add quotation marks>, NULL, NULL, NULL, NULL,&sia,&pia)!=0){
> > > > //Successfully started the process
> > > >   }
> > > >   else{
> > > > //Start process failed
> > > >   }
> > > > ```
> > > > After compiling and running, you can see that the program has opened a video window.At this point, you have already succeeded halfway.if there is no window creation, please check the video file path
> > > # 1-2.Set Background
> > > >Now there is a question: how to obtain the window handle created by mshta.exe?
> > > > 
> > > > The method used in DWPT is FindWindow.However, this only applies to cases where there is only one mshta.exe window.Through the Spy++ tool, we can know that the window class name of mshta.exe is "HTML Application Host Window Class"
> > > >
> > > > So we can add the following code after creating the process code:
> > > > ```C++
> > > >   HWND hMshta=FindWindow("HTML Application Host Window Class", 0);
> > > >   while(hMshta==NULL){//until the window for mshta is found
> > > >     Sleep(500);
> > > >     hMshta=FindWindow("HTML Application Host Window Class", 0);
> > > >   }
> > > > //Found
> > > > ```
> > > > The window handle of mshta.exe is stored in hMshta.Alright, now the first problem has been solved.The second problem is how to put it in
> > > >
> > > > The method I used here comes from the Bilibili user [@偶尔有点小迷糊](https://space.bilibili.com/39665558/)（Uid39665558）
> > > >
> > > > First, send the 0x52C message to the window with the class name Progman, and then use SendMessageTimeout(SendMessage, I don't know whether it is OK or not)to send it.Then adjust the size of the mshta.exe window, set the parent window to Progman, and finally hide the window with the class name WorkerW,
> > > >For those who are confused, you can go to [Confused Teacher's Video]（ https://www.bilibili.com/video/BV1HZ4y1978a/ ）Come take a look, there are detailed tutorials inside
> > > > 
> > > > So the following code follows:
> > > > ```C++
> > > > //This part is placed outside the main function
> > > > DLLIMPORT BOOL CALLBACK VNet WindowProc(_SN_HWND hwnd, _SN_LPARAM Lparm)//Core!!! The process of embedding dynamic wallpapers into windows
> > > >   {
> > > >      HWND hDefView = FindWindowEx(hwnd, 0, "SHELLDLL_DefView", 0);
> > > >      if(hDefView!=0){
> > > >          HWND hWorkerw = FindWindowEx(0, hwnd, "WorkerW", 0);
> > > >          ShowWindow(hWorkerw, SW_HIDE);
> > > >          return FALSE;
> > > >      }
> > > >      return TRUE;
> > > >  }
> > > > //Please place the following part in the main function
> > > > int width=dDeviceCaps(dDC(0), DESKTOPHORZRES), height=dDeviceCaps(dDC(0), DESKTOPVERTRES);//Get screen device resolution
> > > >   HWND hProgman = FindWindow("Progman", 0);
> > > >   SendMessageTimeout(hProgman, 0x52C, 0, 0, 0, 100, 0);// Delay sending messages
> > > >   SetWindowPos(hMshta, NULL, 0, 0, width, height, SWP_NOZORDER);//Set window size and position
> > > >   SetParent(hMshta, hProgman);//Set parent window
> > > >   EnumWindows(EnumWindowProc, 0);// Place this window behind the desktop
> > > > ```
> > > > After compiling and running the program, the dynamic wallpaper is launched, which is relatively simple
> # 2.Turning off dynamic wallpapers
> > This is even simpler, there are two ways to code:
> > # 2-1 Method: Traverse using EnumChildWindows(recommended)
> > > ```C++
> > > //What needs to be written outside the main function
> > > DLLIMPORT BOOL CALLBACK StopDWPProc(D_IN-HWDND hWnd, N_LPARAM lparam){//Stop callback function for dynamic wallpaper(enum traversal)
> > > char Text[1145];
> > > GetClassName(hWnd,Text,sizeof(Text));
> > > //GetWindowText(hWnd,Text,GetWindowTextLength(hWnd)+1);
> > > if(strcmp(Text,"HTML Application Host Window Class")==0)PostMessage(hWnd,WM_CLOSE,0,0);
> > > return FALSE;
> > > }
> > > //What needs to be written when closing
> > > HWND PROGMAN=FindWindow("Progman", 0);
> > > if(PROGMAN)EnumChildWindows(PROGMAN,StopDWPProc,NULL);
> > > ```
> > > # 2-2 Method: taskkill Forces End of Process
> > > ```C++
> > > WinExec("taskkill.exe /F /IM mshta.exe",SW_HIDE);
> > > ```
> > # 2.Write a dynamic wallpaper program using WallpaperCore.dll
> > > # 1.Start dynamic wallpaper
> > > Currently, Wallpaper Core.dll only supports starting DP files and does not support direct startup, so it is necessary to write a DP file to the% temp% directory
> > > # 1-1.Create DP file
> > > The dp file format is as follows:<t/f indicates whether sound is needed><full path of video file>
> > > >
> > > > Example:
> > > > ```Text
> > > > tC:\Video.mp4
> > > > ```
> > > > This means that sound is required to play the C: \ Video.mp4 video
> > > > This text needs to be written to a file in dp format, recommended to be placed in the Temp directory.It must be plain text and GBK encoded, otherwise there may be issues
> > > # 1-2.Start DP file
> > > > After creating the dp file, you can use the StartDwp function of Wallpaper Core.dll to start the wallpaper file.Please include the "Wallpaper Core \ dl.h" file and link the library "Wallpaper Core \ libWallpaper Core.a" during compilation, otherwise the GCC compiler will not find the symbol
> > > >
> > > > Format used:
> > > > ```C++
> > > StartDwp(<dp file full path(char *)>,<whether it is in quiet mode(no window prompt, boolean)>);
> > > > ```
> > > > Example:
> > > > ```C++
> > > > StartDwp("C:\\Users\\Admin\\Desktop\\1.dp",false);
> > > > ```
> > > > This code will start the 1.dp file in the C: \ Users \ Admin \ Desktop directory, without using quiet mode, and thus complete the startup of the dynamic wallpaper, which is very simple.StartDwp starts a thread, so the main function must always run
> > # 2.Turn off dynamic wallpapers
> > > This is the same, but I have already written the StopDWPProc callback function, and you only need two lines of code to terminate it:
> > > ```C++
> > > HWND PROGMAN=FindWindow("Progman", 0);
> > > if(PROGMAN)EnumChildWindows(PROGMAN,StopDWPProc,NULL);
> > > ```
> > > It's still relatively simple.Alright, that's all for this document.DWPT still needs further development.if you feel it's okay, click on the star
> # End
