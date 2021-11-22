//
// Created by camilo on 16/02/2021. 15:50 BRT <3TBS_!!
//
#pragma once


class user_notify_icon_bridge;


namespace freebsd
{


   namespace aura
   {


      class CLASS_DECL_AURA_FREEBSD appindicator :
         virtual public ::matter
      {
         public:


         appindicator();
         virtual ~appindicator();


         virtual bool create(const char * pszId, const char * pszIcon, const char * pszFolder, user_notify_icon_bridge * pbridge) = 0;


      };


   } // namespace aura


} // namespace_freebsd



