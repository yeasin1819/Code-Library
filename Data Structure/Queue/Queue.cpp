#include <bits/stdc++.h>

using namespace std;

typedef struct node Queue;

struct node
{
    int data;
    Queue *next = NULL, *tail = NULL;

    void enQueue(int data)
    {
        Queue *new_node = (Queue*)malloc(sizeof(Queue));
        new_node -> data = data;
        new_node -> next = NULL;
        if(next == NULL)
        {
            tail = next = new_node;
            return;
        }
        tail -> next = new_node;
        tail = new_node;
    }
    void deQueue()
    {
        if(next == NULL) return;
        next = next -> next;
    }
    void print()
    {
        Queue *temp = next;
        while(temp != NULL)
        {
            cout<<temp -> data<<" ";
            temp = temp -> next;
        }
    }
};

int main()
{
    Queue q;

    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.deQueue();
    q.print();

    return 0;
}
