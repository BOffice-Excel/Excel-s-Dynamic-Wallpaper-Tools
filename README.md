# Office-Excel的动态壁纸工具
> 介绍：这是一个用C++写的非常垃圾的动态壁纸工具，也许可以投入到正常使用？目前已经可以开始正式使用了，凑合凑合也能用，还要什么自行车
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
