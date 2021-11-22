#include "framework.h"


extern "C"
void aura_linux_factory_exchange(::factory::factory * pfactory);


extern "C"
void node_gnome_factory_exchange(::factory::factory * pfactory);


extern "C"
void desktop_environment_gnome_factory_exchange(::factory::factory * pfactory)
{

   aura_linux_factory_exchange(pfactory);

   node_gnome_factory_exchange(pfactory);

   pfactory->add_factory_item < ::desktop_environment_gnome::node, ::acme::node > ();


}



