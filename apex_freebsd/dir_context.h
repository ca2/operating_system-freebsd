#pragma once


#include "apex/filesystem/filesystem/dir_context.h"


namespace apex_freebsd
{


   class CLASS_DECL_APEX_FREEBSD dir_context :
      virtual public ::dir_context
   {
   public:


      dir_context();
      ~dir_context() override;


      void initialize(::particle * pparticle) override;


      void init_system() override;
      void init_context() override;



      ::file::listing& root_ones(::file::listing& listing) override;


   };


} // namespace apex_freebsd



