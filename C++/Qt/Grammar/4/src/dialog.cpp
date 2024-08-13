#include "../include/dialog.h"
#include <QHBoxLayout> //水平布局
#include <QVBoxLayout> //垂直布局

Dialog::Dialog(QWidget* parent)
    : QDialog(parent),
    //初始化
    checkBox_Underline(new QCheckBox("Underline")), //勾选框
    checkBox_Italic(new QCheckBox("Italic")),
    checkBox_Bold(new QCheckBox("Bold")),
    radioButton_Black(new QRadioButton("Black")), //单选框
    radioButton_Red(new QRadioButton("Red")),
    radioButton_Blue(new QRadioButton("Blue")),
    plainTextEdit(new QPlainTextEdit), //文本编辑框
    buttonOK(new QPushButton("OK")), //按钮
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
    QPalette palette = plainTextEdit->palette(); //获取颜色
    //设置颜色
    if (radioButton_Black->isChecked())
        palette.setColor(QPalette::Text, Qt::black);
    else if (radioButton_Red->isChecked())
        palette.setColor(QPalette::Text, Qt::red);
    else if (radioButton_Blue->isChecked())
        palette.setColor(QPalette::Text, Qt::blue);
    plainTextEdit->setPalette(palette); //设置颜色
}

void Dialog::initUI() {
    setWindowTitle("Hello World"); //设置窗口标题
    radioButton_Black->setChecked(true); //设置默认选中
    plainTextEdit->setPlainText("Hello World!"); //设置默认文本

    //设置字体大小
    QFont font = plainTextEdit->font(); //获取原有字体
    font.setPointSize(20); //改变大小
    plainTextEdit->setFont(font); //返回字体

    QHBoxLayout* HLayout = new QHBoxLayout(); //水平布局
    HLayout->addWidget(checkBox_Underline); //添加控件
    HLayout->addWidget(checkBox_Italic);
    HLayout->addWidget(checkBox_Bold);

    QHBoxLayout* HLayout2 = new QHBoxLayout();
    HLayout2->addWidget(radioButton_Black);
    HLayout2->addWidget(radioButton_Red);
    HLayout2->addWidget(radioButton_Blue);

    QHBoxLayout* HLayout3 = new QHBoxLayout();
    HLayout3->addStretch(); //增加伸缩量
    HLayout3->addWidget(buttonClear);
    HLayout3->addStretch();
    HLayout3->addWidget(buttonOK);
    HLayout3->addWidget(buttonClose);

    QVBoxLayout* VLayout = new QVBoxLayout(); //垂直布局
    VLayout->addLayout(HLayout); //添加布局
    VLayout->addLayout(HLayout2);
    VLayout->addWidget(plainTextEdit);
    VLayout->addLayout(HLayout3);

    setLayout(VLayout); //设为主布局
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
