/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-03 16:17:21
 * @LastEditTime: 2023-01-03 21:38:04
 * @Description: 实现view.h类中的方法
 */

#include<bits/stdc++.h>
#include<mysql.h>
#include"view.h"
#include"mysqlManager.h"
#include"user.h"
#include"util.h"
#include"admin.h"
using namespace std;

void view:: userLogin()
{
    util tool;
    MySQLManager mysql;
    ConnectionInfo info;
    string username,password;
    cout<<"请输入用户名：";
    cin>>username;
    cout<<"请输入密码：";
    cin>>password;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from user where username='"+username+"' and password='"+password+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    if(0==res->row_count)
    {
        cout<<"用户名或者密码错误！"<<endl;
        return;
    }
    MYSQL_ROW row=mysql_fetch_row(res);
    User u(tool.char2string(row[0]),
                tool.char2string(row[1]),
                tool.char2string(row[2]),
                tool.char2string(row[3]),
                stod(row[4]),
                tool.char2string(row[5]));
    u.mainPage();
    mysql.FreeConnect();                  /*关闭数据库链接*/
}
void view:: adminLogin()
{
    util tool;
    MySQLManager mysql;
    ConnectionInfo info;
    string username,password;
    cout<<"请输入用户名：";
    cin>>username;
    cout<<"请输入密码：";
    cin>>password;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from admin where username='"+username+"' and password='"+password+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    if(0==res->row_count)
    {
        cout<<"用户名或者密码错误！"<<endl;
        return;
    }
    MYSQL_ROW row=mysql_fetch_row(res);
    admin a(tool.char2string(row[0]),
                tool.char2string(row[2]),
                tool.char2string(row[1]),
                stod(row[3]));
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
    a.mainPage();
}

void view:: userRegister()
{
    util tool;
    User u;
    string str,password1,password2;
    /*获取用户信息*/
    cout<<"请输入用户名：";getline(cin,str,'\n');
    cout<<"请输入密码：";getline(cin,password1,'\n');
    cout<<"请再次输入密码：";getline(cin,password2,'\n');
    if(password1!=password2)
    {
        cout<<"两次输入密码不一致！"<<endl;
        return;
    }
    u.setUserName(str);
    u.setPassword(password1);
    cout<<"请输入您的真实姓名：";getline(cin,str,'\n');
    u.setRealName(str);
    cout<<"请输入您的电话号码：";getline(cin,str,'\n');
    u.setTelephoneNum(str);
    u.setaccBalance(0);
    cout<<"请输入您的收货地址：";getline(cin,str,'\n');
    u.setAddress(str);

    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="insert into user values('"+u.getUserName()+"','"+u.getPassword()+"','"+u.getRealName()+"','"+u.getPhoneNumber()+"',"+to_string(u.getAccountBalance())+",'"+u.getAddress()+"')";
    mysql.ExecuteSql(sql.c_str());        /*执行sql语句*/
    mysql.FreeConnect();                  /*关闭数据库链接*/
    cout<<"注册成功！"<<endl;
}

void view:: mainPage()
{
    cout<<"欢迎来到物流管理系统（V1.0）"<<endl;
    cout<<"您可以进行如下操作："<<endl;
    while(true)
    {
        cout<<"1.作为用户注册"<<endl;
        cout<<"2.作为用户登录"<<endl;
        cout<<"3.作为管理员登录"<<endl;
        cout<<"0.退出本系统"<<endl;
        cout<<"请输入操作代码：";
        int choice;
        cin>>choice;getchar();
        if(choice==1)
            userRegister();
        else if(choice==2)
            userLogin();
        else if(choice==3)
            adminLogin();
        else if(choice==0)
        {
            cout<<"下次再见"<<endl;
            break;
        }
        else
            cout<<"请输入规定操作!"<<endl;
        cout<<"请继续操作！"<<endl;
    }
}