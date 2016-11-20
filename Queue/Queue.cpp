//
// Created by botao on 16-11-20.
//
#include <stdio.h>
#include <stdlib.h>
#include "Queue.h"

void Queue::CreateQueue() {
    if (Head->next){
        printf("The Queue has been created!\n");
    }

    Head = (QNode)malloc(sizeof(struct Node));
    Tail = (QNode)malloc(sizeof(struct Node));
    Head->next = NULL;
    Tail->next = NULL;
    length = 0;
}

bool Queue::AddElement(ElemType element) {
    if (isFull()){
        printf("The Queue is full!\n");
        return false;
    }

    if (isEmpty()) {
        Tail->element = element;
        Tail->next = NULL;
        Head->next = Tail;
    }
    else {
        QNode tmpNode = (QNode) malloc(sizeof(struct Node));
        tmpNode->element = element;
        tmpNode->next = NULL;
        Tail->next = tmpNode;
        Tail = tmpNode;
        Tail->next = NULL;
    }
    printf("Add element %d\n", element);
    length++;

    return true;
}

ElemType Queue::PopQueue() {
    if (isEmpty()){
        printf("The Queue is Empty!\n");
        return 0;
    }

    ElemType res = Head->next->element;
    if (Head->next == Tail){
        Head->next = Tail = NULL;
    }
    else {
        QNode tmp = Head->next;
        Head->next = Head->next->next;
        free(tmp);
    }
    printf("Pop element %d\n", res);
    return res;
}

bool Queue::isEmpty() {
    if (!Head->next){
        printf("The Queue is Empty!\n");
        return true;
    }
    else
        return false;
}

bool Queue::isFull() {
    return length >= MAXSIZE ? true : false;
}


