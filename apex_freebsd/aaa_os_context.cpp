#include "framework.h"
#include "os_context.h"
#include "acme/exception/not_implemented.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "acme/filesystem/filesystem/link.h"
#include "apex/platform/node.h"
#include "apex/filesystem/file/set.h"
#include "apex/platform/system.h"
#define __BSD_VISIBLE 1
#include <unistd.h>

int daemonize_process(const char * _cmd_line, int * pprocessId);

#undef USERNAME_LENGTH // mysql one

#include <sys/stat.h>



string empty_get_file_content_type(string)
{

   return "";

}

//PFN_GET_FILE_CONTENT_TYPE g_pfnGetFileContentType = &empty_get_file_content_type;
//
//string freebsd_get_file_content_type(string strPath)
//{
//
//   return (*g_pfnGetFileContentType)(strPath);
//
//}
//
//void set_get_file_content_type_function(PFN_GET_FILE_CONTENT_TYPE pfnGetFileContentType)
//{
//
//   g_pfnGetFileContentType = pfnGetFileContentType;
//
//}


namespace apex_freebsd
{


   os_context::os_context()
   {
   }


   os_context::~os_context()
   {
   }


//   string os_context::get_command_line()
//   {
//
//      return acmesystem()->m_papexsystem->get_command_line();
//
//   }


   void os_context::shutdown(bool bIfPowerOff)
   {
      /*      bool retval = true;
            HANDLE hToken;
            TOKEN_PRIVILEGES tkp;
            if (!OpenProcessToken(GetCurrentProcess(),
               TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
               return false;
            LookupPrivilegeValue(nullptr, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid);
            tkp.PrivilegeCount = 1;
            tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            AdjustTokenPrivileges(hToken, false, &tkp, 0, (PTOKEN_PRIVILEGES) nullptr, 0);
            if (bIfPowerOff)
               retval = ExitWindowsEx(EWX_POWEROFF, 0) != false;
            else
               retval = ExitWindowsEx(EWX_SHUTDOWN, 0) != false;

            //reset the previlages
            tkp.Privileges[0].Attributes = 0;
            AdjustTokenPrivileges(hToken, false, &tkp, 0, (PTOKEN_PRIVILEGES) nullptr, 0);
            return retval;*/

      throw not_implemented();
      //return false;

   }


   void os_context::reboot()
   {
      /*      HANDLE hToken;
            TOKEN_PRIVILEGES tkp;
            if (!OpenProcessToken(GetCurrentProcess(),
               TOKEN_ADJUST_PRIVILEGES | TOKEN_QUERY, &hToken))
               return false;
            if(!LookupPrivilegeValue(nullptr, SE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid))
            {
               TRACELASTERROR();
               return false;
            }
            tkp.PrivilegeCount = 1;
            tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            if(!AdjustTokenPrivileges(hToken, false, &tkp, 0, (PTOKEN_PRIVILEGES) nullptr, 0))
            {
               TRACELASTERROR();
               return false;
            }
            if (get_last_error() == ERROR_NOT_ALL_ASSIGNED)
            {
               return false;
            }
            if(!LookupPrivilegeValue(nullptr, SE_REMOTE_SHUTDOWN_NAME, &tkp.Privileges[0].Luid))
            {
               TRACELASTERROR();
               return false;
            }
            tkp.PrivilegeCount = 1;
            tkp.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
            if(!AdjustTokenPrivileges(hToken, false, &tkp, 0, (PTOKEN_PRIVILEGES) nullptr, 0))
            {
               TRACELASTERROR();
               return false;
            }
            if (get_last_error() == ERROR_NOT_ALL_ASSIGNED)
            {
               return false;
            }


            if(!WTSShutdownSystem(WTS_CURRENT_SERVER_HANDLE, WTS_WSD_REBOOT))
            {
               TRACELASTERROR();
               return false;
            }
      //      if (!ExitWindowsEx(EWX_REBOOT | EWX_FORCE,
      //      SHTDN_REASON_MAJOR_SOFTWARE | SHTDN_REASON_MINOR_INSTALLATION))
      //      {
      //      unsigned int dwLastError = ::get_last_error();
      //      return false;
      //      }
            //reset the previlages
      //      tkp.Privileges[0].Attributes = 0;
      //      AdjustTokenPrivileges(hToken, false, &tkp, 0, (PTOKEN_PRIVILEGES) nullptr, 0);
      //      return true;
            throw not_implemented();
            return false;

         */
      throw not_implemented();
      //return false;
   }


