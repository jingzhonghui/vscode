/*
 * @Descripttion: 
 * @version: 
 * @Date: 2019-07-31 11:59:24
 * @LastEditTime: 2019-08-21 14:04:21
 */
#include<iostream>
#include<fstream>
#include<string>
#include<list>
using namespace std;

int main()
{
    fstream  file,file1;
    file.open("./ElevationGrid.txt",ios_base::in|ios_base::binary);
    file1.open("./data1.txt",ios_base::out);

    if(file.is_open() && file1.is_open())
    {
        double s_x,s_y,step;
        int rownum,colnum;
        //读取文件头
		file.read((char*)&s_x, sizeof(double));
		file.read((char *)&s_y, sizeof(double));
		
		file.read((char *)&rownum, sizeof(int));
		file.read((char*)&colnum, sizeof(int));
        file.read((char*)&step, sizeof(double));
		double z = 0.0;
        int index=0;

	//	return;
		//读取z值
		for (int i = 0; i < rownum; i++)
		{
			for (int j = 0; j < colnum; j++)
			{  
                string str;
                
                file.read((char *)&z, sizeof(double));
                index++;
                if (index%colnum==0)
                {
                    str=std::to_string(z)+"\n";
                }
                else
                {
                    str=std::to_string(z)+" ";
                }
                file1<<str;
            }
            s_y+=step;
        }
    }
    return 0;
}

