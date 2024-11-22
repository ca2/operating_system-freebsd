// From acme_posix/acme_file.cpp by camilo on 2021-11-22 00:07 AM <3ThomasBorregaardSørensen!!
// Created by camilo
// on 2021-08-12 17:38 BRT
// <3ThomasBorregaardSørensen!!
#include "framework.h"
#include "file_system.h"
#include <sys/types.h>
#include <sys/sysctl.h>


namespace acme_freebsd
{


   file_system::file_system()
   {


   }


   file_system::~file_system() noexcept
   {


   }


   void file_system::initialize(::particle * pparticle)
   {

      ::file_system::initialize(pparticle);

   }


   void file_system::init_system()
   {

      ::file_system::init_system();

   }


//   ::file::path acme_file::module()
//   {
//
//      int mib[4];
//
//      mib[0] = CTL_KERN;
//      mib[1] = KERN_PROC;
//      mib[2] = KERN_PROC_PATHNAME;
//      mib[3] = -1;
//
//      char buf[PATH_MAX * 4];
//
//      size_t cb = sizeof(buf);
//
//      int iError = sysctl(mib, 4, buf, &cb, NULL, 0);
//
//      if(iError < 0)
//      {
//
//         int iErrNo = errno;
//
//         auto estatus = errno_status(iErrNo);
//
//         throw ::exception(estatus, "error getting module path");
//
//      }
//
//      return buf;
//
//   }


}  // namespace acme_frebsd



