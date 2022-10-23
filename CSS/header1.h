#include<stdio.h>
#include<stdlib.h>

/**
 * @brief We create a struct node with the following data set
 * @details It will be used as a point in the binary tree
 * 
 */
struct node{
    char data;
    struct node * left;
    struct node * right;
};
/**
 * @brief It checks if the input is alphabet or not
 * @details It returns 1 if input is alphabet else return 0
 * 
 * @param ch 
 * @return int 
 */
int atom(char ch){
    if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        return 1;
    else 
        return 0;
}
/**
 * @brief creates a element of the struct node
 * @details creates a struct node with the defining data as the given input char and the other two parameters as null and returns this new struct node as pointer
 * 
 * @param item 
 * @return struct node* 
 */
struct node * emptynode(char item){
    struct node * new= (struct node *)malloc (sizeof(struct node));
    new -> data = item;
    new -> left = NULL;
    new -> right = NULL;


    return new;
}
/**
 * @brief  printing inorder from parse tree
 * @details Takes the input of a node of the parse tree
 * @details If the left and right parameter as empty then we return nothing and if they are not empty then we convert them into a inorder expression by first printing the opening bracket then printing its left and right node values and then printing the closing bracket.
 * 
 * @param root 
 */
void inorder(struct node * root){
    if (root == NULL)
        return;
    if (root -> left != NULL && root -> right != NULL)
        printf("(");

    inorder(root -> left);
        printf("%c", root -> data);
    inorder(root -> right);
        if (root -> left != NULL && root -> right != NULL)
            printf(")");
}
/**
 * @brief print the prefix of a given parse tree
 * @details It first prints the current data(char) of the struct root and then call the function again with input as the left node of the given struct and after this call it then call the function again with input as the right node of the given struct
 * @details This is done recursively till the whole function is printed in the prefix form
 * 
 * @param root 
 */
void prefix(struct node * root){
    printf("%c", root -> data);
    prefix(root -> left);
    prefix(root -> right);
}
/**
 * @brief It makes parse tree from char input in form of prefix
 * @details We first give the first char of the char pointer exp as the first data point of the struct node root
 * @details If there is a char then we end it there and if there is'nt a aplhabet and there is'nt a negation then we create a new element of the sturct at the left node of the initial struct, also calling the function recursively at the left node with the second char of the input string
 * @details Then we create a new struct node at the right of the initial node and then calling the function recursively at this new sturct with the next element of the char string.
 * 
 * @param root 
 * @param exp 
 * @return int 
 */
int treefromprefix(struct node * root , char * exp){
    int x,y;
    root -> data = exp[0];
    if(atom(exp[0]))
        return 1;
    else 
        x = 0;
        if (exp[0] != '~'){
        root -> left = emptynode('\0');
        x = treefromprefix(root -> left, exp + 1);
        }

        y = 0;
        root -> right = emptynode('\0');
        y = treefromprefix(root -> right , exp + 1 + x);
        return (x + y + 1);
}   