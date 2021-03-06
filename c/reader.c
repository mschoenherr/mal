#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "types.h"
#include "ll.c/ll.h"

int isleftparen(char c) {

  int result;

  switch (c) {
  case '(':
    result = 1;
    break;
  case '[':
    result = 1;
    break;
  case '{':
    result = 1;
    break;
  default:
    result = 0;
  }

  return result;
}

int isrightparen(char c) {

  int result;

  switch (c) {
  case ')':
    result = 1;
    break;
  case ']':
    result = 1;
    break;
  case '}':
    result = 1;
    break;
  default:
    result = 0;
  }

  return result;
}

int isspecialchar(char c) {

  int result = 0;

  if (isleftparen(c) || isrightparen(c) || c == '`' || c == '~' || c == '\'' || c == '^' || c == '@') {
    result = 1;
  }

  return result;
}

char* pop_nonspace_substr (char** input, int num_chars) {

  int pos = 0;

  if (num_chars == 0 && strlen(*input) > 0) {
    while (!isspace((*input)[pos]) && !isrightparen((*input)[pos]) && (*input)[pos] != '\0') {
      pos++;
    }
  } else {
    pos = num_chars;
  }

  /* allocating for pos++ chars, for insert of \0 */
  char* result = (char *) malloc(sizeof(char) * pos + 1);

  if (pos) {
    strncpy(result, *input, pos);
  }

  result[pos] = '\0';

  *input += pos;

  return result;
}

char** drop_spaces (char** input) {

  if (strlen(*input) > 0) {
    while (isspace(**input)) {
      (*input)++;
    }
  }

  return input;
}

char* pop_token (char** input) {

  char* token;

  drop_spaces(input);

  if ((*input)[0] == '\0') {}
  else if (strlen(*input) > 1 && *input[0] == '~' && *input[1] == '@') {
    token = pop_nonspace_substr(input,2);
  } else if (isspecialchar((*input)[0])) {
    token = pop_nonspace_substr(input,1);
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
  if (!token) {
    return rest_list;
  }

  if (strlen(*input) > 0) {
    rest_list = tokenize(input);
  }

  token_list = ll_new(rest_list);

  *token_list = token;
  
  return token_list;
}


/* peek and pop take a pointer to a linked list of tokens.
   This way, freeing resources can be handled by ll.c */
char* peek (char*** token_list) {
  char* token = (char*) malloc(sizeof(char) * (strlen(**token_list) + 1));
  strcpy(token, **token_list);
  return token;
}

char* pop (char*** token_list) {
  char* token = peek(token_list);
  *token_list = ll_pop(*token_list); //ll_pop frees current pointer and returns next one
  return token;
}

mal_v* read_atom (char*** token_list) {

  mal_v* result = (mal_v*) malloc(sizeof(mal_v));
  char* token = pop(token_list);

  if (isdigit(token[0]) || (token[0] == '-' && isdigit(token[1]))) {
    set_type(result, INTEGER);
  } else {
    set_type(result, SYMBOL);
  }

  set_atomic_content(result, token);

  return result;
}

mal_v* read_form(char*** token_list);

mal_v** read_list_helper(char*** token_list) {

  mal_v** result = NULL;
  mal_v* item;
  char* token = peek(token_list);
  
  if (token[0] == ')') {
    pop(token_list);
    result = ll_new(result);
    *result = (mal_v*) malloc(sizeof(mal_v));
    set_type(*result,NIL);
  } else {
    item = read_form(token_list);
    result = ll_new(read_list_helper(token_list));
    *result = item;
  }

  free(token);

  return result;
}

mal_v* read_list(char*** token_list) {

  mal_v** llist = read_list_helper(token_list);
  mal_v* result = (mal_v*) malloc(sizeof(mal_v));

  set_type(result, LIST);
  set_list_content(result, llist);

  return result;
}

mal_v* read_form(char*** token_list) {

  mal_v* result;
  char* token = peek(token_list);

  if (token[0] == '(') {
    pop(token_list);
    result = read_list(token_list);
  } else {
    result = read_atom(token_list);
  }

  free(token);

  // maybe throw error, if token_list non-empty, now

  return result;
}

mal_v* read_str(char* input) {

  char** token_list = tokenize(&input);

  return read_form(&token_list);
}
