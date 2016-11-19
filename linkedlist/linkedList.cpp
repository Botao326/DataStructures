//
// Created by botao on 16-11-18.
//

#include <stdlib.h>
#include <stdio.h>
#include "linkedList.h"

/*
 * Construct of LinkedList
 */
LinkedList::LinkedList() {
    head = NULL;
}

/*
 * Create a linkedlist
 */
bool LinkedList::CreateList(ElemType elem) {
    if (head != NULL){
        printf("The list is NOT empyt!\n");
        return false;
    }

    head = (List)malloc(sizeof(struct Node));
    head->element = elem;
    head->next = NULL;
    printf("The list is created!\n");
    return true;
}

/*
 * Search the linkedlist
 */
List LinkedList::FindPos(ElemType elem) {
    List ptr = head;

    while( ptr != NULL && ptr->element != elem){
        ptr = ptr->next;
    }

    if (!ptr){
        printf("The element is NOT in the list!\n");
        return ptr;
    }
    return ptr;
}

/*
 * Insert an element, if the list is empty, return false;
 */
bool LinkedList::InsertElem(ElemType elem, List pos) {
    if (head == NULL){
        printf("The list is empty!\n");
        return false;
    }

    List tmp, pre;


    /*
     * Find the insertion position
     */
    for(pre = head; pre != pos; pre = pre->next);

    /*
     * No this position
     */
    if (pre == NULL){
        printf("Position is NOT in the list!\n");
        return false;
    }
        /*
         * Position Found, insert the element after the position
         */
    else{
        tmp = (List)malloc(sizeof(struct Node));
        tmp->element = elem;
        tmp->next = pos->next;
        pre->next = tmp;
        return true;
    }

}

void LinkedList::PrintList() {
    if (!head){
        printf("The list is empty!\n");
    }

    for(List ptr = head; ptr != NULL; ptr = ptr->next){
        printf("%d\n", ptr->element);
    }
}

bool LinkedList::DeleteElem(ElemType elem) {
    List pos = FindPos(elem);
    if ( !pos ){
        printf("The element is not in the list!\n");
        return false;
    }

    List ptr = head;

    for(ptr; ptr->next != pos; ptr = ptr->next);

    ptr->next = pos->next;
    free(pos);

    return true;
}


