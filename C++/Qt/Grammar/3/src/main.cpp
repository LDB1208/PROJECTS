#include <QApplication>
#include <QPushButton>
#include "../form/dialog.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    Dialog w;
    w.show();
    return QApplication::exec();
}
