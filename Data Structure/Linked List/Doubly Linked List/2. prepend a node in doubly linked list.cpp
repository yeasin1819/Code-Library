#include <bits/stdc++.h>

using namespace std;

typedef struct node Node;

struct node
{
    int data;
    Node *prev;
    Node *next;
};

void prepend(Node *head, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> prev = head;
    new_node -> next = NULL;
    if(head -> next == NULL)
    {
        head -> next = new_node;
        return;
    }
    head -> next -> prev = new_node;
    new_node -> next = head -> next;
    head -> next = new_node;
}

void print(Node *head)
{
    while(head -> next != NULL)
    {
        cout<<head -> next -> data<<" ";
        head = head -> next;
    }
    cout<<endl;
}

void reverse_print(Node *head)
{
    while(head -> next != NULL) head = head -> next;
    while(head -> prev != NULL)
    {
        cout<<head -> data<<" ";
        head = head -> prev;
    }
    cout<<endl;
}

int main()
{
    Node *head = (Node*)malloc(sizeof(Node));
    head -> next = NULL;
    head -> prev = NULL;
    prepend(head, 5);
    prepend(head, 4);
    prepend(head, 3);
    prepend(head, 2);
    prepend(head, 1);
    print(head);
    reverse_print(head);

    return 0;
}
