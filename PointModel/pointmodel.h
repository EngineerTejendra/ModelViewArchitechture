#ifndef POINTMODEL_H
#define POINTMODEL_H

#include "../IModelInterface.h"
#include <QStandardItemModel>

class PointModel : public IModelInterface
{
public:
    PointModel();
    ~PointModel();

    void addPoint(double x, double y) override;
    QStandardItemModel* getModel() override;

private:
    QStandardItemModel *model;
};

#endif // POINTMODEL_H
