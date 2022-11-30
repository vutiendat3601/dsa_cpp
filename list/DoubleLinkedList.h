#include <iostream>

struct DoubleLinkedList
{
    int val;
    DoubleLinkedList *left;
    DoubleLinkedList *right;
};

void insertNode(DoubleLinkedList **head, DoubleLinkedList **tail, DoubleLinkedList *q, int x);