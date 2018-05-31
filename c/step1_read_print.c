#include <stdio.h>

#include <readline/readline.h>
#include <readline/history.h>

/* Stub function returning its arg */
char* READ(char* input) {

  return input;
}

/* Stub function returning its arg */
char* EVAL(char* input) {

  return input;
}

/* Stub function returning its arg */
char* PRINT(char* input) {

  return input;
}

/* Calls READ, EVAL, PRINT in order and returns 
   the result of PRINT */
char* rep(char* input) {

  return PRINT(EVAL(READ(input)));

}

/* Endlessly calls rep and prints its result */
int main(int* argc, char** argv) {

  char* input;

  while(input = readline("mal-user> ")) {

    add_history(input);
    puts(rep(input));
  }

  return 0;
}
