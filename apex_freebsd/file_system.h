#pragma once


#include "apex/filesystem/filesystem/file_system.h"


namespace apex_freebsd
{


   class CLASS_DECL_APEX_FREEBSD file_system:
      virtual public ::file_system
   {
   public:


      file_system();
      ~file_system() override;


      void initialize(::particle * pparticle) override;


      void init_system() override;


   };


} // namespace apex_freebsd



