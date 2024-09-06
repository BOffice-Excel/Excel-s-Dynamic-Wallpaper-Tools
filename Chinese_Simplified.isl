; *** Inno Setup version 6.1.0+ Chinese Simplified messages ***
;
; To download user-contributed translations of this file, go to:
;   https://jrsoftware.org/files/istrans/
;
; Note: When translating this text, do not add periods (.) to the end of
; messages that didn't have them already, because on those messages Inno
; Setup adds the periods automatically (appending a period would result in
; two periods being displayed).

[LangOptions]
; The following three entries are very important. Be sure to read and 
; understand the '[LangOptions] section' topic in the help file.
LanguageName=中文简体
LanguageID=$0412
LanguageCodePage=0
; If the language you are translating to requires special font faces or
; sizes, uncomment any of the following entries and change them accordingly.
;DialogFontName=
;DialogFontSize=8
;WelcomeFontName=Verdana
;WelcomeFontSize=12
;TitleFontName=Arial
;TitleFontSize=29
;CopyrightFontName=Arial
;CopyrightFontSize=8

[Messages]

; *** Application titles
SetupAppTitle=安装
SetupWindowTitle=安装 - %1
UninstallAppTitle=卸载
UninstallAppFullTitle=%1 卸载

; *** Misc. common
InformationTitle=信息
ConfirmTitle=确定
ErrorTitle=错误

; *** SetupLdr messages
SetupLdrStartupMessage=这将安装%1，是否继续？
LdrCannotCreateTemp=无法创建临时文件，安装程序已中止。
LdrCannotExecTemp=无法执行临时目录中的文件，安装程序已中止。
HelpTextNote=

; *** Startup error messages
LastErrorMessage=%1.%n%n错误 %2: %3
SetupFileMissing=安装目录中缺少文件%1，请更正此问题或获取此安装程序的新版本。
SetupFileCorrupt=安装文件已损坏，请获取该程序的新版本。
SetupFileCorruptOrWrongVer=安装程序文件已损坏，或与此版本的安装程序不兼容。请更正此问题或获取程序的新版本。
InvalidParameter=在命令行上传递了一个无效参数：%n%n%1
SetupAlreadyRunning=安装程序已在运行。
WindowsVersionNotSupported=此程序不支持您的计算机正在运行的Windows版本。
WindowsServicePackRequired=此程序需要%1 Service Pack%2或更高版本。
NotOnThisPlatform=此程序将不会在%1上运行。
OnlyOnThisPlatform=此程序必须在%1上运行。
OnlyOnTheseArchitectures=此程序只能安装在为以下处理器体系结构设计的Windows版本上：%n%n%1
WinVersionTooLowError=此程序需要%1版本%2或更高版本。
WinVersionTooHighError=此程序无法安装在%1版本%2或更高版本上。
AdminPrivilegesRequired=安装此程序时，您必须以管理员身份登录。
PowerUserPrivilegesRequired=安装此程序时，您必须以管理员身份或Power Users组的成员身份登录。
SetupAppRunningError=安装程序检测到%1当前正在运行，%n%n请立即关闭它的所有实例，然后单击“确定”继续，或单击“取消”退出。
UninstallAppRunningError=卸载检测到%1当前正在运行，%n%n请立即关闭它的所有实例，然后单击“确定”继续，或单击“取消”退出。

; *** Startup questions
PrivilegesRequiredOverrideTitle=选择安装程序安装模式
PrivilegesRequiredOverrideInstruction=选择安装模式
PrivilegesRequiredOverrideText1=%1可以为所有用户安装（需要管理权限），也可以仅为您安装。
PrivilegesRequiredOverrideText2=%1只能为您安装，也可以为所有用户安装（需要管理权限）。
PrivilegesRequiredOverrideAllUsers=为所有用户安装（&A）
PrivilegesRequiredOverrideAllUsersRecommended=为所有用户安装（推荐）（&A）
PrivilegesRequiredOverrideCurrentUser=仅为我安装（&M）
PrivilegesRequiredOverrideCurrentUserRecommended=仅为我安装（推荐）（&M）

; *** Misc. errors
ErrorCreatingDir=安装程序无法创建目录“%1”。
ErrorTooManyFilesInDir=无法在目录“%1”中创建文件，因为它包含的文件过多。

