#pragma once

#include <QDialog>
#include <QCheckBox> //��ѡ��
#include <QRadioButton> //��ѡ��
#include <QPlainTextEdit> //���ֱ༭��
#include <QPushButton> //��ť

class Dialog : public QDialog {
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog() {};

private slots: //�ۺ�������
    void do_checkBox_Underline(bool checked);
    void do_checkBox_Italic(bool checked);
    void do_checkBox_Bold(bool checked);
    void do_fontColor();

private:
    //�ؼ�
    QCheckBox* checkBox_Underline, * checkBox_Italic, * checkBox_Bold;
    QRadioButton* radioButton_Black, * radioButton_Red, * radioButton_Blue;
    QPlainTextEdit* plainTextEdit;
    QPushButton* buttonOK, * buttonClose, * buttonClear;
    void initUI();
    void initSignalSlots();
};