   void os_context::terminate_processes_by_title(const ::string & strName)
   {

      throw not_implemented();

      //return;

      /*      unsigned int dwPid;
            while(get_pid_by_title(strName, dwPid))
            {
               HANDLE hProcess = OpenProcess( PROCESS_QUERY_INFORMATION |
                  PROCESS_VM_READ,
                  false, dwPid );
               TerminateProcess(hProcess, (unsigned int) -1);
               Clos_contexteHandle(hProcess);
               ::EnumWindows((WNDENUMPROC)
               CKillProcessHelper::TerminateAppEnum,
               (LPARAM) dwId);
               // Wait on the handle. If it signals, great.

               //If it times out, then you kill it.

               if(WaitForSingleObject(hProcess, 5000)
               !=WAIT_OBJECT_0)
               bResult = TerminateProcess(hProcess,0);
               else
               bResult = true;
               Clos_contexteHandle(hProcess);
               return bResult == true;*/

      //  }
   }


//   bool os_context::path_pid(unsigned int & dwPid, const ::string & strName)
//   {
//
//      u32_array dwa;
//      get_all_processes(dwa);
//      for(int i = 0; i < dwa.get_count(); i++)
//      {
//         if(get_process_path(dwa[i]).compare_ci(strName) == 0)
//         {
//            dwPid = dwa[i];
//            return true;
//         }
//      }
//      return false;
//   }
//
//
//   bool os_context::title_pid(unsigned int & dwPid,  const ::string & strName)
//   {
//
//      u32_array dwa;
//
//      get_all_processes(dwa);
//
//      for(int i = 0; i < dwa.get_count(); i++)
//      {
//
//         if(get_process_path(dwa[i]).title().compare_ci(strName) == 0)
//         {
//
//            dwPid = dwa[i];
//
//            return true;
//
//         }
//
//      }
//
//      return false;
//
//   }
//
//
//   ::file::path os_context::get_process_path(unsigned int dwPid)
//   {
//
//      throw not_implemented();
//
//      return "";
//
//   }
//
//
//   void os_context::get_all_processes(u32_array & dwa )
//   {
//
//      throw not_implemented();
//
//      //return;
//
//      /*
//            dwa.set_size(0);
//            unsigned int cbNeeded = 0;
//            while(cbNeeded == natural(dwa.get_count()))
//            {
//               dwa.set_size(dwa.get_count() + 1024);
//               if(!EnumProcesses(
//                  dwa.get_data(),
//                  (unsigned int) (dwa.get_count() * sizeof(unsigned int)),
//                  &cbNeeded))
//               {
//                  return;
//               }
//               dwa.set_size(cbNeeded / sizeof(unsigned int));
//            }*/
//   }
//
////   string os_context::get_module_path(HMODULE hmodule)
////   {
////      throw not_implemented();
////      return "";
////      /*
////      string strPath;
////      unsigned int dwSize = 1;
////      while(natural(strPath.get_length() + 1) == dwSize)
////      {
////         dwSize = ::GetModuleFileName(
////            hmodule,
////            strPath.get_string_buffer(dwSize + 1024),
////            (dwSize + 1024));
////         strPath.ReleaseBuffer();
////      }
////      return strPath;*/
////   }


   ::payload os_context::connection_settings_get_auto_detect()
   {
      //throw not_implemented();
      return false;

      /*
            registry::Key key1;

            key1.OpenKey(HKEY_CURRENT_USER, "Software\\Micros_contextoft\\Windows\\CurrentVersion\\Internet Settings\\Connections", false);

            memory mem;

            key1.QueryValue("DefaultConnectionSettings", mem);

            bool bAutoDetect = (((byte *) mem.get_data())[8] & 0x08) != 0;

            return bAutoDetect;
      */
   }



