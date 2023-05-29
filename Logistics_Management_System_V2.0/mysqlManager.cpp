/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-01 14:36:08
 * @LastEditTime: 2023-01-06 17:53:16
 * @Description: mysqlManager.h的接口
 */

#include<bits/stdc++.h>
#include<mysql.h>
#include"mysqlManager.h"
using namespace std;

bool MySQLManager::Init(ConnectionInfo& info)
{
    // 初始化mysql,连接mysql，数据库
    mysql_init(&m_mysql);
    // 连接失败
    if (!(mysql_real_connect(&m_mysql, info.host, info.user, info.pwd, info.database, info.port, info.unix_socket, info.clientflag)))
        return false;
    return true;
}

bool MySQLManager::ExecuteSql(const char * sql)
{
    if (mysql_query(&m_mysql, sql))
    {
        // 打印错误log，这里直接显示到控制台
        cerr << "执行sql语句失败，错误信息为： " << mysql_error(&m_mysql) << endl;
        return false;
    }
    return true;
}

// 查询数据
MYSQL_RES* MySQLManager::QueryData(const char* sql)
{
    if (mysql_query(&m_mysql, sql))
    {
        // 打错误log，这里直接显示到控制台
        cerr << "查询语句执行失败，错误信息为： " << mysql_error(&m_mysql) << endl;
        return nullptr;
    }
    // 存储查询结果
    m_res = mysql_store_result(&m_mysql);
    return m_res;
}

// 释放连接
bool MySQLManager::FreeConnect()
{
    mysql_close(&m_mysql);
    return false;
}