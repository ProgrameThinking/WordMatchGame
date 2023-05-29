/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-06 10:49:34
 * @LastEditTime: 2023-01-06 20:24:46
 * @Description: 实现postman.h的方法
 */

#include<bits/stdc++.h>
#include"postman.h"
#include"util.h"
#include"mysqlManager.h"
#include"package.h"
using namespace std;

postman:: postman(){}

postman:: postman(string username,string password,string realname,string phoneNumber,double accountBalance,int state)
{
    uname=username;
    pwd=password;
    rname=realname;
    phoneNum=phoneNumber;
    accBalance=accountBalance;
    st=state;
}

void postman:: setUsername(string username)
{
    uname=username;
}
void postman:: setPassword(string password)
{
    pwd=password;
}
void postman:: setRealName(string realname)
{
    rname=realname;
}
void postman:: setphoneNumber(string phoneNumber)
{
    phoneNum=phoneNumber;
}
void postman:: setAccountBalance(double accountBalance)
{
    accBalance=accountBalance;
}
void postman:: setState(int state)
{
    st=state;
}
string postman:: getUsername()
{
    return uname;
}
string postman:: getPassword()
{
    return pwd;
}
string postman:: getRealName()
{
    return rname;
}
string postman:: getphoneNumber()
{
    return phoneNum;
}
double postman:: getAccountBalance()
{
    return accBalance;
}
int postman:: getState()
{
    return st;
}

void postman:: showinfo()
{
    cout<<"该快递员用户名为："<<uname<<endl;
    cout<<"该快递员密码为："<<pwd<<endl;
    cout<<"该快递员真实姓名为："<<rname<<endl;
    cout<<"该快递员电话号码为："<<phoneNum<<endl;
    cout<<"该快递员账户余额为："<<accBalance<<endl;
    if(st==0)
        cout<<"未任职于本公司"<<endl;
    else if(st==1)
        cout<<"任职于本公司"<<endl;
}

void postman:: pickupPackage()
{
    util tool;
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_poster='"+uname+"' and tracking_state=0";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    Package **p=(Package**)malloc(sizeof(Package)*res->row_count);
    if(tool.checkRst(res,p))
    {
        for(int i=0;i<res->row_count;i++)
        {
            int choice;
            (*p[i]).showInfo();
            cout<<"0--拒绝揽收该快递    1--揽收该快递"<<endl;
            cout<<"请输入您的选择：";
            while(true)
            {
                cin>>choice;getchar();
                if(choice==0||choice==1)    break;
                else
                {
                    cout<<"请输入正确的操作代码！"<<endl;
                    cout<<"请重新输入：";
                }
            }
            if(choice==0)
                sql="update package set tracking_poster = NULL where tracking_num="+to_string((*p[i]).getNumber());
            else if(choice==1)
                sql="update package set tracking_state = 1 where tracking_num="+to_string((*p[i]).getNumber());
            mysql.ExecuteSql(sql.c_str());
            if(choice==1)
            {
                sql="update admin set accountBalance = accountBalance - "+to_string((*p[i]).getPrice()*0.5)+" WHERE username = 123456";
                mysql.ExecuteSql(sql.c_str());
                sql="update postman set accountBalance = accountBalance + "+to_string((*p[i]).getPrice()*0.5)+" WHERE username = '"+uname+"'";
                mysql.ExecuteSql(sql.c_str());
                accBalance+=(*p[i]).getPrice()*0.5;
            }
            cout<<"----------------------------------------------------"<<endl;
        }
    }
    else
        cout<<"没有未揽收的快递!"<<endl;
    mysql_free_result(res);
    mysql.FreeConnect();
}

void postman:: mainPage()
{
    cout<<"欢迎您，快递员"<<uname<<endl;
    cout<<"您可以进行如下操作："<<endl;
    while(true)
    {
        cout<<"1.修改账户密码"<<endl;
        cout<<"2.查看账户余额"<<endl;
        cout<<"3.根据时间查询快递信息"<<endl;
        cout<<"4.根据寄件人查询快递信息"<<endl;
        cout<<"5.根据收件人查询快递信息"<<endl;
        cout<<"6.根据快递单号查询快递信息"<<endl;
        cout<<"7.揽收自己名下的快递"<<endl;
        cout<<"8.根据快递状态传讯快递信息"<<endl;
        cout<<"0.退出登录"<<endl;
        cout<<"请输入操作：";
        int choice;
        cin>>choice;getchar();
        if(choice==1)   changePassword();
        else if(choice==2)  cout<<"您的账户余额为："<<to_string(getBalance())<<endl;
        else if(choice==3)  accTime();
        else if(choice==4)  accSender();
        else if(choice==5)  accReceiver();
        else if(choice==6)  accNum();
        else if(choice==7)  pickupPackage();
        else if(choice==8)  accState();
        else if(choice==0)  break;
        else
        {
            cout<<"请输入规定操作"<<endl;
            cout<<"请重新输入："<<endl;
        }
    }
}

void postman:: changePassword()
{
    string oldpwd,newpwd;
    cout<<"请输入您的旧密码：";
    getline(cin,oldpwd);
    if(oldpwd==pwd)
    {
        cout<<"请输入您的新密码：";
        getline(cin,newpwd);
        pwd=newpwd;

        /*数据库更新密码*/
        MySQLManager mysql;
        ConnectionInfo info;
        if (!mysql.Init(info))                /*链接数据库*/
        {
            cout<<"数据库连接出现问题";
            return;
        }
        string sql="update postman set password='"+newpwd+"'"+" where username="+"'"+uname+"'";        /*写sql语句*/
        mysql.ExecuteSql(sql.c_str());        /*执行sql语句*/
        mysql.FreeConnect();                  /*关闭数据库链接*/
        cout<<"密码修改成功"<<endl;
    }
    else
        cout<<"旧密码错误"<<endl;
}

void postman:: accSender()
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
    string sql="select * from package where tracking_sender='"+senderName+"' and tracking_poster='"+uname+"' and tracking_state!=0";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
}

void postman:: accReceiver()
{
    string receiverName;
    util tool;
    cout<<"请输入查询的寄件人姓名：";
    getline(cin,receiverName);
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_receiver='"+receiverName+"' and tracking_poster='"+uname+"' and tracking_state!=0";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
}

void postman:: accTime()
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
    string sql="select * from package where tracking_sendTime='"+stime+"' or tracking_receiveTime='"+stime+"' and tracking_poster='"+uname+"' and tracking_state!=0";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
}

void postman:: accNum()
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
    string sql="select * from package where tracking_num="+number+" and tracking_poster='"+uname+"' and tracking_state!=0";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
}

void postman:: accState()
{
    util tool;
    MySQLManager mysql;
    int state;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    cout<<"0.查询未揽收的快递"<<endl;
    cout<<"1.查询已揽收的快递"<<endl;
    cout<<"2.查询已签收的快递"<<endl;
    cin>>state;getchar();
    string sql="select * from package where tracking_poster='"+uname+"' and tracking_state="+to_string(state);
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();                  /*关闭数据库链接*/
}

double postman:: getBalance()
{
    return accBalance;
}