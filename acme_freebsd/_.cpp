#include "framework.h"


#include "acme/library.h"


namespace freebsd
{


   ::u32 get_current_directory(string& str)
   {

      int iSize = PATH_MAX * 16;

      auto psz = str.get_string_buffer(iSize);

      getcwd(psz, iSize);

      str.release_string_buffer();

      return str.get_length();

   }


} // namespace freebsd



