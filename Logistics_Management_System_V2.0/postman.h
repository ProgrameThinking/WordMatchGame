/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-06 10:49:28
 * @LastEditTime: 2023-01-06 16:16:29
 * @Description: 实现快递员的类
 */
#ifndef POSTMAN_H_
#define POSTMAN_H_
#include<bits/stdc++.h>
using namespace std;

class postman
{
    private:
        string uname;           //快递员账户名
        string pwd;             //快递员密码
        string rname;           //快递员真实姓名
        string phoneNum;        //快递员电话号码
        double accBalance;      //快递员账户余额
        int st;              //快递员是否任职于该家物流公司
    public:
        /* 构造方法 */
        postman();
        postman(string username,string password,string realname,string phoneNumber,double accountBalance,int state);
        /* 私有元素set方法 */
        void setUsername(string username);              //设置账户用户名
        void setPassword(string password);              //设置账户密码
        void setRealName(string realname);              //设置账户真实姓名
        void setphoneNumber(string phoneNumber);        //设置账户电话号码
        void setAccountBalance(double accountBalance);  //设置商户余额
        void setState(int state);                       //设置账户主是否在本公司
        /* 私有元素get方法 */
        string getUsername();           //设置账户用户名
        string getPassword();           //设置账户密码
        string getRealName();           //设置账户真实姓名
        string getphoneNumber();        //设置账户电话号码
        double getAccountBalance();     //设置商户余额
        int getState();                 //设置账户主是否在本公司
        /* 快递员操作 */
        void changePassword();      //修改账户密码
        void pickupPackage();       //揽收包裹
        void showinfo();            //展示快递员信息
        void accSender();           // 根据寄件人查询快递
        void accReceiver();         //根据收件人查询快递
        void accTime();             // 根据时间查找快递
        void accNum();              // 根据单号查找快递
        void accState();            //根据快递状态查找快递
        double getBalance();          //得到账户余额
        /* 快递员操作总界面 */
        void mainPage();

};
#endif