/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-01 16:34:05
 * @LastEditTime: 2023-01-03 21:18:42
 * @Description: 存储快递信息的类
 */
#ifndef PACKAGE_H_
#define PACKAGE_H_
#include<bits/stdc++.h>
using namespace std;

class Package
{
    private:
        int number;     //快递单号，由系统自动产生
        int state;      //快递状态：0--未接收；1--接收
        string sender;  //寄件人
        string receiver;//收件人
        string sendT;   //寄件时间
        string receiveT;//收件时间
        string describe;//快件描述（可为空）
    public:
        /*构造函数*/
        Package();
        Package(const int num,const int st,const string sName,const string rName,const string sTime,const string rTime,const string des);
        /*私有成员的get方法*/
        int getState();                           //得到快递状态
        /*私有成员的set方法*/
        void setNum(const int num);               //设置快递单号
        void setState(const int st);              //设置快递状态
        void setSender(const string sName);       //设置寄件人
        void setReceiver(const string rName);     //设置收件人
        void setSendTime(const string sTime);     //设置寄件时间
        void setReceiveTime(const string rTime);  //设置收件时间
        void setDescribe(const string des);       //设置快递描述
        /*私有成员的get方法*/
        int getNumber();    //返回快递单号
        /*输出这件快件的信息*/
        void showInfo();
};

#endif