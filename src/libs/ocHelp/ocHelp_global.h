#pragma once

#include <QtCore/qglobal.h>

#if defined(OCHELP_LIBRARY)
#  define OCHELP_EXPORT Q_DECL_EXPORT
#else
#  define OCHELP_EXPORT Q_DECL_IMPORT
#endif
