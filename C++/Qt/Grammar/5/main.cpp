#include <QApplication>
#include <QPushButton>
#include <QTimer>

/*
* ��������ʾԪ����ϵͳ
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QObject* button = new QPushButton;
    qDebug() << button->metaObject()->className(); //����
    
    qDebug() << "====================";

    QPushButton* push_button = qobject_cast<QPushButton*>(button); //������dynamic_cast
    qDebug() << push_button->metaObject()->className(); 

    qDebug() << "====================";

    QTimer* timer = new QTimer();
    qDebug() << timer->inherits("QTimer"); //�Ƿ��Ǽ̳й�ϵ
    qDebug() << timer->inherits("QObject");
    qDebug() << timer->inherits("QAbstractButton");

    qDebug() << "====================";

    qDebug() << button->metaObject()->superClass()->className(); //������
}