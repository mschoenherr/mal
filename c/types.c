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
  union {
    int integer;
    char* symbol;
    struct mal_typed_value** list;
  } value;
} mal_v;
#endif /* MAL_TYPE */

int set_type (mal_v* value, char type) {

  value->type = type;

  return 0;
}

int set_atomic_content (mal_v* value, char* token) {

  if (value->type == SYMBOL) {
    (value->value).symbol = token;
  } else if (value->type == INTEGER) {
    (value->value).integer = atoi(token);
  }
  
  return 0;
}

int set_list_content(mal_v* list, mal_v** llist) {

  if (list->type == LIST) {
    // this will probably blow up?
    (list->value).list= llist;
  }

  return 0;
}

void* get_atomic_content(mal_v* value) {

  if (value->type == SYMBOL) {
    return &(value->value.symbol);
  } else if (value->type == INTEGER) {
    return &(value->value.integer);
  }
}
