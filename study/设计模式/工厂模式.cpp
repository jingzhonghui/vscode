/*
 * @Descripttion: 
 * @version: 
 * @Date: 2019-08-12 22:30:20
 * @LastEditTime: 2019-08-12 22:43:57
 */
#include<iostream>
#include<string>
using namespace std;

//水果抽象类
class Fruit
{
public:
    virtual void getname()=0;
};

//具体水果类
class Apple:public Fruit
{
public:
    virtual void getname()
    {
        cout<<"i am apple"<<endl;
    }
};

class Banane:public Fruit
{
public:
    virtual void getname()
    {
        cout<<"i am banbane"<<endl;
    }
};

//工厂抽象类
class agc
{
public:
    virtual Fruit *creatfruit()=0;
};

//具体的工厂
class applegc:public agc
{
public:
    virtual Fruit *creatfruit()
    {
        return new Apple;
    }
};

class bananegc:public agc
{
public:
    virtual Fruit *creatfruit()
    {
        return new Banane;
    }
};

int main()
{
    Fruit *f=NULL;
    agc *g=NULL;

    //生产苹果，线新建一个苹果工厂，然后在生产苹果
    g=new applegc;
    f=g->creatfruit();
    f->getname();

    delete g;
    delete f;

    //生产香蕉，先新建一个香蕉工厂，在生产香蕉
    g=new bananegc;
    f=g->creatfruit();
    f->getname();

    delete g;
    delete f;

    return 0;
}




