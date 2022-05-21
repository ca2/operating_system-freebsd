#pragma once


#include "acme/_.h"
#include "operating-system-posix/acme_posix/_.h"


#if defined(_ACME_FREEBSD_LIBRARY)
#define CLASS_DECL_ACME_FREEBSD  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_ACME_FREEBSD  CLASS_DECL_IMPORT
#endif



CLASS_DECL_ACME_FREEBSD ::user::enum_desktop get_edesktop();




