#include "types.h"

char** tokenize (char** input);
char** drop_spaces (char** input);
char* pop_nonspace_substr(char** input, int num_chars);
char* pop_token(char** input);
