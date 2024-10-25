#ifndef _CONFIG_DEFS_H_
#define _CONFIG_DEFS_H_

#ifdef __OS_LIB_EXPORT
#define OS_PUBLIC OS_EXPORT
#else
#define OS_PUBLIC OS_IMPORT
#endif

#undef __OS_LIB_EXPORT

#endif