; *** Setup common messages
ExitSetupTitle=退出安装程序
ExitSetupMessage=安装程序未完成。如果您现在退出，程序将不会安装。%n%n您可以在其他时间再次运行安装程序以完成安装。%n%n是否退出安装程序？
AboutSetupMenuItem=关于安装程序（&A）...
AboutSetupTitle=关于安装
AboutSetupMessage=%1版本%2%n%3%n%n%1主页：%n%4
AboutSetupNote=
TranslatorNote=

; *** Buttons
ButtonBack=<&Back
ButtonNext=下一个（&N）>
ButtonInstall=&安装
ButtonOK=OK
ButtonCancel=取消
ButtonYes=是（&Y）
ButtonYesToAll=全部为是（&A）
ButtonNo=否（&N）
ButtonNoToAll=全部为否（&o）
ButtonFinish=完成（&F）
ButtonBrowse=浏览（&B）...
ButtonWizardBrowse=浏览（&R）...
ButtonNewFolder=创建新文件夹（&M）

; *** "Select Language" dialog messages
SelectLanguageTitle=选择安装语言
SelectLanguageLabel=选择要在安装过程中使用的语言。

; *** Common wizard text
ClickNext=单击“下一步”继续，或单击“取消”退出安装程序。
BeveledLabel=
BrowseDialogTitle=浏览文件夹
BrowseDialogLabel=在下面的列表中选择一个文件夹，然后单击“确定”。
NewFolderName=新文件夹

