#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QGraphicsEllipseItem>
#include <QInputDialog>

MainWindow::MainWindow(QWidget *parent, IModelInterface *modelInterface)
    : QMainWindow(parent), ui(new Ui::MainWindow), modelInterface(modelInterface)
{
    ui->setupUi(this);

    // Set up the graphics scene
    scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);
    ui->graphicsView->setRenderHint(QPainter::Antialiasing);

    // Set the model for treeView
    if (modelInterface)
        ui->treeView->setModel(modelInterface->getModel());

    // Connect button to add points
    connect(ui->pushButtonAdd, &QPushButton::clicked, this, &MainWindow::addPoints);
}

void MainWindow::mousePressEvent(QMouseEvent *event)
{
    if (ui->graphicsView->underMouse() && event->button() == Qt::LeftButton)
    {
        QPointF scenePos = ui->graphicsView->mapToScene(event->pos());
        addPointToScene(scenePos);
        if (modelInterface)
            modelInterface->addPoint(scenePos.x(), scenePos.y());
    }
}

void MainWindow::addPoints()
{
    bool okX, okY;
    double x = QInputDialog::getDouble(this, "Enter X", "X Coordinate:", 0, -1000, 1000, 2, &okX);
    if (!okX) return;

    double y = QInputDialog::getDouble(this, "Enter Y", "Y Coordinate:", 0, -1000, 1000, 2, &okY);
    if (!okY) return;

    addPointToScene(QPointF(x, y));
    if (modelInterface)
        modelInterface->addPoint(x, y);
}

void MainWindow::addPointToScene(QPointF point)
{
    scene->addEllipse(point.x() - 5, point.y() - 5, 10, 10, QPen(Qt::black), QBrush(Qt::red));
}

MainWindow::~MainWindow()
{
    delete ui;
}
