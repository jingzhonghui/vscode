/*
 * @Descripttion: 
 * @version: 
 * @Date: 2019-10-11 10:23:58
 * @LastEditTime: 2019-10-11 18:58:32
 */
#include<iostream>
#include<string>
#include<windows.h>
#include<stdlib.h>
using namespace std;

void openfile(string path)
{
    if (path.empty())
    {
       cout<<"文件路径为空"<<endl;
       return ;
    }
    else if (!path.find_last_of("."))
    {
        cout<<"文件名不正确"<<endl;
    }
    else
    {
        
        system(path.c_str());
      // path="cmd.exe "+path;
      // WinExec(path.c_str());
    }
}

int main()
{
    string path="cmd /c E:/联合测绘/颜色.xlsx";
   // openfile(path);
   system("C:/a.txt");
    return 0;
}