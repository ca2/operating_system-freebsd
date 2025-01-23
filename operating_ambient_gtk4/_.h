#pragma once


#include "aura_freebsd/_.h"
#include "node_gtk_based/_.h"


#if defined(_operating_ambient_gtk_based_project)
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_GTK_BASED  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_GTK_BASED  CLASS_DECL_IMPORT
#endif


namespace operating_ambient_gtk_based
{


   class node;


} // namespace operating_ambient_gtk_based



