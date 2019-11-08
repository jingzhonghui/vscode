/*
 * @Descripttion: 
 * @version: 
 * @Date: 2019-08-22 19:41:09
 * @LastEditTime: 2019-08-28 10:44:57
 */
#include<iostream>
#include <algorithm>
#include<string>
#include<map>
using namespace std;

int main()
{
    map<int,string> mymap;

    mymap.insert(pair<int,string>(2,"I"));
    mymap.insert(pair<int,string>(1,"hello"));
    mymap.insert(pair<int,string>(4,"lisi"));
    mymap.insert(pair<int,string>(3,"am"));

    for (auto it=mymap.begin();it!=mymap.end();it++)
    {
        /* code */
        
        cout<<it->first<<" "<<it->second<<endl;
    }
    /*
        结论：
        map(Qmap)在插入数据是，若键值key的类型为int double float string时，map中的
        数据还会根据key进行自动排序
    */
    string str="123单元456";
    int index=str.find("单元");
    cout<<index<<endl;

    return 0;
}