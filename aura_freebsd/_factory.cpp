#include "framework.h"
//#include "acme/node/windows/registry.h"
//#include "acme_freebsd/acme.h"
//#include "apex_windows/apex.h"
//#include "aura.h"


__FACTORY_EXPORT void apex_freebsd_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_freebsd_factory(::factory::factory * pfactory)
{

   apex_freebsd_factory( pfactory);

   pfactory->add_factory_item < ::aura::freebsd::node, ::acme::node >();

}



