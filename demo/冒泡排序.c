#include<stdio.h>

void sort(int a[])
{
    int temp;
    for (int i=0; i<10;i++)
    {
        for (int j = i; j< 10; j++)
        {
          if(a[i]<a[j]){
              temp=a[i];
              a[i]=a[j];
              a[j]=temp;
          }

        }
        
    }

}

 int main()
 {
     int a[10]={2,4,6,5,1,9,7,10,8,3};
     sort(a);
     int i=0;
     for(i=0;i<10;i++)
     {
         printf("%d ",a[i]);
     }
     printf("\n");
     char *p="ksjkajdsalkjasdlkjas";
     printf("%d\n",sizeof(p));
     return 0;
 }