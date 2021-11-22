// From acme_posix/acme_file.cpp by camilo on 2021-11-22 00:07 AM <3ThomasBorregaardSørensen!!
// Created by camilo
// on 2021-08-12 17:38 BRT
// <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "acme/node/operating_system/freebsd/_freebsd.h"


namespace freebsd
{


   acme_file::acme_file()
   {


   }


   acme_file::~acme_file() noexcept
   {


   }


   ::file::path acme_file::module()
   {

      auto pathModule = ::path::module();

      return pathModule;

   }


}  // namespace frebsd



