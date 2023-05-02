/*
 * @Author: SakurakojiSaika
 * @Date: 2023-05-02 10:54:43
 * @LastEditTime: 2023-05-02 18:01:57
 * @Description: 
 */

#include "dbutil.h"

dbUtil::dbUtil()
{
    dbconn = QSqlDatabase::addDatabase("QMYSQL");
    dbconn.setHostName(hostName);
    dbconn.setDatabaseName(dbName);
    dbconn.setUserName(userName);
    dbconn.setPassword(password);
    if(dbconn.open())
        qDebug("database open successfully!");
    else
        qDebug("database open failed!");
}

void dbUtil::close()
{
    dbconn.close();
}