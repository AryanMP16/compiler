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

void printTokenStream(struct token* token_arr){
  size_t i = 0;
  while ((token_arr + i)->length != -1){
    printf("%s\n", (token_arr + i) -> token_str);
    i++;
  }
}

void newlineRemovalHelper(char* str){
  size_t j = 0;
  size_t i = 0;
  
  while (str[i] != '\0'){
    if (str[i] != '\n')
      str[j++] = str[i];
    i++;
  }
  str[j] = '\0';
}

struct token* tokenize(char filename[]){
  FILE* file = fopen(filename, "r");

  //get file size
  fseek(file, 0, SEEK_END);
  size_t size = ftell(file);
  fseek(file, 0, SEEK_SET);

  //read file into string buffer
  char buffer[size];
  fread(buffer, sizeof(char), size, file);

  //remove \n from buffer:
  newlineRemovalHelper(buffer);
  
  //count number of lexemes
  bool wasPrevCharDelim = false;
  size_t r_traverser = 0, l_traverser = 0;

  size_t token_counter = 0;

  size_t capacity = 100;
  struct token* token_array = malloc(capacity * sizeof(struct token));
  
  while (r_traverser < size && l_traverser < size && l_traverser <= r_traverser){
    if (!isDelimeter(buffer[r_traverser])){
      r_traverser++;
      wasPrevCharDelim = false;
    }
 
    else if (isDelimeter(buffer[r_traverser]) && l_traverser < r_traverser){
      if (!wasPrevCharDelim){
	if (l_traverser < r_traverser){
	  char* str = (char*) malloc(r_traverser - l_traverser + 1);
	  strncpy(str, buffer + l_traverser, r_traverser - l_traverser);
	  str[r_traverser - l_traverser] = '\0';

	  if (token_counter >= capacity){
	    capacity *= 2;
	    token_array = realloc(token_array, capacity * sizeof(struct token));
	  }
	  
	  struct token t = {strlen(str), str};
	  *(token_array + token_counter) = t;
	  
	  //printf("%s\n", toPrint);
	  token_counter ++;
	}
	else if (r_traverser == l_traverser){
	  char* str = "X\0";
	  str[0] = buffer[r_traverser];

	  if (token_counter >= capacity){
	    capacity *= 2;
	    token_array = realloc(token_array, capacity * sizeof(struct token));
	  }
	  
	  struct token t = {2, str};
	  *(token_array + token_counter) = t;
	  
	  //printf("%c\n", buffer[r_traverser]);
	  token_counter ++;
	}
      }
      
      r_traverser++;
      l_traverser = r_traverser;

      wasPrevCharDelim = true;
    }
  }

  //something to free allocated memory

  struct token array_escape = {-1, "\0"};
  *(token_array + token_counter) = array_escape;

  return token_array;
}

void freeTokens(struct token* token_arr){
  if (token_arr == NULL)
    return;

  size_t i = 0;
  while (token_arr[i].length != -1){
    free(token_arr[i].token_str);
    i++;
  }
}
