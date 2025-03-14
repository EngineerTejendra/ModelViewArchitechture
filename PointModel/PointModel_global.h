#ifndef POINTMODEL_GLOBAL_H
#define POINTMODEL_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(POINTMODEL_LIBRARY)
#  define POINTMODEL_EXPORT Q_DECL_EXPORT
#else
#  define POINTMODEL_EXPORT Q_DECL_IMPORT
#endif

#endif // POINTMODEL_GLOBAL_H
