/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-03 16:17:17
 * @LastEditTime: 2023-01-06 16:05:58
 * @Description: 证明实现命令行窗口的界面的类
 */

#ifndef VIEW_H_
#define VIEW_H_

class view
{
    public:
        void adminLogin();      //管理员登陆
        void userLogin();       //用户登录
        void postmanlogin();    //快递员登录
        void userRegister();    //用户注册
        void postmanRegister(); //快递员注册
        void mainPage();        //主界面
};

#endif