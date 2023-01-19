#pragma once

#include <QtCore/qglobal.h>

#if defined(OCXML_LIBRARY)
#  define OCXML_EXPORT Q_DECL_EXPORT
#else
#  define OCXML_EXPORT Q_DECL_IMPORT
#endif
