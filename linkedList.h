//
// Created by botao on 16-11-18.
//
#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

typedef int ElemType;

struct Node{
    ElemType element;
    Node* next;
};

typedef Node *List;

class LinkedList{
private:
    List head;
    int length;
public:
    LinkedList();
    void PrintList();
    bool CreateList(ElemType elem);
    bool InsertElem(ElemType elem, List pos);
    bool DeleteElem(ElemType elem);
    List FindPos(ElemType elem);
};

#endif //DATASTRUCTURES_LINKEDLIST_H
