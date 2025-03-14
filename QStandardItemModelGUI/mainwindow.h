#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <../IModelInterface.h>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr, IModelInterface *modelInterface = nullptr);
    ~MainWindow();

protected:
    void mousePressEvent(QMouseEvent *event) override;

private slots:
    void addPoints();

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    IModelInterface *modelInterface;

    void addPointToScene(QPointF point);
};

#endif // MAINWINDOW_H
