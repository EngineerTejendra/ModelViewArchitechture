#include "mainwindow.h"
#include "pointmodel.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Create the model
    PointModel model;

    // Inject the model into the MainWindow
    MainWindow w(nullptr, &model);
    w.show();

    return a.exec();
}
