#pragma once


namespace apex_freebsd
{


   class CLASS_DECL_APEX dir_context :
      virtual public ::dir_context
   {
   public:


      __reference(file_system)      m_pfilesystem;
      __reference(dir_system)       m_pdirsystem;


      dir_context();
      ~dir_context() override;


      void initialize(::object * pobject) override;

      void init_system() override;
      void init_context() override;

      //::file::listing & ls(::file::listing & ls) override;


      //bool  is(const ::file::path & path) override;
      bool  is_inside(const ::file::path & pcszDir, const ::file::path & lpcszPath) override;

      bool  is_inside_time(const ::file::path & pcsz) override;

      bool  name_is(const ::file::path & path) override;
      //bool  has_subdir(const ::file::path & pcsz) override;


      ::file::listing & root_ones(::file::listing & listing) override;
      //bool mk(const ::file::path & pcsz) override;

      //bool rm(const ::file::path & psz, bool bRecursive = true) override;


      ::file::path time() override;
      ::file::path stage() override;
      ::file::path stageapp() override;
      ::file::path netseed() override;

      // stage in ca2os spalib
      //  virtual string matter(const char * pcsz, const char * lpcsz2 = nullptr);

      //virtual ::file::path install();
//      virtual string matter(const string & str);
//      virtual string matter(const string & str, const string & str2);
//      virtual string matter(const char * pcsz, const string & str2);

//      virtual string matter(const string & str, const char * pcsz2);


//      virtual ::file::path module();
//      virtual ::file::path ca2module();
      ::file::path time_square() override;
      ::file::path time_log(const string & pszId) override;


      ::file::path trash_that_is_not_trash(const ::file::path & psz) override;

      //::file::path appdata(const ::string & strAppId = "") override;
      ::file::path commonappdata() override;
      ::file::path element_commonappdata(const string & strElement) override;

//      virtual ::file::path usersystemappdata(const string & pcszPrefix);

//      virtual ::file::path userappdata(::object * pobject);
//      virtual ::file::path userdata(::object * pobject);
//      //virtual ::file::path userfolder(::object * pobject);
//      virtual ::file::path default_os_user_path_prefix(::object * pobject);
//      virtual ::file::path default_userappdata(const string & pcszPrefix, const string & lpcszLogin);

//      virtual ::file::path default_userdata(const string & pcszPrefix, const string & lpcszLogin);

//      virtual ::file::path default_userfolder(const string & pcszPrefix, const string & lpcszLogin);

      //virtual ::file::path userquicklaunch(::object * pobject);
      //virtual ::file::path userprograms(::object * pobject);

      ::file::path commonprograms() override;

      ::file::path music() override;
      ::file::path video() override;
      ::file::path image() override;
      ::file::path download() override;
      ::file::path document() override;


      ::file::path _xdg_get_dir(const string & str);


   };


} // namespace apex_freebsd



