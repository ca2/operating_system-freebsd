#pragma once


#include "aura_freebsd/_.h"
#include "node_gtk_based/_.h"


#if defined(_desktop_environment_gtk_based_project)
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_GTK_BASED  CLASS_DECL_EXPORT
#else
   #define CLASS_DECL_DESKTOP_ENVIRONMENT_GTK_BASED  CLASS_DECL_IMPORT
#endif


namespace desktop_environment_gtk_based
{


   class node;


} // namespace desktop_environment_gtk_based



