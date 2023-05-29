/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-01 16:25:00
 * @LastEditTime: 2023-01-03 19:48:10
 * @Description: 存储用户信息的类
 */

#ifndef USER_H_
#define USER_H_

#include<bits/stdc++.h>
#include<mysql.h>
#include"package.h"
using namespace std;

class User
{
    private:
        string uname;       //用户名
        string pwd;         //用户密码
        string rname;       //用户真实姓名
        string telNum;      //用户电话
        double accBalance;  //用户账户余额
        string addr;        //用户住址
        
        /*四种私有的查询方法实现和辅助输出的方法*/
        
        void accSender();                           //按寄件人查询
        void accReceiver();                         //按收件人查询
        void accSendTime();                         //按寄件时间查询
        void accNum();                              //按快递单号查询
        void showUnsignParcel();                    //显示所有未签收的快递             
    public:
        /*构造函数*/
        User();
        User(const string username,const string password,const string realName,const string telephoneNum, const double balance,const string address);
        /*私有成员的get方法*/
        string getUserName();                       //获取用户名
        string getPassword();                       //获取用户密码
        string getRealName();                       //获取用户真实姓名
        string getPhoneNumber();                    //获取用户电话号码
        double getAccountBalance();                 //获取用户账户余额
        string getAddress();                        //获取用户地址
        /*私有成员的set方法*/
        void setUserName(const string username);        //设置用户名
        void setPassword(const string password);        //设置密码
        void setRealName(const string realName);        //设置用户真实姓名
        void setTelephoneNum(const string telephoneNum);//设置用户手机号
        void setaccBalance(const double balance);       //设置用户余额
        void setAddress(const string address);          //设置用户地址
        
        /*对账户进行操作的方法*/
        void changePwd();    //用户自己更改密码
        void addBalance();    //用户充值
        void sendParcel();             //用户邮寄包裹
        bool receiveParcel(Package p);          //用户收取包裹
        void checkParcel();                     //用户查看自己的包裹
        void showInfo();                //显示用户全部信息

        /*用户的主界面*/
        void mainPage();
};

#endif