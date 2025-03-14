#ifndef IMODELINTERFACE_H
#define IMODELINTERFACE_H

#include <QStandardItemModel>

class IModelInterface
{
public:
    virtual ~IModelInterface() {} // Virtual destructor
    virtual void addPoint(double x, double y) = 0;  // Pure virtual function
    virtual QStandardItemModel* getModel() = 0;     // Get the model
};

#endif // IMODELINTERFACE_H
