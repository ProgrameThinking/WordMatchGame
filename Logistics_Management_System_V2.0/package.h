/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-01 16:34:05
 * @LastEditTime: 2023-01-06 16:31:08
 * @Description: 存储快递信息的类
 */
#ifndef PACKAGE_H_
#define PACKAGE_H_
#include<bits/stdc++.h>
using namespace std;

class Package
{
    protected:
        int number;     //快递单号，由系统自动产生
        int state;      //快递状态：0--未揽收；1--已揽收；2--已签收
        double w;       //存储重量或本数
        string sender;  //寄件人
        string receiver;//收件人
        string sendT;   //寄件时间
        string receiveT;//收件时间
        string describe;//快件描述（可为空）
    public:
        /* 构造函数 */
        Package();
        /* 私有成员的get方法 */
        int getState();                           //得到快递状态
        /* 私有成员的set方法 */
        void setWeight(const double weight);      //设置重量
        void setNum(const int num);               //设置快递单号
        void setState(const int st);              //设置快递状态
        void setSender(const string sName);       //设置寄件人
        void setReceiver(const string rName);     //设置收件人
        void setSendTime(const string sTime);     //设置寄件时间
        void setReceiveTime(const string rTime);  //设置收件时间
        void setDescribe(const string des);       //设置快递描述
        /* 私有成员的get方法 */
        int getNumber();    //返回快递单号

        /* 虚方法 */
        virtual void showInfo();    /*输出这件快件的信息*/
        virtual double getPrice();  //得到物品价格
};

class glass: public Package
{
    private:
        const int unit_price=8; //单价
    public:
        /* 构造函数 */
        glass();
        glass(const int num,const int st,const double weight,const string sName,const string rName,const string sTime,const string rTime,const string des);
        /* 得到快递费 */
        double getPrice();
        /* 输出这件快递的信息 */
        void showInfo();
};

class book: public Package
{
    private:
        const int unit_price=2; //单价
    public:
        /* 构造函数 */
        book();
        book(const int num,const int st,const double weight,const string sName,const string rName,const string sTime,const string rTime,const string des);
        /* 得到快递费 */
        double getPrice();
        /* 输出这件快递的信息 */
        void showInfo();
};

class common_pac: public Package
{
    private:
        const int unit_price=5; //单价
    public:
        /* 构造函数 */
        common_pac();
        common_pac(const int num,const int st,const double weight,const string sName,const string rName,const string sTime,const string rTime,const string des);
        /* 得到快递费 */
        double getPrice();
        /* 输出这件快递的信息 */
        void showInfo();
};

#endif