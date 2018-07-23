#ifndef TYPES_H
#define TYPES_H
typedef struct mal_typed_value {
  char type;
  void* value;
} mal_v;
typedef mal_v* (*mal_func)(mal_v*, ...);

int set_type (mal_v* value, char type);
char get_type(mal_v* value);
int set_atomic_content (mal_v* value, char* token);
int set_list_content(mal_v* list, mal_v** llist);
mal_v** get_list_content(mal_v* value);
void* get_atomic_content(mal_v* value);
mal_func get_function_content(mal_v* value);
int set_function_content(mal_v* value, mal_func fun);

extern char FUNCTION;
extern char NIL;
extern char LIST;
extern char SYMBOL;
extern char INTEGER;

#endif /* TYPES_H */
