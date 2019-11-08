/*
 * @Descripttion: c++11多线程
 * @version: 
 * @Date: 2019-08-08 15:11:42
 * @LastEditTime: 2019-08-08 15:37:50
*/
#include<iostream>
#include<string>
#include<thread>
using namespace std;

//无参线程函数
void func()
{
    cout<<"hello i am is thread"<<endl;
}

//带参线程函数
void func1(void *str)
{
    cout <<(char *)str<<endl;
}

//对象的成员函数作为线程函数
class t
{
private:
    /* data */
public:
    void func2(void *str);
};

void t::func2(void *str)
{
    cout<<(char *)str<<endl;
}

/*不带参数线程 测试*/
int main1()
{
    thread Thread(func);    //创建线程执行func函数
    Thread.join();  //等待线程结束
    return 0;
}
/**
 * @description: 带参数线程函数测试
 * @param {type} 
 * @return: 
 */
int main2()
{
    thread Thread(func1,(void *)"hello");
    Thread.join();
    return 0;
}

//对象的成员函数作为线程函数测试
int main()
{
    t T;
    thread Thread(T.func2,T,(void *)"hello i am a class func");
    Thread.join();
    return 0;
}