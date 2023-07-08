#pragma once


#include "apex/filesystem/filesystem/dir_system.h"


namespace apex_freebsd
{


   class CLASS_DECL_APEX_FREEBSD dir_system :
      virtual public ::dir_system
   {
   public:


      dir_system();
      ~dir_system() override;


      void initialize(::particle * pparticle) override;


      void init_system() override;


   };


} // namespace apex_freebsd



