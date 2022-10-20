#include<stdio.h>
#include<stdlib.h>
#include "header1.h"

int main(){
  struct node* root = emptynode('\0');
  char* input = "++abc";
  treefromprefix(root, input);
  inorder(root);
  return 0;
}