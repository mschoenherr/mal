#include <stdio.h>

#include <readline/readline.h>

char* READ() {

  return readline("mal> ");
}

char* EVAL(char* input) {

  return input;
}

void PRINT(char* output) {

  puts(output);
}

int rep() {

  char* input = READ();

  if (!input) {
    return -1;
  }
  
  PRINT(EVAL(input));

  return 0;
}

int main(int* argc, char** argv) {

  while(rep() == 0) {
  }

  return 0;
}
