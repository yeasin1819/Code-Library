#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *next;
};

Node *head = NULL, *tail = NULL;

void enQueue(int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> next = NULL;
    if(head == NULL)
    {
        head = new_node;
        tail = new_node;
        return;
    }
    tail -> next = new_node;
    tail = new_node;
}

void deQueue()
{
    Node *temp = head;
    head = head -> next;
    free(temp);
}

void print()
{
    Node *temp = head;
    while(temp != NULL)
    {
        cout<<temp -> data<<" ";
        temp = temp -> next;
    }
    cout<<endl;
}

int main()
{
    enQueue(1);
    enQueue(2);
    print();
    enQueue(3);
    print();
    deQueue();
    print();
    enQueue(4);
    deQueue();
    print();

     return 0;
}