   ::payload os_context::connection_settings_get_auto_config_url()
   {

      //throw not_implemented();
      return "";
      /*
            registry::Key key;

            key.OpenKey(HKEY_CURRENT_USER, "Software\\Micros_contextoft\\Windows\\CurrentVersion\\Internet Settings", false);

            string strUrl;

            key.QueryValue("AutoConfigURL", strUrl);

            return strUrl;
      */
   }


   void os_context::local_machine_set_run(const ::string & strKey, const ::file::path & pathExecutable, const ::string& strArguments, bool bSet)
   {


      throw not_implemented();
//      throw not_implemented();
//      return false;

      /*
            registry::Key keyKar(HKEY_LOcaL_MACHINE, "SOFTWARE\\Micros_contextoft\\Windows\\CurrentVersion\\Run", true);


            keyKar.SetValue(pszKey, pszCommand);


            return true;
      */
   }


   void os_context::local_machine_set_run_once(const ::string & strKey, const ::file::path & pathExecutable, const ::string& strArguments, bool bSet)
   {


      throw not_implemented();
      //return false;
      /*    registry::Key keyKar(HKEY_LOcaL_MACHINE, "SOFTWARE\\Micros_contextoft\\Windows\\CurrentVersion\\RunOnce", true);


            keyKar.SetValue(pszKey, pszCommand);
      */

      ///return false;

   }


   void os_context::current_user_set_run(const ::string & strKey, const ::file::path & pathExecutable, const ::string& strArguments, bool bSet)
   {

      throw not_implemented();
      //return false;

      /*
            registry::Key keyKar(HKEY_CURRENT_USER, "SOFTWARE\\Micros_contextoft\\Windows\\CurrentVersion\\Run", true);


            keyKar.SetValue(pszKey, pszCommand);
      */

      //return false;

   }


   void os_context::current_user_set_run_once(const ::string & strKey, const ::file::path & pathExecutable, const ::string& strArguments, bool bSet)
   {

      throw not_implemented();
      //return false;

      /*
            registry::Key keyKar(HKEY_CURRENT_USER, "SOFTWARE\\Micros_contextoft\\Windows\\CurrentVersion\\RunOnce", true);


            keyKar.SetValue(pszKey, pszCommand);

      */
      //return false;

   }


   void os_context::defer_register_ca2_plugin_for_mozilla()
   {
      //  throw not_implemented();
      //return false;

      /*
            registry::Key keyPlugins;

            if(keyPlugins.OpenKey(HKEY_LOcaL_MACHINE, "SOFTWARE\\MozillaPlugins", true))
            {

               registry::Key keyPlugin;

               if(keyPlugin.OpenKey(keyPlugins, "@ca2.cc/npca2", true))
               {

                  keyPlugin.SetValue("Description", "ca2 plugin for NPAPI");
                  keyPlugin.SetValue("Path", ::apex::get_system()->m_strCa2Module("npca2.dll"));
                  keyPlugin.SetValue("ProductName", "ca2 plugin for NPAPI");
                  keyPlugin.SetValue("Vendor", "ca2 Desenvolvimento de Software Ltda.");
                  keyPlugin.SetValue("Version", get_application()->file_as_string(pcontext->m_papexcontext->dir().ca2("appdata/x86/ca2_build.txt")));

                  registry::Key keyApplicationca2;

                  if(keyApplicationca2.OpenKey(keyPlugin, "application/ca2", true))
                  {

                     keyApplicationca2.SetValue("Description", "ca2 Document");

                  }

               }

            }

            return true;
      */
   }


   void os_context::file_extension_get_open_with_list_keys(string_array & straKey, const ::string & strExtension)
   {

      throw not_implemented();
      //return false;

      /*
            string strExt;

            strExt = ".";
            strExt += strExtension;

            string strOpenWithKey;
            strOpenWithKey = strExt + "\\OpenWithList";

            registry::Key key;

            key.OpenKey(HKEY_CLASSES_ROOT, strOpenWithKey, false);

            key.EnumKey(straKey);

            return true;
      */
   }


