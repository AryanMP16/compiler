#include "lexer.h"
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

bool isOperator(char c){
  return (c == '+' || c == '-' || c == '/' ||
	  c == '*' || c == '=' || c == '<' ||
	  c == '>');
}

bool isDelimeter(char c){
  return (c == ' ' || c == ',' || c == '%' ||
	  c == ';' || c == '(' || c == ')' ||
	  c == '[' || c == ']' || c == '{' ||
	  c == '}');
}

bool isKeyWord(char* str){
  char* keyWords[] = {"size_t"};
  for (size_t i = 0; i < sizeof(keyWords); i++){
    if (!strcmp(str, keyWords[i]))
      return true;
  }
  return false;
}

struct token* tokenize(char filename[]){
  struct token* test = malloc(sizeof(struct token));
  test->length = 5;
  char str[] = "test_str";
  test->token_str = str;
  //the above is just there so C doesn't yell at me for not returning a token*

  FILE* file = fopen(filename, "r");

  //get file size
  fseek(file, 0, SEEK_END);
  size_t size = ftell(file);
  fseek(file, 0, SEEK_SET);

  //read file into string buffer
  char buffer[size];
  fread(buffer, sizeof(char), size, file);

  //count number of lexemes
  bool wasPrevCharDelim = false;
  size_t r_traverser = 0, l_traverser = 0;
  while (r_traverser < size && l_traverser < size && l_traverser <= r_traverser){
    if (!isDelimeter(buffer[r_traverser])){
      r_traverser++;
      wasPrevCharDelim = false;
    }
 
    else if (isDelimeter(buffer[r_traverser]) && l_traverser < r_traverser){
      if (wasPrevCharDelim == true) {}
      else if (l_traverser < r_traverser){
	char* toPrint;
	strncpy(toPrint, buffer + l_traverser, r_traverser - l_traverser);
	printf("%s", toPrint);
      }
      else if (r_traverser == l_traverser){
	printf("%c", buffer[r_traverser]);
      }
      
      r_traverser++;
      l_traverser = r_traverser;

      wasPrevCharDelim = true;
    }
  }
  
  //just for testing
  //printf("%s\n", buffer);
  
  return test;
}
