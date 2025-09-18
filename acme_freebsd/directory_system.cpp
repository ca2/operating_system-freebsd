// Create on 2021-03-21 20:00 <3ThomasBS_
#include "framework.h"
#include "directory_system.h"
#include "file_system.h"


namespace acme_freebsd
{

   
   directory_system::directory_system()
   {

      m_pplatformdir = this;

   }


   directory_system::~directory_system()
   {


   }
   
   
   
   void directory_system::initialize(::particle * pparticle)
   {

      //auto estatus =

      ::directory_system::initialize(pparticle);


   }


   void directory_system::init_system()
   {

      ::directory_system::init_system();

   }



   string directory_system::dir_root()
   {

      return home() / ".config/ca2";

   }


   ::file::path directory_system::get_memory_map_base_folder_path() 
   {

      return home() / ".config/ca2/memory_map";

   }


//   ::file::path directory_system::home()
//   {
//
//      return getenv("HOME");
//
//   }


   ::file::path directory_system::program_data()
   {

      return home() / "application";

   }


   ::file::path directory_system::roaming()
   {

      return home() / ".config";

   }


   ::file::path directory_system::appdata()
   {

      return ca2roaming() / "appdata" / this->appid();

   }


//    ::file::path directory_system::public_system()
//    {
//
//       return public_root() / "system";
//
//    }


   ::file::path directory_system::userconfig()
   {

      return ca2roaming() / "user";

   }


   ::file::path directory_system::config()
   {

      return ca2roaming() / "config";

   }


   ::file::path directory_system::local()
   {

      return ca2roaming() / "local";

   }


   ::file::path directory_system::sensitive()
   {

   #ifdef FREEBSD

      return "C:\\sensitive\\sensitive";

   #else

      return "/sensitive/sensitive";

   #endif

   }







   string directory_system::system_short_name()
   {

      ::file::path pathSystemShortName = localconfig() / "system_short_name.txt";

      return m_pfilesystem->as_string(pathSystemShortName).trimmed();

   }


   ::file::path directory_system::relative(::file::path path)
   {

      path.find_replace(":", "");

      path.case_insensitive_ends_eat(".exe");

      return path;

   }

   #ifdef _UWP


   ::file::path directory_system::app_relative()
   {

      return "";

   }


   #else


   ::string directory_system::appid()
   {

      ::file::path path = m_pfilesystem->module();

      path = file_path_folder(path);

      return path;

   }


   #endif



   ::file::path directory_system::inplace_install(const ::scoped_string & scopedstrAppId, const ::scoped_string & scopedstrPlatform, const ::scoped_string & scopedstrConfiguration)
   {

   #ifdef FREEBSD_DESKTOP

      ::file::path path;

      string strFolder;

      character_count iFind = strAppId.find('/');

      if (strPlatform.compare_ci("win32") == 0 || strPlatform.compare_ci("x86") == 0)
      {

         path = program_files_x86();

      }
      else
      {
         path = program_files_x86();


         path = program_files();

      }

      if (iFind < 0)
      {

         path /= strAppId;

      }
      else
      {

         path /= strAppId.Left(iFind);

         path /= strAppId.Mid(iFind + 1);

      }

      return path;

   #elif defined(ANDROID)

      return pacmedir->roaming();

   #else

      return file_system()->module().folder(4);

   #endif


   }


   ::file::path directory_system::inplace_matter_install(const ::scoped_string & scopedstrAppId, const ::scoped_string & scopedstrPlatform, const ::scoped_string & scopedstrConfiguration)
   {

   #ifdef FREEBSD_DESKTOP

      ::file::path path;

      string strFolder;

      character_count iFind = strAppId.find('/');

      path = ca2roaming();

      path /= "_matter";

      return path;

   #elif defined(ANDROID)

      return pacmedir->roaming();

   #else

      return file_system()->module().folder(4);

   #endif


   }


   ::file::path directory_system::install()
   {

      if (m_pathInstallFolder.is_empty())
      {

         return default_install();

      }

      return m_pathInstallFolder;

   }


   ::file::path directory_system::default_install()
   {

   #ifdef ANDROID

      return pacmedir->roaming();

   #elif defined(__APPLE__)

      return m_psystem->m_pacmepath->app_module().folder(3);

   #else

      return file_system()->module().folder(4);

   #endif

   }


   ::file::path directory_system::beforeca2()
   {

      return file_path_folder(install());

   }


   ::file::path directory_system::program_files_x86()
   {

      ::file::path path("/opt/ca2");

      return path;

   }


   ::file::path directory_system::program_files()
   {

      ::file::path path("/opt/ca2");

      return path;

   }

   ::file::path directory_system::stage(const ::scoped_string & scopedstrAppId, const ::scoped_string & scopedstrPlatform, const ::scoped_string & scopedstrConfiguration)
   {

      return inplace_install(scopedstrAppId, scopedstrPlatform, scopedstrConfiguration) / "time" / scopedstrPlatform / scopedstrConfiguration;

   }


   ::file::path directory_system::home()
   {

      return getenv("HOME");

   }


   void directory_system::set_path_install_folder(const ::scoped_string & scopedstrPath)
   {

      m_pathInstallFolder = scopedstrPath;

   }


   ::file::path directory_system::bookmark()
   {

      return localconfig() / "bookmark";

   }





   ::file::path directory_system::sys_temp()
   {

      return appdata() / "time";

   }


   //::string directory_system::dir_root()
   //{

   //   return "";

   //}


   //::file::path directory_system::home()
   //{

   //   return "";

   //}


   //::file::path directory_system::program_data()
   //{

   //   return "";

   //}


   ::file::path directory_system::ca2appdata()
   {

      return ca2roaming() / "appdata";

   }



   ::file::path directory_system::public_root()
   {

      return program_data() / "ca2";

   }

   ::file::path directory_system::ca2roaming()
   {

      return roaming() / "ca2";

   }


   ::file::path directory_system::localconfig()
   {

      return ca2roaming() / "localconfig";

   }


   ::file::path directory_system::module()
   {

      return ::acme_darwin::directory_system::module();

   }

   //
   //::file::path directory_system::base_module()
   //{
   //
   //   return "";
   //
   //}
   //

   //::file::path directory_system::ca2_module()
   //{
   //
   //   return "";
   //
   //}
   //
   ::file::path directory_system::archive()
   {

      return "";

   }



   ::file::path directory_system::tool()
   {

      return "";

   }


   //::file::path directory_system::roaming()
   //{

   //   return "";

   //}


   ::file::path directory_system::pathfind(const ::scoped_string & scopedstrEnv, const ::scoped_string & scopedstrTopic, const ::scoped_string & scopedstrMode)
   {

      ::file::path_array stra;

      stra.add_tokens(scopedstrEnv, ":", false);

      string strCandidate;

      for (::collection::index i = 0; i < stra.get_count(); i++)
      {

         strCandidate = stra[i] / scopedstrTopic;

         //if (m_pcontext->m_papexcontext->file().exists(strCandidate))
         if (file_exists(strCandidate))
         {

            return strCandidate;

         }

      }

      return "";

   }


   //::file::path directory_system::get_memory_map_base_folder_path()
   //{

   //   return "";

   //}


   ::file::path directory_system::user_appdata_local()
   {

      //return _shell_get_special_folder_path(CSIDL_LOCAL_APPDATA);

      return home() / ".config";

   }


} // namespace acme_freebsd



