//
// Created by camilo on 19/01/2021. --<33ThomasBS!!
//
#include "framework.h"
#include "node.h"
#include "acme/constant/id.h"
#include "acme/filesystem/filesystem/directory_system.h"
#include "acme/platform/system.h"
#include "acme/prototype/datetime/datetime.h"
#include "apex/platform/system.h"
#include "aura/platform/session.h"
#include "aura/user/user/user.h"
#include "aura/windowing/windowing.h"
#include "windowing_x11/windowing_x11.h"


void gdk_branch(const ::procedure & procedure);
//CLASS_DECL_ACME void set_main_user_itask(itask_t itask);

namespace operating_ambient_gtk4
{


   //CLASS_DECL_ACME void _os_process_user_theme_color(string strTheme);


   node::node()
   {

      //m_pNodeDesktopEnvironmentGtkBased = this;

//      defer_initialize_x11();

      ///m_pGtkSettingsDeposthemecolorsfault = nullptr;

   }


   node::~node()
   {

//      if(m_pGtkSettingsDefault)
//      {
//
//         g_object_unref(m_pGtkSettingsDefault);
//
//      }

   }



//   void node::start_node()
//   {
//
//      node_gnome::node::start_node();
//
//   }


   void node::initialize(::particle * pparticle)
   {

      ::node_freebsd::node::initialize(pparticle);

      ::node_gtk4::node::initialize(pparticle);

   }


//   bool node::aaa_windowing_message_loop_step()
//   {
//
//      set_main_user_itask(current_itask());
//
//      //if(main_user_itask() != current_itask())
//      //{
//
//
//
//      //}
//
//      auto psession = session();
//
//      if(::is_null(psession))
//      {
//
//         return false;
//
//      }
//
//      auto paurasession = psession;
//
//      if(::is_null(paurasession))
//      {
//
//         return false;
//
//      }
//
//      auto puser = paurasession->user();
//
//      if(::is_null(puser))
//      {
//
//         return false;
//
//      }
//
//      auto pwindowing = system()->windowing();
//
//      if(::is_null(pwindowing))
//      {
//
//         return false;
//
//      }
//
//      bool bRet = pwindowing->aaa_message_loop_step();
//
//      return bRet;
//
//   }


//   string node::os_get_user_theme()
//   {
//
//      return m_strTheme;
//
//   }
//
//
//   bool node::os_set_user_theme(const ::string &strUserTheme)
//   {
//
//      // https://ubuntuforums.org/showthread.php?t=2140488
//      // gsettings set org.gnome.desktop.interface gtk-theme your_theme
//
//      // indirect wall-changer sourceforge.net contribution
//
//      auto psystem = system();
//
//      auto pnode = psystem->node();
//
//      auto edesktop = pnode->get_edesktop();
//
//      switch (edesktop)
//      {
//
//      case ::user::e_operating_ambient_gnome:
//      case ::user::e_operating_ambient_ubuntu_gnome:
//      case ::user::e_operating_ambient_unity_gnome:
//      {
//
//      bool bOk1 = ::node_gnome::aaa_gsettings_set("org.gnome.desktop.interface", "gtk-theme", strUserTheme);
//
//      bool bOk2 = true;
//
//      //if(::file::system_short_name().case_insensitive_contains("manjaro"))
//      {
//
//         bOk2 = ::node_gnome::aaa_gsettings_set("org.gnome.desktop.wm.preferences", "theme", strUserTheme);
//
//      }
//
//      sleep(300_ms);
//
//      ::node_gnome::gsettings_sync();
//
//      sleep(300_ms);
//
//      return
//      bOk1 &&bOk2;
//
//      }
//
//      case ::user::e_operating_ambient_mate:
//
//      //return ::user::aaa_gsettings_set("org.mate.background", "picture-filename", strLocalImagePath);
//
//      case ::user::e_operating_ambient_lxde:
//
//      //call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
//
//      break;
//
//      case ::user::e_operating_ambient_xfce:
//      {
//      //        Q_FOREACH(QString entry, Global::getOutputOfCommand("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << "/backdrop" << "-l").split("\n")){
//      //          if(entry.contains("image-path") || entry.contains("last-image")){
//      //            QProcess::startDetached("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << entry << "-s" << image);
//      //      }
//      //}
//
//      }
//
//      //break;
//
//      default:
//
//      informationf("Failed to change wallpaper. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
//      return false;
//
//      }
//
//      return true;
//
//   }


//   void node::os_process_user_theme(string strTheme)
//   {
//
//      _os_process_user_theme(strTheme);
//
//   }


//   bool node::set_wallpaper(::collection::index iScreen, string strLocalImagePath)
//   {
//
//      // wall-changer sourceforge.net contribution
//
//      auto psystem = system();
//
//      auto pnode =  psystem->node();
//
//      auto edesktop = pnode->get_edesktop();
//
//      switch (edesktop)
//      {
//
//         case ::user::e_operating_ambient_gnome:
//         case ::user::e_operating_ambient_ubuntu_gnome:
//         case ::user::e_operating_ambient_unity_gnome:
//
//            return ::node_gnome::aaa_gsettings_set("org.gnome.desktop.background", "picture-uri", "file://" + strLocalImagePath);
//
//         case ::user::e_operating_ambient_mate:
//
//            return ::node_gnome::aaa_gsettings_set("org.mate.background", "picture-filename", strLocalImagePath);
//
//         case ::user::e_operating_ambient_lxde:
//
//            call_async("pcmanfm", "-w " + strLocalImagePath, nullptr, e_display_none, false);
//
//            break;
//
//         case ::user::e_operating_ambient_xfce:
//         {
//            //        Q_FOREACH(QString entry, Global::getOutputOfCommand("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << "/backdrop" << "-l").split("\n")){
//            //          if(entry.contains("image-path") || entry.contains("last-image")){
//            //            QProcess::startDetached("xfconf-query", QStringList() << "-c" << "xfce4-desktop" << "-point" << entry << "-s" << image);
//            //      }
//            //}
//
//         }
//
//            //break;
//
//         default:
//
//            informationf("Failed to change wallpaper. If your Desktop Environment is not listed at \"Preferences->Integration-> Current Desktop Environment\", then it is not supported.");
//            return false;
//
//      }
//
//      return true;
//
//   }
//
//
//
//
//   string node::get_file_icon_path(const ::string & strPath, int iSize)
//   {
//
//      string str = ::node_gnome::node::get_file_icon_path(strPath, iSize);
//
//      return str;
//
//      //return ::linux_g_direct_get_file_icon_path(pszPath, iSize);
//
//   }
//
//
//   string node::get_file_content_type(const ::string & strPath)
//   {
//
//      string str = ::node_gnome::node::get_file_content_type(strPath);
//
//      return str;
//
//   }
//
//
//   string node::get_wallpaper(::collection::index iScreen)
//   {
//
//      return "";
//
//   }


//   void node::handle(::topic * ptopic, ::handler_context * pcontext)
//   {
//
////      if(ptopic->m_atom == ::id_operating_system_user_theme_change)
////      {
////
////         //_os_process_user_theme_color(m_strTheme);
////
////      }
//
//      ::node_gnome::node::handle(ptopic, pcontext);
//
//   }

//
//   bool node::should_launch_on_node(::topic * ptopic)
//   {
//
//      if(::is_null(ptopic))
//      {
//
//         return false;
//
//      }
//
//      if(ptopic->m_atom == id_operating_system_user_color_change)
//      {
//
//         return false;
//
//      }
//
//      return false;
//
//   }


//   bool node::launch_on_node(::topic * ptopic)
//   {
//
//      auto bOk = ::node_gnome::node::launch_on_node(ptopic);
//
//      return bOk;
//
//   }


