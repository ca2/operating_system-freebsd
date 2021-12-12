//
// Created by camilo on 11/29/21 18:21 BRT <3ThomasBorregaardSorensen!!
//
#include "framework.h"
#include <sys/utsname.h>


::user::enum_desktop calculate_edesktop()
{

   const char * pszDesktop = getenv("XDG_CURRENT_DESKTOP");

   string strDesktop(pszDesktop);

   if(strDesktop.compare_ci("kde") == 0)
   {

      return ::user::e_desktop_kde;

   }

   utsname name;

   memset(&name, 0, sizeof(utsname));

   uname(&name);

   if(pszDesktop != nullptr)
   {

      if(strcasecmp(pszDesktop, "Unity") == 0)
      {

         return ::user::e_desktop_unity_gnome;

      }

   }

   if(is_directory("/etc/xdg/lubuntu"))
   {

      return ::user::e_desktop_lxde;

   }
   else if(file_exists("/usr/bin/xfconf-query"))
   {

      return ::user::e_desktop_xfce;

   }
   else if(file_exists("/usr/bin/mate-about"))
   {

      return ::user::e_desktop_mate;

   }
   else if(file_exists("/usr/bin/unity"))
   {

      return ::user::e_desktop_unity_gnome;

   }
   else if(strcasecmp(pszDesktop, "ubuntu:gnome") == 0)
   {

      return ::user::e_desktop_ubuntu_gnome;

   }
   else if(strcasecmp(pszDesktop, "gnome") == 0)
   {

      return ::user::e_desktop_gnome;

   }

   return ::user::e_desktop_gnome;

}


::user::enum_desktop g_edesktop = ::user::e_desktop_none;


::user::enum_desktop get_edesktop()
{

   if(g_edesktop == user::e_desktop_none)
   {

      g_edesktop = calculate_edesktop();

   }

   return g_edesktop;

}


