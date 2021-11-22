#include "framework.h"
#include "apex/platform/launcher.h"
#include "launcher.h"
#include "crypto.h"
#include "ip_enum.h"
#include "apex/parallelization/service.h"
#include "apex/parallelization/service_handler.h"
#include "service_handler.h"


__FACTORY_EXPORT void apex_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void apex_freebsd_factory(::factory::factory * pfactory)
{

   apex_posix_factory(pfactory);

   pfactory->add_factory_item < ::freebsd::dir_system, ::dir_system >();
   pfactory->add_factory_item < ::freebsd::file_system, ::file_system >();

   pfactory->add_factory_item < ::freebsd::dir_context, ::dir_context >();
   pfactory->add_factory_item < ::freebsd::file_context, ::file_context >();

   //add_factory_item < ::freebsd::stdio_file, ::file::text_file >();
   //add_factory_item < ::freebsd::file, ::file::file >();
   pfactory->add_factory_item < ::freebsd::os_context, ::os_context >();
   //pfactory->add_factory_item < ::freebsd::pipe, ::process::pipe >();
   //pfactory->add_factory_item < ::freebsd::process, ::process::process >();

   //add_factory_item < ::freebsd::console, ::console::console >();
   //pfactory->add_factory_item < ::freebsd::crypto, ::crypto::crypto >();
   pfactory->add_factory_item < ::freebsd::ip_enum, ::net::ip_enum >();


   pfactory->add_factory_item < ::freebsd::interprocess_communication_base, ::interprocess_communication::base >();
   pfactory->add_factory_item < ::freebsd::interprocess_communication_rx, ::interprocess_communication::rx >();
   pfactory->add_factory_item < ::freebsd::interprocess_communication_tx, ::interprocess_communication::tx >();
   //add_factory_item < ::freebsd::interprocess_communication, ::interprocess_communication::interprocess_communication >();


   //add_factory_item < ::freebsd::buffer, ::graphics::graphics >();
   //add_factory_item < ::freebsd::interaction_impl, ::user::interaction_impl >();

   //pfactory->add_factory_item < ::file::os_watcher, ::file::watcher >();
   //pfactory->add_factory_item < ::file::os_watch, ::file::watch >();

   pfactory->add_factory_item < ::freebsd::file_context, ::file_context >();
   pfactory->add_factory_item < ::freebsd::service_handler, ::service_handler >();

   pfactory->add_factory_item < ::apex::freebsd::node, ::acme::node >();

   //add_factory_item < ::freebsd::copydesk, ::user::cop
   // 
   // 
   // ydesk >();
   ////add_factory_item < ::freebsd::shell, ::user::shell >();


}




