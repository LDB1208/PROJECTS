#pragma once

#include <QtWidgets/QDialog>
#include "ui_formula_qt.h"

class FormulaQt : public QDialog
{
    Q_OBJECT

public:
    FormulaQt(QWidget *parent = nullptr);
    ~FormulaQt();
private slots:
    // void on_pushButton_Solve_clicked(double, double, double, double, double, double);
private:
    Ui::FormulaQtClass* ui;
};
