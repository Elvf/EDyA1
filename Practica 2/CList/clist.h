#ifndef __CLIST_H__
#define __CLIST_H__

#include <stddef.h>

typedef struct _CNodo {
  int dato;
  struct _CNodo sig;
} CNodo;

typedef *CNodo CList;



#endif /* __CLIST_H__ */
