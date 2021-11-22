#include "framework.h"
//#include "node/platform/node.h"
#include "acme/filesystem/filesystem/acme_dir.h"
#include "acme/filesystem/filesystem/acme_path.h"
//#include "acme_freebsd/acme.h"
#include "node.h"
//#include "aura/node/operating_system/freebsd/_c.h"


bool __node_node_pre_init();
bool __node_node_pos_init();


namespace apex
{


   namespace freebsd
   {
   
   
      node::node()
      {

         //m_pnodenode = this;

      }


      node::~node()
      {


      }


      string node::get_user_name()
      {

//      WCHAR wsz[1024];
//
//      DWORD dwSize = sizeof(wsz) / sizeof(WCHAR);
//
//      ::GetUserNameW(wsz, &dwSize);
//
//      return string(wsz);

         return "";

      }


      ::e_status node::initialize(::object * pobject)
      {

         auto estatus = ::acme::freebsd::node::initialize(pobject);

         if (!estatus)
         {

            return estatus;

         }

//         if (!__node_node_pre_init())
//         {
//
//            return error_failed;
//
//         }


//         if (!__node_node_pos_init())
//         {
//
//            return error_failed;
//
//         }

         return estatus;

      }


      ::e_status node::_001InitializeShellOpen()
      {

         //ASSERT(m_atomApp == nullptr && m_atomSystemTopic == nullptr); // do once

         //m_atomApp            = ::GlobalAddAtomW(::str::international::utf8_to_unicode(m_strAppName));

         //m_atomSystemTopic    = ::GlobalAddAtomW(L"system");

         return ::success;

      }


      ::e_status node::process_init()
      {

         //defer_initialize_winsock();
         return success;

      }


   } // namespace freebsd


} // namespace apex



