#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <errno.h>
#include <syslog.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <sys/time.h>
#include <QCoreApplication>
#include "hstester-server.h"

QString getTime();
void demonize();
int writeLog(const QString &msg);

int main(int argc, char** argv)
{
	QCoreApplication app(argc, argv);
	HstesterServer foo;
	demonize();
	return app.exec();
}

void demonize()
{
    if(QCoreApplication::arguments().contains("--no-daemon"))
        return;
    writeLog("HsTestServer Start");
    // Наши ID процесса и сессии 
    pid_t pid, sid;
    // отделяемся от родительского процесса
    pid = fork();
    if(pid < 0)
    {
        // Фиксируем ошибку (через syslog при возможности)
        exit(EXIT_FAILURE);
    }
    // Если с PID'ом все получилось, то родительский процесс можно завершить.
    if(pid > 0)
    {
        exit(EXIT_SUCCESS);
    }
    
    // Изменяем файловую маску
    umask(0);
    
    writeLog("HsTestServer set session id");
    
    // Создание нового SID для дочернего процесса
    sid = setsid();
    if(sid < 0)
    {
        writeLog("HsTestServer  no set session id");
        exit(EXIT_FAILURE);
    }
    
    // Изменяем текущий рабочий каталог
    /*if(chdir("/") < 0)
    {
        writeLog("HsTestServer  no set current dir");
        exit(EXIT_FAILURE);
    }*/
    
    // Закрываем стандартные файловые дескрипторы
    /*close(STDIN_FILENO);
    close(STDOUT_FILENO);
    close(STDERR_FILENO);*/
}

QString getTime() //функция возвращает форматированную дату и время
{
    QDateTime now = QDateTime::currentDateTime();
    return now.toString("yyyy-MM-dd hh:mm:ss");
}

int writeLog(const QString &msg)  //функция записи строки в лог
{
    QFile pLog("/home/roman/projects/daemon/sdaemon.log");
    if(!pLog.open(QIODevice::Append | QIODevice::Text))
    {
        return 1;
    }
    QTextStream out(&pLog);
    out << getTime() << " ==========================";
    out << msg;
    pLog.close();
    return 0;
}