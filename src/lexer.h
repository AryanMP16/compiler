#ifndef LEXER_H
#define LEXER_H

struct token{
  int length;
  char token_str[];
};

struct token* tokenize(char filename[]);

#endif
