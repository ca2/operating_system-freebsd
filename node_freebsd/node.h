//
// Created by camilo on 21/01/2021. <33TBS!!
//

//
// Created by camilo on 21/01/2021. <3-<3ThomasBS!!
//
#pragma once


#include "aura_freebsd/node.h"

namespace node_freebsd
{


      class CLASS_DECL_NODE_FREEBSD node :
         virtual public ::aura_freebsd::node
      {
      public:


         node();

         ~node() override;


         void initialize(::particle* pparticle) override;


         //string get_user_name();


         //virtual bool _os_calc_app_dark_mode() override;

         //virtual bool _os_calc_system_dark_mode() override;

         //virtual ::color::color get_default_color(::u64 u) override;

         //virtual void set_console_colors(unsigned int dwScreenColors, unsigned int dwPopupColors, unsigned int dwWindowAlpha) override;

         //virtual ::e_status set_system_dark_mode1(bool bSet = true);

         //virtual ::e_status set_app_dark_mode1(bool bSet = true);

         //virtual double get_time_zone() override;

         //virtual ::e_status get_system_time(system_time_t * psystemtime) override;

         //void open_folder(const ::file::path & pathFolder) override;

         //virtual ::e_status register_dll(const ::file::path & pathDll) override;

         //virtual ::e_status start() override;


      };



} // namespace node_freebsd



