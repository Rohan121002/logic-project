#include<stdio.h>
#include<stdlib.h>
#include"header1.h"
/**
 * @brief converts the given prefix to a binary tree using struct
 * @details First we create a empty node and then give it a prefix expression,then using the function tree from prefix convert it into a rooted binary tree 
 * 
 * @return int 
 */
int main(){
    struct node * root = emptynode('\0');
    char * expression = ">*a+bcd";
    treefromprefix(root , expression);
    inorder(root);

return 0;

}