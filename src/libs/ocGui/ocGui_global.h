#pragma once

#include <QtCore/qglobal.h>

#if defined(OCGUI_LIBRARY)
#  define OCGUI_EXPORT Q_DECL_EXPORT
#else
#  define OCGUI_EXPORT Q_DECL_IMPORT
#endif
