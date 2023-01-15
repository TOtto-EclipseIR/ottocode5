#pragma once

#include <QtCore/qglobal.h>

#if defined(OCWIDGETS_LIBRARY)
#  define OCWIDGETS_EXPORT Q_DECL_EXPORT
#else
#  define OCWIDGETS_EXPORT Q_DECL_IMPORT
#endif
