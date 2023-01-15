#pragma once

#include <QtCore/qglobal.h>

#if defined(OCCORE_LIBRARY)
#  define OCCORE_EXPORT Q_DECL_EXPORT
#else
#  define OCCORE_EXPORT Q_DECL_IMPORT
#endif
