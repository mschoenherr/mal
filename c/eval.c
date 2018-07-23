#include <glib-2.0/gmodule.h>

typedef GHashTable* Env;

Env create_env () {
  return g_hash_table_new(g_str_hash, g_str_equal);
}

Env get_standard_env () {
  Env std_env = create_env();
  g_hash_table_insert(std_env, "+", 0); //dummy insert
  return std_env;
}

void destroy_env (Env env) {
  g_hash_table_destroy(env);
}
