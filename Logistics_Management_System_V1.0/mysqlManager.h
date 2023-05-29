/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-01 14:36:00
 * @LastEditTime: 2023-01-03 22:08:31
 * @Description: MySQL连接数据库管理类
 */
#ifndef MYSQLMANAGER_H_
#define MYSQLMANAGER_H_

#include<bits/stdc++.h>
#include<mysql.h>
using namespace std;

/*添加工程依赖项*/
#pragma comment(lib, "libmysql.lib")

struct ConnectionInfo
{ 
    const char* host="localhost";            // 主机地址
    const char* user="root";            // 用户名
    const char* pwd="wenbo030605";        // 密码
    const char* database="Logistics_Management_System";        // 数据库名
    unsigned int port=3306;            // 端口号
    const char*  unix_socket=NULL;    // unix连接标识
    unsigned long clientflag=0;    // 客户端连接标志
};

class MySQLManager
{
    private:
        MYSQL m_mysql;      //mysql链接
        MYSQL_RES* m_res;   //查询结果集
    public:
    // 连接数据库
    bool Init(ConnectionInfo& info);
    // 释放连接
    bool FreeConnect();
    // 执行sql语句, 包括增加、删除、更新数据
    bool ExecuteSql(const char* sql);
    // 查询数据
    MYSQL_RES* QueryData(const char* sql);
};

#endif