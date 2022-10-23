#include<stdio.h>
#include<stdlib.h>
#include "header1.h" 
/**
 * @brief It takes input of the form of prefix and prints the inorder of it.
 * @details Create a empty struct node root, then we gives the input of the form of prefix and then converts that prefix into rooted binary parse tree using the function tree from prefix and then prints the inorder using the inorder function
 * 
 * @return int 
 */
int main(){
  struct node* root = emptynode('\0');
  char* input = "++abc";
  treefromprefix(root, input);
  inorder(root);
  return 0;
}