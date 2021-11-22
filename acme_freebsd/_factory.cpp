#include "framework.h"


__FACTORY_EXPORT void acme_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void acme_freebsd_factory(::factory::factory * pfactory)
{

   acme_posix_factory(pfactory);

   pfactory->add_factory_item < ::acme::freebsd::node, ::acme::node >();
   pfactory->add_factory_item < ::freebsd::acme_dir, ::acme_dir >();
   pfactory->add_factory_item < ::freebsd::acme_file, ::acme_file >();
   pfactory->add_factory_item < ::freebsd::acme_path, ::acme_path >();


}



