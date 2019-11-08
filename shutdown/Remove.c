#include <stdio.h>
#include <windows.h>

int main()
{
    char *Register = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    HKEY hKey;
    DWORD dwDisposition;
    system("shutdown -a");
    //taskkill杀死一个进程
    system("taskkill -f -im a.exe");
    //打开注册表启动项 
    if(RegOpenKeyExA(HKEY_CURRENT_USER, Register, 0, KEY_ALL_ACCESS, &hKey)== ERROR_SUCCESS)
    {
       //删除一个键值
        RegDeleteValueA(hKey,"Shutdown");
        //关闭注册表
        RegCloseKey(hKey);
        //printf("succeed!\n");
    }
    else
    {
        printf("Failed!");
        return -1;
    }
    return 0;
}