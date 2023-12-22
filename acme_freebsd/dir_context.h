#pragma once


#include "acme/filesystem/filesystem/dir_context.h"


namespace acme_freebsd
{


   class CLASS_DECL_ACME_FREEBSD dir_context :
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


} // namespace acme_freebsd



