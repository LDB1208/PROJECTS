#include "../include/dialog.h"

Dialog::Dialog(QWidget* parent)
    : QDialog(parent), ui(new Ui::DialogClass) {
    ui->setupUi(this);
    ui->radioButton_Black->setChecked(true); //radioButton_BlackĬ��ѡ��

    //����SIGNAL��SLOT
    connect(ui->radioButton_Black, SIGNAL(clicked()), this, SLOT(do_fontColor()));
    connect(ui->radioButton_Blue, SIGNAL(clicked()), this, SLOT(do_fontColor()));
    connect(ui->radioButton_Red, SIGNAL(clicked()), this, SLOT(do_fontColor()));
}

Dialog::~Dialog() {
    delete ui;
}

void Dialog::on_checkBox_Underline_clicked(bool checked) {
    //Underline ��ѡ��
    QFont font = ui->plainTextEdit->font();
    font.setUnderline(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::on_checkBox_Italic_clicked(bool checked) {
    //Italic ��ѡ��
    QFont font = ui->plainTextEdit->font();
    font.setItalic(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::on_checkBox_Bold_clicked(bool checked) {
    //Bold ��ѡ��
    QFont font = ui->plainTextEdit->font();
    font.setBold(checked);
    ui->plainTextEdit->setFont(font);
}

void Dialog::do_fontColor() {
    //�Զ���ۺ���������������ɫ
    QPalette palette = ui->plainTextEdit->palette();
    if (ui->radioButton_Black->isChecked())
        palette.setColor(QPalette::Text, Qt::black);
    else if (ui->radioButton_Red->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    else if (ui->radioButton_Blue->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);    
    ui->plainTextEdit->setPalette(palette);
}