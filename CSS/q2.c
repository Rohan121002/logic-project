#include<stdio.h>
#include<stdlib.h>
#include"header1.h"
/**
 * @brief 
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