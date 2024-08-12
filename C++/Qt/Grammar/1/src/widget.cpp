#include "../include/widget.h"

QtWidgetsApplication::QtWidgetsApplication(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

QtWidgetsApplication::~QtWidgetsApplication()
{}
