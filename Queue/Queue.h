//
// Created by botao on 16-11-20.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

typedef int ElemType;

struct Node{
    ElemType element;
    struct Node* next;
};

typedef Node* QNode;

class Queue {
private:
    QNode Head;
    QNode Tail;
    int length;
public:
    QNode CreateQueue();
    bool AddElement(ElemType element);
    ElemType PopQueue();
    bool isEmpty();
    bool isFull();
};


#endif //QUEUE_QUEUE_H
