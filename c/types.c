#include <string.h>
#include <stdlib.h>
#include "ll.c/ll.h"
#include <stdarg.h>

/* Basis for type system */
char FUNCTION = 0;
char NIL = 1;
char LIST = 2;
char SYMBOL = 3;
char INTEGER = 4;


typedef struct mal_typed_value {
  char type;
  void* value;
} mal_v;

typedef mal_v* (*mal_func)(mal_v*, ...);

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

int set_function_content(mal_v* value, mal_func fun) {
  value->value = fun;
}

mal_func get_function_content(mal_v* value) {
  return value->value;
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
