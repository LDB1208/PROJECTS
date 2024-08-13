#include "formula_qt.h"

FormulaQt::FormulaQt(QWidget *parent)
    : QDialog(parent), ui(new Ui::FormulaQtClass)
{
    ui->setupUi(this);
}

FormulaQt::~FormulaQt()
{
    delete ui;
}

//void FormulaQt::on_pushButton_Solve_clicked(double a, double b, double c, double d, double e, double f) { //二元一次方程组的通解
//    double x, y;
//    if (a * e - b * d == 0) {
//        if (c * e - b * f == 0 || a * f - c * d == 0)
//            cout << "无数解" << endl;
//        else
//            cout << "无解" << endl;
//    }
//    else {
//        x = (c * e - b * f) / (a * e - b * d);
//        y = (a * f - c * d) / (a * e - b * d);
//        cout << "x的值为:" << x << endl << "y的值为:" << y << endl;
//    }
//}