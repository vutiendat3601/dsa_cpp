#include "DoubleLinkedList.h"

int main()
{
    DoubleLinkedList *head = nullptr;
    insertNode(&head, &head, head, 10);
    insertNode(&head, &head, head, 10);
    insertNode(&head, &head->right, head->right, 10);
    std::cout << "Hello" << std::endl;
}

void insertNode(DoubleLinkedList **head, DoubleLinkedList **tail,
                DoubleLinkedList *q, int x)
{
    DoubleLinkedList *node = new DoubleLinkedList{x, nullptr, nullptr};
    if (*tail == nullptr)
    {
        *head = node;
        *tail = node;
        return;
    }
    else
    {
        if (q == *head)
        {
            node->right = q;
            q->left = node;
            *head = node;
        }
        else
        {
            node->left = q->left;
            node->right = q;
            q->left = node;
        }
    }
}