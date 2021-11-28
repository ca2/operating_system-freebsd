#include "framework.h"
#include <sys/utsname.h>



__FACTORY_EXPORT void node_freebsd_factory(::factory::factory * pfactory)
{

   auto edesktop = get_edesktop();

   ::e_status estatus = ::success_none;

   if (edesktop & ::user::e_desktop_kde)
   {

      auto & pfactoryKde = pfactory->m_psystem->factory("desktop_environment", "kde");

   }
   else if (edesktop & ::user::e_desktop_gnome)
   {

      auto & pfactoryGnome = pfactory->m_psystem->factory("desktop_environment", "gnome");

   }
   else if (edesktop & ::user::e_desktop_xfce)
   {

      auto & pfactoryXfce = pfactory->m_psystem->factory("desktop_environment", "xfce");

   }
   else
   {

      auto & pfactoryGnome = pfactory->m_psystem->factory("desktop_environment", "gnome");

      if (!pfactoryGnome)
      {

         auto & pfactoryKde = pfactory->m_psystem->factory("desktop_environment", "kde");

         if (!pfactoryKde)
         {

            auto & pfactoryXfce = pfactory->m_psystem->factory("desktop_environment", "kde");

         }

      }

   }
//
//#else
//
//      estatus = factory("aura", "windows");
//
//#endif


//      apex_freebsd_factory( pfactory);
//
//   aura_posix_factory( pfactory);
//
//   pfactory->add_factory_item < ::aura::freebsd::node, ::acme::node >();

}


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

   if(::dir::is("/etc/xdg/lubuntu"))
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



