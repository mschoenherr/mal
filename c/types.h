typedef struct mal_typed_value mal_v;

int set_type (mal_v* value, char type);
int set_atomic_content (mal_v* value, char* token);

extern char LIST;
extern char SYMBOL;
extern char INTEGER;
