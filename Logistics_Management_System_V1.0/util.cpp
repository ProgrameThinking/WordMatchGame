/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-02 14:56:22
 * @LastEditTime: 2023-01-03 22:07:31
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
    util tool;
    MYSQL_ROW row;
    cout<<"查询结果为："<<endl;
    cout<<"----------------------------------------------------"<<endl;
    while((row=mysql_fetch_row(res)))
    {
        string rtime;
        if(stoi(row[1])==0)
            rtime="";
        else if(stoi(row[1])==1)
            rtime=tool.char2string(row[5]);
        Package p(
                    stoi(row[0]),stoi(row[1]),
                    tool.char2string(row[2]),
                    tool.char2string(row[3]),
                    tool.char2string(row[4]),rtime,
                    tool.char2string(row[6])
                    );
        
        p.showInfo();
        cout<<"----------------------------------------------------"<<endl;
    }
}

Package* util:: checkRst(MYSQL_RES* res)
{
    if(0==res->row_count)
        return NULL;
    util tool;
    int lines=mysql_num_rows(res);
    MYSQL_ROW row;
    Package* retp=new Package[lines];

    for(int i=0;i<lines;i++)
    {
        row=mysql_fetch_row(res);
        retp[i].setNum(stoi(row[0]));
        retp[i].setState(0);
        retp[i].setSender(tool.char2string(row[2]));
        retp[i].setReceiver(tool.char2string(row[3]));
        retp[i].setSendTime(tool.char2string(row[4]));
        retp[i].setReceiveTime("");
        retp[i].setDescribe(tool.char2string(row[6]));
    }
    return retp;
}

string util:: char2string(const char* str)
{
    string s(str);
    return s;
}