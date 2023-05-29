/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-02 14:56:22
 * @LastEditTime: 2023-01-06 20:04:58
 * @Description: 实现util.h的方法
 */

#include<bits/stdc++.h>
#include"util.h"
#include"package.h"
#include<mysql.h>
using namespace std;

void util:: showTotalPackageInfo(MYSQL_RES* res)
{
    if(NULL==res)
    {
        cout<<"输入格式有误！"<<endl;
        return;
    }
    if(0==res->row_count)
    {
        cout<<"查询结果为空"<<endl;
        return;
    }
    MYSQL_ROW row;
    cout<<"查询结果为："<<endl;
    cout<<"----------------------------------------------------"<<endl;
    while((row=mysql_fetch_row(res)))
    {
        Package* p;
        if(stoi(row[7])==1)  p=new glass();
        else if(stoi(row[7])==2)  p=new book();
        else if(stoi(row[7])==3)  p=new common_pac();
        p->setNum(stoi(row[0]));
        p->setState(stoi(row[1]));
        p->setSender(char2string(row[2]));
        p->setReceiver(char2string(row[3]));
        p->setSendTime(char2string(row[4]));
        p->setReceiveTime(row[5]);
        p->setWeight(stod(row[6]));
        p->setDescribe(char2string(row[8]));
        p->showInfo();
        cout<<"----------------------------------------------------"<<endl;
    }
}

bool util:: checkRst(MYSQL_RES* res,Package** retp)
{
    if(0==res->row_count)
        return false;
    util tool;
    int lines=mysql_num_rows(res);
    MYSQL_ROW row;

    for(int i=0;i<lines;i++)
    {
        row=mysql_fetch_row(res);
        if(stoi(row[7])==1)
            retp[i]=new glass();
        else if(stoi(row[7])==2)
            retp[i]=new book();
        else if(stoi(row[7])==3)
            retp[i]=new common_pac();
        (*retp[i]).setNum(stoi(row[0]));
        (*retp[i]).setState(0);
        (*retp[i]).setSender(char2string(row[2]));
        (*retp[i]).setReceiver(char2string(row[3]));
        (*retp[i]).setSendTime(char2string(row[4]));
        (*retp[i]).setReceiveTime(char2string(row[5]));
        (*retp[i]).setWeight(stod(row[6]));
        (*retp[i]).setDescribe(char2string(row[8]));
    }
    return true;
}

string util:: char2string(const char* str)
{
    string s(str);
    return s;
}