#pragma once


namespace freebsd
{


   class CLASS_DECL_APEX os_context :
      public ::os_context
   {
   public:


      os_context();
      ~os_context() override;


      virtual string get_command_line() override;


      virtual bool reboot() override;
      virtual bool shutdown(bool bPowerOff) override;

      virtual void terminate_processes_by_title(const ::string & strName) override;


      virtual bool freebsd_can_exec(const char *file);


      //virtual ::file::path get_module_path(HMODULE hmodule) override;


      virtual bool get_pid_by_path(const ::string & strName, ::u32 & dwPid) override;
      virtual bool get_pid_by_title(const ::string & strName, ::u32 & dwPid) override;
      virtual void get_all_processes(u32_array & dwa) override;
      virtual ::file::path get_process_path(::u32 dwPid) override;
      virtual int get_pid() override;

      virtual ::payload connection_settings_get_auto_detect() override;
      virtual ::payload connection_settings_get_auto_config_url() override;


      virtual bool local_machine_set_run(const ::string & strKey, const ::string & strCommand);
      virtual bool local_machine_set_run_once(const ::string & strKey, const ::string & strCommand);
      virtual bool current_user_set_run(const ::string & strKey, const ::string & strCommand);
      virtual bool current_user_set_run_once(const ::string & strKey, const ::string & strCommand);
      virtual bool defer_register_ca2_plugin_for_mozilla() override;

      virtual bool file_extension_get_open_with_list_keys(string_array & straKey, const ::string & strExtension) override;
      virtual bool file_extension_get_open_with_list_commands(string_array & straCommand, const ::string & strExtension) override;

      virtual bool file_association_set_default_icon(const ::string & strExtension, const ::string & strExtensionNamingClass, const ::string & strIconPath) override;
      virtual bool file_association_set_shell_open_command(const ::string & strExtension, const ::string & strExtensionNamingClass,  const ::string & strCommand, const ::string & strParam) override;
      virtual bool file_association_get_shell_open_command(const ::string & strExtension, string & strExtensionNamingClass, string & strCommand, string & strParam) override;


      virtual bool open_in_ie(const char * pcsz);


      virtual bool create_service(::object * pobject);
      virtual bool erase_service(::object * pobject);

      virtual bool start_service(::object * pobject);
      virtual bool stop_service(::object * pobject);

      void raise_exception( ::u32 dwExceptionCode, ::u32 dwExceptionFlags);

      virtual bool is_remote_session() override;

      virtual void post_to_all_threads(const ::id & id, wparam wparam, lparam lparam);


      virtual bool initialize_wallpaper_fileset(::file::set * pfileset, bool bAddSearch) override;

      virtual bool get_default_browser(string & strId, ::file::path & path, string & strParam) override;

      virtual bool file_open(::file::path strSrc, string strParams, string strFolder) override;

      virtual void list_process(::file::patha & patha, u32_array & iaPid) override;


   };


} // namespace freebsd



//typedef string GET_FILE_CONTENT_TYPE(string strPath);

//typedef GET_FILE_CONTENT_TYPE * PFN_GET_FILE_CONTENT_TYPE;

//void set_get_file_content_type_function(PFN_GET_FILE_CONTENT_TYPE pfnGetFileContentType);

