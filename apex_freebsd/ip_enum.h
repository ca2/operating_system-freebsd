#pragma once

/*
Module : IPENUM.H
Purpose: Interface for an apex API class wrapper for IP address enumeration
Created: PJN / 21-04-1998
History: None

Copyright (ca) 1998 by PJ Naughter.


*/


namespace apex_freebsd
{


   class CLASS_DECL_APEX_FREEBSD ip_enum :
      virtual public ::net::ip_enum
   {
   public:


      bool     m_bWinsockInitialized;


      ip_enum();
      ~ip_enum() override;


      //      virtual ::count enumerate(ip_array & ipa);
      ::count enumerate(array < ::net::address > & ipa) override;

   };


} // namespace apex_freebsd



