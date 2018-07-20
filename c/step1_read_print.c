#include <stdio.h>
#include <stdlib.h>

#include "linenoise/linenoise.h"

#include "types.h"
#include "reader.h"
#include "printer.h"
#include "ll.c/ll.h"

/* Stub function returning its arg */
mal_v* READ(char* input) {

  return read_str(input);
}

/* Stub function returning its arg */
mal_v* EVAL(mal_v* ast) {

  return ast;
}

/* Stub function returning its arg */
char* PRINT(mal_v* ast) {

  return pr_str(ast);
}

/* Calls READ, EVAL, PRINT in order and returns 
   the result of PRINT */
char* rep(char* input) {

  return PRINT(EVAL(READ(input)));

}

/* Endlessly calls rep and prints its result */
int main(int* argc, char** argv) {

  char* input;
  linenoiseHistorySetMaxLen(1000);

  while(input = linenoise("mal-user> ")) {

    linenoiseHistoryAdd(input);
    char* to_print = rep(input);
    puts(to_print);
    free(to_print);
    linenoiseFree(input);
  }

  return 0;
}
