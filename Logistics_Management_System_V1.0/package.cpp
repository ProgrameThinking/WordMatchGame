/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-01 16:34:14
 * @LastEditTime: 2023-01-03 21:19:04
 * @Description: 实现package.h中的方法
 */

#include<bits/stdc++.h>
#include"package.h"
using namespace std;

/*类构造函数*/
Package:: Package(){}
Package::Package(const int num,const int st,const string sName,const string rName,const string sTime,const string rTime,const string des)
{
    number=num;   
    state=st;   
    sender=sName;
    receiver=rName;
    sendT=sTime;
    receiveT=rTime;
    describe=des;
}
/*私有成员的set方法*/
void Package::setNum(const int num)
{
    number=num;
}
void Package::setState(const int st)
{
    state=st;
}
void Package::setSender(const string sName)
{
    sender=sName;
}
void Package::setReceiver(const string rName)
{
    receiver=rName;
}
void Package::setSendTime(const string sTime)
{
    sendT=sTime;
}
void Package::setReceiveTime(const string rTime)
{
    receiveT=rTime;
}
void Package::setDescribe(const string des)
{
    describe=des;
}
/*私有成员get方法*/
int  Package::getState()
{
    return state;
}
int Package::getNumber()
{
    return number;
}
/*输出这件快件的信息*/
void Package::showInfo()
{
    cout<<"快递单号："<<number<<endl;
    if(state==1)
        cout<<"快递状态：已签收"<<endl;
    else if(state==0)
        cout<<"快递状态：未签收"<<endl;
    cout<<"寄件人："<<sender<<endl;
    cout<<"收件人："<<receiver<<endl;
    cout<<"寄件时间："<<sendT<<endl;
    if(""!=receiveT)
        cout<<"收件时间："<<receiveT<<endl;
    if(""!=describe)
        cout<<"快递描述："<<describe<<endl;
}