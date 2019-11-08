/*strstr strtok
##name=zhangsan;sex=m;age=18;score=99.5##
正则表达式实现
//sscanf(str, "%*[^=]=%[^;];%*[^=]=%c;%*[^=]=%d;%*[^=]=%f##", name,&sex,&age,&score);
%*[^=]：表示过滤掉=号前面的字符。
=：匹配一个等号
%[^;]:读取字符直到遇到;号停止。
;匹配一个;号
%c读取一个%c类型的数据
%d：读取一个%d类型的数据
%f：读取一个%f类型的数据

*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct student
{
	char name[32];
	char sex;
	int age;
	float score;
}STU;

int main(int argc, char const *argv[])
{
    char str[100]="##name=zhangsan;sex=m;age=18;score=99.5##";
    char name[100]="123145,world",sex;
    int age=0;
    float score;
   // memset(name,0,sizeof(name));
    #if 0
    STU s;
    sscanf(str, "%*[^=]=%[^;];%*[^=]=%c;%*[^=]=%d;%*[^=]=%f##", s.name,&s.sex,&s.age,&s.score);

    printf("%s %c %d %0.1f\n",s.name,s.sex,s.age,s.score );
    #endif
    char tmp[100]={0};
    sscanf(name,"%[1-9]",tmp);
    printf("%s\n",tmp );
    return 0;
}