; *** “欢迎”向导页面
WelcomeLabel1=欢迎使用[name]安装向导
WelcomeLabel2=这将在您的计算机上安装[name/ver]。%n%n建议您在继续之前关闭所有其他应用程序。
; *** “密码”向导页面
WizardPassword=密码
PasswordLabel1=此安装受密码保护。
PasswordLabel3=请提供密码，然后单击“下一步”继续。密码区分大小写。
PasswordEditLabel=密码（&C）：
IncorrectPassword=您输入的密码不正确。请再试一次。
; *** “许可协议”向导页
WizardLicense=许可协议
LicenseLabel=继续之前，请阅读以下重要信息。
LicenseLabel3=请阅读以下许可协议。在继续安装之前，您必须接受本协议的条款。
LicenseAccepted=我接受协议（&A）
LicenseNotAccepted=我不接受协议（&D）
; *** “信息”向导页面
WizardInfoBefore=信息
InfoBeforeLabel=继续之前，请阅读以下重要信息。
InfoBeforeClickLabel=准备好继续安装程序后，请单击“下一步”。
WizardInfoAfter=信息
InfoAfterLabel=继续之前，请阅读以下重要信息。
InfoAfterClickLabel=准备好继续安装程序后，请单击“下一步”。
; *** “用户信息”向导页
WizardUserInfo=用户信息
UserInfoDesc=请输入您的信息。
UserInfoName=用户名（&H）：
UserInfoOrg=组织（&O）：
UserInfoSerial=序列号（&S）：
UserInfoNameRequired=必须输入名称。
; *** “选择目的地位置”向导页面
WizardSelectDir=选择目标位置
SelectDirDesc=应该在哪里安装[name]？
SelectDirLabel3=安装程序将[name]安装到以下文件夹中。
SelectDirBrowseLabel=若要继续，请单击“下一步”。如果要选择其他文件夹，请单击“浏览”。
DiskSpaceGBLabel=至少需要[gb]gb的可用磁盘空间。
DiskSpaceMBLabel=至少需要[mb]mb的可用磁盘空间。
CannotInstallToNetworkDrive=安装程序无法安装到网络驱动器。
CannotInstallToUNCPath=安装程序无法安装到UNC路径。
InvalidPath=您必须输入带有驱动器号的完整路径；例如：%n%nC:\APP%n%n也没有格式为：%n%n\\server\share的UNC路径
InvalidDrive=您选择的驱动器或UNC共享不存在或不可访问。请选择另一个。
DiskSpaceWarningTitle=磁盘空间不足
DiskSpaceWarning=安装程序需要至少%1 KB的可用空间才能安装，但所选驱动器只有%2 KB可用空间。%n%n是否仍要继续？
DirNameTooLong=文件夹名称或路径太长。
InvalidDirName=文件夹名称无效。
BadDirName32=文件夹名称不能包含以下任何字符：%n%n%1
DirExistsTitle=文件夹存在
DirExists=文件夹：%n%n%1%n%n已存在。是否仍要安装到该文件夹？
DirDoesntExistTitle=文件夹不存在
DirDoesntExist=文件夹：%n%n%1%n%n不存在。是否要创建文件夹？
; *** “选择组件”向导页面
WizardSelectComponents=选择组件
SelectComponentsDesc=应该安装哪些组件？
SelectComponentsLabel2=选择要安装的组件；清除不想安装的组件。准备好继续时，请单击“下一步”。
FullInstallation=完全安装
; 如果可能的话，不要把“Compact”翻译成“Minimal”（我在你的语言中是指“Minimal”）
CompactInstallation=紧凑型安装
CustomInstallation=自定义安装
NoUninstallWarningTitle=组件存在
NoUninstallWarning=安装程序检测到下列组件已安装在您的计算机上：%n%n%1%n%n选择这些组件将不会卸载它们。%n%n是否仍要继续？
ComponentSize1=%1 KB
ComponentSize2=%1 MB
ComponentsDiskSpaceGBLabel=当前选择至少需要[gb]gb的磁盘空间。
ComponentsDiskSpaceMBLabel=当前选择至少需要[mb]mb的磁盘空间。
; *** “选择其他任务”向导页面
WizardSelectTasks=选择其他任务
SelectTasksDesc=应执行哪些附加任务？
SelectTasksLabel2=选择您希望安装程序在安装[name]时执行的其他任务，然后单击“下一步”。
; *** “选择开始菜单文件夹”向导页面
WizardSelectProgramGroup=选择「开始」菜单文件夹
SelectStartMenuFolderDesc=安装程序应该将程序的快捷方式放在哪里？
SelectStartMenuFolderLabel3=安装程序将在以下“开始菜单”文件夹中创建程序的快捷方式。
SelectStartMenuFolderBrowseLabel=若要继续，请单击“下一步”。如果要选择其他文件夹，请单击“浏览”。
MustEnterGroupName=必须输入文件夹名称。
GroupNameTooLong=文件夹名称或路径太长。
InvalidGroupName=文件夹名称无效。
BadGroupName=文件夹名称不能包含以下任何字符：%n%n%1
NoProgramGroupCheck2=不创建「开始」菜单文件夹（&D）
; *** “准备安装”向导页面
WizardReady=准备安装
ReadyLabel1=安装程序现在可以开始在您的计算机上安装[name]了。
ReadyLabel2a=单击“安装”继续安装，如果要查看或更改任何设置，请单击“上一步”。
ReadyLabel2b=单击“安装”继续安装。
ReadyMemoUserInfo=用户信息：
ReadyMemoDir=目标位置：
ReadyMemoType=设置类型：
ReadyMemoComponents=所选组件：
ReadyMemoGroup=开始菜单文件夹：
ReadyMemoTasks=其他任务：
; *** D下载向导页面向导页面和下载临时文件
DownloadingLabel=正在下载其他文件...
ButtonStopDownload=停止下载（&S）
StopDownload=是否确实要停止下载？
ErrorDownloadAborted=下载中止
ErrorDownloadFailed=下载失败：%1%2
ErrorDownloadSizeFailed=获取大小失败：%1%2
ErrorFileHash1=文件哈希失败：%1
ErrorFileHash2=无效的文件哈希：应为%1，找到%2
ErrorProgress=无效进度：第%1个，共%2个
ErrorFileSize=无效的文件大小：应为%1，找到%2
; *** “准备安装”向导页面
WizardPreparing=准备安装
PreparingDesc=安装程序正准备在您的计算机上安装[name]。
PreviousInstallNotCompleted=上一个程序的安装/删除未完成。您需要重新启动计算机才能完成安装。%n%n重新启动计算机后，请再次运行安装程序以完成[name]的安装。
CannotContinue=安装程序无法继续。请单击“取消”退出。
ApplicationsFound=以下应用程序正在使用安装程序需要更新的文件。建议您允许安装程序自动关闭这些应用程序。
ApplicationsFound2=以下应用程序正在使用安装程序需要更新的文件。建议您允许安装程序自动关闭这些应用程序。安装完成后，安装程序将尝试重新启动应用程序。
CloseApplications=自动关闭应用程序（&A）
DontCloseApplications=不关闭应用程序（&D）
ErrorCloseApplications=安装程序无法自动关闭所有应用程序。建议您关闭所有使用安装程序需要更新的文件的应用程序，然后再继续。
PrepareToInstallNeedsRestart=安装程序必须重新启动计算机。重新启动计算机后，再次运行安装程序以完成[name]的安装。%n%n您想现在重新启动吗？
; *** “安装”向导页面
WizardInstalling=安装
InstallingLabel=安装程序正在您的计算机上安装[name]，请稍候。
; *** “安装完成”向导页面
FinishedHeadingLabel=正在完成[name]安装向导
FinishedLabelNoIcons=安装程序已完成在您的计算机上安装[name]。
FinishedLabel=安装程序已完成在您的计算机上安装[name]。可以通过选择已安装的快捷方式来启动应用程序。
ClickFinish=单击Finish退出安装程序。
FinishedRestartLabel=若要完成[name]的安装，安装程序必须重新启动计算机。您想现在重新启动吗？
FinishedRestartMessage=若要完成[name]的安装，安装程序必须重新启动计算机。%n%n您想现在重新启动吗？
ShowReadmeCheck=是，我想查看自述文件
YesRadio=是，立即重新启动计算机（&Y）
NoRadio=&否，我稍后将重新启动计算机
; 例如用作“Run MyProg.exe”
RunEntryExec=运行%1
; 例如用作“查看自述.txt”
RunEntryShellExec=查看%1
; *** “安装程序需要下一个磁盘”之类的东西
ChangeDiskTitle=安装程序需要下一个磁盘
SelectDiskLabel2=请插入磁盘%1，然后单击“确定”。%n%n如果此磁盘上的文件位于以下文件夹以外的文件夹中，请输入正确的路径或单击“浏览”。
PathLabel=路径（&P）：
FileNotInDir2=无法在“%2”中找到文件“%1”。请插入正确的磁盘或选择其他文件夹。
SelectDirectoryLabel=请指定下一个磁盘的位置。
; *** 安装阶段消息
SetupAborted=安装程序未完成。%n%n请更正此问题，然后重新运行安装程序。
AbortRetryIgnoreSelectAction=选择操作
AbortRetryIgnoreRetry=重试（&T）
AbortRetryIgnoreIgnore=忽略错误并继续（&E）
AbortRetryIgnoreCancel=取消安装
; *** 安装状态消息
StatusClosingApplications=正在关闭应用程序...
StatusCreateDirs=正在创建目录...
StatusExtractFiles=正在提取文件...
StatusCreateIcons=正在创建快捷方式...
StatusCreateIniEntries=正在创建INI项...
StatusCreateRegistryEntries=正在创建注册表项...
StatusRegisterFiles=正在注册文件...
StatusSavingUninstall=正在保存卸载信息...
StatusRunProgram=正在完成安装...
StatusRestartingApplications=正在重新启动应用程序...
StatusRollback=正在回滚更改...

