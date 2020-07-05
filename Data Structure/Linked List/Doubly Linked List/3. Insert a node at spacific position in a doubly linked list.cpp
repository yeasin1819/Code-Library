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
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    new_node -> prev = NULL;
    new_node -> next = NULL;
    while(head -> next != NULL) head = head -> next;
    new_node -> prev = head;
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

void insert_nth_pos(Node *head, int n, int data)
{
    Node *new_node = (Node*)malloc(sizeof(Node));
    new_node -> data = data;
    n--;
    while(n && (head -> next != NULL)) head = head -> next, n--;
    new_node -> prev = head;
    if(head -> next == NULL)
    {
        new_node -> prev = head;
        head -> next = new_node;
        return;
    }
    head -> next -> prev = new_node;
    new_node -> next = NULL;
    new_node -> next = head -> next;
    head -> next = new_node;

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
    prepend(head, 2);
    prepend(head, 1);
    append(head, 3);
    insert_nth_pos(head, 3, 4);
    insert_nth_pos(head, 5, 4);
    print(head);
    reverse_print(head);

    return 0;
}