   void os_context::file_extension_get_open_with_list_commands(string_array & straCommand, const ::string & strExtension)
   {

      string_array straKey;

      //if(!
      //
      file_extension_get_open_with_list_keys(straKey, strExtension);
//      {
//
//         //return false;
//
//         throw exception(error_failed);
//
//      }

      //return true;

   }


   void os_context::file_association_set_default_icon(const ::string & strExtension, const ::string & strExtensionNamingClass, const ::string & strIconPath)
   {

      throw not_implemented();
      //return false;

      /*
            string strExtensionNamingClass(pszExtensionNamingClass);

            registry::Key keyLink3(HKEY_CLASSES_ROOT, strExtensionNamingClass, true);
            keyLink3.SetValue("DefaultIcon", pszIconPath);


            return false;
      */
   }


   void os_context::file_association_set_shell_open_command(const ::string & strExtension, const ::string & strExtensionNamingClass,  const ::string & strCommand, const ::string & strParam)
   {

      //return false;

      throw not_implemented();

      //return false;

      /*
            string strExt;

            strExt = ".";
            strExt += strExtension;

            string strExtensionNamingClass(pszExtensionNamingClass);

            registry::Key key(HKEY_CLASSES_ROOT, strExt, true);
            key.SetValue(nullptr, strExtensionNamingClass);

            registry::Key keyLink3(HKEY_CLASSES_ROOT, strExtensionNamingClass + "\\shell", true);
            keyLink3.SetValue(nullptr, "open");

            registry::Key keyLink2(keyLink3, "open", true);
            keyLink2.SetValue(nullptr, "&Abrir");

            registry::Key keyLink1(keyLink2, "command", true);

            string strFormat;
            strFormat.Format("\"%s\" \"%%L\" %s", pszCommand, pszParam);
            keyLink1.SetValue(nullptr, strFormat);

            return true;
      */
   }


   void os_context::file_association_get_shell_open_command(const ::string & strExtension, string & strExtensionNamingClass, string & strCommand, string & strParam)
   {

      throw not_implemented();

      //return false;

      /*
            string strExt;

            strExt = ".";
            strExt += strExtension;

            registry::Key key(HKEY_CLASSES_ROOT, strExt, false);
            if(!key.QueryValue(nullptr, strExtensionNamingClass))
               return false;

            registry::Key keyLink(HKEY_CLASSES_ROOT, strExtensionNamingClass + "\\shell\\open\\command", false);

            string strFormat;
            if(keyLink.QueryValue(nullptr, strFormat))
            {

               const ::string & str = strFormat;

               try
               {

                  strCommand = ::str::consume_quoted_value(psz);
                  ::str::consume_spaces(psz);
                  ::str::consume(psz, "\"%L\"");
                  strParam = psz;

               }
               catch(...)
               {
               }


            }

            return true;
      */
   }


//   bool os_context::open_in_ie(const char * pcsz)
//   {
//
//      throw not_implemented();
//      return false;
//
//      /*    registry reg;
//            string str;
//            string str2;
//            string strCommand;
//            registry::Key key;
//            if(key.OpenKey(HKEY_CLASSES_ROOT, ".html", false))
//            {
//               if(reg.RegQueryValue(key.m_hkey, "", str))
//               {
//                  if(key.OpenKey(HKEY_CLASSES_ROOT, ".html\\shell\\opennew\\command", false))
//                  {
//                     string str;
//                     if(reg.RegQueryValue(HKEY_CLASSES_ROOT, str, str2))
//                     {
//                        string strCommand(str2);
//                        strCommand.replace("%1", pcsz);
//
//                        WinExec(strCommand,e_display_normal);
//                     }
//                  }
//                  else
//                  {
//                     if(key.OpenKey(HKEY_CLASSES_ROOT, str, false))
//                     {
//                        str += "\\shell\\opennew\\command";
//                        if(key.OpenKey(HKEY_CLASSES_ROOT, str, false))
//                        {
//                           if(reg.RegQueryValue(key.m_hkey, "", str2))
//                           {
//                              string strCommand(str2);
//                              strCommand.replace("%1", pcsz);
//
//                              WinExec(strCommand,e_display_normal);
//                           }
//                        }
//                     }
//                  }
//               }
//            }
//
//            return true;
//      */
//
//   }


