#include "types.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "ll.c/ll.h"

/* strcpy appendix onto stem, reallocating for necessary space,
   helper for sequential building of strings */
void realloc_append_str(char** stem, char* appendix) {
  int old_len = strlen(*stem);
  int new_len = old_len + strlen(appendix) + 1;
  (char*) realloc(*stem, new_len);
  strcpy((*stem) + old_len, appendix);
}

/* Quick and dirty calculator for number of digits of an int*/
int digit_count_int(int n) {
  if (n == 0) { return 1;}
  int dec_len = 0;
  if (n < 0) {
    n = -n;
    dec_len++;
  }
  while (n > 9) {
    n = n / 10;
    dec_len++;
  }
  return dec_len;
}

char* pr_int(mal_v* value) {
  int num = *((int*) get_atomic_content(value));
  int len = digit_count_int(num);
  char* result = (char*) malloc(len + 1);
  sprintf(result, "%d", num);
  return result;
}

/* need to declare this here, for trampolining with pr_list */
char* pr_str(mal_v* value);

char* pr_list(mal_v* value) {
  mal_v** list_content = get_list_content(value);
  char* result = (char*) malloc(2);
  strcpy(result, "(");
  
  while (ll_next(list_content)) {
    char* another_token = pr_str(*list_content);
    realloc_append_str(&result, another_token);
    if (!(get_type(*(ll_next(list_content))) == NIL)) {
      realloc_append_str(&result, " ");
    }
    list_content = ll_next(list_content);
  }
  
  realloc_append_str(&result, ")");
  return result;
}

char* pr_symbol(mal_v* value) {
  return *((char**) get_atomic_content(value));
}

char* pr_str(mal_v* value) {

  if (get_type(value) == SYMBOL) {
    return pr_symbol(value);
  } else if (get_type(value) == INTEGER) {
    return pr_int(value);
 } else if (get_type(value) == LIST) {
    return pr_list(value);
  } else if (get_type(value) == NIL) {
    return "nil";
  } else {
    return "Unprintable Object";
  }
}
