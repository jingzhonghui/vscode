/*
 * @Descripttion: 
 * @version: 
 * @Date: 2019-09-02 18:28:52
 * @LastEditTime: 2019-10-05 22:37:33
 */
//二维动态数组
#include <iostream>
#include<cstring>
#include<cstdlib>
#include<ctime>
#include<cstring>

using namespace std;

int find_arr(int *a,int num)
{
    if (a==NULL)
    return 0;
    int i=0;
    for ( i = 0; i < 10; i++)
    {
        if (a[i]==num)
        {
            return 1;
        }
    }
    return 0;
}

void sort_suiji(int *a)
{
    if (a==NULL)
    {
      return;
    }
    int i=0;
    int temp_arr[10];
    memset(temp_arr,-1,sizeof(temp_arr));
    i=0;
    while (i<10)
    {
        int j=rand()%10;
        if(!find_arr(temp_arr,j))
        {
            temp_arr[i]=j;
            i++;
        }
    }
    for(i=0;i<10;i++)
    {
       cout<<temp_arr[i]<<" ";
    }
    cout<<endl;
    int temp_a[10]={0};
     for(i=0;i<10;i++)
    {
      temp_a[i]=a[temp_arr[i]];
    }
     for(i=0;i<10;i++)
    {
      a[i]=temp_a[i];
    }
}
 
 int main()
 {
     srand(time(NULL));
     int a[10]={1,2,3,4,5,6,7,8,9,10};
     printf("sort befo:\n");
    for(int i=0;i<10;i++)
    {
        cout <<a[i]<<" ";
    }
    cout<<endl;
     sort_suiji(a);
     printf("sort after:\n");
     for(int i=0;i<10;i++)
    {
        cout <<a[i]<<" ";
    }
    cout<<endl;

     return 0;
 }