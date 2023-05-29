/*
 * @Author: SakurakojiSaika
 * @Date: 2023-01-02 14:56:17
 * @LastEditTime: 2023-01-06 18:51:53
 * @Description: 工具类，无私有成员变量,实现一些常用的方法
 */
#ifndef UTIL_H_
#define UTIL_H_
#include<bits/stdc++.h>
#include<mysql.h>
#include"package.h"
using namespace std;

class util
{
    public:
        /* 将char*类型转换为string类型 */
        string char2string(const char* str);
        /* 展示所有包裹信息 */
        void showTotalPackageInfo(MYSQL_RES* res);
        /* 返回包裹列表 */
        bool checkRst(MYSQL_RES* res,Package** retp);
};
#endif