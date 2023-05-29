/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-02 16:48:44
 * @LastEditTime: 2023-01-03 16:48:31
 * @Description: 定义物流公司管理员的类
 */

#ifndef ADMIN_H_
#define ADMIN_H_
#include<bits/stdc++.h>
using namespace std;

class admin
{
    private:
        string uname;           //管理员用户名
        string pwd;             //管理员密码
        string rname;           //管理员真实姓名
        double accBalance;  //管理员账户余额
    public:
        /*构造方法*/
        admin();
        admin(string username,string password,string realName,double accountBalance);
        /*私有变量的set方法*/
        void setUserName(string username);             // 设置管理员用户名
        void setPassword(string password);             // 设置管理员密码
        void setRealName(string realName);             // 设置管理员真实姓名
        void setAccountBalance(double accountBalance); // 设置管理员账户余额
        /*管理员操作*/
        void showAllUsers();  // 查看所有用户信息
        void showAllParcel(); // 查看所有快递信息
        void accUser();       // 根据用户名查找快递
        void accTime();       // 根据时间查找快递
        void accNum();        // 根据单号查找快递
        /*管理员操作的主界面*/
        void mainPage();
};
#endif