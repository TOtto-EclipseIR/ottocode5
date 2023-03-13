#pragma once

#include <QtCore/qglobal.h>

#if defined(OCSVG_LIBRARY)
#  define OCSVG_EXPORT Q_DECL_EXPORT
#else
#  define OCSVG_EXPORT Q_DECL_IMPORT
#endif
