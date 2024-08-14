#include "../include/widget.h"

QtWidgetsApplication::QtWidgetsApplication(QWidget *parent)
    : QMainWindow(parent),
    ui(new Ui::QtWidgetsApplicationClass)
{
    ui->setupUi(this); //实现组件的各种设置, 信号与槽的关联
}

QtWidgetsApplication::~QtWidgetsApplication()
{
    delete ui;
}
