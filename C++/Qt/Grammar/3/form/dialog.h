//
// Created by LDB on 2024/8/25.
//

#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>


QT_BEGIN_NAMESPACE

namespace Ui {
    class Dialog;
}

QT_END_NAMESPACE

class Dialog : public QDialog {
Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);

    ~Dialog() override;

private slots: //slots是必须的
    void on_checkBox_Underline_clicked(bool checked);

    void on_checkBox_Italic_clicked(bool checked);

    void on_checkBox_Bold_clicked(bool checked);

    void do_fontColor();

private:
    Ui::Dialog *ui;
};

#endif //DIALOG_H
