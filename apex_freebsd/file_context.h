#pragma once


namespace apex_freebsd
{


   class CLASS_DECL_APEX file_context :
      virtual public ::apex_posix::file_context
   {
   public:


      __reference(file_system)      m_pfilesystem;
      __reference(dir_system)       m_pdirsystem;


      file_context();
      ~file_context() override;


      void initialize(::object * pobject) override;


      void init_system() override;
      void init_context() override;


      //::file_transport get_file(const ::payload & varFile, const ::file::e_open & eopen) override;


      //virtual bool is_link(string strPath) override;


      ::file::path dropbox_info_network_payload() override;


   };


} // namespace apex_freebsd



