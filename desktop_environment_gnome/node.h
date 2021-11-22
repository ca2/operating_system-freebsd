//
// Created by camilo on 19/01/2021. <33TBS!!
//

//
// Created by camilo on 19/01/2021. <3-<3ThomasBS!!
//
#pragma once


namespace desktop_environment_gnome
{


   class CLASS_DECL_DESKTOP_ENVIRONMENT_GNOME node :
      virtual public ::aura::freebsd::node,
      virtual public ::node_gnome::node
   {
   public:


      //gpointer m_pGtkSettingsDefault;
      //string   m_strTheme;

      ::logic::bit         m_bitDarkMode;


      node();
      virtual ~node();


      virtual int node_init_check(int * pi, char *** ppz) override;

      virtual void defer_notify_startup_complete() override;

      virtual ::e_status start_node() override;

      virtual ::e_status initialize(::object * pobject) override;

      virtual void os_calc_dark_mode();

      virtual bool _os_calc_dark_mode();

      virtual string os_get_user_theme() override;

      string _os_get_user_theme() override;

      //virtual string _os_get_user_theme();

      virtual void os_process_user_theme(string strTheme);

      virtual void _os_process_user_theme_color(string strTheme);

      virtual bool os_set_user_theme(const string & strUserTheme) override;

      //virtual void os_process_user_theme(string strTheme) override;

      virtual void enable_wallpaper_change_notification() override;

      virtual string get_file_icon_path(const char * pszPath, int iSize) override;

      virtual string get_file_content_type(const char * pszPath) override;

      virtual bool set_wallpaper(index iScreen, string strLocalImagePath) override;

      virtual string get_wallpaper(index iScreen) override;

      using ::aura::node::node_fork;

      virtual bool windowing_message_loop_step();

      virtual ::e_status node_branch(const ::routine & routine);

      //virtual void node_post_quit() override;

      void on_subject(::subject::subject * psubject, ::subject::context * pcontext) override;

      //virtual void _on_change_os_user_theme(string strTheme);

      //virtual void _os_process_user_theme_color(string strTheme);

      //virtual ::node_linux::appindicator * appindicator_allocate() override;

      //virtual void appindicator_destroy(::freebsd::appindicator * pappindicator) override;

      //virtual void enum_display_monitors(::aura::session * psession) override;

      //virtual bool _os_calc_system_dark_mode() override;

      virtual void os_post_quit() override;

      virtual bool should_launch_on_node(::subject::subject * psubject);

      virtual bool launch_on_node(::subject::subject * psubject);


   };


} // namespace desktop_environment_gnome




