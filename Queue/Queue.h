//
// Created by botao on 16-11-20.
//

#ifndef QUEUE_QUEUE_H
#define QUEUE_QUEUE_H

#define MAXSIZE 100

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
    void CreateQueue();
    bool AddElement(ElemType element);
    ElemType PopQueue();
    bool isEmpty();
    bool isFull();
};


#endif //QUEUE_QUEUE_H
