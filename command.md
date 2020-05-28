## Linux 命令
```
su 用户名	切换用户 su aaronc 
mv A B	A重命名为B
mv /a /b/c	a目录移动到b下，并且重命名为a
cp /a/a /b/b 文件移动
cp -r a /b 	a文件夹拷贝到b

ls -al1	显示隐藏文件
```
## vim编辑器模式

i 进入insert
Esc 进入命令模式
shift+ :输入命令

**代码跳转**
```
1.安装ctags
sudo yum update
sudo yum install ctags
2.在需要阅读的代码的根目录
ctags -R
3.Ctrl + ] 跳转
Ctrl + o 返回上一级
4.特别注意的地方
因为tags是链接工程代码的重要文件，如果想进行函数跳转操作，需要在工程根目录（tags在哪个目录就要在哪个目录使用vim +文件路径）打开我们所要阅读的文件，才能跳转函数。
```

## c++环境

### 安装C++环境
```
udo yum install -y gcc-C++
sudo yum install gdb
```
### 编译命令
```
g++ hello.cpp -o -h
-E                       仅作预处理，不进行编译、汇编和链接
-S                       编译到汇编语言，不进行汇编和链接
-c                       编译、汇编到目标代码，不进行链接
-o <文件>                输出到 <文件>
```
### 链接库libunp.a
```
gcc timeServer.c -L. -lunp -o s
```
