/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-01 16:25:10
 * @LastEditTime: 2023-01-06 20:33:07
 * @Description: 实现user.h中的方法
 */

#include<bits/stdc++.h>
#include<mysql.h>
#include"user.h"
#include"package.h"
#include"mysqlManager.h"
#include"util.h"
using namespace std;

/*构造函数*/
User:: User(){}

User:: User(const string username,const string password,const string realName,const string telephoneNum, const double balance,const string address)
{
    uname=username;
    pwd=password;
    rname=realName;
    telNum=telephoneNum;
    accBalance=balance;
    addr=address;
}
/*私有成员的get方法*/
string User:: getUserName()
{
    return uname;
}                       
string User:: getPassword()
{
    return pwd;
}                       
string User:: getRealName()
{
    return rname;
}                       
string User:: getPhoneNumber()
{
    return telNum;
}                   
double User:: getAccountBalance()
{
    return accBalance;
}                 
string User:: getAddress()
{   
    return addr;
}                        
/*私有成员的set方法*/
void User:: setUserName(const string username)
{
    uname=username;
}

void User:: setPassword(const string password)
{
    pwd=password;
}

void User:: setRealName(const string realName)
{
    rname=realName;
}

void User:: setTelephoneNum(const string telephoneNum)
{
    telNum=telephoneNum;
}

void User:: setaccBalance(const double balance)
{
    accBalance=balance;
}

void User:: setAddress(const string address)
{
    addr=address;
}

/*四种私有的查询方法实现和辅助输出的方法*/
void User::accSender()
{
    string sname;
    util tool;
    cout<<"请输入寄件人姓名：";
    cin>>sname;
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_sender='"+sname+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();
}

void User::accReceiver()
{
    string sname;
    util tool;
    cout<<"请输入收件人姓名：";
    cin>>rname;
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_receiver='"+rname+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();
}

void User::accSendTime()
{
    string stime;
    util tool;
    cout<<"请输入寄件时间(格式：yyyy-mm-dd hh-mm-ss)："<<endl;
    getline(cin,stime);
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_sendTime='"+stime+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    tool.showTotalPackageInfo(res);
    mysql_free_result(res);
    mysql.FreeConnect();
}

void User::accNum()
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
    mysql.FreeConnect();
}

void User::showUnsignParcel()
{
    MySQLManager mysql;
    ConnectionInfo info;
    util tool;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="select * from package where tracking_state=1 and tracking_receiver='"+rname+"'";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    int lines=mysql_num_rows(res);
    Package **p=(Package**)malloc(sizeof(Package)*res->row_count);
    if(tool.checkRst(res,p))
    {
        cout<<"您的未签收快递为："<<endl;
        for(int i=0;i<lines;i++)
        {
            printf("第%d件：\n",(i+1));
            (*p[i]).showInfo();
            cout<<"----------------------------------------------------"<<endl;
        }
         cout<<"请输入您签收的快递号码（PS:一次一件,输入0表示拒绝签收）：";
        while(true)
        {
            int choice;cin>>choice;
            if(choice==0)
                break;
            else if(choice>lines||choice<1)
            {
                cout<<"请输入正确的数字！"<<endl;
                cout<<"重新输入：";
                continue;
            }
            else
            {
                if(receiveParcel(*p[choice-1]))
                    cout<<"签收成功！请继续输入：";
                else
                    cout<<"该件快递已签收"<<endl;
            }
        }
    }
    else
        cout<<"您没有未签收的快递！"<<endl;
    mysql_free_result(res);
    mysql.FreeConnect();
}

/*对账户进行操作的方法*/
void User:: changePwd()
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
        string sql="update user set password='"+newpwd+"'"+" where username="+"'"+uname+"'";        /*写sql语句*/
        mysql.ExecuteSql(sql.c_str());        /*执行sql语句*/
        mysql.FreeConnect();                  /*关闭数据库链接*/
        cout<<"密码修改成功"<<endl;
    }
    else
        cout<<"旧密码错误"<<endl;    
}

void User:: addBalance()
{
    double adder;
    cout<<"请输入您要充值的金额：";
    cin>>adder;
    accBalance+=adder;
    /*数据库更新余额*/
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    string sql="update user set accountBalance="+to_string(accBalance)+" where username="+"'"+uname+"'";        /*写sql语句*/
    mysql.ExecuteSql(sql.c_str());        /*执行sql语句*/
    mysql.FreeConnect();                  /*关闭数据库链接*/
    cout<<"充值成功！"<<endl;
}

