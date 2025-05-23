//
// Created by camilo on 19/01/2021. <33TBS!!
//

//
// Created by camilo on 19/01/2021. <3-<3ThomasBS!!
//
#pragma once


#include "node_freebsd/node.h"
#include "node_gtk4/node.h"


namespace operating_ambient_gtk4
{


   class CLASS_DECL_OPERATING_AMBIENT_GTK4 node :
      virtual public ::node_freebsd::node,
      virtual public ::node_gtk4::node
   {
   public:


      node();
      ~node() override;


      //void defer_notify_startup_complete() override;

      //void start_node() override;

      void initialize(::particle * pparticle) override;

      //virtual bool aaa_windowing_message_loop_step();

//      void handle(::topic * ptopic, ::handler_context * pcontext) override;
//
//      bool should_launch_on_node(::topic * ptopic) override;
//
//      bool launch_on_node(::topic * ptopic) override;
//


      void launch_app_by_app_id(const ::scoped_string & scopedstrAppId, bool bSingleExecutableVersion) override;


   };


} // namespace operating_ambient_gtk4




