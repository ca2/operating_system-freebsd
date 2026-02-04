#pragma once


/* #define FF_API_AVIO_WRITE_NONCONST 1 */

#if defined(__aarch64__)

#define AVIO_FILE_WRITE_TYPE const uint8_t

#else

#define AVIO_FILE_WRITE_TYPE uint8_t

#endif


