#include<stdio.h>
#include<string.h> 
#include<limits.h>
#include<stdlib.h>
# define Max 100
int top = -1;
char arr[Max];

int isFull() {
    return top == Max - 1;
} 

int isEmpty() { 
    return top == -1; 
}

void push(char item) {
    if (isFull()) 
        return; 
	top++;
	arr[top] = item;
}
 
int pop() { 
    if (isEmpty()) 
        return 0; 
           
    return arr[top--]; 
} 

int print(){ 
    if (isEmpty()) 
        return 0; 
    return arr[top]; 
} 

int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

int precedence(char ch) 
{ 
    switch (ch) 
    {  
    case '>':
        return 1;
    
    case '+': 
        return 2; 

    case '*':
        return 3; 

    case '~': 
        return 4; 
    } 
    return -1; 
} 

int Postfix(char* expression) 
{ 
    int i, j;

    for (i = 0, j = -1; expression[i]; ++i) 
    { 
        if (checkIfOperand(expression[i])) 
            expression[++j] = expression[i]; 

        else if (expression[i] == '(') 
            push(expression[i]); 

        else if (expression[i] == ')') 
        { 
            while (!isEmpty(arr) && print(arr) != '(') 
                expression[++j] = pop(arr); 
            if (!isEmpty(arr) && print(arr) != '(') 
                return -1;             
            else
                pop(arr); 
        } 
        else 
        { 
            while (!isEmpty(arr) && precedence(expression[i]) <= precedence(print(arr))) 
                expression[++j] = pop(arr); 
            push(expression[i]); 
        } 

    } 
    while (!isEmpty(arr)) 
        expression[++j] = pop(arr); 

    expression[++j] = '\0'; 
    
}

void reverse(char *ptr){

    int size = strlen(ptr);
    int j = size, i=0;
    char temp[size];

    temp[j--]='\0';
    while(ptr[i]!='\0')
    {
        temp[j] = ptr[i];
        j--;
        i++;
    }
    strcpy(ptr,temp);
}
void brackets(char* ptr){
    int i = 0;
    while(ptr[i]!='\0')
    {
        if(ptr[i]=='(')
            ptr[i]=')';
        else if (ptr[i]==')')
            ptr[i]='(';
        i++;
    }
}
void InfixtoPrefix(char *ptr){

    int size = strlen(ptr);

    reverse(ptr);
    brackets(ptr);
    Postfix(ptr);
    reverse(ptr);
}

int main()
{    
    printf("The infix is: ");

    char expression[] = "((a*b)+(c>d))"; 
    printf("%s\n",expression);
    InfixtoPrefix(expression); 

    printf("The prefix is: ");
    printf("%s\n",expression);

    return 0; 
}