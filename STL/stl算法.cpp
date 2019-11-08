/*
    vector容器的基本使用
    list容器的基本使用
    容器成员函数remove() and remove_if()函数的使用
    stl算法 remove() and remove_if() 函数的使用
*/

#include <iostream>
#include<algorithm>
#include<vector>
#include<list>

using namespace std;


bool test(int a)
{
    if(a==5)
    return true;
    else
    {
        return false;
    }
    
}

//vector容器
int main1()
{
    int a[6]={1,2,5,4,6,7};
    vector<int> temp(a,a+6);
    vector<int>::iterator it;
    for (it  = temp.begin(); it< temp.end(); it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    //条件查找
    it=find_if(temp.begin(),temp.end(),test);
    
    cout<<*it<<endl;
    return 0;
}

//list容器
int main2()
{
    list<int> v;
    v.push_back(12);
    v.empty();  //判断是否为空
    v.clear();
    for(int i=0;i<10;i++)
    {
        v.push_back(i);
    }
    list<int>::iterator it;
    for(it=v.begin();it!=v.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;

    list<int> p;
    p.assign(v.begin(),v.end());    //assign重置list元素，初始化或者复制list时非常方便

    for(it=p.begin();it!=p.end();it++)
    {
        cout<<*it<<" ";
    }
    cout<<endl;
    cout<<"p的长度为:"<<p.size()<<endl;
}


void print(int &a)
{
    cout<<a<<" ";

}

bool func(int a)
{
    if(a>5)
        return true;
    else
    {
        return false;
    }
        
    
}

//remove and remove_if的使用
//容器的成员函数remove后直接跟要删除的数字，remove_if参数为仿函数，bool func()
int main()
{

    list<int> q;
    /* for(int i=0;i<10;i++)
    {
        q.push_back(i+1);
    }
    for_each(q.begin(),q.end(),print);
    cout<<endl;

    q.remove(2);  
    for_each(q.begin(),q.end(),print);
    cout<<endl;

    q.remove_if(func);
    for_each(q.begin(),q.end(),print);
    cout<<endl;

    q.clear(); */
    for(int i=0;i<10;i++)
    {
        q.push_back(i+1);
    }
    //算法remove
    remove(q.begin(),q.end(),2);
    for_each(q.begin(),q.end(),print);
    cout<<endl;
    //注意：remove_if()的参数是迭代器，前两个参数表示迭代器的起始位置和这个起始位置对应的停止位置，最后一个参数传入一个回调函数
    //若返回值为真，则将当前所指向的参数移动到尾部，返回值是被移动区域的首个元素
    //注意：remove_if不会直接删除满足条件的值，返回被移动区域的首个元素，配合erase()函数达到删除目的
    q.erase(remove_if(q.begin(),q.end(),func),q.end());
    for_each(q.begin(),q.end(),print);
    cout<<endl;


    return 0;
}