#include "framework.h"
#include "acme/filesystem/filesystem/acme_directory.h"
#include "acme/filesystem/filesystem/acme_path.h"
#include "node.h"


bool __node_node_pre_init();

bool __node_node_pos_init();


namespace apex_freebsd
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


   void node::initialize(::particle * pparticle)
   {

      //auto estatus =
      //
      ::acme_freebsd::node::initialize(pparticle);

//      if (!estatus)
//      {
//
//         return estatus;
//
//      }

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

      //return estatus;

   }


   void node::_001InitializeShellOpen()
   {

      //ASSERT(m_atomApp == nullptr && m_atomSystemTopic == nullptr); // do once

      //m_atomApp            = ::GlobalAddAtomW(::str::international::utf8_to_unicode(m_strAppName));

      //m_atomSystemTopic    = ::GlobalAddAtomW(L"system");

      //return ::success;

   }


   void node::process_init()
   {

      //defer_initialize_winsock();
      //return success;

   }


} // namespace apex_freebsd



