#include "framework.h"
#include "acme/platform/system.h"


//::user::enum_desktop get_edesktop();


namespace nano
{
   namespace user
   {
      ::user::enum_desktop get_edesktop();
   }//namespace user
}// namespace nano


__FACTORY_EXPORT void node_freebsd_factory(::factory::factory * pfactory)
{

   auto edesktop = ::nano::user::get_edesktop();

   ::e_status estatus = ::success_none;

   if (edesktop == ::user::e_desktop_kde)
   {

      auto & pfactoryKde = ::platform::get()->factory("desktop_environment", "kde");

      pfactoryKde->merge_to_global_factory();

   }
   else if (edesktop == ::user::e_desktop_gnome)
   {

      auto & pfactoryGtkBased = ::platform::get()->factory("desktop_environment", "gtk_based");

      pfactoryGtkBased->merge_to_global_factory();

   }
   else if (edesktop == ::user::e_desktop_xfce)
   {

      auto & pfactoryXfce = ::platform::get()->factory("desktop_environment", "xfce");

      pfactoryXfce->merge_to_global_factory();

   }
   else
   {

      auto & pfactoryGtkBased = ::platform::get()->factory("desktop_environment", "gtk_based");

      if (!pfactoryGtkBased)
      {

         auto & pfactoryKde = ::platform::get()->factory("desktop_environment", "kde");

         if (!pfactoryKde)
         {

            auto & pfactoryXfce = ::platform::get()->factory("desktop_environment", "kde");

            if (!pfactoryXfce)
            {

               output_debug_string("No desktop_environment_*\n");

            }
            else
            {

               pfactoryXfce->merge_to_global_factory();

            }

         }
         else
         {

            pfactoryKde->merge_to_global_factory();

         }

      }
      else
      {

         pfactoryGtkBased->merge_to_global_factory();

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



