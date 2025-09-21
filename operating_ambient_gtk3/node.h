//
// Created by camilo on 19/01/2021. <33TBS!!
//

//
// Created by camilo on 19/01/2021. <3-<3ThomasBS!!
//
#pragma once


#include "aura_freebsd/node.h"
#include "node_gtk3/node.h"


namespace operating_ambient_gtk3
{


   class CLASS_DECL_OPERATING_AMBIENT_GTK3 node :
      virtual public ::aura_freebsd::node,
      virtual public ::node_gtk3::node
   {
   public:


      node();
      ~node() override;


      virtual int node_init_check(int * pi, char *** ppz) override;

      void start_node() override;

      void initialize(::particle * pparticle) override;



   };


} // namespace operating_ambient_gtk3




