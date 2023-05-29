/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-01 16:34:14
 * @LastEditTime: 2023-01-06 19:51:02
 * @Description: 实现package.h中的方法
 */

#include<bits/stdc++.h>
#include"package.h"
using namespace std;

/*类构造函数*/
Package:: Package(){}
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
void Package::setWeight(const double weight)
{
    w=weight;
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

/*glass类方法实现*/
glass::glass(){}
glass::glass(const int num,const int st,const double weight,const string sName,const string rName,const string sTime,const string rTime,const string des)
{
    number=num;   
    state=st;   
    w=weight;
    sender=sName;
    receiver=rName;
    sendT=sTime;
    receiveT=rTime;
    describe=des;
}
double glass::getPrice()
{
    return w*unit_price;
}

void glass::showInfo()
{
    cout<<"快递单号："<<number<<endl;
    cout<<"快递类型：易碎品"<<endl;
    cout<<"快递重量："<<w<<endl;
    cout<<"快递费："<<getPrice()<<endl;
    if(state==2)
        cout<<"快递状态：已签收"<<endl;
    else if(state==1)
        cout<<"快递状态：待签收"<<endl;
    else if(state==0)
        cout<<"快递状态：待揽收"<<endl;
    cout<<"寄件人："<<sender<<endl;
    cout<<"收件人："<<receiver<<endl;
    cout<<"寄件时间："<<sendT<<endl;
    if(sendT!=receiveT)
        cout<<"收件时间："<<receiveT<<endl;
    if(""!=describe)
        cout<<"快递描述："<<describe<<endl;
}

/*book类方法实现*/
book::book(){}
book::book(const int num,const int st,const double weight,const string sName,const string rName,const string sTime,const string rTime,const string des)
{
    number=num;   
    state=st;   
    w=weight;
    sender=sName;
    receiver=rName;
    sendT=sTime;
    receiveT=rTime;
    describe=des;
}
double book::getPrice()
{
    return w*unit_price;
}

void book::showInfo()
{
    cout<<"快递单号："<<number<<endl;
    cout<<"快递类型：图书"<<endl;
    cout<<"快递本数："<<w<<endl;
    cout<<"快递费："<<getPrice()<<endl;
    if(state==2)
        cout<<"快递状态：已签收"<<endl;
    else if(state==1)
        cout<<"快递状态：待签收"<<endl;
    else if(state==0)
        cout<<"快递状态：待揽收"<<endl;
    cout<<"寄件人："<<sender<<endl;
    cout<<"收件人："<<receiver<<endl;
    cout<<"寄件时间："<<sendT<<endl;
    if(sendT!=receiveT)
        cout<<"收件时间："<<receiveT<<endl;
    if(""!=describe)
        cout<<"快递描述："<<describe<<endl;
}

/*common_pac类方法实现*/
common_pac::common_pac(){}
common_pac::common_pac(const int num,const int st,const double weight,const string sName,const string rName,const string sTime,const string rTime,const string des)
{
    number=num;   
    state=st;   
    w=weight;
    sender=sName;
    receiver=rName;
    sendT=sTime;
    receiveT=rTime;
    describe=des;
}
double common_pac::getPrice()
{
    return w*unit_price;
}

void common_pac::showInfo()
{
    cout<<"快递单号："<<number<<endl;
    cout<<"快递类型：普通货物"<<endl;
    cout<<"快递重量："<<w<<endl;
    cout<<"快递费："<<getPrice()<<endl;
    if(state==2)
        cout<<"快递状态：已签收"<<endl;
    else if(state==1)
        cout<<"快递状态：待签收"<<endl;
    else if(state==0)
        cout<<"快递状态：待揽收"<<endl;
    cout<<"寄件人："<<sender<<endl;
    cout<<"收件人："<<receiver<<endl;
    cout<<"寄件时间："<<sendT<<endl;
    if(sendT!=receiveT)
        cout<<"收件时间："<<receiveT<<endl;
    if(""!=describe)
        cout<<"快递描述："<<describe<<endl;
}

void Package:: showInfo(){}
double Package:: getPrice(){}