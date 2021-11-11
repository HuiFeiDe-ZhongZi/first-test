#1.0
#app:ADD.c SUB.c MUL.c DES.c main.c
#	gcc *.c -I../include -o app

#2.0
#可以帮助开发者节省编译时间，可以检测工程源码更改是否重新编译。
#节省编译时间 编译过程：（1）预处理.c——>.i (2)编译 .i——>.s (3)汇编 .s ——> .o二进制 （4） 链接 将若干二进制与启动接口链接生成ELF可执行应用程序文件 
#汇编耗费时间 链接时间很短 方案：第一次编译的.o文件不删除 空间换时间

#app:ADD.o SUB.o MUL.o DES.o main.o
#	gcc *.o -o app
#
#ADD.o:ADD.c
#	gcc -I../include -c ADD.c
##-c为了保存.o文件  汇编的过程需要头文件
#SUB.o:SUB.c
#	gcc -I../include -c SUB.c
#MUL.o:MUL.c
#	gcc -I../include -c MUL.c
#DES.o:DES.c
#	gcc -I../include -c DES.c
#main.o:main.c
#	gcc -I../include -c main.c
#自顶向下建立依赖关系，自底向上执行任务 先写链接再写汇编 执行时先汇编再链接
#如何检测更新————最近访问时间 最近修改时间（内容） 最近改动时间（属性）
#目标文件的最近修改时间要比依赖文件新


#3.0 
#1.变量的定义和使用(常见变量)
#2.特殊变量
#3.内建语法
#4.内置函数
#5.伪目标
#6.功能目标

#TIME = "2020.1.30"
#output:
#	echo $(TIME)
#变量名括号，防止识别错误
#常见变量

INCLUDE_PATH=../include #存储头文件路径
CFLAGS= -I$(INCLUDE_PATH) -g -c -Wall#存储编译时选项
CPPFLAGES=-E -D -O1 -O2 -O3#存储预处理选项
LIBRARY_PATH=../library
LDFLAGS=-lpthread#存储库选项 -L库位置 -l库名（掐头去尾）
TARGET=THREAD_POOL_SERVER#存储目标名
CC=gcc #存储编译器
INSTALL_PATH=/usr/bin/#程序安装路径

#特殊变量 $@:表示目标 $^表示所有依赖 $<表示第一个依赖
#app:a.c b.c c.c d.c
#	$@:app $^:a.c b.c c.c d.c $<:a.c

#使用内置函数自动获取文件名
SRCFILE=$(wildcard *.c) #获取当前目录下的文件名,调用函数获取返回值

DESFILE=$(patsubst %.c,%.o,$(SRCFILE)) #字符串处理，可根据需求修改替换字符串内容
#第一次只有.c 用wilecard获取 用patsubst将.c替换为.o
$(TARGET):$(DESFILE)
	$(CC) $^ $(LDFLAGS) -o $@
#内建语法完成迭代
%.o:%.c
	$(CC) $(CFLAGS) $<
#修改变量即可，提高复用性
#三个功能目标 1.clean清理中间文件 2.install 编译成功后，将app移动到指定文件夹（安装）3. distclean卸载，app从安装位置删除，并删除工程的配置文件
clean:
	rm $(DESFILE) -rf
	rm $(TARGET) -rf
install:
	sudo mv $(TARGET) $(INSTALL_PATH)
distclean:
	sudo rm $(INSTALL_PATH)$(TARGET) -rf 
#一定确认卸载正确 TARGET打错了会把INSTALL_PATH删掉
output:
	echo $(INSTALL_PATH)$(TARGET)
#显示：@隐藏命令本身 只显示打印结果 
#- 被修饰命令出错可继续向后执行，否则遇到错误直接退出
