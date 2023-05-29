/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-02 16:48:44
 * @LastEditTime: 2023-01-06 17:58:42
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

        /* 实现管理员操作的函数 */
        void showAllUsers();  // 查看所有用户信息
        void showAllParcel(); // 查看所有快递信息
        bool showAllPostman();// 查看所有快递员
        void accUser();       // 根据用户名查找快递
        void accTime();       // 根据时间查找快递
        void accNum();        // 根据单号查找快递
        void accPostman();    // 根据快递员查看其揽收投递的所有快递
        void accSender();     // 根据寄件人查询快递
        void accReceiver();   //根据收件人查询快递
        void distributePostman();// 将揽收快递分配给快递员
        void managerPostman();  // 管理快递员
        /* 辅助实现上面函数的方法 */
    public:
        /* 构造方法 */
        admin();
        admin(string username,string password,string realName,double accountBalance);
        /* 私有变量的set方法 */
        void setUserName(string username);             // 设置管理员用户名
        void setPassword(string password);             // 设置管理员密码
        void setRealName(string realName);             // 设置管理员真实姓名
        void setAccountBalance(double accountBalance); // 设置管理员账户余额
        /* 管理员操作的主界面 */
        void mainPage();
};
#endif