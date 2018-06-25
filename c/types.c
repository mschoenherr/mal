#include "types.h"
#include <string.h>
#include <stdlib.h>

/* Basis for type system */
struct mal_typed_value {
  char type;
  void** value;
};

char LIST = 0;
char SYMBOL = 1;
char INTEGER = 2;

int set_type (mal_v* value, char type) {

  value->type = type;

  return 0;
}

int set_atomic_content (mal_v* value, char* token) {

  if (value->type == SYMBOL) {
    *(value->value) = (char *) malloc(strlen(token));
    strcpy(*(value->value), token);
  }
  
  return 0;
}
