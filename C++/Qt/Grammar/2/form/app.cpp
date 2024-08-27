//
// Created by LDB on 2024/8/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_App.h" resolved

#include "../form/app.h"
#include "ui_App.h"


App::App(QWidget *parent) :
    QWidget(parent), ui(new Ui::App) {
    ui->setupUi(this);
}

App::~App() {
    delete ui;
}
