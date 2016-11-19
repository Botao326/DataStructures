#include <iostream>
#include "Stack.h"
using namespace std;

int main() {
    Stack test;

    test.push(1);
    test.push(2);


    printf("%d\n", test.pop());
    printf("%d\n", test.pop());

    if(test.isEmpty()){
        printf("Hello, Stack\n");
    }
    else
        printf("Haha\n");


    return 0;
}