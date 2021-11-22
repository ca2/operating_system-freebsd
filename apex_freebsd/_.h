#pragma once


#include "apex/_.h"
#include "apex_posix/_.h"
#include "acme_freebsd/_.h"


#if defined(_APEX_FREEBSD_LIBRARY)
#define CLASS_DECL_APEX_FREEBSD  CLASS_DECL_EXPORT
#else
#define CLASS_DECL_APEX_FREEBSD  CLASS_DECL_IMPORT
#endif
