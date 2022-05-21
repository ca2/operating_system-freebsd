// From acme_posix/acme_file.cpp by camilo on 2021-11-22 00:07 AM <3ThomasBorregaardSørensen!!
// Created by camilo
// on 2021-08-12 17:38 BRT
// <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "acme/operating_system/freebsd/_freebsd.h"


namespace acme_freebsd
{


   acme_file::acme_file()
   {


   }


   acme_file::~acme_file() noexcept
   {


   }


   ::file::path acme_file::module()
   {

      return ::acme_posix::acme_file::module();

      //auto pathModule = m_psystem->m_pacmepath->module();

      //return pathModule;

   }


}  // namespace acme_frebsd



