#include "framework.h"
//#include "acme/node/windows/registry.h"
//#include "acme_linux/acme.h"
//#include "apex_windows/apex.h"
//#include "aura.h"


__FACTORY_EXPORT void apex_linux_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_linux_factory(::factory::factory * pfactory)
{

   apex_linux_factory( pfactory);

   pfactory->add_factory_item < ::freebsd::aura::node, ::acme::node >();

}



