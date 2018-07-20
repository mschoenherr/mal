#include <string.h>
#include <stdlib.h>
#include "ll.c/ll.h"

/* Basis for type system */
char NIL = 0;
char LIST = 1;
char SYMBOL = 2;
char INTEGER = 3;

#ifndef MAL_TYPE
#define MAL_TYPE
typedef struct mal_typed_value {
  char type;
  void* value;
} mal_v;
#endif /* MAL_TYPE */

int set_type (mal_v* value, char type) {

  value->type = type;

  return 0;
}

char get_type(mal_v* value) {
  return value->type;
}

int set_atomic_content (mal_v* value, char* token) {

  if (value->type == SYMBOL) {
    value->value = token;
  } else if (value->type == INTEGER) {
    int* result = (int*) malloc(sizeof(int));
    *result = atoi(token);
    value->value = result;
  }
  
  return 0;
}

int set_list_content(mal_v* list, mal_v** llist) {

  if (list->type == LIST) {
    list->value = &(*llist);
  }

  return 0;
}

mal_v** get_list_content(mal_v* value) {
  return (mal_v**) (value->value);
}

void* get_atomic_content(mal_v* value) {
  return value->value;
}
