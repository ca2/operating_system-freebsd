#pragma once


#include "apex_darwin/file_context.h"


namespace apex_freebsd
{


   class CLASS_DECL_APEX_FREEBSD file_context :
      virtual public ::apex_darwin::file_context
   {
   public:


      file_context();
      ~file_context() override;


      void initialize(::particle * pparticle) override;


      ::file::path dropbox_info_network_payload() override;


   };


} // namespace apex_freebsd



