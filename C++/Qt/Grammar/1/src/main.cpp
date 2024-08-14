#include "../include/widget.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv); //定义并创建应用大师
    QtWidgetsApplication w; //定义并创建窗口
    w.show(); //显示窗口
    return a.exec(); //应用程序运行, 开始消息循环和事件处理
}
