#pragma once

#include <QtWidgets/QWidget>
#include "ui_widget.h"

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::WidgetClass ui;
};
