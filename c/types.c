#include "types.h"

/* Basis for type system */
struct mal_typed_value {
  char type;
  void* value;
};
