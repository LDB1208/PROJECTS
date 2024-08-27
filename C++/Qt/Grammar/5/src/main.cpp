#include <QApplication>
#include <QPushButton>
#include <QTimer>

/*
* 本程序演示元对象系统
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QObject* button = new QPushButton;
    qDebug() << button->metaObject()->className(); //类名

    qDebug() << "====================";

    QPushButton* push_button = qobject_cast<QPushButton*>(button); //类似于dynamic_cast
    qDebug() << push_button->metaObject()->className();

    qDebug() << "====================";

    QTimer* timer = new QTimer();
    qDebug() << timer->inherits("QTimer"); //是否是继承关系
    qDebug() << timer->inherits("QObject");
    qDebug() << timer->inherits("QAbstractButton");

    qDebug() << "====================";

    qDebug() << button->metaObject()->superClass()->className(); //父对象
}
