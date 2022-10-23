#include<stdio.h>
#include<stdlib.h>
#include"header1.h"
/**
 * @brief converts the given prefix to a binary tree using struct
 * @details First we create a empty struct root node and then create a expression of a prefix,then using the function tree from prefix convert it into a rooted binary tree in the first created empty node.
 * @details We have also print the in order function from the rooted binary tree to show that we have created a rooted tree and it can be used in other functions.
 * @return int 
 */
int main(){
    struct node * root = emptynode('\0');
    char * expression = ">*a+bcd";
    treefromprefix(root , expression);
    inorder(root);

return 0;

}