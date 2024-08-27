#include <QApplication>
#include <QPushButton>
#include "../form/app.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    App w;
    w.show();
    return QApplication::exec();
}
