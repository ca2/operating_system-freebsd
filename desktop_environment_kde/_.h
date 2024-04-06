#pragma once


#include "aura_freebsd/_.h"
#if defined(HAS_KDE6)
#include "operating_system-posix/node_kde6/_.h"
#elif defined(HAS_KDE5)
#include "operating_system-posix/node_kde5/_.h"
#endif


#if defined(_DESKTOP_ENVIRONMENT_KDE_LIBRARY)
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_KDE  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_KDE  CLASS_DECL_IMPORT
#endif

#undef new
#include <qmetatype.h>
#include <QApplication>
#include <QPalette>
#include <QAbstractNativeEventFilter>
#define new ACME_NEW

namespace desktop_environment_kde
{


   class node;


} // namespace node_kde


namespace user
{


   char * gsettings_get_malloc(const char * pszSchema, const char * pszKey);


} // namespace user


//#include "node.h"


//#include "copydesk.h"


//#include "appindicator.h"


//#include "factory_exchange.h"


//#include "node.h"



