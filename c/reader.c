#include <stdio.h>
//stdio only included for debugging
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "types.h"
#include "ll.c/ll.h"

char* pop_nonspace_substr (char** input, int num_chars) {

  int pos = 0;

  if (num_chars == 0 && strlen(*input) > 1) {
    while (!isspace((*input)[pos]) && (*input)[pos] != '\0') {
      pos++;
    }
  } else {
    pos = num_chars;
  }

  /* allocating for pos++ chars, for insert of \0 */
  char* result = (char *) malloc((pos + 1));

  if (pos) {
    strncpy(result, *input, pos);
  }

  result[pos] = '\0';

  *input += pos;

  return result;
}

char** drop_spaces (char** input) {

  if (strlen(*input) > 1) {
    while (isspace(**input)) {
      (*input)++;
    }
  }

  return input;
}

char* pop_token (char** input) {

  char* token = NULL;

  drop_spaces(input);

  if (*input[0] == '\0') {}
  else if (strlen(*input) > 2 && *input[0] == '~' && *input[1] == '@') {
    token = pop_nonspace_substr(input,2);
  } else {
    token = pop_nonspace_substr(input,0);
  }

  return token;
}

char** tokenize (char** input) {

  char* token;
  char** rest_list = NULL;
  char** token_list;

  token = pop_token(input);

  // if there is no token to extract, stop and return NULL
  if (!token || strlen(token) == 1) {
    return rest_list;
  }

  rest_list = tokenize(input);

  token_list = ll_new(rest_list);

  *token_list = token;
  
  return token_list;
}
