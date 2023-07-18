#include <stdio.h>
#include <stdlib.h>

typedef enum TypeTag
{ ADD,
    SUB,
    MUL,
    DIV,
    CONDITION,
    //VALUE,

}TypeTag;
typedef struct Node
{
    //OPERATIONS
   int value;
   TypeTag type;
   struct Node* left;
   struct Node* right;

}Node;

Node* makeFunc(TypeTag type, Node* left,Node* right)
{
    Node* node = malloc(sizeof(Node));
    node->type = type;
    node->left = left;
    node->right = right;

    return node;
}

void calc(Node* node)
{
    //TypeTag type;
    if(node==NULL)
    {
        return;
    }else if(node->type==ADD)
    {
        node->left->value + node->right->value;
    }else if(node->type==SUB)
    {
        node->left->value - node->right->value;
    }else if(node->type==MUL)
    {
        node->left->value*node->right->value;
    }else if(node->type==DIV)
    {
        node->left->value/node->right->value;
    }else if(node->type==CONDITION)
    {
        (node->left->value)>(node->right->value)?1:0;
    }

    calc(node->left);
    calc(node->right);
}

int Fibonacci(int n)
{
    if(n<=0)
    {
        return 0;
    }else if(n==1)
    {
        return 1;
    }

    int* fib = (int*)malloc((n+1)*sizeof(int));
    fib[0] = 0;
    fib[1] = 1;

    for(int i =2; i<=n;i++)
    {
        fib[i] = fib[i-1] + fib[i-2];
    }

    int result = fib[n];
    free(fib);

    return result;
}

 int main()
{
   //Node *add = makeFunc(ADD,makeFunc()),makeFunc());

    //calc(add);
    //calc(mul);
    //calc(sub);
    //calc(fibo);

    //printf("add : %d\n", add->value);
    //printf("mul : %d\n", mul->value);
    //printf("sub : %d\n", sub->value);
    //printf("fibo : %d\n", fibo->value);

    return 0;

    return 0;
}
