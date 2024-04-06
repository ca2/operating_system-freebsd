//
// Created by camilo on 20/01/2021. ThomasBS!!
//
#pragma once


#if defined(HAS_GTK4)
#include "node_gtk4/appindicator.h"
#elif defined(HAS_GTK3)
#include "node_gtk3/appindicator.h"
#endif


namespace desktop_environment_gnome
{


   class appindicator :
#if defined(HAS_GTK4)
      virtual public ::node_gtk4::appindicator
#elif defined(HAS_GTK3)
      virtual public ::node_gtk3::appindicator
#endif
   {
   public:


      appindicator();
      ~appindicator() override;


      bool create(const char * pszId, const char * pszIcon, const char * pszFolder, application_menu * papplicationmenu, application_menu_callback * papplicationmenucallback) override;



   };


} // namespace desktop_environment_gnome



