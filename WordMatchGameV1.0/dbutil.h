/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-01 18:48:30
 * @LastEditTime: 2023-05-01 19:31:42
 * @Description: Provide initialize and execute sql methods for database.
 */

#ifndef DBUTIL_H
#define DBUTIL_H

#include <mysql.h>
#pragma comment(lib, "libmysql.lib")
using namespace std;

struct ConnectionInfo
{ 
    const char* host="localhost";            // 主机地址
    const char* user="root";            // 用户名
    const char* pwd="wenbo030605";        // 密码
    const char* database="wordmatchgame";        // 数据库名
    unsigned int port=3306;            // 端口号
    const char*  unix_socket=NULL;    // unix连接标识
    unsigned long clientflag=0;    // 客户端连接标志
};

class dbUtil
{
    private:
        MYSQL m_mysql;      //mysql链接
        MYSQL_RES* m_res;   //查询结果集
    public:
        dbUtil();
        bool Init(ConnectionInfo& info);
        bool FreeConnect();
        bool ExecuteSql(const char* sql);
        MYSQL_RES* QueryData(const char* sql);
        void PrintQueryRes();
};


#endif // DBUTIL_H
