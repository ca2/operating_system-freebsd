#include "framework.h"


extern "C"
void node_freebsd_factory_exchange(::factory::factory * pfactory)
{

   add_factory_item < node_freebsd::node, ::acme::node >();

}



