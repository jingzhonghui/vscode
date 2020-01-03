/*
 * @Descripttion: 
 * @version: 
 * @Date: 2019-08-05 10:46:57
 * @LastEditTime: 2019-11-18 21:32:44
 */
#include<iostream>
#include<fstream>
#include<string>
#include<cstdio>
#include<cstdlib>
using namespace std;

typedef struct list_len
{
	int data;
	struct list_len *next;
}LIST,*p_LIST;


//头插法建立链表
void node1(LIST **head,LIST **tile)
{
	int i;
	LIST *new_data=NULL;
	for(i=0;i<4;i++)
	{
		new_data=(LIST *)malloc(sizeof(LIST));
		new_data->data=i*5+33;
		new_data->next=NULL;
		//如果链表为空
		if(*head==NULL)
		{
			*head=new_data;
			*tile=new_data;
		}
		else
		{
			new_data->next=*head;
			*head=new_data;
		}
		
	}
}

//遍历打印
void put(LIST *tem)
{
	while(tem!=NULL)
	{
		printf("%d ",tem->data);
		tem=tem->next;
	}
	printf("\n");
}


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