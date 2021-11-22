#include "framework.h"


extern "C"
void node_linux_factory_exchange(::factory::factory * pfactory)
{

   add_factory_item < node_linux::node, ::acme::node >();

}



