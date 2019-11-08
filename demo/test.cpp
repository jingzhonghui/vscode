/*
 * @Descripttion: 
 * @version: 
 * @Date: 2019-09-02 17:22:39
 * @LastEditTime: 2019-11-07 17:45:07
 */
#include<iostream>
#include<string>
#include <list>
#include<algorithm>


using namespace std;

class A
{
private:
    /* data */
public:
  virtual void vfunc()
  {
      cout<<"A"<<endl;
  }
  void func()
  {
      cout<<"A A"<<endl;
  }
};

class B:public A
{
private:
    /* data */
public:
    virtual void vfunc()
    {
        cout<<"B"<<endl;
    }
    void func()
    {
        cout<<"B B"<<endl;
    }
    void func1()
    {
        cout<<"123"<<endl;
    }
};

class  c:public A
{
private:
    /* data */
public:
    virtual void vfunc()
    {
        cout<<"C"<<endl;
    }
    void func()
    {
        cout<<"C C"<<endl;
    }
    
};








int main()
{
   
    A *a=new B;
    a->vfunc();
    a->func();
   return 0;
}


