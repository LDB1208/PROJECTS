#include "../include/dialog.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return QApplication::exec();
}
