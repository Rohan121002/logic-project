#include<stdio.h>
#include<string.h>
#include<stdlib.h>
# define Max 50
int top = -1;
char arr[Max];
/**
 * @brief Checks weather the array is full.
 * @details This function checks weather the array is full or not if array is full than the topmost term will become max-1.
 * 
 * @return int 
 */
int isFull() {
    return top == Max - 1;
} 
/**
 * @brief Checks weather the array is empty or not 
 * @details It returns -1 as the topmost element 
 * 
 * @return int 
 */
int isEmpty() { 
    return top == -1; 
}
/**
 * @brief  Creating a stack function named push().
 * @details This is a function which puts the item to the top of the array. 
 * @details It only does so when the array is not full.
 * 
 * @param item 
 */
void push(char item) {
    if (isFull()) 
        return; 
	top++;
	arr[top] = item;
}

/**
 * @brief Removes the topmost element
 * @details Here if the function is empty this function returns 0 as there is no element to pop
 * @details but if its not empty than this function removes a element from the top and returns an array with size which is one less than the size of previous array.
 * 
 * @return int 
 */
int pop() { 
    if (isEmpty()) 
        return 0; 
           
    return arr[top--]; 
} 

/**
 * @brief Prints top element in array
 * @details If the array is not empty then it returns the top element in an array otherwise it returns 0
 * @details It checks weather the array is not empty using isEmpty fucntion already declared
 * @return int 
 */
int print(){ 
    if (isEmpty()) 
        return 0; 
    return arr[top]; 
} 
/**
 * @brief Checks operand
 * @details This is a function which checks weather the element given is operand (>,+,*,~) or not
 * @details This gives output 1 when ch is not operand 
 * @param ch 
 * @return int 
 */
int checkIfOperand(char ch) {
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 

/**
 * @brief Checks the precedence of the operands
 * @details This function uses switch case to give precedence order to all the operands. 
 * @details Here the precedence order followed is (>) >> (+) >> (*) >> (~).
 * @details It returns 1 when operand is (>)
 * @details It returns 2 when operand is (+)
 * @details It returns 3 when operand is (*)
 * @details It returns 4 when operand is (~)
 * @details It returns -1 when the element is not an operand.
 * 
 * @param ch 
 * @return int 
 */
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

void Postfix(char* expression) 
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
            while (!isEmpty() && print() != '(') 
                expression[++j] = pop(); 
            if (!isEmpty() && print() != '(') 
                continue;             
            else
                pop(); 
        } 
        else 
        { 
            while (!isEmpty() && precedence(expression[i]) <= precedence(print())) 
                expression[++j] = pop(); 
            push(expression[i]); 
        } 

    } 
    while (!isEmpty()) 
        expression[++j] = pop(); 

    expression[++j] = '\0'; 
    
}

void reverse(char *ptr){

    int j = strlen(ptr), i=0;
    char temp[strlen(ptr)];

    temp[j]='\0';
    --j;
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

/**
 * @brief This function converts the given expression from infix to prefix.
 * @details It converts the expression from infix to prefix using reverse, brackets, Postfix, fucntions
 * 
 * @param ptr 
 */
void InfixtoPrefix(char *ptr){

    reverse(ptr);
    brackets(ptr);
    Postfix(ptr);
    reverse(ptr);
}

int main()
{    
    char expression[] = "a*(b+c)>d"; 
    printf("Given Infix : %s\n",expression);
    
    InfixtoPrefix(expression); 
    printf("The Prefix is: %s ", expression );

    return 0;
}