#include "types.h"
#include <stdlib.h>

enum { symbol, integer };

/* Basis for type system */
struct mal_typed_value {
  char type;
  void* value;
};

/* Linked list type holding mal_typed_values*/
struct mal_linked_list {
  struct mal_typed_value node;
  struct mal_linked_list* next;
};

/* add_node can also be used to create list, by passing a NULL list */
struct mal_linked_list* add_node(struct mal_typed_value mv, struct mal_linked_list* mll) {

  struct mal_linked_list* new_mll = malloc(sizeof(struct mal_linked_list));

  new_mll->node = mv;
  new_mll->next = mll;

  return new_mll;
}
