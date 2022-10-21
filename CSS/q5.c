#include <stdio.h>
#include <stdlib.h>
#include "header1.h"
#define T 'T'
#define F 'F'

struct atom
{
  char name;
  char value;
};


char evaluate(struct node*, struct atom[]);
char valueOfAtom(char, struct atom[]);
char Negation(char);
char And(char, char);
char Or(char, char);
char Implies(char, char);

char valueOfAtom(char ch, struct atom atoms[]){
  int size = sizeof(atoms)/ sizeof(atoms[0]);
  for(int i = 0; i < size; i++){
    if (atoms[i].name == ch){
      return atoms[i].value;
    }
  }
  return (printf("Error: Atom not defined"));
}

char evaluate(struct node* root, struct atom atoms[]){
  if (atom(root->data)) return valueOfAtom(root->data, atoms);
  char lval, rval;
  if (root->data != '~'){
    lval = evaluate(root->left, atoms);
  }
  rval = evaluate(root->right, atoms);
  switch (root->data)
  {
  case '~':
    return Negation(rval);
    break;
  
  case '*':
    return And(lval, rval);
    break;
  
  case '+':
    return Or(lval, rval);
    break;
  
  case '>':
    return Implies(lval, rval);
    break;
  }

  return 'T';
}

char Negation(char in){
  if (in == T){
    return F;
  } else {
    return T;
  }
}

char And(char in1, char in2){
  if (in1 == T && in2 == T){
    return T;
  } else {
    return F;
  }
}

char Or(char in1, char in2){
  if (in1 == T || in2 == T){
    return T;
  } else {
    return F;
  }
}

char Implies(char in1, char in2){
  if (in1 == T && in2 == F){
    return F;
  } else {
    return T;
  }
}

int main(){
  struct atom atoms[] = {{'a', T}, {'b', F}, {'c', F}};
  struct node* root =emptynode('\0');
  treefromprefix(root, ">+ab*bc");
  printf("%c\n", evaluate(root, atoms));
  return 0;
}