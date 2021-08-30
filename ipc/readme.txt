如何编译：
1.需安装libdbus-1-dev libdbus-glib-1-dev
2.编译服务器 gcc server.c -ldbus-1 -I/usr/include/dbus-1 -o service，然后执行./service &，让其在后台运行
3.编译客户端 gcc client.c -ldbus-1 -I/usr/include/dbus-1 -o client 然后执行./client &看执行效果。

注意事项：
(1)有可能找不到dbus/dbus.h。那么ubuntu下用apt-search找这个文件到底在那个目录下面。
(2)有可能找到不到dbus-arch-deps.h头文件，那么请看此博客：http://www.aiseminar.cn/bbs/forum.php?mod=viewthread&tid=1700
