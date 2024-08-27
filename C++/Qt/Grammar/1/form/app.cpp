//
// Created by LDB on 2024/8/24.
//

// You may need to build the project (run Qt uic code generator) to get "ui_App.h" resolved

#include "app.h"
#include "ui_App.h"


App::App(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::App) {
    ui->setupUi(this); //实现组件的各种设置, 信号与槽的关联
}

App::~App() {
    delete ui;
}
