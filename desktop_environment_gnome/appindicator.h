//
// Created by camilo on 20/01/2021. ThomasBS!!
//
#pragma once


#include "node_gnome/appindicator.h"


namespace desktop_environment_gnome
{


   class appindicator :
      virtual public ::node_gnome::appindicator
   {
   public:


      appindicator();
      ~appindicator() override;


      virtual bool create(const char * pszId, const char * pszIcon, const char * pszFolder, user_notify_icon_bridge * pbridge) override;



   };


} // namespace desktop_environment_gnome



