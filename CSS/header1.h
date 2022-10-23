#include<stdio.h>
#include<stdlib.h>


struct node{
    char data;
    struct node * left;
    struct node * right;
};

int atom(char ch){
    if((ch >= 65 && ch <= 90) || (ch >= 97 && ch <= 122))
        return 1;
    else 
        return 0;
}

struct node * emptynode(char item){
    struct node * new= (struct node *)malloc (sizeof(struct node));
    new -> data = item;
    new -> left = NULL;
    new -> right = NULL;


    return new;
}
/**
 * @brief 
 * @details
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

void prefix(struct node * root){
    printf("%c", root -> data);
    prefix(root -> left);
    prefix(root -> right);
}

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