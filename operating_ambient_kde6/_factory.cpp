#include "framework.h"
#include "node.h"


__FACTORY_EXPORT void node_freebsd_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void node_kde5_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void operating_ambient_kde5_factory(::factory::factory * pfactory)
{

   node_freebsd_factory(pfactory);

   node_kde5_factory(pfactory);

   pfactory->add_factory_item < ::operating_ambient_kde5::node, ::platform::node > ();


}



