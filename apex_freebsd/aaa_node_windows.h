#pragma once


#include "acme/node/freebsd/_node_freebsd.h"


//#include "exception.h"

string get_error_message(unsigned int dwError);


//CLASS_DECL_APEX_FREEBSD bool __initialize();


//#include "system_dir.h"
//#include "system_file.h"
//
//#include "folder_watch.h"
//#include "factory_exchange.h"
//#include "uac_tools.h"
//#include "thread.h"
//#include "file.h"
//#include "crypto.h"
//#include "ip_enum.h"


#define NODE_THREAD(pthread) (dynamic_cast < ::freebsd::thread * > (dynamic_cast < thread * >(pthread)))


//
//#include "command.h"



//void CLASS_DECL_APEX_FREEBSD __cdecl _ca2_purecall();
//void CLASS_DECL_APEX_FREEBSD __cdecl _null_se_translator(unsigned int uiCode, EXCEPTION_POINTERS * ppointers);
//bool CLASS_DECL_APEX_FREEBSD __freebsd_init();
int CLASS_DECL_APEX_FREEBSD __freebsd_main(::apex::system * psystem, ::create * pmaininitdata);






//#include "file_find.h"
//#include "file.h"
//#include "shell.h"
//#include "stdio_file.h"
//#include "registry.h"
//#include "os.h"

//
//// Sanity checks for ATOMs
//CLASS_DECL_APEX_FREEBSD bool __is_valid_atom(ATOM nAtom);
////CLASS_DECL_APEX_FREEBSD bool __is_valid_atom(const char * psz);
//CLASS_DECL_APEX_FREEBSD bool __is_valid_atom(const wchar_t * psz);
//

///////////////////////////////////////////////////////////////////////////////
//// locale-invariant comparison helpers till CRT gets that support
//inline int __invariant_stricmp(const char *pszLeft,const char *pszRight)
//{
//#ifdef FREEBSD_DESKTOP
//   return ::CompareStringA(MAKELCID(MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US),SORT_DEFAULT),
//                           NORM_IGNORECASE,
//                           pszLeft,
//                           -1,
//                           pszRight,
//                           -1) - CSTR_EQUAL;
//#else
//   return ansi_compare_ci(pszLeft,pszRight);
//#endif
//}
//
//inline int __invariant_stricmp(const unichar *pwszLeft,const unichar *pwszRight)
//{
//#ifdef FREEBSD_DESKTOP
//   return ::CompareStringW(MAKELCID(MAKELANGID(LANG_ENGLISH,SUBLANG_ENGLISH_US),SORT_DEFAULT),
//                           NORM_IGNORECASE,
//                           pwszLeft,
//                           -1,
//                           pwszRight,
//                           -1) - CSTR_EQUAL;
//#else
//   return wide_compare_case_insensitive(pwszLeft,pwszRight);
//#endif
//}

/////////////////////////////////////////////////////////////////////////////
// Portability abstractions

#define __set_dialog_control_id(oswindow, nID)     SetWindowLong(oswindow, GWL_ID, nID)
#define __set_dialog_control_id_(oswindow, nID)     oswindow->SetWindowLong(GWL_ID, nID)
#define __get_dialog_control_id(oswindow)         ((unsigned int)(::u16)::GetDlgCtrlID(oswindow))
#define __get_dialog_control_id_(oswindow)         ((unsigned int)(::u16)oswindow->GetDlgCtrlId())


//#include "pipe.h"
//#include "process.h"








//
//
//namespace freebsd
//{
//
//
//   class thread;
//
//   class freebsd
//   {
//      int function();
//   };
//
//   CLASS_DECL_APEX_FREEBSD HINSTANCE   load_library(const char * psz);
//
//   CLASS_DECL_APEX_FREEBSD bool        shell_get_special_folder_path(::windowing::window * pwindow,::file::path &str,int csidl,bool fCreate);
//   CLASS_DECL_APEX_FREEBSD ::file::path  shell_get_special_folder_path(int csidl, bool fCreate = true, ::windowing::window * pwindow = nullptr);
//   CLASS_DECL_APEX_FREEBSD unsigned int       get_file_attributes(const char * pFileName);
//
//   CLASS_DECL_APEX_FREEBSD unsigned int       get_current_directory(string & str);
//   CLASS_DECL_APEX_FREEBSD unsigned int       get_temp_path(string & str);
//   CLASS_DECL_APEX_FREEBSD ::int        reg_query_value(HKEY hkey,const char * pszSubKey,string & str);
//
//   CLASS_DECL_APEX_FREEBSD HICON       extract_icon(HINSTANCE hInst,const char * pszExeFileName,unsigned int nIconIndex);
//
//   CLASS_DECL_APEX_FREEBSD bool        delete_file(const char * pFileName);
//
//   CLASS_DECL_APEX_FREEBSD int     get_menu_string(HMENU hMenu,unsigned int uDItem,string & str,unsigned int flags);
//   CLASS_DECL_APEX_FREEBSD void        time_to_filetime(::object * pobject,const ::datetime::time& time,LPFILETIME pFileTime);
//
//
//} // namespace freebsd
//
//
//
//
//
//CLASS_DECL_APEX_FREEBSD ::int delete_registry_tree_helper(HKEY hParentKey,const string & strKeyName);
//
//
//CLASS_DECL_APEX_FREEBSD HINSTANCE __get_resource_handle();
//CLASS_DECL_APEX_FREEBSD void __set_resource_handle(HINSTANCE hInstResource);
//
//CLASS_DECL_APEX_FREEBSD HINSTANCE __get_resource_handle();
//CLASS_DECL_APEX_FREEBSD HINSTANCE __find_string_resource_handle(unsigned int nID);
//

CLASS_DECL_APEX_FREEBSD __pointer(::apex::application) __get_app();

CLASS_DECL_APEX_FREEBSD int app_main(::apex::system * psystem, HINSTANCE hInstance, HINSTANCE hPrevInstance, char * pCmdLine, ::e_display edisplay);




//#include "tts_speaker.h"




