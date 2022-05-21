#include "framework.h"
//#include "acme/node/windows/registry.h"
//#include "acme_freebsd/acme.h"
//#include "apex_windows/apex.h"
//#include "aura.h"


__FACTORY_IMPORT void apex_freebsd_factory(::factory::factory * pfactory);


__FACTORY_IMPORT void aura_posix_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void aura_freebsd_factory(::factory::factory * pfactory)
{

   apex_freebsd_factory( pfactory);

   aura_posix_factory(pfactory);

   pfactory->add_factory_item < ::aura_freebsd::node, ::acme::node >();
   pfactory->add_factory_item < ::aura_freebsd::interaction_impl, ::user::interaction_impl >();

}



