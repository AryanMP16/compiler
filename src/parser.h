#ifndef PARSER_H
#define PARSER_H
#include "stdbool.h"
#include "stddef.h"

struct rule{
  char* non_terminal;
  char** produces;
  size_t num_production_options;
};

struct rule* create_rule(char* non_terminal, char* productions[], size_t num_production_options);
void free_rule(struct rule* r);

//rules
void initialize_globals();
extern struct rule* s_da;
#endif
