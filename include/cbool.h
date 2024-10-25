#if (defined(__STDC__) && __STDC_VERSION__ >= 199901L) || (defined(_MSC_VER) && _MSC_VER >= 1800)
#include <stdbool.h>
#elif !defined(__cplusplus) && !defined(bool)
#ifndef _CBOOL_H_
#define _CBOOL_H_

typedef unsigned char bool;

#define bool bool
#define false 0
#define true 1

#endif //_CBOOL_H_
#endif // stdbool.h