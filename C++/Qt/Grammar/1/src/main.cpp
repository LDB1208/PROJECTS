#include <QApplication>
#include <QPushButton>
#include "form/app.h"

/*
 * 本程序演示UI Hello World
 */

int main(int argc, char *argv[]) {
    QApplication a(argc, argv); //定义应用程序对象,Qt图形界面程序的入口
    App w; //定义并创建窗口
    w.show(); //显示窗口
    return QApplication::exec(); //应用程序运行, 开始消息循环和事件处理
}
