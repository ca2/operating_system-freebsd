#include "framework.h"


__FACTORY_EXPORT aura_freebsd_factory(::factory::factory * pfactory);


__FACTORY_EXPORT node_xfce_factory(::factory::factory * pfactory);


__FACTORY_EXPORT operating_ambient_gkt3_factory(::factory::factory * pfactory)
{

   aura_freebsd_factory(pfactory);

   node_xfce_factory(pfactory);

   pfactory->add_factory_item < ::operating_ambient_gkt3::node, ::acme::node > ();


}