   void node::launch_app_by_app_id(const ::scoped_string & scopedstrAppId, bool bSingleExecutableVersion)
   {
      
      ::file::path path = get_executable_path_by_app_id(scopedstrAppId, bSingleExecutableVersion);

      ::file::path pathFolder = path.folder();

      string strName = path.name();

      ::string strCommand;

      directory_system()->change_current(pathFolder);

      ::file::path pathLogFolder;

      pathLogFolder = directory_system()->home() / "application" / scopedstrAppId / "log";

      directory_system()->create(pathLogFolder);

      ::string strLogFileName;

      strLogFileName = datetime()->date_time_text_for_file_with_no_spaces();

      strLogFileName += ".txt";

      ::file::path pathLog;

      pathLog = pathLogFolder / strLogFileName;
      
      directory_system()->create(pathLog.folder());

      strCommand = "/bin/sh -c \"nohup ./\\\"" + strName + "\\\" > \\\"" + pathLog +"\\\"\"";

      information() << "node::launch_app_by_app_id : " << strCommand;

      auto inlinelog = std_inline_log();

      inlinelog.set_timeout(10_minutes);

      int iExitCode = this->command_system(strCommand, inlinelog);

      if(iExitCode != 0)
      {

         throw ::exception(error_failed);

      }

/*    
    ::string strDbusName;
    
    strDbusName = scopedstrAppId;
    
    strDbusName.find_replace("/", "." );
    
    ::string strObjectName;
    
    strObjectName = strDbusName;
    
    strObjectName.find_replace(".", "/");
    
    strObjectName = "/" + strObjectName;
    
    const char *object_path = strObjectName;
    
    informationf("Dbus name: %s", strDbusName.c_str());
    
    informationf("Object path: %s", strObjectName.c_str());


   dbus_activate_application(strDbusName, strObjectName);
      
  */    
/*
    // Wait for the subprocess to finish (blocking call)
    gboolean success = g_subprocess_wait(subprocess, nullptr, &error);

    if (!success) {
        std::cerr << "Subprocess failed: " << (error ? error->message : "Unknown error") << std::endl;
        if (error) {
            g_error_free(error);
        }
        
        throw ::exception(error_failed);
    } else {
        // Get exit status
        int exit_status = g_subprocess_get_exit_status(subprocess);
        //std::cout << "Application exited with status: " << exit_status << std::endl;
    }
*/


    // Cleanup
//    g_object_unref(subprocess);

    ///;;return 0;
//}
//      information() << "node::launch_app_by_app_id : " << scopedstrAppId;
//
//      auto pathDesktopFile = get_desktop_file_path_by_app_id(scopedstrAppId);
//
//      if(!file_system()->exists(pathDesktopFile))
//      {
//
//         information() << "Desktop file (\"" << pathDesktopFile << "\") doesn't exist. Going to try to launch with executable path.";

         //::aura_posix::node::launch_app_by_app_id(scopedstrAppId, bSingleExecutableVersion);

//         return;
//
//      }
//
//      ::string strAppId = scopedstrAppId;
//
//      strAppId.find_replace("/", ".");
//
//      ::string strCommand = "sh -c \"nohup gtk-launch " + strAppId + " &\"";
//
//      int iExitCode = node()->command_system(strCommand, 10_minutes);
//
//      if(iExitCode == 0)
//      {
//
//         information() << "Successfully launched \"" << scopedstrAppId << "\"";
//
//         return;
//
//      }
//
//      warning() << "Failed to launch application \"" + scopedstrAppId + "\" using gtk-launch";
//
//      information() << "Going to try to launch with executable path.";
//
//      ::aura_posix::node::launch_app_by_app_id(scopedstrAppId);

   }



} // namespace operating_ambient_gtk4



