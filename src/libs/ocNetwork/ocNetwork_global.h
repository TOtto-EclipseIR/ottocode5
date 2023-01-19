#pragma once

#include <QtCore/qglobal.h>

#if defined(OCNETWORK_LIBRARY)
#  define OCNETWORK_EXPORT Q_DECL_EXPORT
#else
#  define OCNETWORK_EXPORT Q_DECL_IMPORT
#endif
