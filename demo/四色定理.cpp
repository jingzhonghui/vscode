/*
 * @Descripttion: 
 * @version: 
 * @Date: 2019-09-02 17:22:39
 * @LastEditTime: 2019-09-02 18:28:45
 */
#include <iostream>
 
 using namespace std;
 
 /* *************************************
  *
  *            Four Color Label
  *
  * *************************************/
 
 /* *************************************
  *           Main Function
  *  Para:
  *      @Adj: Adjacent Matrix
  *      @Record: Record the labeled results
  *      @cur: current index
  *      @n: The number of regions
  *
  * *************************************/
 void FourColorLabel(int Adj[][6], int* Record, int cur, int n);
 
 /* *************************************
  *           CheckOk
  *  Para:
  *      @Adj: Adjacent Matrix
  *      @Record: Record the labeled results
  *      @cur: current index
  *      @clabel: The label of cur
  *
  * Check "color the cur region with clabel" is ok or not
  * *************************************/
 bool CheckOk(int Adj[][6], int *Record, int cur, int clabel);
 
 int main()
 {
 
 
     /* ****************************************************
      *
      *     Test CASE
      *
      *     ----------------------
      *     | 1   /   2  /       |
      *     |    /-------/   3   |
      *     |---/        \-------|
      *     |     4       /      |
      *     |------------/  5    |
      *     |             \------|
      *     |    6        /      |
      *     |            /    7  |
      *     ----------------------
      * ****************************************************/
    /*  int Adj[7][7] = { {0, 1, 0, 1, 0, 0, 0},
                       {1, 0, 1, 1, 0, 0, 0},
                       {0, 1, 0, 1, 1, 0, 0},
                       {1, 1, 1, 0, 1, 1, 0},
                       {0, 0, 1, 1, 0, 1, 1},
                       {0, 0, 0, 1, 1, 0, 1},
                       {0, 0, 0, 0, 1, 1, 0} }; */
int Adj[6][6] = { {0,1,1,1,0,0},
    {1,0,0,0,1,1},
    {1,0,0,1,0,0},
    {1,0,1,0,1,0},
    {0,1,0,1,0,1},
    {0,1,0,0,1,0}};
 
 
 
     int Record[6] = {0};
 
     FourColorLabel(Adj, Record, 0, 6);
 
     for(int i=0; i < 6; i++)
     {
         cout << Record[i] << " ";
     }
     cout << endl;
 
     return 0;
 }
 void FourColorLabel(int Adj[][6], int* Record, int cur, int n)
 {
     // Index exceed, then return
     if(cur<0 || cur >= n)
     {
         // Break Out
         return;
     }
     int clabel=0;
     if(Record[cur] != 0)
     {
         int flag = 0;
         for(clabel = Record[cur]+1; clabel <= 4; clabel++)
         {
             if(CheckOk(Adj, Record, cur, clabel))
             {
                 Record[cur] = clabel;
                 flag = 1;
                 break;
             }
         }
         // IF 成功标记
         if(flag == 1)
         {
             FourColorLabel(Adj, Record, cur+1, n);
         }
         // ELSE 不成功，返回上一步
         else
         {
             FourColorLabel(Adj, Record, cur-1, n);
         }
     }
 
 
     int flag = 0;
     for(clabel = 1; clabel <= 4; clabel++)
     {
         if(CheckOk(Adj, Record, cur, clabel))
         {
             Record[cur] = clabel;
             flag = 1;
             break;
         }
     }
     // IF 成功标记
     if(flag == 1)
     {
         FourColorLabel(Adj, Record, cur+1, n);
     }
     // ELSE 不成功，返回上一步
     else
     {
         FourColorLabel(Adj, Record, cur-1, n);
     }
 
 }
 
 bool CheckOk(int Adj[][6], int* Record, int cur, int clabel)
 {
     int i = 0;
     for(;i < cur; i++)
     {
         // IF 相邻 && 标记相同
         if(Adj[i][cur]==1 && Record[i]==clabel)
         {
             return false;
         }
     }
     return true;
 }