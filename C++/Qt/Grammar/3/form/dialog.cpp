//
// Created by LDB on 2024/8/25.
//

// You may need to build the project (run Qt uic code generator) to get "ui_Dialog.h" resolved

#include "dialog.h"
#include "ui_Dialog.h"


Dialog::Dialog(QWidget *parent) :
        QDialog(parent), ui(new Ui::Dialog) {
    ui->setupUi(this);
    ui->radioButton_Black->setChecked(true); //radioButton_Black默认选中

    //连接SIGNAL和SLOT
    connect(ui->radioButton_Black, SIGNAL(clicked()), this, SLOT(do_fontColor()));
    connect(ui->radioButton_Blue, SIGNAL(clicked()), this, SLOT(do_fontColor()));
    connect(ui->radioButton_Red, SIGNAL(clicked()), this, SLOT(do_fontColor()));
}

Dialog::~Dialog() {
    delete ui;
}

//函数名称为on_<object_name>_<signal_name>自动添加SIGNAL和SLOTS
void Dialog::on_checkBox_Underline_clicked(bool checked) {
    //Underline 复选框
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::on_checkBox_Italic_clicked(bool checked) {
    //Italic 复选框
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::on_checkBox_Bold_clicked(bool checked) {
    //Bold 复选框
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::do_fontColor() {
    //自定义槽函数，设置文字颜色
    QPalette palette = ui->plainTextEdit->palette();
    if (ui->radioButton_Black->isChecked())
        palette.setColor(QPalette::Text, Qt::black);
    else if (ui->radioButton_Red->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    else if (ui->radioButton_Blue->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);
    ui->plainTextEdit->setPalette(palette);
}
