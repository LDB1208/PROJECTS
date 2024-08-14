#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_widget.h"

class QtWidgetsApplication : public QMainWindow
{
    Q_OBJECT //宏, 使用Qt信号和槽机制必须添加

public:
    QtWidgetsApplication(QWidget *parent = nullptr);
    ~QtWidgetsApplication();

private:
    Ui::QtWidgetsApplicationClass* ui;
};
