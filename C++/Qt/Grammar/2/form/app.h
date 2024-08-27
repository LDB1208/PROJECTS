//
// Created by LDB on 2024/8/25.
//

#ifndef APP_H
#define APP_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class App; }
QT_END_NAMESPACE

class App : public QWidget {
Q_OBJECT

public:
    explicit App(QWidget *parent = nullptr);
    ~App() override;

private:
    Ui::App *ui;
};


#endif //APP_H
