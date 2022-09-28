#include "framework.h"
#include "dir_system.h"


namespace apex_freebsd
{


   dir_system::dir_system()
   {

   }


   dir_system::~dir_system()
   {

   }


   void dir_system::initialize(::object * pobject)
   {

      //auto estatus =

      ::dir_system::initialize(pobject);

//      if(!estatus)
//      {
//
//         return estatus;
//
//      }

      m_pathHome = getenv("HOME");

      m_pathCa2Config = m_pathHome / ".config/ca2";

//      return estatus;

    }


} // namespace apex_freebsd



