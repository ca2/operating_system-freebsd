#include "framework.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "acme/filesystem/filesystem/acme_directory.h"


#undef USE_MISC

#include <dlfcn.h>
#include <link.h>


namespace apex_freebsd
{


   file_system::file_system()
   {

   }


   file_system::~file_system()
   {

   }


   void file_system::initialize(::object * pobject)
   {

      //auto estatus =

      ::file_system::initialize(pobject);

//      if(!estatus)
//      {
//
//         return estatus;
//
//      }

      ::file::path pathAppModule = m_psystem->m_pacmefile->module();

      m_pathModule = pathAppModule;

      //m_pathCa2Module = pathCa2AppModule;

//      auto psystem = m_psystem;
//
//      auto pacmedir = psystem->m_pacmedir;
//
//      ::file::path pathCa2AppModule = pacmedir->module();

      //m_pathCa2Module = pathCa2AppModule;

//
//      void * handle = dlopen("libapex.so", RTLD_NOW);
//
//      if(::is_set(handle))
//      {
//
//         link_map * plm;
//
//         dlinfo(handle, RTLD_DI_LINKMAP, &plm);
//
//         m_pathCa2Module = plm->l_name;
//
//         dlclose(handle);
//
//      }
//
//      if(m_pathCa2Module.is_empty() || m_pathCa2Module[0] != '/')
//      {
//
//         m_pathCa2Module = m_pathModule;
//
//      }

//      return estatus;

   }


   void file_system::init_system()
   {

//      if(!update_module_path())
//      {
//
//         return ::error_failed;
//
//      }

//      return ::success;

   }


//   ::e_status file_system::update_module_path()
//   {
//
//      auto estatus = ::file_system::update_module_path();
//
//      if(!estatus)
//      {
//
//         return estatus;
//
//      }
//
//      ::file::path pathAppModule = m_psystem->m_pacmefile->module();
//
//      m_pathModule = pathAppModule;
//
//      auto psystem = m_psystem;
//
//      auto pacmedir = psystem->m_pacmedir;
//
//      ::file::path pathCa2AppModule = pacmedir->module();
//
//      m_pathCa2Module = pathCa2AppModule;
//
//      return estatus;
//
//   }


} // namespace apex_freebsd



