#include "framework.h"
#include "node.h"
#include "directory_system.h"
#include "file_system.h"
#include "path_system.h"
//#include "dir_system.h"
//#include "file_system.h"
#include "directory_context.h"
#include "file_context.h"
//#include "file.h"


__FACTORY_EXPORT void acme_darwin_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_freebsd_factory(::factory::factory * pfactory)
{

   acme_darwin_factory(pfactory);


   pfactory->add_factory_item < ::acme_freebsd::directory_system, ::directory_system >();
   pfactory->add_factory_item < ::acme_freebsd::file_system, ::file_system >();

   pfactory->add_factory_item < ::acme_freebsd::directory_context, ::directory_context >();
   pfactory->add_factory_item < ::acme_freebsd::file_context, ::file_context >();


   pfactory->add_factory_item < ::acme_freebsd::node, ::platform::node >();
   pfactory->add_factory_item < ::acme_freebsd::directory_system, ::directory_system >();
   pfactory->add_factory_item < ::acme_freebsd::file_system, ::file_system >();
   pfactory->add_factory_item < ::acme_freebsd::path_system, ::path_system >();


//   pfactory->add_factory_item < ::acme_freebsd::file, ::file::file >();


}


