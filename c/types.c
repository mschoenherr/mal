#include <string.h>
#include <stdlib.h>

/* Basis for type system */
char NIL = 0;
char LIST = 1;
char SYMBOL = 2;
char INTEGER = 3;

#ifndef MAL_TYPE
#define MAL_TYPE
typedef struct mal_typed_value {
  char type;
  void** value;
} mal_v;
#endif /* MAL_TYPE */


int set_type (mal_v* value, char type) {

  value->type = type;

  return 0;
}

int set_atomic_content (mal_v* value, char* token) {

  if (value->type == SYMBOL) {
    *(value->value) = (char *) malloc(strlen(token));
    strcpy(*(value->value), token);
  } else if (value->type == INTEGER) {
    *(value->value) = (int*) malloc(1);
    *(value->value) = 0; // fix this
  }
  
  return 0;
}

int set_list_content(mal_v* list, mal_v** llist) {

  if (list->type == LIST) {
    // this will probably blow up?
    *(list->value)= llist;
  }

  return 0;
}
