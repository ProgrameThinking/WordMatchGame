/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-02 16:56:54
 * @LastEditTime: 2023-01-03 22:14:21
 * @Description: 实现admin.h内的方法
 */

#include<bits/stdc++.h>
#include<mysql.h>
#include"user.h"
#include"admin.h"
#include"package.h"
#include"util.h"
#include"mysqlManager.h"
using namespace std;

/*构造方法*/
admin:: admin(){}

admin:: admin(string username,string password,string realName,double accountBalance)
{
    uname=username;
    pwd=password;
    rname=realName;
    accBalance=accountBalance;
}

/*私有变量的set方法*/
void admin:: setUserName(string username)
{
    uname=username;
}

void admin:: setPassword(string password)
{
    pwd=password;
}

void admin:: setRealName(string realName)
{
    rname=realName;
}

void admin:: setAccountBalance(double accountBalance)
{
    accBalance=accountBalance;
}
/*管理员操作*/
void admin:: showAllUsers()
{
    MySQLManager mysql;
    ConnectionInfo info;
    util tool;
    MYSQL_ROW row;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }

    string sql="select * from user";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    cout<<"查询结果为："<<endl;
    while((row=mysql_fetch_row(res)))
    {
        User u(tool.char2string(row[0]),
                tool.char2string(row[1]),
                tool.char2string(row[2]),
                tool.char2string(row[3]),
                stod(row[4]),
                tool.char2string(row[5]));
        u.showInfo();
        cout<<"----------------------------------------------------"<<endl;
    }
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
}  

void admin:: showAllParcel()
{
    MySQLManager mysql;
    ConnectionInfo info;
    util tool;
    MYSQL_ROW row;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }

    string sql="select * from package";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    cout<<"查询结果为："<<endl;
    while((row=mysql_fetch_row(res)))
    {
        string rtime;
        if(stoi(row[1])==0)
            rtime="";
        else if(stoi(row[1])==1)
            rtime=tool.char2string(row[5]);
        Package p(
                    stoi(row[0]),stoi(row[1]),
                    tool.char2string(row[2]),
                    tool.char2string(row[3]),
                    tool.char2string(row[4]),rtime,
                    tool.char2string(row[6])
                    );
        
        p.showInfo();
        cout<<"----------------------------------------------------"<<endl;
    }
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
} 

void admin:: accUser()
{
    string username;
    util tool;
    cout<<"请输入查询的用户名：";
    getline(cin,username);
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_uname='"+username+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
} 

void admin:: accTime()
{
    string stime;
    util tool;
    cout<<"请输入寄件/收件时间(格式：yyyy-mm-dd hh-mm-ss)："<<endl;
    getline(cin,stime);
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_sendTime='"+stime+"' or tracking_receiveTime='"+stime+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
} 

void admin:: accNum()
{
    string number;
    util tool;
    cout<<"请输入快递单号：";
    cin>>number;
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_num='"+number+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
}         

void admin:: mainPage()
{
    cout<<"欢迎您！管理员"+uname<<endl;
    cout<<"您可以执行如下操作："<<endl;
    while(true)
    {
        cout<<"1.查看所有用户信息"<<endl;
        cout<<"2.查看所有快递信息"<<endl;
        cout<<"3.根据时间查询快递信息"<<endl;
        cout<<"4.根据单号查询快递信息"<<endl;
        cout<<"0.退出登录"<<endl;
        int choice;
        cout<<"请输入操作代码：";
        cin>>choice;getchar();
        if(choice==1)
            showAllUsers();
        else if(choice==2)
            showAllParcel();
        else if(choice==3)
            accTime();
        else if(choice==4)
            accNum();
        else if(choice==0)
            break;
        else
            cout<<"请输入指定的操作代码！"<<endl;
    }
}