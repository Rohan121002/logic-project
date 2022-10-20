#include<stdio.h>
#include<stdlib.h>
#include "header1.h"

int height(struct node * root){
  if (root == NULL){
    return 0;
  }

  int leftrootheight = height(root->left);
  int rightrootheight = height(root->right);

  if (leftrootheight < rightrootheight){
    return (rightrootheight + 1);
  } else {
    return (leftrootheight + 1);
  }
} 

int main(){
  struct node* root = emptynode('\0');
  char* input = ">*a+bcd";
  treefromprefix(root, input);
  printf("%d\n", height(root));
}