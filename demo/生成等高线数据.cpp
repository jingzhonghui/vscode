#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{

    fstream file,file1;
    file.open("./1.txt",ios_base::in);
    file1.open("./data1.txt",ios_base::out|ios_base::binary);
    if(file.is_open()&& file1.is_open())
    {
        double g_x=100.0,g_y=100.0;
        double g_step=1.0;
        int g_rownum=10;
        int g_colnum=10;
        file1.write((char*)&g_x, sizeof(double));
		file1.write((char *)&g_y, sizeof(double));
		file1.write((char*)&g_step, sizeof(double));
		file1.write((char *)&g_rownum, sizeof(int));
		file1.write((char*)&g_colnum, sizeof(int));
        string str;
         while(true)
        {
            getline(file,str);
            if(file.eof())
            {
                break;
            }
            for(int i=0;i<str.length();i++)
            {
                if(i%2==0)
                {
                    double z=str[i]-0x30;
                    file1.write((char *)&z,sizeof(double));
                }
            }
            str.clear();
        } 
    }

    else
    {
        cout<<"open file error!"<<endl;
    }
    

    return 0;
}