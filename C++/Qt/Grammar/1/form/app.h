//
// Created by LDB on 2024/8/24.
//

#ifndef APP_H
#define APP_H

#include <QMainWindow>


QT_BEGIN_NAMESPACE

namespace Ui {
    class App;
}

QT_END_NAMESPACE

class App : public QMainWindow {
    Q_OBJECT //宏, 使用Qt信号和槽机制必须添加

public:
    explicit App(QWidget *parent = nullptr);

    ~App() override;

private:
    Ui::App *ui;
};


#endif //APP_H