   void os_context::enable_service(const ::string & strServiceName, const ::string & strDisplayName, const ::string & strCommand, const ::string & strUser, const ::string & strPass)
   {

      throw not_implemented();

      //throw not_implemented();
      //return true;

      /*
            if(papp->m_strAppName.is_empty()
            || papp->m_strAppName.compare_ci("bergedge") == 0
            || !papp->is_serviceable())
               return false;

            SC_HANDLE hdlSCM = OpenSCManager(0, 0, SC_MANAGER_CREATE_SERVICE);

            string strcalling = papp->m_strModulePath + " : app=" + papp->m_strAppId + " service usehos_contexttlogin";

            if(hdlSCM == 0)
            {
               //::get_last_error()
               return false;
            }

            SC_HANDLE hdlServ = ::CreateService(
               hdlSCM,                    // SCManager database
               "apex-" + papp->m_strAppName,               // name of service
               "ccwarehouse ca2 account " + papp->m_strAppName,        // service name to display
               STANDARD_RIGHTS_REQUIRED,  // desired access
               SERVICE_WIN32_OWN_PROCESS | SERVICE_INTERACTIVE_PROCESS, // service type
               SERVICE_AUTO_START,      // start type
               SERVICE_ERROR_NORMAL,      // error control type
               strcalling,                   // service's binary Path name
               0,                      // no load ordering group
               0,                      // no tag identifier
               0,                      // no dependencies
               0,                      // LocalSystem account
               0);                     // no password

            if (!hdlServ)
            {
               Clos_contexteServiceHandle(hdlSCM);
               //Ret = ::get_last_error();
               return false;
            }

            Clos_contexteServiceHandle(hdlServ);
            Clos_contexteServiceHandle(hdlSCM);

            return true;
      */

   }


   void os_context::disable_service(const ::string & strServiceName)
   {

      throw not_implemented();

//      throw not_implemented();
      //return false;

      /*
            if(papp->m_strAppName.is_empty()
            || papp->m_strAppName.compare_ci("bergedge") == 0
            || !papp->is_serviceable())
               return false;

            SC_HANDLE hdlSCM = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);

            if(hdlSCM == 0)
            {
               //::get_last_error();
               return false;
            }

            SC_HANDLE hdlServ = ::OpenService(
               hdlSCM,                    // SCManager database
               "apex-" + papp->m_strAppName,               // name of service
               DELETE);                     // no password

            if (!hdlServ)
            {
               // Ret = ::get_last_error();
               Clos_contexteServiceHandle(hdlSCM);
               return false;
            }

            ::DeleteService(hdlServ);

            Clos_contexteServiceHandle(hdlServ);

            Clos_contexteServiceHandle(hdlSCM);

            return false;
      */
   }


   void os_context::start_service(const ::string & strServiceName)
   {

      throw not_implemented();

      //throw not_implemented();
      //return false;

      /*
            if(papp->m_strAppName.is_empty()
            || papp->m_strAppName.compare_ci("bergedge") == 0
            || !papp->is_serviceable())
               return false;

            SC_HANDLE hdlSCM = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);

            if(hdlSCM == 0)
            {
               //::get_last_error();
               return false;
            }

            SC_HANDLE hdlServ = ::OpenService(
               hdlSCM,                    // SCManager database
               "apex-" + papp->m_strAppName,               // name of service
               SERVICE_START);                     // no password


            if (!hdlServ)
            {
               Clos_contexteServiceHandle(hdlSCM);
               //Ret = ::get_last_error();
               return false;
            }

            bool bOk = StartService(hdlServ, 0, nullptr) != false;

            Clos_contexteServiceHandle(hdlServ);
            Clos_contexteServiceHandle(hdlSCM);

            return bOk != false;
            */
   }


