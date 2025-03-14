#include "pointmodel.h"

PointModel::PointModel()
{
    model = new QStandardItemModel(0, 2);
    model->setHeaderData(0, Qt::Horizontal, "X");
    model->setHeaderData(1, Qt::Horizontal, "Y");
}

PointModel::~PointModel()
{
    delete model;
}

void PointModel::addPoint(double x, double y)
{
    QList<QStandardItem*> row;
    row.append(new QStandardItem(QString::number(x, 'f', 2)));
    row.append(new QStandardItem(QString::number(y, 'f', 2)));
    model->appendRow(row);
}

QStandardItemModel* PointModel::getModel()
{
    return model;
}
