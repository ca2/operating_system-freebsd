#include "framework.h"


extern "C"
void aura_linux_factory_exchange(::factory::factory * pfactory);


extern "C"
void node_kde_factory_exchange(::factory::factory * pfactory);


extern "C"
void desktop_environment_kde_factory_exchange(::factory::factory * pfactory)
{

   aura_linux_factory_exchange(pfactory);

   node_kde_factory_exchange(pfactory);

   pfactory->add_factory_item < ::desktop_environment_kde::node, ::acme::node > ();
//add_factory_item < ::node_kde::copydesk, ::user::copydesk > ();
   //pfactory->add_factory_item < ::node_kde::appindicator, ::node_linux::appindicator >();

}



