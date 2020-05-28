## 用户名aaron 不在 sudoers文件中，此事将被报告
```
1. 执行su，切换到root
2. cd /etc/sudoers
3. 在root后添加帐号
   root ALL=(ALL:ALL)ALL
   aaron ALL=(ALL:ALL)ALL
4. 强制保存wq!
```

## 主机使用代理情况下虚拟机上网
```
1. 虚拟机网络适配器选NAT模式
2. 设置代理允许其他设备接入
3. linux设置全局代理，设为代理的地址和端口，非主机
    打开/etc/skel/.bash_profile添加：
   http_proxy=http://172.16.71.48:808
   https_proxy=http://172.16.71.48:808
   export http_proxy https_proxy
   
    执行source /etc/skel/.bash_profile马上更新
4. 设置代理地址
    打开/etc/yum.conf添加：
   proxy=http://172.16.71.133:808 
   #proxy_username=代理服务器用户名 (没有不填）
   #proxy_password=代理服务器密码 (没有不填)
```

## 虚拟机与主机无法共享文件(没有/mnt/hgfs目录)
```	
1. 点击重新安转VMware Tools
2. 进入VMware Tools目录，拷贝安装包 cp VMwareTools-10.3.10-13959562.tar.gz /mnt/cdrom
3. cd /mnt/cdrom,sudo tar -zxvf VMwareTools-10.3.10-13959562.tar.gz
4. 安装sudo vmware-distrib/vmware-install.pl
5. cd /mnt/hgfs, ls
```

## 安装git
```
yum -y install git
// 代理设置
git config --global https.proxy http://172.18.33.48:808
git config --global https.proxy https://172.18.33.48:808
```
## 安装C++环境
```
sudo yum install -y gcc-C++
sudo yum install gdb
```
