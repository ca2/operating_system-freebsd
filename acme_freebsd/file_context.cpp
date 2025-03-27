#include "framework.h"
#include "file_context.h"
#include "acme/filesystem/filesystem/directory_system.h"


namespace acme_freebsd
{


   file_context::file_context()
   {

   }


   file_context::~file_context()
   {

   }


   void file_context::initialize(::particle * pparticle)
   {

      ::acme_darwin::file_context::initialize(pparticle);

   }


   void file_context::init_system()
   {

      ::file_context::init_system();

   }


   void file_context::init_context()
   {

      ::file_context::init_context();


   }


   // ::file::path file_context::dropbox_info_network_payload()
   // {

   //    ::file::path pathJson;

   //    pathJson = directory_system()->home() / ".dropbox/info.json";

   //    return pathJson;

   // }


} // namespace acme_freebsd



