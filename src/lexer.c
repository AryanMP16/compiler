#include "lexer.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

struct token* tokenize(char filename[]){
  struct token* test = malloc(sizeof(struct token));
  test->length = 5;
  strcpy(test->token_str, "hello");
  //the above is just there so C doesn't yell at me for not returning a token*

  
  return test;
}
