#pragma once

#include <QDialog>
#include <QCheckBox> //勾选框
#include <QRadioButton> //单选框
#include <QPlainTextEdit> //文字编辑框
#include <QPushButton> //按钮

class Dialog : public QDialog {
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog() {};

private slots: //槽函数声明
    void do_checkBox_Underline(bool checked);
    void do_checkBox_Italic(bool checked);
    void do_checkBox_Bold(bool checked);
    void do_fontColor();

private:
    //控件
    QCheckBox* checkBox_Underline, * checkBox_Italic, * checkBox_Bold;
    QRadioButton* radioButton_Black, * radioButton_Red, * radioButton_Blue;
    QPlainTextEdit* plainTextEdit;
    QPushButton* buttonOK, * buttonClose, * buttonClear;
    void initUI();
    void initSignalSlots();
};
