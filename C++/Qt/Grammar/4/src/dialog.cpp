#include "../include/dialog.h"
#include <QHBoxLayout> //ˮƽ����
#include <QVBoxLayout> //��ֱ����

Dialog::Dialog(QWidget* parent)
    : QDialog(parent),
    //��ʼ��
    checkBox_Underline(new QCheckBox("Underline")), //��ѡ��
    checkBox_Italic(new QCheckBox("Italic")),
    checkBox_Bold(new QCheckBox("Bold")),
    radioButton_Black(new QRadioButton("Black")), //��ѡ��
    radioButton_Red(new QRadioButton("Red")),
    radioButton_Blue(new QRadioButton("Blue")),
    plainTextEdit(new QPlainTextEdit), //�ı��༭��
    buttonOK(new QPushButton("OK")), //��ť
    buttonClear(new QPushButton("Clear")),
    buttonClose(new QPushButton("Close"))
{
    initUI();
    initSignalSlots();
}

void Dialog::do_checkBox_Underline(bool checked) {
    QFont font = plainTextEdit->font();
    font.setUnderline(checked);
    plainTextEdit->setFont(font);
}

void Dialog::do_checkBox_Italic(bool checked) {
    QFont font = plainTextEdit->font();
    font.setItalic(checked);
    plainTextEdit->setFont(font);
}

void Dialog::do_checkBox_Bold(bool checked) {
    QFont font = plainTextEdit->font();
    font.setBold(checked);
    plainTextEdit->setFont(font);
}

void Dialog::do_fontColor() {
    QPalette palette = plainTextEdit->palette(); //��ȡ��ɫ
    //������ɫ
    if (radioButton_Black->isChecked())
        palette.setColor(QPalette::Text, Qt::black);
    else if (radioButton_Red->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    else if (radioButton_Blue->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);
    plainTextEdit->setPalette(palette); //������ɫ
}

void Dialog::initUI() {
    setWindowTitle("Hello World"); //���ô��ڱ���
    radioButton_Black->setChecked(true); //����Ĭ��ѡ��
    plainTextEdit->setPlainText("Hello World!"); //����Ĭ���ı�

    //���������С
    QFont font = plainTextEdit->font(); //��ȡԭ������
    font.setPointSize(20); //�ı��С
    plainTextEdit->setFont(font); //��������

    QHBoxLayout* HLayout = new QHBoxLayout(); //ˮƽ����
    HLayout->addWidget(checkBox_Underline); //���ӿؼ�
    HLayout->addWidget(checkBox_Italic);
    HLayout->addWidget(checkBox_Bold);

    QHBoxLayout* HLayout2 = new QHBoxLayout();
    HLayout2->addWidget(radioButton_Black);
    HLayout2->addWidget(radioButton_Red);
    HLayout2->addWidget(radioButton_Blue);

    QHBoxLayout* HLayout3 = new QHBoxLayout();
    HLayout3->addStretch(); //����������
    HLayout3->addWidget(buttonClear);
    HLayout3->addStretch();
    HLayout3->addWidget(buttonOK);
    HLayout3->addWidget(buttonClose);

    QVBoxLayout* VLayout = new QVBoxLayout(); //��ֱ����
    VLayout->addLayout(HLayout); //���Ӳ���
    VLayout->addLayout(HLayout2);
    VLayout->addWidget(plainTextEdit);
    VLayout->addLayout(HLayout3);

    setLayout(VLayout); //��Ϊ������
}

void Dialog::initSignalSlots() {
    connect(checkBox_Underline, SIGNAL(clicked(bool)), this, SLOT(do_checkBox_Underline(bool)));
    connect(checkBox_Italic, SIGNAL(clicked(bool)), this, SLOT(do_checkBox_Italic(bool)));
    connect(checkBox_Bold, SIGNAL(clicked(bool)), this, SLOT(do_checkBox_Bold(bool)));

    connect(radioButton_Black, SIGNAL(clicked(bool)), this, SLOT(do_fontColor()));
    connect(radioButton_Red, SIGNAL(clicked(bool)), this, SLOT(do_fontColor()));
    connect(radioButton_Blue, SIGNAL(clicked(bool)), this, SLOT(do_fontColor()));

    connect(buttonOK, SIGNAL(clicked()), this, SLOT(accept()));
    connect(buttonClose, SIGNAL(clicked()), this, SLOT(close()));
    connect(buttonClear, SIGNAL(clicked()), plainTextEdit, SLOT(clear()));
}