   void os_context::stop_service(const ::string & strServiceName)
   {

      throw not_implemented();

      //throw not_implemented();
      //return false;

      /*
            if(papp->m_strAppName.is_empty()
            || papp->m_strAppName.compare_ci("bergedge") == 0
            || !papp->is_serviceable())
               return false;

            SC_HANDLE hdlSCM = OpenSCManager(0, 0, SC_MANAGER_ALL_ACCESS);

            if(hdlSCM == 0)
            {
               //::get_last_error();
               return false;
            }

            SC_HANDLE hdlServ = ::OpenService(
               hdlSCM,                    // SCManager database
               "apex-" + papp->m_strAppName,               // name of service
               SERVICE_STOP);                     // no password

            if (!hdlServ)
            {
               // Ret = ::get_last_error();
               Clos_contexteServiceHandle(hdlSCM);
               return false;
            }

            SERVICE_STATUS ss;

            __memset(&ss, 0, sizeof(ss));

            bool bOk = ::ControlService(hdlServ, SERVICE_CONTROL_STOP, &ss) != false;

            ::DeleteService(hdlServ);

            Clos_contexteServiceHandle(hdlServ);

            Clos_contexteServiceHandle(hdlSCM);

            return bOk != false;
      */
   }


   void os_context::raise_exception( unsigned int dwExceptionCode, unsigned int dwExceptionFlags)
   {

      throw not_implemented();
      return;
      /*
            RaiseException( dwExceptionCode, dwExceptionFlags, 0, nullptr );
            */
   }


   bool os_context::is_remote_session()
   {

//      throw not_implemented();
      return false;
      /*
            return GetSystemMetrics(SM_REMOTESESSION) != false;
      */
   }


//   void os_context::post_to_all_threads(const ::id & id, wparam wparam, lparam lparam)
//   {
//
//      return;
//
//   }


//   int os_context::get_pid()
//   {
//
//      return ::getpid();
//
//   }


   void os_context::initialize_wallpaper_fileset(::file::set * pfileset, bool bAddSearch)
   {

      if (bAddSearch)
      {

         ::file::path pathBaseFolder;

         pathBaseFolder = "/usr/local/share/backgrounds";

         ::file::path pathFolder;

         string strCurrentDesktop;

         strCurrentDesktop = string(getenv("XDG_CURRENT_DESKTOP")).lowered();

         pathFolder = pathBaseFolder / strCurrentDesktop;

         pfileset->add_search(pathFolder, true);

      }

      //return true;

   }


   //#elif defined(FREEBSD)
   //            }
   //
   //#elif defined(MACos_context)
   //   //string strDir;
   //   //strDir = pcontext->m_papexcontext->dir().path(getenv("HOME"), "Pictures");
   //   //imagefileset.add_search(strDir);
   //   string strDir;
   //   strDir = "/Library/Desktop Pictures";
   //   imagefileset.add_search(strDir, true);
   //            }
   //
   //#else

   void os_context::get_default_browser(string & strId, ::file::path & path, string & strParam)
   {

      auto str = node()->get_output("/bin/sh -c \"xdg-settings get default-web-browser\"");

      str.trim();

      if(str.case_insensitive_ends(".desktop"))
      {

         ::file::path pathDesktop = "/usr/share/applications";

         pathDesktop /= str;

         if(file_exists(pathDesktop))
         {

            ::file::path pathTarget;

            auto pfilelink = path_system()->resolve_link(pathTarget, ::file::e_link_target);

            path = pfilelink->m_pathTarget;

         }

      }

      //string str = ::apex::get_system()->process().get_output("xdg-settings get default-web-browser");

      if(str.case_insensitive_find_index("chrome") >= 0)
      {

         strId = "chrome";

         if(path.is_empty())
         {

            path = "google-chrome";

         }

      }
      else
      {

         strId = "firefox";


         path = "firefox";

      }

      //return true;

   }


