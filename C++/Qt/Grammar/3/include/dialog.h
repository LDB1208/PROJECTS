#pragma once

#include <QtWidgets/QDialog>
#include "ui_dialog.h"

class Dialog : public QDialog {
    Q_OBJECT

public:
    Dialog(QWidget *parent = nullptr);
    ~Dialog();

private slots: //slotsÊÇ±ØÐëµÄ
    void on_checkBox_Underline_clicked(bool checked);

    void on_checkBox_Italic_clicked(bool checked);

    void on_checkBox_Bold_clicked(bool checked);

    void do_fontColor();
private:
    Ui::DialogClass *ui;
};
