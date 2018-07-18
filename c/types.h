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

#ifndef TYPES_H
#define TYPES_H

int set_type (mal_v* value, char type);
char get_type(mal_v* value);
int set_atomic_content (mal_v* value, char* token);
int set_list_content(mal_v* list, mal_v** llist);
mal_v** get_list_content(mal_v* value);
void* get_atomic_content(mal_v* value);

extern char NIL;
extern char LIST;
extern char SYMBOL;
extern char INTEGER;

#endif /* TYPES_H */
