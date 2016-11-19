//
// Created by botao on 16-11-19.
//

#ifndef STACK_STACK_H
#define STACK_STACK_H

typedef int ElemType;

struct Node{
    ElemType element;
    Node* next;
};

typedef Node* StackNode;

class Stack {
private:
    StackNode head;
    int size;
public:
    Stack();
    bool isEmpty();
    bool push(ElemType element);
    ElemType  pop();
};


#endif //STACK_STACK_H
