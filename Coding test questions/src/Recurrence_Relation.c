#include <stdio.h>
#include <stdlib.h>

//Method 1
/*
Advantages: It directly follows the given recurrence relation, 
making the code easier to understand and implement.
Disadvantages: The recursive approach may lead to redundant function calls, 
resulting in higher time complexity. 
It can be inefficient for larger values of n due to repeated calculations.
*/
int _recFunc(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;
    else
        return _recFunc(n - 3) + _recFunc(n - 2);
}

//method 2
/*
    Advantages: The iterative approach eliminates redundant function calls and 
    is more efficient than the recursive version for large values of n. 
    It has a time complexity of O(n).
    Disadvantages: It requires maintaining additional variables and a loop structure, 
    which can make the code slightly more complex than the recursive approach.
*/
int _iterativeLoop(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    int a = 0, b = 1, c = 2, i, temp;

    for (i = 3; i <= n; i++) {
        temp = a + b;
        a = b;
        b = c;
        c = temp;
    }

    return c;
}


//method 3
/*
Advantages: Dynamic programming with memoization optimizes the recursive approach 
by storing previously calculated values in an array (memoization table). 
This avoids redundant calculations and significantly improves performance for larger n values.
Disadvantages: It requires extra memory to store the memoization table. 
The memory usage increases with the maximum value of n. 
In the provided code, MAX_SIZE is set to 100, 
but you can adjust it based on the maximum n value you expect
*/
#define MAX_SIZE 100

int memo[MAX_SIZE];

int _dynamicProgramming(int n) {
    if (n == 0)
        return 0;
    else if (n == 1)
        return 1;
    else if (n == 2)
        return 2;

    if (memo[n] != -1)
        return memo[n];

    memo[n] = _dynamicProgramming(n - 3) + _dynamicProgramming(n - 2);
    return memo[n];
}

int main()
{
    //Method 1
    printf("Method 1: ");
    int n1 = 10;  // example value
    int result1 = _recFunc(n1);
    printf("_recFunc(%d) = %d\n", n1, result1);

    //Method 2
    printf("Method 2: ");
    int n2 = 10;  // example value
    int result2 = _iterativeLoop(n2);
    printf("_iterativeLoop(%d) = %d\n", n2, result2);

    //Method 3
    printf("Method 3: ");
    int n3 = 10;  // example value
    int i;

    // Initialize memoization table
    for (i = 0; i < MAX_SIZE; i++)
        memo[i] = -1;

    int result3 = _dynamicProgramming(n3);
    printf("_dynamicProgramming(%d) = %d\n", n3, result3);
    return 0;
}