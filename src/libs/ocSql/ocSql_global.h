#pragma once

#include <QtCore/qglobal.h>

#if defined(OCSQL_LIBRARY)
#  define OCSQL_EXPORT Q_DECL_EXPORT
#else
#  define OCSQL_EXPORT Q_DECL_IMPORT
#endif
