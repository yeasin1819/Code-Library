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

void append(Node *head, int data)
{
    while(head -> next != NULL) head = head -> next;
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> prev = head;
    new_node -> next = NULL;
    head -> next = new_node;
}

void delete_node_nth_pos(Node *head, int pos)
{
    pos--;
    while(pos--) head = head -> next;
    if(head -> next -> next == NULL)
    {
        head -> next = NULL;
        return;
    }
    head -> next -> next -> prev = head;
    head -> next = head -> next -> next;
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
    head -> prev = NULL;
    head -> next = NULL;
    append(head, 2);
    append(head, 3);
    prepend(head, 1);
    delete_node_nth_pos(head, 2);
    print(head);
    reverse_print(head);

    return 0;
}