   void os_context::file_open(const ::file::path & path, const ::string & strParams, const ::file::path & pathFolder)
   {

      string strTarget;

      strTarget = get_context()->m_papexcontext->defer_process_path(path);

      if(freebsd_can_exec(strTarget))
      {

         //int iPid;

         //daemonize_process(strTarget, &iPid);

         //::system("cd /; setsid \"" + strTarget + "\" </dev/null &>/dev/null");

         //int daemonize_process(const char * _cmd_line, int * pprocessId)

         // 2018-01-29 call_async("/bin/bash", "-c \"" + strTarget + "\"", strFolder, SW_SHOWDEFAULT, false);

         node()->call_async(strTarget, strParams, pathFolder, e_display_default, false);

//         char * pszCommandLine = strdup(strTarget + " " + strParams);

//         pid_t pid = ::fork();
//
//         if(pid == 0)
//         {
//
//            int iExitCode = ::system(pszCommandLine);
//
//            free(pszCommandLine);
//
//            exit(iExitCode);
//
//         }
//         else if(pid < 0)
//         {
//
//            free(pszCommandLine);
//
//            return false;
//
//         }

         //return true;

      }
      else
      {

         //call_async("/bin/bash", "-i -c 'xdg-open \"" + strTarget + "\"'", strFolder, SW_SHOWDEFAULT, false);

         //::system("nohup /bin/bash -l -c 'xdg-open \"" + strTarget + "\"' > /dev/null 2>&1&");

         //::system("nohup xdg-open \"" + strTarget + "\" > /dev/null 2>&1&");

         node()->user_post([this, strTarget]()
         {

            string strUri = strTarget;

            if(!strUri.contains("://"))
            {

               strUri = "file://" + strUri;

            }

            string strError;

            int iBufferSize = 4096;

            char * pszError = strError.get_buffer(iBufferSize);

            int iBool = node()->os_launch_uri(strUri, pszError, iBufferSize);

            strError.release_buffer();

            if(!iBool)
            {

               informationf("Error launching file : \"%s\" , %s", strUri.c_str(), strError.c_str());

            }

         });

      }

      //return true;

   }


//   void os_context::list_process(::file::path_array & patha, u32_array & uaPid)
//   {
//
//      ::output_debug_string("freebsd::os_context::list_process");
//
//      ::file::listing listing;
//
//      listing.set_folder_listing("/proc/");
//
//      m_psystem->m_pacmedirectory->enumerate(listing);
//
//      auto psystem = m_psystem;
//
//      auto pnode = psystem->node();
//
//      for(auto & strPid : listing)
//      {
//
//         int iPid = atoi(strPid.title());
//
//         if(iPid > 0)
//         {
//
//            ::file::path path = pnode->module_path_from_pid(iPid);
//
//            if(path.has_char())
//            {
//
//               patha.add(path);
//
//               uaPid.add(iPid);
//
//            }
//
//         }
//
//      }
//
//   }


   bool os_context::freebsd_can_exec(const char *file)
   {

      struct stat st;

      string str(file);

      if(str.case_insensitive_begins_eat("\""))
      {

         character_count iFind = str.find_index("\"");

         if(iFind < 0)
         {

            return false;

         }

         str = str.left(iFind);

      }
      else if(str.case_insensitive_begins_eat("\'"))
      {

         character_count iFind = str.find_index("\'");

         if(iFind < 0)
         {

            return false;

         }

         str = str.left(iFind);

      }
      else
      {

         character_count iFind = str.find_index(" ");

         if(iFind > 0)
         {

            str = str.left(iFind);

         }


      }

      if(str == "sudo")
      {

         return true;

      }

      zero(st);

      if (stat(str, &st) < 0)
      {

         return false;

      }

      if ((st.st_mode & S_IEXEC) != 0)
      {

         string strContentType = node()->get_file_content_type(str);

         if(strContentType == "application/x-shellscript")
         {

            return true;

         }
         else if(strContentType == "application/x-sharedlib")
         {

            return true;

         }


         return false;

      }

      return false;

   }


} // namespace apex_freebsd



