/*****<3ThomasBorregaardSørensen!!Created by camilo*/
// From acme_posix/acme_file by camilo on 2021-11-22 00:07 AM <3ThomasBorregaardSørensen!!
// From acme_apple/acme_file.h
// on 2021-08-09
// 05:02 BRT
#pragma once


#include "acme_darwin/file_system.h"


namespace acme_freebsd
{


   class CLASS_DECL_ACME file_system :
      virtual public ::acme_darwin::file_system
   {
   public:


      file_system();
      ~file_system() noexcept override ;
      
      
      void initialize(::particle * pparticle) override;


      void init_system() override;


      //::file::path module() override;


   };


} // namespace acme_freebsd



