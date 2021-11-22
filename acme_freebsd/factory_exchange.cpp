#include "framework.h"


extern "C"
void acme_posix_factory_exchange(::factory::factory * pfactory);


extern "C"
void acme_linux_factory_exchange(::factory::factory * pfactory)
{

   acme_posix_factory_exchange(pfactory);

   pfactory->add_factory_item < ::linux::acme::node, ::acme::node >();
   pfactory->add_factory_item < ::linux::acme_dir, ::acme_dir >();
   pfactory->add_factory_item < ::linux::acme_path, ::acme_path >();


}



