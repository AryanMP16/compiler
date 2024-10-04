#include "parser.h"
#include "stdio.h"
#include "stdlib.h"

struct rule* s_da = NULL; //so gcc doesn't scream at me

//defining rule methods
struct rule* create_rule(char* non_terminal, char* productions[2]/*Chomsky Normal Form requires only 2 productions at most*/, size_t num_production_options){
  
  struct rule* new_rule = malloc(sizeof(struct rule));
  if (!new_rule)
    return NULL;

  //assign values
  new_rule->non_terminal = non_terminal;
  new_rule->num_production_options = num_production_options;
  new_rule->produces = malloc(2 * sizeof(char));

  new_rule->produces[0] = productions[0];
  new_rule->produces[1] = productions[1];

  return new_rule;

}

void free_rule(struct rule* r){
  if (r){
    free(r->produces[0]);
    free(r->produces[1]);
    free(r->produces);
  }
  free(r);
}

void initialize_globals(){
  //creating actual rules
  char* production_s_da[2] = {"declaration", "assignment"};
  struct rule* s_da = create_rule("statement", production_s_da, 1);
}