void User:: sendParcel()
{
    string sendName;
    string receiveName;
    string desc;
    int kind;
    int util_price;
    double weight;
    double price;

    cout<<"请输入快递类型："<<endl;
    cout<<"1.易碎品（8元/kg）"<<endl;
    cout<<"2.图书（2元/本）"<<endl;
    cout<<"3.普通商品（5元/kg）"<<endl;
    cin>>kind;getchar();

    while(true)
    {
        if(kind==1||kind==2||kind==3)   break;
        else
        {
            cout<<"快递类型不匹配，请重新输入：";
            cin>>kind;getchar();
        }
    }

    if(kind==1)
        util_price=8;
    else if(kind==2)
        util_price=2;
    else if(kind==3)
        util_price=5;
    
    if(kind!=2)
    {
        cout<<"请输入快递重量：";
        cin>>weight;getchar();
    }
    else if(kind==2)
    {
        cout<<"请输入快递的本数：";
        cin>>weight;getchar();
        if(fmod(weight, 1.0) != 0.0)
        {
            cout<<"书本数必须为整数"<<endl;
            return;
        }
    }
    price=weight*util_price;
    cout<<"请输入寄件人姓名：";
    getline(cin,sendName);
    cout<<"请输入收件人姓名：";
    getline(cin,receiveName);
    cout<<"请输入物品描述(输入q代表描述为空)："<<endl;
    getline(cin,desc);
    if(desc=="q")   desc="";
    if(accBalance<price)
    {
        cout<<"余额不足请充值！"<<endl;
        return;
    }
    accBalance-=price;

    /*数据库更新余额和快件状态*/
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return;
    }
    /*由于快递公司只有一位管理员，因此直接用sql语句更新管理员的信息*/
    string sql="update admin set accountBalance = accountBalance + "+to_string(price)+" WHERE username = 123456";
    mysql.ExecuteSql(sql.c_str());        /*执行sql语句更新管理员账户余额*/
    sql="update user set accountBalance="+to_string(accBalance)+" where username="+"'"+uname+"'";        /*写sql语句*/
    mysql.ExecuteSql(sql.c_str());        /*执行sql语句更新余额*/
    sql="insert into package(tracking_state,tracking_sender,tracking_receiver,tracking_sendTime,tracking_receiveTime,tracking_describe,tracking_uname,tracking_kind,tracking_weight) values ";
    sql+="(0,'"+sendName+"',"+"'"+receiveName+"',"+"now(),now(),"+"'"+desc+"','"+uname+"',"+to_string(kind)+","+to_string(weight)+")";        /*写sql语句*/
    mysql.ExecuteSql(sql.c_str());        /*执行sql语句将快递送出*/

    /*更新包裹状态，输出信息*/
    sql="select tracking_num,tracking_sendTime from package order by tracking_num desc limit 1";
    MYSQL_RES* res=mysql.QueryData(sql.c_str());
    MYSQL_ROW row=mysql_fetch_row(res);
    string sTime(row[1]);
    cout<<"您寄出的快递信息如下："<<endl;
    Package *p;
    if(kind==1)
        p=new glass(stoi(row[0]),0,weight,sendName,receiveName,sTime,sTime,desc);
    else if(kind==2)
        p=new book(stoi(row[0]),0,weight,sendName,receiveName,sTime,sTime,desc);
    else if(kind==3)
        p=new common_pac(stoi(row[0]),0,weight,sendName,receiveName,sTime,sTime,desc);
    p->showInfo();
    cout<<"快递已送出，您的账户余额为："<<accBalance<<endl;
    mysql_free_result(res);
    mysql.FreeConnect();
}

bool User:: receiveParcel(Package p)
{
    if(p.getState()==2)
    {
        cout<<"已签收！"<<endl;
        return false;
    }
    MySQLManager mysql;
    ConnectionInfo info;
    if (!mysql.Init(info))                /*链接数据库*/
    {
        cout<<"数据库连接出现问题";
        return false;
    }
    string sql="update package set tracking_state=2 where tracking_num = "+to_string(p.getNumber());
    mysql.ExecuteSql(sql.c_str());        /*执行sql语句*/
    sql="update package set tracking_receiveTime=now() where tracking_num = "+to_string(p.getNumber());
    mysql.ExecuteSql(sql.c_str());        /*执行sql语句*/
    mysql.FreeConnect();                  /*关闭数据库链接*/
    return true;
}

void User:: checkParcel()
{
    int choice;
    cout<<"查询快递有以下五种方式："<<endl;
    while(true)
    {
        cout<<"1.按发件人查询"<<endl;
        cout<<"2.按收件人查询"<<endl;
        cout<<"3.按发件时间查询"<<endl;
        cout<<"4.按快递单号查询"<<endl;
        cout<<"5.显示所有未签收的快递"<<endl;
        cout<<"0.退出查询界面"<<endl;
        cout<<"请输入操作：";
        cin>>choice;getchar();
        if(choice==1)
            accSender();
        else if(choice==2)
            accReceiver();
        else if(choice==3)
            accSendTime();
        else if(choice==4)
            accNum();
        else if(choice==5)
            showUnsignParcel();
        else if(choice==0)
            break;
        else
            cout<<"请输入有效输入"<<endl;
    }
}

void User:: showInfo()
{
    cout<<"用户名："<<uname<<endl;
    cout<<"用户密码："<<pwd<<endl;
    cout<<"用户真实姓名："<<rname<<endl;
    cout<<"用户电话号码："<<telNum<<endl;
    cout<<"用户账户余额："<<accBalance<<endl;
    cout<<"用户地址："<<addr<<endl;
}

void User:: mainPage()
{
    cout<<"您好，用户"+uname<<endl;
    cout<<"您可以执行如下操作："<<endl;
    while(true)
    {
        cout<<"1.修改账户密码"<<endl;
        cout<<"2.查询余额"<<endl;
        cout<<"3.充值余额"<<endl;
        cout<<"4.发送快递"<<endl;
        cout<<"5.查询快递"<<endl;
        cout<<"0.退出登录"<<endl;
        int choice;
        cout<<"请输入操作代码：";
        cin>>choice;getchar();
        if(choice==1)
            changePwd();
        else if(choice==2)
            cout<<"您的账户余额为："+to_string(accBalance)<<endl;
        else if(choice==3)
            addBalance();
        else if(choice==4)
            sendParcel();
        else if(choice==5)
            checkParcel();
        else if(choice==0)
            break;
        else
            cout<<"请输入指定的操作代码！"<<endl;
        cout<<"请继续输入操作："<<endl;
    }
}