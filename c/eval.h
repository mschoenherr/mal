#ifndef EVAL_H
#define EVAL_H
#include <glib-2.0/gmodule.h>
typedef GHashTable* Env;
Env create_env();
void destroy_env(Env env);
#endif /* EVAL_H */