; *** 杂项。错误
ErrorInternal2=内部错误：%1
ErrorFunctionFailedNoCode=%1失败
ErrorFunctionFailed=%1失败；代码%2
ErrorFunctionFailedWithMessage=%1失败；代码%2。%n%3
ErrorExecutingProgram=无法执行文件：%n%1
; *** 注册表错误
ErrorRegOpenKey=打开注册表项时出错：%n%1\%2
ErrorRegCreateKey=创建注册表项时出错：%n%1\%2
ErrorRegWriteKey=写入注册表项时出错：%n%1\%2
; *** INI错误
ErrorIniEntry=在文件“%1”中创建INI项时出错。
; *** 文件复制错误
FileAbortRetryIgnoreSkipNotRecommended=跳过此文件（不推荐）（&S）
FileAbortRetryIgnoreIgnoreNotRecommended=忽略错误并继续（不推荐）
SourceIsCorrupted=源文件已损坏
SourceDoesntExist=源文件“%1”不存在
ExistingFileReadOnly2=无法替换现有文件，因为它被标记为只读。
ExistingFileReadOnlyRetry=删除只读属性并重试（&R）
ExistingFileReadOnlyKeepExisting=保留现有文件（&K）
ErrorReadingExistingDest=尝试读取现有文件时出错：
FileExistsSelectAction=选择操作
FileExists2=文件已存在。
FileExistsOverwriteExisting=覆盖现有文件（&O）
FileExistsKeepExisting=保留现有文件（&K）
FileExistsOverwriteOrKeepAll=为下一个冲突执行此操作（&D）
ExistingFileNewerSelectAction=选择操作
ExistingFileNewer2=现有文件比安装程序试图安装的文件新。
ExistingFileNewerOverwriteExisting=覆盖现有文件（&O）
ExistingFileNewerKeepExisting=保留现有文件（推荐）（&C）
ExistingFileNewerOverwriteOrKeepAll=为下一个冲突执行此操作（&D）
ErrorChangingAttr=尝试更改现有文件的属性时出错：
ErrorCreatingTemp=尝试在目标目录中创建文件时出错：
ErrorReadingSource=尝试读取源文件时出错：
ErrorCopying=尝试复制文件时出错：
ErrorReplacingExistingFile=尝试替换现有文件时出错：
ErrorRestartReplace=RestartReplace失败：
ErrorRenamingTemp=尝试重命名目标目录中的文件时出错：
ErrorRegisterServer=无法注册DLL/OCX:%1
ErrorRegSvr32Failed=RegSvr32失败，退出代码为%1
ErrorRegisterTypeLib=无法注册类型库：%1
; *** 卸载显示名称标记
; 例如用作“我的程序（32位）”
UninstallDisplayNameMark=%1（%2）
; 例如用作“我的程序（32位，所有用户）”
UninstallDisplayNameMarks=%1（%2，%3）
UninstallDisplayNameMark32Bit=32位
UninstallDisplayNameMark64Bit=64位
UninstallDisplayNameMarkAllUsers=所有用户
UninstallDisplayNameMarkCurrentUser=当前用户
; *** 安装后错误
ErrorOpeningReadme=试图打开自述文件时出错。
ErrorRestartingComputer=安装程序无法重新启动计算机。请手动执行此操作。
; *** 卸载程序消息
UninstallNotFound=文件“%1”不存在。无法卸载。
UninstallOpenError=无法打开文件“%1”。无法卸载
UninstallUnsupportedVer=此版本的卸载程序无法识别卸载日志文件“%1”的格式。无法卸载
UninstallUnknownEntry=在卸载日志中遇到未知条目（%1）
ConfirmUninstall=确实要完全删除%1及其所有组件吗？
UninstallOnlyOnWin64=此安装只能在64位Windows上卸载。
OnlyAdminCanUninstall=此安装只能由具有管理权限的用户卸载。
UninstallStatusLabel=正在从计算机中删除%1，请稍候。
UninstalledAll=%1已成功从您的计算机中删除。
UninstalledMost=%1卸载完成。%n%n某些元素无法删除。这些可以手动移除。
UninstalledAndNeedsRestart=若要完成%1的卸载，必须重新启动计算机。%n%n您想现在重新启动吗？
UninstallDataCorrupted=“%1”文件已损坏。无法卸载
; *** 卸载阶段消息
ConfirmDeleteSharedFileTitle=是否删除共享文件？
ConfirmDeleteSharedFile2=系统指示以下共享文件不再被任何程序使用。是否要进行卸载以删除此共享文件？%n%n如果任何程序仍在使用此文件并将其删除，则这些程序可能无法正常运行。如果您不确定，请选择“否”。将文件留在系统中不会造成任何后果。
SharedFileNameLabel=文件名：
SharedFileLocationLabel=位置：
WizardUninstalling=卸载状态
StatusUninstalling=正在卸载%1...
; *** 停机阻塞原因
ShutdownBlockReasonInstallingApp=正在安装%1。
ShutdownBlockReasonUninstallingApp=正在卸载%1。
; 下面的自定义消息不由安装程序本身使用，但如果您
; 在你的脚本中使用它们，你会想翻译它们。
[CustomMessages]
NameAndVersion=%1 版本 %2
AdditionalIcons=其他快捷方式：
CreateDesktopIcon=创建桌面快捷方式（&D）
CreateQuickLaunchIcon=创建快速启动快捷方式（&Q）
ProgramOnTheWeb=Web上的%1
UninstallProgram=卸载%1
LaunchProgram=启动%1
AssocFileExtension=将%1与%2文件扩展名关联（&A）
AssocingFileExtension=正在将%1与%2文件扩展名关联...
AutoStartProgramGroupDescription=启动：
AutoStartProgram=自动启动%1
AddonHostProgramNotFound=在您选择的文件夹中找不到%1。%n%n是否仍要继续？