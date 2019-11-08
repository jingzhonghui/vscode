#include<iostream>
#include<time.h>
#include<string>
#include<list>
#include<algorithm>
using namespace std;


void print(int a)
{
    cout<<a<<" ";
}

void main1()
{
    list<int> L;
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        L.push_back(rand()%10);
    }
    for_each(L.begin(),L.end(),print);
    cout<<endl;
    L.reverse();
    for_each(L.begin(),L.end(),print);
    cout<<endl;
    return ;
}

int main()
{
    main1();
    return 0;
}