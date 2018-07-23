#include <glib-2.0/gmodule.h>
#include "types.h"
#include "ll.c/ll.h"

#include <stdarg.h>

typedef GHashTable* Env;

/* Following functions probably need to be factored out */
mal_v* add_int(mal_v* a, ...) {

  va_list ap;
  va_start(ap, a);
  int sum = 0;
  int ind;
  mal_v* item;

  for (ind=0; ind<2; ind++) {
    item = va_arg(ap, mal_v*);
    sum += *((int*) get_atomic_content(item));
  }

  va_end(ap);
  mal_v* result = malloc(sizeof(mal_v));
  set_type(result, INTEGER);
  result->value = &sum;

  return result;
}

/* End of badly placed function section */

Env create_env () {
  return g_hash_table_new(g_str_hash, g_str_equal);
}

Env get_standard_env () {
  Env std_env = create_env();
  g_hash_table_insert(std_env, "+", &add_int);
  return std_env;
}

void destroy_env (Env env) {
  g_hash_table_destroy(env);
}
