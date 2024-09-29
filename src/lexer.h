#ifndef LEXER_H
#define LEXER_H

#include "stdbool.h"

struct token{
  int length;
  char* token_str;
};

struct token* tokenize(char filename[]);
bool isDelimeter(char c);
bool isKeyWord(char* str);
bool isOperator(char c);

#endif
