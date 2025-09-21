//
// Created by camilo on 19/01/2021. --<33ThomasBS!!
//
#include "framework.h"
#include "node.h"
///#include "xfce_shared.h
//#include "appindicator.h"
//#include "gdk.h"
//#include "windowing_gtk3/windowing_gtk3.h"


void gdk_branch(const ::procedure & procedure);


namespace operating_ambient_gtk3
{


   node::node()
   {

      m_pGtkSettingsDefault = nullptr;

   }


   node::~node()
   {

      if(m_pGtkSettingsDefault)
      {

         g_object_unref(m_pGtkSettingsDefault);

      }

   }


   int node::node_init_check(int *pi, char ***ppz)
   {

      auto iResult = gtk_init_check(pi, ppz);

      return iResult;

   }



   void node::start_node()
   {

      ::node_gtk3::node::start_node();

   }


   void node::initialize(::particle *pparticle)
   {

::aura_freebsd::node::initialize(pparticle);
      ::node_gtk3::node::initialize(pparticle);



   }


} // namespace operating_ambient_gtk3



