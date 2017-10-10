# NDKDemo
ndk调用

## 1.环境配置：
    a.新建项目，选中：Include C++ Support，AndroidStudio会为我们创建cpp文件夹、
    CMake文件、模块的Gradle也会做些相应的配置。
![](https://github.com/kongxianglei0403/NDKDemo/blob/master/picture/20161011082637504.png)
    
        b.创建项目有可能会报NDK找不到之类的错误，右击项目 ->Open Module Setting->SDK Location 查看Android NDK location是否有配置起来，
         没有，就下载NDK，或者去AndroidStudio Settings中配置，Appearance&Behavior->System Setings->Android SDK，选中SDK Tools标签
          页，选择CMake，LLDB，NDK进行安装
![](https://github.com/kongxianglei0403/NDKDemo/blob/master/picture/20161011083412889.png)

        c.上面需要的东西都配置好后，新建的项目就会多出cpp文件夹，模块Gradle也多了些配置
![](https://github.com/kongxianglei0403/NDKDemo/blob/master/picture/20161011083854333.png)

        d.并且AndroidStudio已经帮我们创建了一个调用C的例子，直接运行项目，Activiity里的就可以成功调用到C的方法。
          我们在Activity里创建一个native方法，直接报红，然后Alt+Enter，选第一个
![](https://github.com/kongxianglei0403/NDKDemo/blob/master/picture/20161011082637504.png)

        e.native-lib.cpp里自动帮我们添加了新的方法
![](https://github.com/kongxianglei0403/NDKDemo/blob/master/picture/20161011085255620.png)

        f.给该方法一个正确的返回值，然后在Activity中调用native方法。呵呵崩掉了！

        
        g.项目可以通过编译，但是找不到C++里面的方法，这是因为CMake在编译C++代码的时候把刚才新建的C++函数漏掉了，怎么把他加上呢，注意到C++代码
          里面有一个extern "C"这句话了吗，这个是CMake的东西，把这句话放到最上面，然后加个大括号，把所有java需要调用的方法都放里面
![](https://github.com/kongxianglei0403/NDKDemo/blob/master/picture/20161011091543038.png)

