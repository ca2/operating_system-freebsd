#include "framework.h"
#include "node.h"


__FACTORY_EXPORT void aura_freebsd_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void node_gtk_based_factory(::factory::factory * pfactory);


__FACTORY_EXPORT void desktop_environment_gtk_based_factory(::factory::factory * pfactory)
{

   aura_freebsd_factory(pfactory);

   node_gtk_based_factory(pfactory);

   pfactory->add_factory_item < ::desktop_environment_gtk_based::node, ::platform::node > ();

}



