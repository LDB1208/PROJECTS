#include "formula_qt.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    FormulaQt w;
    w.show();
    return a.exec();
}