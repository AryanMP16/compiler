#include "lexer.h"
#include "stdio.h"

int main(int argc, char* argv[]){
  struct token* token_arr = tokenize("../src/filename.c");

  printTokenStream(token_arr);
  freeTokens(token_arr);
  
  return 0;
}
