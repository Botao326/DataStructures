//
// Created by botao on 16-11-19.
//
#include <stdlib.h>
#include <stdio.h>
#include "Stack.h"

Stack::Stack() {
    head = (StackNode)malloc(sizeof(struct Node));
    head->next = NULL;
    size = 0;
}

bool Stack::isEmpty() {
    if (!head->next) return true;
}

bool Stack::push(ElemType element) {
    StackNode tmp;
    tmp = (StackNode)malloc(sizeof(struct Node));
    tmp->element = element;
    tmp->next = head->next;
    head->next = tmp;
    size++;
    return true;
}

ElemType Stack::pop() {
    if(size == 0) {
        printf("The stack is Empty!\n");
        return 0;
    }
    else {
        ElemType result;
        StackNode First;

        First = head->next;
        result = First->element;
        head->next = First->next;
        free(First);
        return result;
    }
}



