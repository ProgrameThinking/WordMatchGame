/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-02 16:56:54
 * @LastEditTime: 2023-01-06 19:20:03
 * @Description: 实现admin.h内的方法
 */

#include<bits/stdc++.h>
#include<mysql.h>
#include"postman.h"
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
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();
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
    mysql_free_result(res);
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
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
}         

bool admin:: showAllPostman()
{
    MySQLManager mysql;
    ConnectionInfo info;
    util tool;
    MYSQL_ROW row;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return false;
    }

    string sql="select * from postman";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    if(res->row_count==0)
    {
        cout<<"目前没有任何一名快递员注册！"<<endl;
        return false;
    }
    cout<<"所有快递员："<<endl;
    while((row=mysql_fetch_row(res)))
    {
        postman p(tool.char2string(row[0]),
                tool.char2string(row[1]),
                tool.char2string(row[2]),
                tool.char2string(row[3]),
                stod(row[4]),stoi(row[5]));
        p.showinfo();
        cout<<"----------------------------------------------------"<<endl;
    }
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
    return true;
}

void admin:: accPostman()
{
    string username;
    util tool;
    cout<<"请输入查询的快递员用户名：";
    getline(cin,username);
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_poster='"+username+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
}

void admin:: accSender()
{
    string senderName;
    util tool;
    cout<<"请输入查询的寄件人姓名：";
    getline(cin,senderName);
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_sender='"+senderName+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
}

void admin:: accReceiver()
{
    string receiveName;
    util tool;
    cout<<"请输入查询的收件人姓名：";
    getline(cin,receiveName);
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_receiver='"+receiveName+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
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
        cout<<"3.查看所有快递员信息"<<endl;
        cout<<"4.根据时间查询快递信息"<<endl;
        cout<<"5.根据用户查询快递信息"<<endl;
        cout<<"6.根据快递员查询快递信息"<<endl;
        cout<<"7.根据寄件人查询快递信息"<<endl;
        cout<<"8.根据收件人查询快递信息"<<endl;
        cout<<"9.根据快递单号查询快递信息"<<endl;
        cout<<"10.管理快递员"<<endl;
        cout<<"11.将快递分配给快递员"<<endl;
        cout<<"0.退出登录"<<endl;
        int choice;
        cout<<"请输入操作代码：";
        cin>>choice;getchar();
        if(choice==1)  showAllUsers();
        else if(choice==2)  showAllParcel();
        else if(choice==4)  accTime();
        else if(choice==9)  accNum();
        else if(choice==3)  showAllPostman();
        else if(choice==5)  accUser();
        else if(choice==6)  accPostman();
        else if(choice==7)  accSender();
        else if(choice==8)  accReceiver();
        else if(choice==10)  managerPostman();
        else if(choice==11)  distributePostman();
        else if(choice==0)  break;
        else  cout<<"请输入指定的操作代码！"<<endl;
    }
}

void admin:: distributePostman()
{
    MySQLManager mysql;
    ConnectionInfo info;
    MYSQL_ROW row;
    util tool;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from postman where state=1";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    cout<<"可分配的快递员信息："<<endl;
    while((row=mysql_fetch_row(res)))
    {
        cout<<"----------------------------------------------------"<<endl;
        postman p(tool.char2string(row[0]),
                tool.char2string(row[1]),
                tool.char2string(row[2]),
                tool.char2string(row[3]),
                stod(row[4]),stoi(row[5]));
        p.showinfo();
        cout<<"----------------------------------------------------"<<endl;
    }
    sql="select * from package where tracking_state=0 and tracking_poster is NULL" ;
    res=mysql.QueryData(sql.c_str());
    Package** p=(Package**)malloc(sizeof(Package)*res->row_count);
    int lines=res->row_count;
    if(tool.checkRst(res,p))
    {
        cout<<"未揽收的快递:"<<endl;
        for(int i=0;i<lines;i++)
        {
            string username;
            (*p[i]).showInfo();
            cout<<"请输入该件快递分配快递员的用户名：";
            while(true)
            {
                getline(cin,username);
                sql="select * from postman where state=1 and username='"+username+"'";
                res=mysql.QueryData(sql.c_str());
                if(res->row_count==0)
                {
                    cout<<"快递员用户名有误或快递员不属于该物流公司"<<endl;
                    cout<<"请重新输入：";
                }
                else  break;
            }
            sql="update package set tracking_poster = '"+username+"' where tracking_num="+to_string((*p[i]).getNumber());
            mysql.ExecuteSql(sql.c_str());
            cout<<"操作成功"<<endl;
            cout<<"----------------------------------------------------"<<endl;
        }
    }
    else
        cout<<"没有未揽收的快递!";
    mysql_free_result(res);
    mysql.FreeConnect();
}

void admin:: managerPostman()
{
    if(!showAllPostman())
        return;
    MySQLManager mysql;
    ConnectionInfo info;
    MYSQL_RES* res;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql;
    while(true)
    {
        string username;
        int state;
        cout<<"请输入要操作快递员的用户名：(输入'NULL'退出快递员管理系统)";
        getline(cin,username);
        while(true)
        {
            if("NULL"==username)  break;
            sql="select * from postman where username='"+username+"'";
            res=mysql.QueryData(sql.c_str());
            if(res->row_count==0)
            {
                cout<<"快递员用户名有误"<<endl;
                cout<<"请重新输入(输入'NULL'退出快递员管理系统)：";
                getline(cin,username);
            }
            else  
                break;
        }
        if("NULL"==username)  break;
        cout<<"请输入要进行的操作(0：从快递公司移除该名快递员   1：添加该名快递员进入公司)：";
        cin>>state;getchar();
        while(true)
        {
            if(state==0||state==1)  break;
            else
            {
                cout<<"请输入规定的状态：";
                cin>>state;getchar();
            }
        }
        sql="update postman set state="+to_string(state)+" where username='"+username+"'";
        mysql.ExecuteSql(sql.c_str());
        cout<<"操作成功"<<endl;
        mysql_free_result(res);
        mysql.FreeConnect();
    }
}