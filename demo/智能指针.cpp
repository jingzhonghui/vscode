/*
 * @Descripttion: 
 * @version: 
 * @Date: 2019-09-16 09:52:42
 * @LastEditTime: 2019-10-15 20:06:52
 */
#include<iostream>
#include<memory.h>
#include<memory>
#include<string.h>
using namespace std;

int main()
{
    //允许多个指针指向同一个对象
    shared_ptr<string> p=make_shared<string> ("hello world");
     cout<<*p<<endl;
    string *q=new string("I am xiaona");
    cout<<*q<<endl;
    //"独占"所指向的对象
    unique_ptr<string> ptr(new string("nice"));
     cout<<*ptr<<endl;
    //弱引用，只能访问资源不能影响其生命周期，常配合shared_ptr使用
    weak_ptr<string> t_p(p);
    auto temp=t_p.lock();
    cout<<*temp<<endl;
   
}