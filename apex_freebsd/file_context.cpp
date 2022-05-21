#include "framework.h"
#include <sys/types.h>
#include <sys/stat.h>
#include "acme/filesystem/filesystem/acme_directory.h"


struct PROCESS_INFO_t
{
   string csProcess;
   u32 dwImageListIndex;
};


namespace apex_freebsd
{


   file_context::file_context()
   {
   }


   file_context::~file_context()
   {

   }


   void file_context::initialize(::object * pobject)
   {

      //auto estatus =

      ::object::initialize(pobject);

//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      return estatus;


   }


//   file_transport file_context::get_file(const ::payload & varFile, const ::file::e_open & eopen)
//   {
//
//      return ::file_context::get_file(varFile, eopen);
//
//   }


   void file_context::init_system()
   {

      //auto estatus =
      //
      ::file_context::init_system();

//   if(!estatus)
//   {
//
//   return estatus;
//
//   }
//
//      return estatus;

   }


   void file_context::init_context()
   {

   //auto estatus =

      ::file_context::init_context();

//   if(!estatus)
//   {
//
//   return estatus;
//
//   }
//
//      return estatus;

   }


//   bool file_context::is_link(string strPath)
//   {
//
//      return file_path_is_link(strPath);
//
//   }


   ::file::path file_context::dropbox_info_network_payload()
   {

      ::file::path pathJson;

      auto psystem = m_psystem;

      auto pacmedir = psystem->m_pacmedirectory;

      pathJson = pacmedir->home() / ".dropbox/info.json";

      return pathJson;

   }


} // namespace apex_freebsd



