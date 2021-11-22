#include "framework.h"
//#include "acme/node/windows/registry.h"
//#include "acme_linux/acme.h"
//#include "apex_windows/apex.h"
//#include "aura.h"

extern "C"
void apex_linux_factory_exchange(::factory::factory * pfactory);


extern "C"
void aura_linux_factory_exchange(::factory::factory * pfactory)
{

   apex_linux_factory_exchange( pfactory);

   pfactory->add_factory_item < ::linux::aura::node, ::acme::node >();

}



